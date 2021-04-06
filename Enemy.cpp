#include "Enemy.h"
#include <iostream>
#include <sstream>
using namespace std;
void Enemy::initData() {
	fullHp = 30;
	cardShow.cardState = null;

	isTurn = false;				//���˺����

	useCardNum = getCardNum;				//�ǵ��޸�

	humanPlayer = false;
	handCardNums = 0;
	getCardNum = 4;
	movePower = 2;

	mp = 3;

	hp = fullHp;		//�趨Ϊ��ʼѪ��
	for (int i = 0; i < handMaxNum; i++) {						//��ʼ����������
		handCards[i] = &nullCard;
	}

	turnStart = false;

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

}
Enemy::Enemy() {
	hpText.setCharacterSize(18);
	hpText.setPosition(785, 328);
	mpText.setCharacterSize(15);
	mpText.setPosition(785, 348);
	moveText.setPosition(895, 343);

	hpBar.setPosition(913, 334);
	mpBar.setPosition(867, 354);

	cardPosition.x = 400;
	cardPosition.y = 100;

	initData();

}
void Enemy::loadMedia() {
	tHpBar.loadFromFile("./data/ui/blong.png");	//�趨��ͼ
	tMpBar.loadFromFile("./data/ui/bshort.png");
	for (int i = 0; i < 10; i++) {
		stringstream ss;
		ss << "./data/ui/" << i << ".png";
		tNums[i].loadFromFile(ss.str());
	}
	hpBar.setTexture(tHpBar);
	mpBar.setTexture(tMpBar);
	sMovePower.setTexture(tNums[1]);

	for (int i = 0; i < 20; i++) {
		stringstream ss;
		ss << "./data/status/card" << i << ".png";
		tPlayerStatus[i].loadFromFile(ss.str());
		sPlayerStatus[i].setTexture(tPlayerStatus[i]);
		sPlayerStatus[i].setScale(0.3f, 0.3f);
	}
}
void Enemy::setName(int num) {
	name = num;
	switch (name) {
		case carpente:
			tShape.loadFromFile("./data/enemy/carpente.png");
			shape.setTexture(tShape);
			break;
		case prisone:
			tShape.loadFromFile("./data/enemy/prisone.png");
			shape.setTexture(tShape);
			break;
		default:
			break;
	}
}
bool Enemy::checkMouse(Vector2i mouse) {
	return ((mouse.x > shape.getPosition().x && mouse.x < shape.getPosition().x + shape.getTexture()->getSize().x) &&
		(mouse.y > shape.getPosition().y && mouse.y < shape.getPosition().y + shape.getTexture()->getSize().y)) ? true : false;
}
void Enemy::getCard(Card cards[], int getNum, int length) {
	Player::getCard(cards, getNum, length);
	cardShow = nullCard;			//�غϿ�ʼʱ����Ϊnull
	useCardTimer.restart();			//������ʱ��
}
int Enemy::showCard(RenderWindow* window, Player* player, cardManager* cm) {
	useCardNum = 0;
	for (int i = 0; i < handMaxNum; i++) {
		if (handCards[i]->cardState != handCards[i]->null) {
			if (cm->cardUsable(this, handCards[i])) {
				useCardNum++;
			};
		}
	}
	if (useCardNum == 0 && handCardNums == handMaxNum) {
		for (int i = 0; i < handMaxNum; i++) {
			handCards[i]->cardState = handCards[i]->disCardPool;
			handCards[i] = &nullCard;
			handCardNums--;
		}
		return 0;
	}
	if (useCardNum > 0) {
		if (useCardTimer.getElapsedTime().asMilliseconds() > 800) {		//����800 ms
			for (int i = 0; i < handMaxNum; i++) {
				if (handCards[i]->cardState != handCards[i]->null) {		//������Ʋ�Ϊ��

					//useCardTo(handCards[i], player);									//����
					//useCardTo(handCards[i], player);

					Card tempCardShow = *handCards[i];								//չʾ�ÿ���
					int cardNum = handCardNums;
					int num = cm->useCard(this, handCards[i], i, player);

					useCardNum += handCardNums - cardNum;

					//if (handCardNums == 0) {
					//	useCardNum = 0;
					//} else {
					//	if (handCardNums < cardNum) {
					//		useCardNum -= 1;
					//	}
					//}
					//cardShow = tempCardShow;
					//useCardTimer.restart();									//������ʱ��

					//return i;													//�˳�ѭ��


					switch (num) {				//�Ƿ����
						/*case 2:
						case 3:
							return -1;*/
						case -2:
						case -1:
							useCardNum--;
							//handCards[i] = &nullCard;								//��������λ��Ϊnull
							cardShow = tempCardShow;
							useCardTimer.restart();									//������ʱ��

							return i;													//�˳�ѭ��
							break;
					}

				}
			}
		}
	}
	return -2;
}
void Enemy::drawStatus(RenderWindow* window) {
	for (int i = 0; i < playerStatus.size(); i++) {
		sPlayerStatus[playerStatus[i]].setPosition(625 + i * 60.f, 400);
		window->draw(sPlayerStatus[playerStatus[i]]);
	}
}
