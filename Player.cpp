#include "Player.h"

#include <sstream>
#include <iostream>
using namespace std;

void Player::initData() {
	fullHp = 50;
	//cardPoolNum = 72;
	getCardState = true;						//�ɷ����
	handCardNums = 0;							//Ŀǰ������Ŀ
	getCardNum = 4;								//������Ŀ
	cardSelect = -1;							//û�н��п��ƽ���

	hp = fullHp;
	mp = 2;
	movePower = 1;

	nullCard.cardState = nullCard.null;

	for (int i = 0; i < handMaxNum; i++) {		//�����������
		handCards[i] = &nullCard;
	}
	getCardState = true;					//��ҿ��Գ���
	handCardNums = 0;
	getCardNum = 5;
	movePower = 1;

	playerStatus.clear();				//���״̬����

	addUpDamage = 0;		//������˺�Ϊ0
	countDamage[0] = 0;		//����
	countDamage[1] = 1;		//����

	turnMagicUsedNum = 0;	//���غ�ʹ��������Ϊ0
	turnMagicAdd = 0;		//���غ����������Ӵ���

	fireState = 0;
	iceState = 0;
	reduceDamageNum = 0;
	reduceGetCardNum = 0;

	turnStart = true;
}
Player::Player() {
	initData();

	textFont.loadFromFile("./data/font/simsun.ttc");
	hpText.setFont(textFont);
	hpText.setCharacterSize(20);

	hpText.setPosition(620, 864);

	mpText.setFont(textFont);
	mpText.setCharacterSize(20);
	mpText.setPosition(920, 864);


	moveText.setFont(textFont);
	moveText.setCharacterSize(20);
	moveText.setPosition(1090, 860);


	hpBar.setPosition(780, 870);
	mpBar.setPosition(1028, 870);

}
void Player::loadMedia() {
	tHpBar.loadFromFile("./data/ui/kong.png");	//�趨��ͼ
	tMpBar.loadFromFile("./data/ui/skong.png");
	for (int i = 0; i < 10; i++) {
		stringstream ss;
		ss << "./data/ui/" << i << ".png";
		tNums[i].loadFromFile(ss.str());
	}
	hpBar.setTexture(tHpBar);
	mpBar.setTexture(tMpBar);

	for (int i = 0; i < 20; i++) {
		stringstream ss;
		ss << "./data/status/card" << i << ".png";
		tPlayerStatus[i].loadFromFile(ss.str());
		sPlayerStatus[i].setTexture(tPlayerStatus[i]);
		sPlayerStatus[i].setScale(0.3f, 0.3f);
	}


}
void Player::randCardPool(Card card[], int cardsLength) {
	srand((unsigned)time(NULL));
	for (int j = 0; j < cardsLength; j++) {
		int index = rand() % cardsLength;
		if (index != j) {
			Card temp = card[j];
			card[j] = card[index];
			card[index] = temp;
		}										//ϴ��
	}
}
void Player::getCard(Card card[], int getNum, int cardLength) {
	if (handCardNums == handMaxNum) {
		return;
	} else if (getNum + handCardNums > handMaxNum) {
		getNum = handMaxNum - handCardNums;
	}
	srand((unsigned)time(NULL));
	if (handCardNums <= handMaxNum) {
		for (; getNum != 0;) {
			int num = rand() % cardLength;
			for (int i = 0; i < handMaxNum; i++) {
				if (handCards[i] == &nullCard) {
					if (card[num].cardState == card[num].cardPool) {									//��������ڿ�����ͳ���
						card[num].cardState = card[num].handPool;										//�����Ƶ�������
						handCardNums += 1;												//��������һ
						handCards[i] = &card[num];										//�������鸳ֵ
						getNum--;
					}
				}
			}
		}
	}
}
void Player::disCard(Card* card) {						//����
	card->cardState = card->disCardPool;			//�������ƶ�
	handCardNums--;								//��������һ
}
void Player::drawState(RenderWindow* window) {
	//�ڵ��������Ͻ�
	mp <= 10 ? mpBar.setScale(-1 * (1 - mp / (float)10), 1) : mpBar.setScale(0, 1);			//mp���ӣ��ڵ������
	hpBar.setScale(-1 * (1 - hp / (float)fullHp), 1);

	hpText.setString(to_string(hp));
	mpText.setString(to_string(mp));
	moveText.setString(to_string(movePower));
	window->draw(mpBar);
	window->draw(hpBar);
	window->draw(hpText);
	window->draw(mpText);
	window->draw(moveText);
}
void Player::drawStatus(RenderWindow* window) {
	for (int i = 0; i < playerStatus.size(); i++) {
		sPlayerStatus[playerStatus[i]].setPosition(325 + i * 60.f, 790);
		window->draw(sPlayerStatus[playerStatus[i]]);
	}
}
void Player::statusUpdate(Player* enemy, int turn, int time) {		//-1Ĭ��  0�ǻغϿ�ʼ 1�ǻغϽ��� 
	for (int i = 0; i < playerStatus.size(); i++) {
		if (time == -1) {
			switch (playerStatus[i]) {
				case 0:															//�ۼ����4�˺���1������ֵ
					addUpDamageAble = true;
					if (addUpDamage / 4 >= 1) {
						hp += addUpDamage / 4;
						addUpDamage %= 4;
					}
					break;
				case 1:
					if (turn == 1 && countDamage[0] == 0) {
						addUpDamage += hp / 10;
						enemy->hp -= hp / 10;
						countDamage[0] = 1;
					} else if (turn == 0) {
						countDamage[0] = 0;
					}
					break;
				case 5:
					if (turn == 0 && countDamage[1] == 0) {
						if (addUpDamageAble) {
							addUpDamage += 1;
						}
						enemy->hp -= 1;
						countDamage[1] = 1;
					} else if (turn == 1) {
						countDamage[1] = 0;
					}
					break;
				case 8:
					if (turn == 1) {
						playerStatus.erase(playerStatus.begin() + i);
					}
					break;
				case 11:
					if (enemy->reduceGetCardNum == 0) {
						playerStatus.erase(playerStatus.begin() + i);
					}
					break;
			}
		} else if (time == 1) {
			switch (playerStatus[i]) {
				case 12:
					playerStatus.erase(playerStatus.begin() + i);
					break;
				case 13:
					playerStatus.erase(playerStatus.begin() + i);
					break;
			}
		}

	}
}
void Player::useCardTo(Card* card, Player* player) {
	card->cardState = card->disCardPool;
	handCardNums--;
}

void Player::cheat_getCard(Card card[], int num) {
	if (handCardNums == handMaxNum) {
		return;
	}
	for (int i = 0; i < handMaxNum; i++) {
		if (handCards[i] == &nullCard) {
			if (card[num].cardState == card[num].cardPool) {									//��������ڿ�����ͳ���
				card[num].cardState = card[num].handPool;										//�����Ƶ�������
				handCardNums += 1;												//��������һ
				handCards[i] = &card[num];										//�������鸳ֵ
			}
		}
	}
}