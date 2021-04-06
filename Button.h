#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Button :public Sprite {   //�̳�SFML��Sprite��
public:
	Texture tNormal;			//���ֲ�ͬ״̬������
	Texture tHover;
	Texture tClick;
	bool hoverSd = true;				//�Ƿ񲥷���Ч
	bool pressSd = true;

	enum BtnState {
		NORMAL, HOVER, CLICK, RELEASE
	};
	int btnState = NORMAL;										//��ť״̬
	int checkMouse(Vector2i, Event);					//������״̬
	void setTextures(Texture, Texture);					//������������״̬
	void setTextures(Texture, Texture, Texture);		//������������״̬
	void setState(int);									//���ð�ť״̬
	void offset(float, float);
	bool mouseContain(Vector2i);						//�������Ƿ��ھ�����
	bool mouseContain(Vector2i, int, int);						//�������Ƿ��ھ�����
	bool mouseContainf(Vector2f, float, float);						//�������Ƿ��ھ�����
	int checkMouse(Vector2i, Event, int, int);					//������״̬
};