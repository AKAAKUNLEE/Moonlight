#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <sstream>
#include "Button.h"
#include "Card.h"
#include "Animation.h"
#include "Enemy.h"
#include "cardManager.h"
#include "hintText.h"
#include "playerManager.h"
using namespace sf;
enum gameSceneState {		//��ͬ����Ϸ����
	SCENE_START, SCENE_FIGHT, SCENE_LOADING
};
enum enemyName {					//���˵�����
	null, carpente, prisone
};
enum e_whosTurn {					//˭�Ļغ�
	ePlayerTurn, eEnemyTurn
};
class Game {
public:
	sf::RenderWindow window;    //������Ϸ����
	Uint32 windowStyle = Style::Close | Style::Titlebar;
	Game();
	int windowWidth, windowHeight;						//��������
	int gameSceneState;									//����״̬
	bool gameOver, gameQuit;
	bool startMusicState, fightMusicState;						//���ֲ���״̬
	Texture tGameStartBK, tGameFightBK, tStartBtnNormal, tStartBtnHover, tStartBtnClick;		//��������
	Texture tbackToMenuNormal, tbackToMenuHover, tbackToMenuClick;
	Sprite sGameStartBK, sGameFightBK, sStartBtn;		//����
	Music gameStartMusic, fightMusic;								//����
	SoundBuffer victorSb, defeatSb, attackSb, hoverSb, pressSb, releaseSb;  //��Ч����
	Sound victorSd, defeatSd, attackSd, hoverSd, pressSd, releaseSd;		//��Ч
	Button startBtn, backToMenuBtn;									//�Զ���button��

	Player humanPlayer;									//�������

	int enemyName;							//��ŵ������
	Enemy enemyCarpente, enemyPrisone;						//��ʼ������

	Texture tLoadBk, tLoads[40];				//���ؽ��汳�������ض�������
	Animation anLoading;						//���ض���
	Sprite sLoadBk;								//���ؽ��汳��

	Texture tPlayUI, tEnemy[30], tEnemyUI, tNums[10], tDialog, tTurn;
	Sprite sPlayUI, sEnemy[30], sEnemyUI, sNums[10], sDialog, sTurn;
	Vector2i cardOffset;					//�趨����ƫ����

	Button turnEnd, disCardBtn;					//�غϽ�����ť,���ư�ť
	Texture turnEndNormal, turnEndHover, turnEndCllick, tDisCardBtn, tDisCardBtnHover;	//�غ�

	Texture tYesNormal, tYesHover, tYesClick, tNoNormal, tNoHover, tNoClick;		// �� ��
	Button yesBtn, noBtn;
	bool showBackDialog = false;				//�Ƿ���ʾ����������Ի���

	int whosTurn = 0;				//Ĭ����һغ�

	Sprite gmLoseDialog, gmWinDialog;
	Texture tgmOverToMenuBtn, tgmOverToMenuBtnHover, tgmOverToMenuBtnClick;
	Texture tgmOverReplayBtn, tgmOverReplayBtnHover, tgmOverReplayBtnClick;
	Texture tgameLoseDialog, tgameWinDialog;
	Button gmOvertoMenuBtn, gmOverReplayBtn;
	bool gameLose = false, gameWin = false;

	hintText hint;			//��ʾ��Ϣ
	bool showHint = false;			//�Ƿ���ʾ

	cardManager cardManage;			//���ƹ���
	playerManager playerManager;	//��ҹ���

	void Run();				//��Ϸ����

	void Initial();			//��ʼ��
	void initFightData();	//��ʼ��ս������
	void initMusic();		//��ʼ������
	void initLoading();	//��ʼ�����ؽ���

	void loadMediaData();	//����ý��
	void loadMusic();		//��������
	void loadCards();		//���ؿ���
	void loadEnemy();		//���ص���

	void Input();			//����
	void startInput(Vector2i, Event);		//��ʼ�����Ľ���
	void fightInput(Vector2i, Event);		//ս�������Ľ���

	void Draw();			//���Ʋ�ͬ������
	void drawPosition();	//���û���λ��
	void drawStart();		//��ʼ����
	void drawFight();		//ս������
	void drawLoading();     //��Ϸ���ؽ���
	void drawCard();
	void drawPlayer();		//���UI����
	void drawEnemy();       //����UI����
	void drawDialog();		//�Ƿ���ƶԻ���

	void Logic();

};