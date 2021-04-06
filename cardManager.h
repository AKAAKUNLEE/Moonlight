#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;
class cardManager {
public:
	int playerCardPoolNum = 72, enemyCardPoolNum = 72;							//�����п�������
	int playerCardLength = 72, enemyCardLength = 72;
	Card playerCards[72], enemyCards[72];										//��������
	Texture tCard1[3][72], tEnemyCard[72];										//������������
	void initCards();															//��ʼ����������
	int useCard(Player*, Card*, int i, Player*);										//ʹ�ÿ���
	void getCard(Player*, Card[], int, int, int);								//���� ��ң����� ������ �������� ��������
	bool cardUsable(Player*, Card*);												//�����Ƿ����
	int getCardPoolNum(Player*, Card[], int);				//��ȡ�������Ƶ�����
	vector<int> searchCard(Player*, Card[], int, int, int);					//��Ѱ���� ���� ���� ���� ���� 

	void drawCardPoolNum(RenderWindow*);				//���ƿ���ʣ�࿨��

	Text textCardPoolNum;		//�鿨��ʣ�࿨��
	Font textFont;				//����

	int playerStatus(Player*, Card*, Player*);
};