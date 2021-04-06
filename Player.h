#pragma once
#include "Card.h"
#include "statusBtn.h"
class Player {
public:

	int handMaxNum = 8;
	Card* handCards[8];				//����[��������]
	Card nullCard;					//����
	int handCardNums;				//������Ŀ
	int getCardNum;					//������Ŀ
	void getCard(Card[], int, int);			//����

	bool getCardState = false;					//��ҿɷ����
	void randCardPool(Card[], int);			//�鿨��ϴ��
	int cardSelect;					//���ĸ��������ڽ���

	Texture tNums[10];			//��������
	int hp;						//Ѫ��
	int fullHp = 100;					//��ѪѪ��
	int mp = 5;						//����
	int movePower = 1;				//�ж���
	void drawState(RenderWindow*);			//����״̬
	int cardPoolNum;			//�����п�������
	Sprite sMovePower;			//�ж���
	Texture tHpBar;				//Ѫ������
	Texture tMpBar;				//����
	Sprite	hpBar;		//Ѫ������
	Sprite  mpBar;		//����
	void loadMedia();
	Player();

	Font textFont;			//���ֵ�����
	Text hpText, mpText, moveText;		//����

	void updateHandCard();					//��������״̬
	void useCardTo(Card*, Player*);			//��ĳ������ʹ�ÿ���

	void disCard(Card*);					//����

	bool isTurn = true;		//�Ƿ�Ϊ����һغ�

	int fireState = 0;		//���汻��
	int poisonState = 0;			//������
	int iceState = 0;			//���䱻��
	int reduceGetCardNum = 0;		//���ٵĳ�����
	int reduceDamageNum = 0;		//���ٵ��˺���

	bool humanPlayer = true;	//�Ƿ�Ϊ�������

	std::vector<int> playerStatus;				//���״̬������
	void drawStatus(RenderWindow* window);		//���ƿ���״̬
	Texture tPlayerStatus[20];					//״̬����
	statusBtn sPlayerStatus[20];					//״̬����
	void statusUpdate(Player* enemy, int turn, int time);		//��״̬���н���

	bool addUpDamageAble = false;
	int addUpDamage = 0;
	int countDamage[2] = { 0,1 };

	void initData();			//��ʼ������

	void cheat_getCard(Card[], int num);		//���ָ������

	int turnMagicUsedNum = 0;		//���غ�ʹ������������
	int turnInvalidCardNum = 0;		//�غ���ʧЧ����
	int turnMagicAdd = 0;			//���غ����������Ӵ���

	bool turnStart = true;		//�غϿ�ʼ

	int useCardNum;		//����ʹ�õĿ�������
};

