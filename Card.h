#pragma once
#include "Button.h"
class Card : public Button {
public:
	enum e_cardType {
		attack, mp, magic, movePower, fightBack, equip //��ɫ�����ƣ������ƣ������ƣ��ж����ƣ������ƣ�װ����
	};
	enum e_cardState {
		cardPool, handPool, disCardPool, noPool, null			//���Ƶ�״̬�����أ��������������������Ƴ�,��
	};
	enum e_special {
		potion
	};
	enum e_potionType {
		fire, ice, dark, thunder,
	};
	int playerStatus = -1;		//������ҵ�����״̬
	int getCardType = -1;		//��������
	int reduceEnemyGetNum = 0;	//���ٵ��˳�����
	int attackTimes = 1;	//��������
	int potionType = -1;
	int failNum = 0;		//ʹ���˳���ʧЧ����
	bool removeGame = false;//�Ƿ��Ƴ���Ϸ
	int useTimes = 1;		//��������
	int cardSpecial = -1;	//���⿨��
	int getStrong = 0;		//��á�ǿЧ��		
	int cost = 0;			//���ĵ���
	int damage = 0;			//�����˺�
	int fireDamage = 0;		//�����˺�
	int iceDamage = 0;		//�����˺�
	int poisonDamage = 0;	//���˺�
	int getMp = 0;			//���ħ��
	//int reduceMagic = 0;	//����ħ��
	int getMovePower = 0;	//����ж���
	int getHp = 0;			//��Ѫ
	int superHp = 0;		//Ѫ������
	bool destory = false;		//�Ƿ��Ƴ�������
	//bool getCard = 0;		//����
	int getCardNum = 0;		//������
	int cardType = 0;		//��������
	int cardState = cardPool;	//����״̬ �ĸ�������
	bool discard = false;		//�Ƿ������

	void move(Vector2i);		//�����ƶ�
	Vector2f originPosition;	//��ʼλ��
	Vector2i originMouse;		//��ʼ���λ��



};

