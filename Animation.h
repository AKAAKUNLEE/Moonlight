#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Animation :public Sprite {
public:

	Texture* frames = nullptr;					//��������
	int frameLength = 0;					//������
	int frameNo = 0;					//��ǰ����֡
	void bindFrames(Texture[], int);				//������
	void play();			//���Ŷ���
};

