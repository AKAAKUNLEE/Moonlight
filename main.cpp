#include<iostream>
#include"Game.h"
#include <thread>
using namespace std;
Game game;
int main() {
	thread thLoad(&Game::loadMediaData, &game);			//����һ���̼߳�����Ϸ�ز�
	thLoad.detach();									//���������߳�����
	game.Run();
	return 0;
}