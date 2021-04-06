#include "Game.h"
#include <iostream>
#include <thread>
using namespace std;

Game::Game() {
	windowWidth = 1600;								//���ڿ��
	windowHeight = 900;								//���ڸ߶�
	window.create(VideoMode(windowWidth, windowHeight), L"��Բ֮ҹ", windowStyle);			//����һ��xx��xx�ߣ�����Ϊxxx�Ĵ��ڣ�L��ʾ˫�ֽ�
	gameSceneState = SCENE_LOADING;					//��ʼĬ����Ϸ����
	initLoading();

}
void Game::Initial() {
	window.setFramerateLimit(60);					//ˢ��֡��
	gameOver = gameQuit = false;
	fightMusicState = true;
	startMusicState = true;
	drawPosition();
}
void Game::initFightData() {
	whosTurn = ePlayerTurn;
	for (int i = 0; i < sizeof(cardManage.playerCards) / sizeof(cardManage.playerCards[0]); i++) {			//��ʼ����ҿ���
		cardManage.playerCards[i].cardState = cardManage.playerCards[i].cardPool;
		cardManage.playerCards[i].discard = true;
	}


	for (int i = 0; i < humanPlayer.handMaxNum; i++) {			//��������������
		humanPlayer.handCards[i] = &humanPlayer.nullCard;
	}
	humanPlayer.initData();
	enemyCarpente.initData();
	gameLose = false;			//��Ϸû����

	for (int i = 0; i < sizeof(cardManage.enemyCards) / sizeof(cardManage.enemyCards[0]); i++) {		//��ʼ�����˿���
		cardManage.enemyCards[i].cardState = cardManage.enemyCards[i].cardPool;
		cardManage.enemyCards[i].discard = true;
	}


	enemyCarpente.initData();
}
void Game::loadMediaData() {
	//������ͼ����
	tGameStartBK.loadFromFile("./data/bg/bg1.png");
	tStartBtnNormal.loadFromFile("./data/button/start.png");
	tStartBtnHover.loadFromFile("./data/button/startHover.png");
	tStartBtnClick.loadFromFile("./data/button/startClick.png");
	tGameFightBK.loadFromFile("./data/bg/bg2.png");
	tbackToMenuNormal.loadFromFile("./data/button/backNormal.png");
	tbackToMenuHover.loadFromFile("./data/button/backHover.png");
	tbackToMenuClick.loadFromFile("./data/button/backClick.png");

	tPlayUI.loadFromFile("./data/ui/playerUI.png");
	tEnemyUI.loadFromFile("./data/ui/enemyUI.png");
	tDialog.loadFromFile("./data/ui/dialog.png");
	tTurn.loadFromFile("./data/ui/yourTurn.png");

	sPlayUI.setTexture(tPlayUI);
	sEnemyUI.setTexture(tEnemyUI);
	sDialog.setTexture(tDialog);
	sTurn.setTexture(tTurn);

	//���������
	sGameStartBK.setTexture(tGameStartBK);
	startBtn.setTextures(tStartBtnNormal, tStartBtnHover, tStartBtnClick);
	sGameFightBK.setTexture(tGameFightBK);
	backToMenuBtn.setTextures(tbackToMenuNormal, tbackToMenuHover, tbackToMenuClick);

	tDisCardBtn.loadFromFile("./data/button/delete.png");
	tDisCardBtnHover.loadFromFile("./data/button/deleteHover.png");
	disCardBtn.setTextures(tDisCardBtn, tDisCardBtnHover, tDisCardBtnHover);

	//������Ƶ
	gameStartMusic.openFromFile("./data/music/game.ogg");
	fightMusic.openFromFile("./data/music/fight.ogg");

	victorSb.loadFromFile("./data/sound/victor.ogg");
	defeatSb.loadFromFile("./data/sound/defeat.ogg");
	attackSb.loadFromFile("./data/sound/attack.ogg");
	hoverSb.loadFromFile("./data/sound/hover.ogg");
	pressSb.loadFromFile("./data/sound/press.ogg");
	releaseSb.loadFromFile("./data/sound/release.ogg");

	victorSd.setBuffer(victorSb);
	defeatSd.setBuffer(defeatSb);
	attackSd.setBuffer(attackSb);
	hoverSd.setBuffer(hoverSb);
	pressSd.setBuffer(pressSb);
	releaseSd.setBuffer(releaseSb);

	turnEndNormal.loadFromFile("./data/button/endNormal.png");
	turnEndHover.loadFromFile("./data/button/endHover.png");
	turnEndCllick.loadFromFile("./data/button/endClick.png");
	turnEnd.setTextures(turnEndNormal, turnEndHover, turnEndCllick);

	tYesNormal.loadFromFile("./data/button/yes.png");
	tYesHover.loadFromFile("./data/button/yesHover.png");
	tYesClick.loadFromFile("./data/button/yesClick.png");
	tNoNormal.loadFromFile("./data/button/no.png");
	tNoHover.loadFromFile("./data/button/noHover.png");
	tNoClick.loadFromFile("./data/button/noClick.png");

	yesBtn.setTextures(tYesNormal, tYesHover, tYesClick);
	noBtn.setTextures(tNoNormal, tNoHover, tNoClick);


	tgameWinDialog.loadFromFile("./data/ui/youWin.png");						//��Ӯ�ĶԻ���
	tgameLoseDialog.loadFromFile("./data/ui/youLose.png");
	tgmOverToMenuBtn.loadFromFile("./data/button/toMenu.png");					//������Ϸ����ʱ�İ�ť	
	tgmOverToMenuBtnHover.loadFromFile("./data/button/toMenuHover.png");		//����������
	tgmOverToMenuBtnClick.loadFromFile("./data/button/toMenuClick.png");
	tgmOverReplayBtn.loadFromFile("./data/button/replay.png");
	tgmOverReplayBtnHover.loadFromFile("./data/button/replayHover.png");
	tgmOverReplayBtnClick.loadFromFile("./data/button/replayClick.png");

	gmOverReplayBtn.setTextures(tgmOverReplayBtn, tgmOverReplayBtnHover, tgmOverReplayBtnClick);
	gmOvertoMenuBtn.setTextures(tgmOverToMenuBtn, tgmOverToMenuBtnHover, tgmOverToMenuBtnClick);
	gmWinDialog.setTexture(tgameWinDialog);
	gmLoseDialog.setTexture(tgameLoseDialog);

	loadCards();
	gameSceneState = SCENE_START;
	initMusic();
	humanPlayer.loadMedia();
	loadEnemy();

}
void Game::initMusic() {
	gameStartMusic.setLoop(true);			////��������ѭ��
	fightMusic.setLoop(true);
	gameStartMusic.play();
}
void Game::loadMusic() {
	switch (gameSceneState) {
		case SCENE_START:
			fightMusic.stop();
			if (startMusicState) {			//���ֿ���
				gameStartMusic.play();
			} else {
				gameStartMusic.stop();
			}break;
		case SCENE_FIGHT:
			gameStartMusic.stop();
			if (fightMusicState) {			//���ֿ���
				fightMusic.play();
			} else {
				fightMusic.stop();
			}break;
		default:
			break;
	}
}
void Game::loadCards() {
	cardManage.initCards();
}
void Game::loadEnemy() {
	enemyCarpente.setName(1);
	enemyCarpente.loadMedia();
}
void Game::Input() {
	Event event;
	Vector2i mousePosition = Mouse::getPosition(window);
	while (window.pollEvent(event)) {				//�����¼�
		if (event.type == Event::Closed) {
			window.close();							//�رռ��رմ���
			gameQuit = true;
		}
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			window.close();							//��esc���رմ���
			gameQuit = true;
		}
		switch (gameSceneState) {
			case SCENE_START:
				startInput(mousePosition, event); break;
			case SCENE_FIGHT:
				fightInput(mousePosition, event); break;
			default:
				break;
		}
	}
}
void Game::startInput(Vector2i mousePosition, Event event) {
	backToMenuBtn.setState(0);
	switch (startBtn.checkMouse(mousePosition, event)) {
		case 1:
			break;
		case 3:														//���RELEASE״̬
			releaseSd.play();
			gameSceneState = SCENE_FIGHT;							//�л�����
			loadMusic();											//��������
			initFightData();										//����ս������
		default:
			break;
	}
}
void Game::fightInput(Vector2i mousePosition, Event event) {

	if (gameWin) {
		if (event.type == Event::EventType::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			gameSceneState = SCENE_START;				//�л�����
			gameWin = false;							//
		}
	} else if (gameLose) {
		switch (gmOverReplayBtn.checkMouse(mousePosition, event)) {
			case 3:
				initFightData();
				gmOverReplayBtn.setState(gmOverReplayBtn.NORMAL);
		}
		switch (gmOvertoMenuBtn.checkMouse(mousePosition, event)) {
			case 3:
				gameLose = false;
				gameSceneState = SCENE_START;									//�л�����
				gmOvertoMenuBtn.setState(gmOvertoMenuBtn.NORMAL);				//�趨Ϊ��ͨ״̬
				loadMusic();													//�л�����
		}
	} else {

		startBtn.setState(0);
		switch (backToMenuBtn.btnState) {
			case 1:
			case 2:
				backToMenuBtn.offset(-5, -5);						//�趨ƫ����
				break;
		}
		switch (backToMenuBtn.checkMouse(mousePosition, event)) {
			case 1:
				break;
			case 3:
				releaseSd.play();										//�ͷŰ�ť������
				showBackDialog = true;									//��ʾ�Ի���
				break;
		}
		if (showBackDialog) {
			switch (yesBtn.checkMouse(mousePosition, event)) {
				case 3:
					gameSceneState = SCENE_START;							//�л�����
					loadMusic();											//��������
					showBackDialog = false;								//����ʾ�Ի���
					yesBtn.setState(0);									//�趨��ťΪ��ͨ״̬
					break;
			}
			switch (noBtn.checkMouse(mousePosition, event)) {
				case 3:
					showBackDialog = false;
					break;
			}
		}
		if (whosTurn == ePlayerTurn) {
			switch (turnEnd.checkMouse(mousePosition, event, 0, 0)) {
				case 1:
					hoverSd.play();
					break;
				case 3:

					//humanPlayer.cheat_getCard(cardManage.playerCards, 18);		//ȥ��
					//humanPlayer.cheat_getCard(cardManage.playerCards, 23);		//ȥ��

					releaseSd.play();

					whosTurn = eEnemyTurn;									//���˻غ�
					enemyCarpente.getCardState = true;						//������
					enemyCarpente.turnStart = true;					//���˻غϿ�ʼ
					turnEnd.setState(turnEnd.NORMAL);
					break;
			}
			int cardPos = 0;											//��ǰ�����������еĵڼ���
			for (int i = 0; i < humanPlayer.handMaxNum; i++) {
				if (humanPlayer.handCards[i]->cardState != humanPlayer.handCards[i]->null) {
					cardPos++;
					if (cardPos != humanPlayer.handCardNums) {	//����������һ�����ƣ��������棩
						cardOffset.x = 80;
						cardOffset.y = 0;
					} else {
						cardOffset.x = 0;
						cardOffset.y = 0;
					}
					if (humanPlayer.handCards[i]->mouseContain(mousePosition, cardOffset.x, cardOffset.y)) {
						humanPlayer.cardSelect = i;								//���i�ſ��ƽ��н���
					}
					switch (humanPlayer.handCards[i]->checkMouse(mousePosition, event, cardOffset.x, cardOffset.y)) {		//��Ƭ�¼�
						case 0:
							humanPlayer.handCards[i]->hoverSd = true;					//�����ƬΪ��ͨ״̬ ���� ����Ƶ������� ԭ���ͷſ���
							humanPlayer.handCards[i]->pressSd = true;
							if (humanPlayer.cardSelect != -1) {							//���������뿨�ƽ��н���

							} else if (mousePosition.x > (300 + (humanPlayer.handCardNums - 1) * 150 + 200) || mousePosition.x < 300 || mousePosition.y>800 || mousePosition.y < 500) {		//�������������
								pressSd.stop();											//����ʱ����Ч
								hoverSd.stop();											//����ʱ����Ч
							}
							break;
						case 1:
							pressSd.stop();
							if (humanPlayer.handCards[i]->hoverSd) {					//���������Ч�ɲ���
								hoverSd.play();											//����������Ч
								humanPlayer.handCards[i]->hoverSd = false;				//���ɲ���������Ч
							}
							break;
						case 2:
							hoverSd.stop();
							if (humanPlayer.handCards[i]->pressSd) {
								pressSd.play();
								humanPlayer.handCards[i]->pressSd = false;
							}
							disCardBtn.setState(disCardBtn.HOVER);
							break;
						case 3:
							pressSd.stop();
							releaseSd.play();
							if (enemyCarpente.checkMouse(mousePosition)) {
								switch (cardManage.useCard(&humanPlayer, humanPlayer.handCards[i], i, &enemyCarpente)) {		//�Ƿ�ɳ���
									case 2:
										hint.setText(0);
										break;
									case 3:
										hint.setText(1);
										break;
									case -1:
										attackSd.play();													//���Ź�������
										//humanPlayer.useCardTo(humanPlayer.handCards[i], &enemyCarpente);	//�Ե���ʹ�ÿ���

										//humanPlayer.handCards[i] = &humanPlayer.nullCard;					//�趨ʹ�ú������Ϊnull
										break;
									case -2:			//��Ч��һ����

										break;
								}
							} else {
								if (humanPlayer.handCards[i]->mouseContainf(disCardBtn.getPosition(), 30, -30)) {
									humanPlayer.disCard(humanPlayer.handCards[i]);
									humanPlayer.handCards[i] = &humanPlayer.nullCard;					//�趨ʹ�ú������Ϊnull
								} else
									humanPlayer.handCards[i]->setState(humanPlayer.handCards[i]->NORMAL);		//�ͷź��趨Ϊ��ͨ״̬
							}
							disCardBtn.setState(disCardBtn.NORMAL);
							humanPlayer.cardSelect = -1;								//û�����뿨�ƽ��н���
							humanPlayer.handCards[i]->hoverSd = true;					//�ͷſ��ƣ���Ч�ɲ���
							humanPlayer.handCards[i]->pressSd = true;
							break;

					}
				}

			}
		}
	}
}
void Game::drawPosition() {

	sGameStartBK.setPosition(0, 0);			//���û���λ��
	startBtn.setPosition(windowWidth * 0.7f, windowHeight * 0.3f);

	sGameFightBK.setPosition(0, 0);			//�趨����ͼλ��

	sTurn.setPosition(540, 400);
	sPlayUI.setPosition(0, 700);

	turnEnd.setPosition(1275, 785);
	disCardBtn.setPosition(80, 840);

	//����
	enemyCarpente.shape.setPosition(680, 10);
	sEnemyUI.setPosition(635, 300);

	//�Ի���
	sDialog.setPosition(635, 200);
	yesBtn.setPosition(700, 350);
	noBtn.setPosition(875, 350);

	//��Ӯ�Ի���
	gmOverReplayBtn.setPosition(830, 580);
	gmOvertoMenuBtn.setPosition(440, 580);
	gmLoseDialog.setPosition(420, 20);
	gmWinDialog.setPosition(420, 20);

}
void Game::Draw() {
	Vector2u size;
	size.x = windowWidth;
	size.y = windowHeight;
	window.setSize(size);
	switch (gameSceneState) {		//�����ж�
		case SCENE_START:
			drawStart();
			break;
		case SCENE_FIGHT:
			drawFight();
			break;
		case SCENE_LOADING:
			drawLoading();
			break;
		default:
			break;
	}
}
void Game::initLoading() {
	tLoadBk.loadFromFile("./data/bg/loading.png");		//���ر���
	stringstream ss;
	for (int i = 0; i < 40; i++) {						//���ض�������
		ss << "./data/anime/loading/load" << i << ".png";
		tLoads[i].loadFromFile(ss.str());
		ss.str("");
	}
	sLoadBk.setTexture(tLoadBk);
	anLoading.bindFrames(tLoads, sizeof(tLoads) / sizeof(tLoads[0]));	//�󶨶�������
	anLoading.setScale(0.5, 0.5);										//����
}
void Game::drawLoading() {
	sLoadBk.setPosition(0, 0);
	window.draw(sLoadBk);
	anLoading.setPosition(800, 400);
	anLoading.play();						//���ŵ�ǰ֡
	window.draw(anLoading);
	window.display();
}
void Game::drawStart() {					//��ʼ����
	window.clear();							//����
	window.draw(sGameStartBK);				//����
	window.draw(startBtn);
	window.display();
}
void Game::drawFight() {					//ս������
	window.clear();							//����
	window.draw(sGameFightBK);				//���Ʊ���ͼ

	backToMenuBtn.setPosition(windowWidth * 0.9f, windowHeight * 0.05f);	//���ٷֱȻ���	��Ҫд����ĺ�����ȥ
	window.draw(backToMenuBtn);
	drawPlayer();
	drawEnemy();
	//����
	drawCard();
	drawDialog();

	window.display();						//չʾ��Ļ
}
void Game::drawCard() {
	int pos = 0;					//��¼����λ��
	for (int i = 0; i < humanPlayer.handMaxNum; i++) {
		if (humanPlayer.handCards[i]->cardState != humanPlayer.handCards[i]->null) {
			//cout << "is " << i << endl;
			if (humanPlayer.handCards[i]->btnState == humanPlayer.handCards[i]->CLICK) {				//���Ϊ���µ�״̬
				humanPlayer.handCards[i]->move(Mouse::getPosition(window));								//�����ƶ��¼�
			} else {
				humanPlayer.handCards[i]->setPosition((float)(700 + (pos - humanPlayer.handCardNums / 2) * 120), (float)480);								//Ĭ��λ��
				humanPlayer.handCards[i]->originPosition = humanPlayer.handCards[i]->getPosition();		//����Ĭ��λ��
				humanPlayer.handCards[i]->originMouse = Mouse::getPosition(window);						//�趨�������ǰ����λ��
			}
			window.draw(*humanPlayer.handCards[i]);
			if (pos < humanPlayer.handCardNums) {
				pos++;
			}
		}
	}
}
void Game::drawPlayer() {
	window.draw(sPlayUI);
	humanPlayer.drawState(&window);			//������������
	humanPlayer.drawStatus(&window);			//��������״̬
	window.draw(turnEnd);
	window.draw(disCardBtn);
	cardManage.drawCardPoolNum(&window);
}
void Game::drawEnemy() {
	window.draw(enemyCarpente.shape);
	window.draw(sEnemyUI);
	enemyCarpente.drawState(&window);
	if (whosTurn == eEnemyTurn && !gameLose) {

		//int i = enemyCarpente.showCard(&window, &humanPlayer);
		//cardManage.useCard(&enemyCarpente, enemyCarpente.handCards[i], i, &humanPlayer);

		int j = enemyCarpente.showCard(&window, &humanPlayer, &cardManage);

		if (enemyCarpente.cardShow.cardState != enemyCarpente.cardShow.null) {
			enemyCarpente.cardShow.setPosition(enemyCarpente.cardPosition);
			window.draw(enemyCarpente.cardShow);
		}

		//cout << enemyCarpente.handCardNums;
	}
	enemyCarpente.drawStatus(&window);


}
void Game::drawDialog() {
	if (showBackDialog) {
		window.draw(sDialog);
		window.draw(yesBtn);
		window.draw(noBtn);
	}
	if (gameLose) {
		window.draw(gmLoseDialog);
		window.draw(gmOverReplayBtn);
		window.draw(gmOvertoMenuBtn);
	}
	if (gameWin) {
		window.draw(gmWinDialog);
	}
	hint.showHint(&window);
}

