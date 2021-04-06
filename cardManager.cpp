#include "cardManager.h"
#include <sstream>

using namespace std;

void cardManager::initCards() {
	textFont.loadFromFile("./data/font/simsun.ttc");
	textCardPoolNum.setFont(textFont);
	textCardPoolNum.setCharacterSize(20);
	textCardPoolNum.setPosition(1202, 810);
	textCardPoolNum.setFillColor(Color::Black);

	stringstream ssNormalCard;
	stringstream ssHoverCard;
	stringstream ssClickCard;
	for (int j = 0; j < 72; j++) {
		ssNormalCard << "./data/card1/card" << j << ".png";
		tCard1[0][j].loadFromFile(ssNormalCard.str());
		ssHoverCard << "./data/hoverCard1/card" << j << ".png";
		tCard1[1][j].loadFromFile(ssHoverCard.str());
		ssClickCard << "./data/clickCard1/card" << j << ".png";
		tCard1[2][j].loadFromFile(ssClickCard.str());
		ssNormalCard.str("");
		ssHoverCard.str("");
		ssClickCard.str("");
		playerCards[j].setTextures(tCard1[0][j], tCard1[1][j], tCard1[2][j]);
	}
	//for (int i = 0; i < 63; i++) {										//���ص��˵Ŀ���
	//	ssNormalCard << "./data/card2/card" << i << ".png";
	//	tEnemyCard[i].loadFromFile(ssNormalCard.str());
	//	ssNormalCard.str("");
	//	enemyCards[i].setTexture(tEnemyCard[i]);
	//}

	for (int i = 0; i < 72; i++) {
		if (i < 6) {
			playerCards[i].cardType = playerCards[i].equip;

		} else if (i < 14) {
			playerCards[i].cardType = playerCards[i].attack;
		} else if (i < 26) {
			playerCards[i].cardType = playerCards[i].mp;
		} else if (i < 45) {
			playerCards[i].cardType = playerCards[i].movePower;
		} else if (i < 72) {
			playerCards[i].cardType = playerCards[i].magic;
			playerCards[i].cost = 1;
		}
	}

	playerCards[0].playerStatus = 0;
	playerCards[1].playerStatus = 1;
	playerCards[2].playerStatus = 2;
	playerCards[3].playerStatus = 3;
	playerCards[4].playerStatus = 0;
	playerCards[5].playerStatus = 5;

	playerCards[6].damage = 5;
	playerCards[7].damage = 5;

	playerCards[8].damage = 6;
	playerCards[8].getMp = 6;
	playerCards[9].damage = 5;
	playerCards[10].damage = 5;
	playerCards[11].damage = 5;
	playerCards[12].damage = 12;
	playerCards[12].destory = true;
	playerCards[13].damage = 5;
	playerCards[14].destory = true;
	playerCards[14].getMp = 25;
	playerCards[15].getMp = 8;
	playerCards[16].getMp = 5;
	playerCards[16].getHp = 5;
	playerCards[17].getMp = 5;
	playerCards[17].getHp = 5;

	playerCards[18].destory = true;
	playerCards[18].getCardNum = 1;
	playerCards[18].playerStatus = 8;			//ÿʹ��һ�������ƣ����һ�㷨��

	playerCards[19].getMp = 5;
	playerCards[19].getCardNum = 1;				//��һ�ŷ�����
	playerCards[19].getCardType = playerCards[19].mp;

	playerCards[20].getMp = 5;
	playerCards[20].getCardNum = 1;

	playerCards[21].getMp = 5;					//��Ч������һ����
	playerCards[21].playerStatus = 9;			//

	playerCards[22].getMp = 5;
	playerCards[22].getCardNum = 1;				//��һ��������
	playerCards[22].getCardType = playerCards[22].magic;

	playerCards[23].destory = true;
	playerCards[23].getCardNum = 1;
	playerCards[23].getMp = 9;
	playerCards[24].getMp = 7;
	playerCards[24].getMovePower = 2;

	playerCards[25].getMp = 7;					//��һ������������һ��Ч��
	playerCards[25].playerStatus = 10;

	playerCards[26].destory = true;
	playerCards[26].getMovePower = 3;
	playerCards[26].cost = 0;

	playerCards[27].cost = 1;					//�������ʧ����ֵһ��
	playerCards[27].cardSpecial = 30;

	playerCards[28].cost = 1;
	playerCards[28].damage = 10;

	playerCards[29].cost = 1;
	playerCards[29].damage = 5;

	playerCards[30].cost = 1;					//ҩˮ��üӱ�
	playerCards[30].damage = 5;

	playerCards[31].cost = 1;
	playerCards[31].getCardNum = 1;
	playerCards[31].getMp = 8;

	playerCards[32].cost = 1;					//�������ʧ����ֵһ��
	playerCards[33].cardSpecial = 30;

	playerCards[33].destory = true;
	playerCards[33].getMovePower = 3;
	playerCards[33].cost = 0;

	playerCards[34].getHp = 2;
	playerCards[34].getCardNum = 1;
	playerCards[34].cost = 1;

	playerCards[35].getHp = 2;
	playerCards[35].getCardNum = 1;
	playerCards[35].cost = 1;

	playerCards[36].cost = 1;					//�з��»غϳ��Ƽ�һ
	playerCards[36].playerStatus = 11;

	playerCards[37].cost = 1;					//�з��»غϳ��Ƽ�һ
	playerCards[37].playerStatus = 11;

	playerCards[38].damage = 30;
	playerCards[38].removeGame = true;			//�Ƴ���Ϸ
	playerCards[38].cost = 1;

	playerCards[39].destory = true;
	playerCards[39].cost = 1;
	playerCards[39].getCardNum = 2;

	playerCards[40].destory = true;
	playerCards[40].cost = 1;
	playerCards[40].getCardNum = 2;

	playerCards[41].cost = 1;
	playerCards[41].getCardNum = 2;

	playerCards[42].destory = true;
	playerCards[42].getCardNum = 2;
	playerCards[42].cost = 0;
	playerCards[43].destory = true;
	playerCards[43].getCardNum = 2;
	playerCards[43].cost = 0;

	playerCards[44].destory = true;
	playerCards[44].cost = 0;
	playerCards[44].getCardNum = 2;

	playerCards[45].damage = 3;
	playerCards[45].fireDamage = 3;
	playerCards[45].potionType = 0;			//��
	playerCards[45].playerStatus = 12;		//3������

	playerCards[46].damage = 3;
	playerCards[46].iceDamage = 3;
	playerCards[46].potionType = 1;			//��
	playerCards[46].playerStatus = 13;		//3�㺮��

	playerCards[47].damage = 3;
	playerCards[47].fireDamage = 3;
	playerCards[47].potionType = 0;			//��
	playerCards[47].playerStatus = 12;		//3������

	playerCards[48].damage = 5;
	playerCards[48].superHp = 5;
	playerCards[48].potionType = 2;		//��
	playerCards[49].damage = 5;
	playerCards[49].superHp = 5;
	playerCards[49].potionType = 2;		//��
	playerCards[50].damage = 4;
	playerCards[50].potionType = 3;			//��

	playerCards[51].damage = 3;
	playerCards[51].getCardNum = 2;		//����������Ϊ1��������
	playerCards[51].getCardType = 6;

	playerCards[52].damage = 3;
	playerCards[52].getCardNum = 2;		//����������Ϊ1��������
	playerCards[52].getCardType = 6;

	playerCards[53].getMp = 5;
	playerCards[53].destory = true;
	playerCards[54].damage = 5;
	playerCards[54].superHp = 5;
	playerCards[54].potionType = 2;		//��

	playerCards[55].damage = 10;
	playerCards[55].cost = 3;			//�ظ�10%��������
	playerCards[55].cardSpecial = 20;

	playerCards[56].damage = 10;
	playerCards[56].cost = 3;			//�ظ�10%��������
	playerCards[56].cardSpecial = 20;

	playerCards[57].destory = true;
	playerCards[57].getCardNum = 1;

	playerCards[58].destory = true;
	playerCards[58].damage = 1;
	playerCards[58].attackTimes = 3;

	playerCards[59].destory = true;
	playerCards[59].getCardNum = 1;
	playerCards[59].cost = 2;

	playerCards[60].cost = 8;			//�ظ�50%��ʧ����ֵ����ɻظ���50%���˺�
	playerCards[60].destory = true;
	playerCards[60].cardSpecial = 10;

	playerCards[61].cost = 8;			//�ظ�50%��ʧ����ֵ����ɻظ���50%���˺�
	playerCards[61].destory = true;
	playerCards[61].cardSpecial = 10;

	playerCards[62].cost = 8;			//�ظ�50%��ʧ����ֵ����ɻظ���50%���˺�
	playerCards[62].destory = true;
	playerCards[62].cardSpecial = 10;

	playerCards[63].cost = 8;			//�ظ�50%��ʧ����ֵ����ɻظ���50%���˺�
	playerCards[63].destory = true;
	playerCards[63].cardSpecial = 10;

	playerCards[64].damage = 3;
	playerCards[64].getCardNum = 2;		//����������Ϊ1��������
	playerCards[64].getCardType = 6;

	playerCards[65].damage = 10;
	playerCards[65].cost = 3;			//�ظ�10%��������
	playerCards[65].cardSpecial = 20;

	playerCards[66].damage = 3;
	playerCards[66].iceDamage = 3;
	playerCards[66].potionType = 1;			//��
	playerCards[66].playerStatus = 13;

	playerCards[67].damage = 3;
	playerCards[67].iceDamage = 3;
	playerCards[67].potionType = 1;			//��
	playerCards[67].playerStatus = 13;

	playerCards[68].damage = 3;
	playerCards[68].fireDamage = 3;
	playerCards[68].potionType = 0;			//��
	playerCards[68].playerStatus = 12;

	playerCards[69].damage = 3;
	playerCards[69].fireDamage = 3;
	playerCards[69].potionType = 0;			//��
	playerCards[68].playerStatus = 12;

	playerCards[70].getHp = 7;
	playerCards[71].getHp = 7;

	//������
	/*for (int i = 72; i < 77; i++) {
		playerCards[i].playerStatus = i - 57;
	}*/
	for (int i = 0; i < 72; i++) {
		enemyCards[i] = playerCards[i];
	}

}
int cardManager::useCard(Player* player1, Card* card, int pos, Player* player2) {
	if (!cardUsable(player1, card)) {
		return card->cardType;
	} else {
		if (player1->turnInvalidCardNum > 0) {
			player1->turnInvalidCardNum--;
			for (int i = 0; i < player2->playerStatus.size(); i++) {
				if (player2->playerStatus[i] == 9) {
					player2->playerStatus.erase(player2->playerStatus.begin() + i);
				}
			}
			return -2;			//��Ч��һ����
		} else {
			int getNum = 0;
			int getType = 0;

			int num = playerStatus(player1, card, player2);

			player1->handCardNums--;				//��������һ
			card->cardState = card->disCardPool;	//�Ƶ�������


			switch (card->cardType) {				//��ȥ��Ӧ������
				case card->magic:
					player1->mp -= card->cost;
					break;
				case card->movePower:
					player1->movePower -= card->cost;
					break;
				default:
					break;
			}

			if (card->destory) {
				card->cardState = card->noPool;			//���Ƴ�
			}
			if (card->removeGame) {
				card->cardState = card->null;		//����Ϸ��ȥ
			}

			for (int times = 0; times < num; times++) {
				switch (card->cardSpecial) {
					case 10:
						card->getHp = (player1->fullHp - player1->hp) / 2;
						card->damage = card->getHp / 2;
						break;
					case 20:
						card->getHp = (player1->fullHp - player1->hp) / 10;
						break;
					case 30:
						card->damage = (player1->fullHp - player1->hp) / 2;
						break;
				}

				player1->mp += card->getMp;				//�������
				player1->movePower += card->getMovePower;	//����ж���
				if (player1->hp + card->getHp > player1->fullHp) {
					player1->hp = player1->fullHp;
				} else {
					player1->hp += card->getHp;				//���Ѫ��
				}

				player1->hp += card->superHp;			//���Ѫ������
				player1->fullHp += card->superHp;

				player2->reduceGetCardNum += card->reduceEnemyGetNum;		//���ٳ�����

																			//TODO
				if (card->damage > 0) {										//����˺�
					if (card->damage - player1->reduceDamageNum > 0) {
						player2->hp -= card->damage - player1->reduceDamageNum;
						if (player2->hp < 0) {
							player2->hp = 0;
						}
						if (player1->addUpDamageAble) {
							player1->addUpDamage += card->damage - player1->reduceDamageNum;		//�ۼ��˺�
						}
					}
					if (player1->iceState == 0) {
						player1->reduceDamageNum = 0;
					}
				}


				//player2->fireState += card->fireDamage;		//����״̬
				//player2->iceState += card->iceDamage;		//����״̬
				//player2->poisonState += card->poisonDamage;	//�ж�״̬

				getNum += card->getCardNum;
				getType += card->getCardType;
			}

			if (card->playerStatus >= 0) {

				switch (card->playerStatus) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
						player1->playerStatus.push_back(card->playerStatus);
						break;
					case 9:						//��Ч������һ����
						player1->playerStatus.push_back(card->playerStatus);
						player2->turnInvalidCardNum += 1;
						break;
					case 10:					//��������������Ч��
						player1->playerStatus.push_back(card->playerStatus);
						player1->turnMagicAdd += 1;
						break;
					case 11:
						player1->playerStatus.push_back(card->playerStatus);
						player2->reduceGetCardNum += 1;
						player2->getCardNum - player2->reduceGetCardNum > 0 ? player2->getCardNum -= player2->reduceGetCardNum : player2->getCardNum = 0;
						break;
					case 12:
						player2->playerStatus.push_back(12);		//���ӻ��汻��
						player2->fireState += 3;
						break;
					case 13:
						player2->playerStatus.push_back(13);
						player2->iceState += 3;
						break;
				}
			}

			player1->handCards[pos] = &player1->nullCard;		//����Ϊ��

			if (getNum >= 1) {
				if (player1->humanPlayer) {
					getCard(player1, playerCards, getNum, playerCardLength, getType);
				} else {
					getCard(player1, enemyCards, getNum, enemyCardLength, getType);
				}
			}



			return -1;
		}
	}
}
int cardManager::playerStatus(Player* player1, Card* card, Player* player2) {
	for (int i = 0; i < player1->playerStatus.size(); i++) {
		switch (player1->playerStatus[i]) {
			case 2:
				if (card->cardType == card->magic) {
					player2->hp -= 1;
				}
				break;
			case 3:
				if (card->destory) {
					player2->hp -= 2;
				}
				break;
			case 8:							//�غ�ʹ��һ�������� ���һ����
				if (card->cardType == card->magic) {
					player1->mp += 1;
				}
				break;
			case 9:						//��Ч������һ����
				player2->turnInvalidCardNum -= 1;
				break;
			case 10:						//�´�����������һ��Ч��
				if (card->cardType == card->magic) {
					int num = player1->turnMagicAdd + 1;
					player1->turnMagicAdd = 0;
					player1->playerStatus.erase(player1->playerStatus.begin() + i);
					return num;
				}
				break;
			case 12:													//�����˸ĳ�player2
				player2->hp -= player2->fireState;
				player2->fireState - 2 > 0 ? player2->fireState -= 2 : player2->fireState = 0;
				if (player2->fireState == 0) {
					player2->playerStatus.erase(player2->playerStatus.begin() + i);
				}
				break;
			case 13:
				if (card->damage > 0) {
					player2->reduceDamageNum = player2->iceState;
					player2->iceState - 2 > 0 ? player2->iceState -= 2 : player2->iceState = 0;
					if (player2->iceState == 0) {
						player2->playerStatus.erase(player2->playerStatus.begin() + i);
					}
				}
				break;
		}
	}
	return 1;
}
void cardManager::getCard(Player* player, Card cards[], int getNum, int cardLength, int cardType) {
	if (player->handCardNums == player->handMaxNum) {								//�����Ѵ�����
		return;
	} else if (getNum + player->handCardNums > player->handMaxNum) {				//���ƺ��ﵽ����
		getNum = player->handMaxNum - player->handCardNums;
	}
	srand((unsigned)time(NULL));													//���
	vector<int> pos;
	if (player->handCardNums <= player->handMaxNum) {
		for (; getNum != 0;) {
			int num = rand() % cardLength;
			for (int i = 0; i < player->handMaxNum; i++) {
				if (getNum == 0) {
					return;
				}
				if (player->handCards[i] == &player->nullCard) {
					switch (cardType) {
						case -1:
							pos = searchCard(player, cards, cardLength, cardType, -1);
							if (pos.empty()) {
								return;
							} else {
								int randPos = rand() % pos.size();
								cards[pos[randPos]].cardState = cards[pos[randPos]].handPool;			//�����Ƶ�������
								player->handCardNums += 1;								//��������һ
								player->handCards[i] = &cards[pos[randPos]];					//�������鸳ֵ
								getNum--;
								if (player->humanPlayer) {

									playerCardPoolNum--;
								} else {
									enemyCardPoolNum--;
								}
								break;
							}
						case 0:case 1:case 2:case 3:case 4:case 5:
							pos = searchCard(player, cards, cardLength, cardType, -1);
							if (pos.empty()) {
								return;
							} else {
								int randPos = rand() % pos.size();
								cards[pos[randPos]].cardState = cards[pos[randPos]].handPool;			//�����Ƶ�������
								player->handCardNums += 1;							//��������һ
								player->handCards[i] = &cards[pos[randPos]];					//�������鸳ֵ
								getNum--;
								if (player->humanPlayer) {
									playerCardPoolNum--;
								} else {
									enemyCardPoolNum--;

								}
								break;
							}
						case 6:
							pos = searchCard(player, cards, cardLength, 2, 1);					//��������Ϊ1��������
							if (pos.empty()) {
								return;
							} else {
								int randPos = rand() % pos.size();
								cards[pos[randPos]].cardState = cards[pos[randPos]].handPool;			//�����Ƶ�������
								player->handCardNums += 1;							//��������һ
								player->handCards[i] = &cards[pos[randPos]];					//�������鸳ֵ
								getNum--;
								if (player->humanPlayer) {
									playerCardPoolNum--;
								} else {
									enemyCardPoolNum--;
								}
								break;
							}
						case 7:						//���Ƶ�����

							break;
					}
				}
			}
		}
	}
}
bool cardManager::cardUsable(Player* player, Card* card) {
	switch (card->cardType) {
		case card->magic:
			if (player->mp - card->cost < 0) {					//����
				return false;
			}
			break;
		case card->movePower:
			if (player->movePower - card->cost < 0) {				//�ж���
				return false;
			}
			break;
	}
	return true;
}
int cardManager::getCardPoolNum(Player* player, Card cards[], int length) {
	int num = length;
	for (int i = 0; i < length; i++) {
		if (cards[i].cardState != cards[i].cardPool) {
			num--;
		}
	}
	if (player->humanPlayer) {			//���������
		playerCardPoolNum = num;
		return playerCardPoolNum;
	} else {
		enemyCardPoolNum = num;
		return enemyCardPoolNum;
	}
}
vector<int> cardManager::searchCard(Player* player, Card cards[], int length, int type, int cost) {
	vector<int> pos;
	if (getCardPoolNum(player, cards, length) == 0) {
		return pos;
	} else {
		switch (type) {
			case -1:
				for (int i = 0; i < length; i++) {
					if (cards[i].cardState == cards[i].cardPool) {
						pos.push_back(i);
					}
				}
				break;
			case 0:case 1:case 2:case 3:case 4:case 5:
				if (cost == -1) {
					for (int i = 0; i < length; i++) {
						if (cards[i].cardState == cards[i].cardPool && cards[i].cardType == type) {
							pos.push_back(i);
						}
					}
				} else {
					for (int i = 0; i < length; i++) {
						if (cards[i].cardState == cards[i].cardPool && cards[i].cardType == type && cards[i].cost == cost) {
							pos.push_back(i);
						}
					}
				}
				break;
		}
	}
	return pos;
}

void cardManager::drawCardPoolNum(RenderWindow* window) {
	textCardPoolNum.setString(to_string(playerCardPoolNum));
	window->draw(textCardPoolNum);
}
