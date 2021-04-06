#pragma once
#include "Player.h"
#include "cardManager.h"
using namespace sf;
class Enemy :public Player {
public:
	enum eName {					//���˵�����
		null, carpente, prisone
	};

	int name = 0;						//����
	Texture tShape;					//��������
	Sprite shape;					//���˾���s
	void setName(int);				//�趨����
	void loadMedia();
	Enemy();

	bool checkMouse(Vector2i);	//�������Ƿ��ڵ�������

	void getCard(Card[], int, int);			//����
	int showCard(RenderWindow*, Player*, cardManager*);		//�ѵ����ù��Ŀ���չʾ����Ļ��
	Card cardShow;			//չʾ�Ŀ���
	Vector2f cardPosition;		//���˿��ƵĻ���λ��
	Clock useCardTimer;			//���ƶ�ʱ��

	Clock lastCardClock;			//���˳����һ���Ƶ���ʱ

	void initData();
	void drawStatus(RenderWindow* window);
};