void Game::Logic() {
	switch (gameSceneState) {
		case SCENE_FIGHT:
			if (humanPlayer.hp <= 0) {
				gameLose = true;
				enemyCarpente.cardShow = enemyCarpente.nullCard;
			}
			if (enemyCarpente.hp <= 0) {
				gameWin = true;
			}
			humanPlayer.statusUpdate(&enemyCarpente, whosTurn, -1);
			enemyCarpente.statusUpdate(&humanPlayer, whosTurn, -1);
			//cout << enemyCarpente.getCardState << "and" << enemyCarpente.isTurn;
			if (whosTurn == eEnemyTurn) {
				humanPlayer.statusUpdate(&enemyCarpente, whosTurn, 1);
				if (enemyCarpente.getCardState) {
					if (cardManage.enemyCardPoolNum == 0) {
						for (int i = 0; i < sizeof(cardManage.enemyCards) / sizeof(cardManage.enemyCards[0]); i++) {			//����
							if (cardManage.enemyCards[i].cardState == cardManage.enemyCards[i].disCardPool) {					//����������ƶѾ�ת�Ƶ����ƶ���
								cardManage.enemyCards[i].cardState = cardManage.enemyCards[i].cardPool;
							}
						}
					}
					if (enemyCarpente.movePower < 2) {
						enemyCarpente.movePower = 2;
					}

					cardManage.getCard(&enemyCarpente, cardManage.enemyCards, enemyCarpente.getCardNum, sizeof(cardManage.enemyCards) / sizeof(cardManage.enemyCards[0]), -1);
					if (enemyCarpente.reduceGetCardNum > 0) {			//�ظ����ٳ�����
						enemyCarpente.getCardNum += enemyCarpente.reduceGetCardNum;
						enemyCarpente.reduceGetCardNum = 0;

					}
					//enemyCarpente.getCard(cardManage.enemyCards, enemyCarpente.getCardNum, sizeof(cardManage.enemyCards) / sizeof(cardManage.enemyCards[0]));				//����  ��ȡ��������

					enemyCarpente.getCardState = false;
				}
				if (enemyCarpente.turnStart) {
					enemyCarpente.useCardNum = enemyCarpente.handCardNums;	//���˿���������
					enemyCarpente.turnStart = false;
				}
				if (enemyCarpente.useCardNum == 1) {
					enemyCarpente.lastCardClock.restart();													//������ʱ��
				}
				if (enemyCarpente.useCardNum == 0) {
					if (enemyCarpente.lastCardClock.getElapsedTime().asMilliseconds() > 1600) {				//��ȡ���һ����չʾʱ��
						whosTurn = ePlayerTurn;																//��һغ�
						humanPlayer.getCardState = true;													//��ҿɳ���
						enemyCarpente.cardShow = enemyCarpente.nullCard;									//�趨չʾ����Ϊnull
						humanPlayer.turnStart = true;														//��һغϿ�ʼ
					}
				}

			} else if (whosTurn == ePlayerTurn && !gameLose) {

				enemyCarpente.statusUpdate(&humanPlayer, whosTurn, 1);
				if (humanPlayer.getCardState) {
					if (cardManage.playerCardPoolNum == 0) {																	//������س�����
						for (int i = 0; i < sizeof(cardManage.playerCards) / sizeof(cardManage.playerCards[0]); i++) {			//����
							if (cardManage.playerCards[i].cardState == cardManage.playerCards[i].disCardPool) {					//����������ƶѾ�ת�Ƶ����ƶ���
								cardManage.playerCards[i].cardState = cardManage.playerCards[i].cardPool;
							}
						}
					}
					humanPlayer.mp /= 2;					//ÿ�غ�ħ������
					if (humanPlayer.movePower == 0) {		//ÿ�غϻظ�һ���ж���
						humanPlayer.movePower = 1;
					}
					cardManage.getCard(&humanPlayer, cardManage.playerCards, humanPlayer.getCardNum, sizeof(cardManage.playerCards) / sizeof(cardManage.playerCards[0]), -1);
					if (humanPlayer.reduceGetCardNum > 0) {			//�ظ����ٳ�����
						humanPlayer.getCardNum += humanPlayer.reduceGetCardNum;
						humanPlayer.reduceGetCardNum = 0;
					}
					//humanPlayer.getCard(cardManage.playerCards, humanPlayer.getCardNum, sizeof(cardManage.playerCards) / sizeof(cardManage.playerCards[0]));				//����  ��ȡ��������
					humanPlayer.getCardState = false;
					for (int i = 0; i < humanPlayer.handCardNums; i++) {
						humanPlayer.handCards[i]->setState(0);		//������ͼΪ��ͨ״̬
					}
				}
				if (humanPlayer.turnStart) {
					humanPlayer.turnStart = false;
				}
			}

			break;
	}
}

void Game::Run() {
	Initial();
	while (window.isOpen()) {
		Input();
		Draw();
		Logic();
	}
}
