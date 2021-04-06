#include "Button.h"
#include <iostream>
using namespace std;
void Button::setTextures(Texture _tNormal, Texture _tClick) {
	tNormal = _tNormal;
	tClick = _tClick;
	btnState = NORMAL;
	setTexture(tNormal);		//Ĭ�ϼ�����ͨ����
}
void Button::setTextures(Texture _tNormal, Texture _tHover, Texture _tClick) {
	tNormal = _tNormal;
	tHover = _tHover;
	tClick = _tClick;
	btnState = NORMAL;
	setTexture(tNormal);		//Ĭ�ϼ�����ͨ����	
}
void Button::setState(int state) {
	btnState = state;
	switch (btnState) {
		case 0:
			setTexture(tNormal);
			break;
		case 1:
			setTexture(tHover);
			break;
		case 2:
			setTexture(tClick);
			break;
		case 3:
			setTexture(tNormal);
			break;
		default:
			break;
	}
}
bool Button::mouseContain(Vector2i mouse) {
	return (mouse.x > getPosition().x && mouse.x < getPosition().x + getTexture()->getSize().x) &&
		(mouse.y > getPosition().y && mouse.y < getPosition().y + getTexture()->getSize().y) ? true : false;
}
bool Button::mouseContain(Vector2i mouse, int xOffset, int yOffset) {
	return (mouse.x > getPosition().x && mouse.x < getPosition().x + getTexture()->getSize().x - xOffset) &&
		(mouse.y > getPosition().y && mouse.y < getPosition().y + getTexture()->getSize().y - yOffset) ? true : false;
}
bool Button::mouseContainf(Vector2f mouse, float xOffset, float yOffset) {
	return (mouse.x > getPosition().x && mouse.x < getPosition().x + getTexture()->getSize().x - xOffset) &&
		(mouse.y > getPosition().y && mouse.y < getPosition().y + getTexture()->getSize().y - yOffset) ? true : false;
}

int Button::checkMouse(Vector2i mouse, Event event) {
	//�ж�����ǲ����ڰ�ť�ڣ�ǰ���Ƿ����ľ��Σ�һ������¶�����������������ι�״����Ҫ��д��ķ���
	if (mouseContain(mouse)) {
		if (event.type == Event::EventType::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {			//����ڷ�Χ�ﰴ�������һ����CLICK״̬																				//���������ʱ
			setState(CLICK);
		} else if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {	//�����Χ���ͷ������
			if (btnState == CLICK) {																					//���֮ǰ��CLICK״̬����ô����RELEASE״̬����ʾ����
				setState(RELEASE);																						//����Ļ�ʲôҲ����
			}
		} else {																										//�������ƶ��Ļ�������ǲ��ǰ��ŵģ����Ǿͱ�ʾHOVER״̬��
			if (btnState != CLICK) {
				setState(HOVER);
			}
		}
	} else {																											//����ڰ�ť��Χ��
		if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {			//�ڷ�Χ���ͷ�������
			setState(NORMAL);																							//�ع�NORMAL״̬
		} else if (btnState == HOVER) {																					//�����HOVER��Ҳ����Ҳû�а��¹����ع�NORMAL״̬
			setState(NORMAL);																							//�����ͱ���ԭ�� ���簴ס���ŵ�ʱ��
		}
	}
	return btnState;																									//��󷵻ذ�ť״̬
}
int Button::checkMouse(Vector2i mouse, Event event, int xOffset, int yOffset) {
	//�ж�����ǲ����ڰ�ť�ڣ�ǰ���Ƿ����ľ��Σ�һ������¶�����������������ι�״����Ҫ��д��ķ���
	if (mouseContain(mouse, xOffset, yOffset)) {
		if (event.type == Event::EventType::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {			//����ڷ�Χ�ﰴ�������һ����CLICK״̬																				//���������ʱ
			setState(CLICK);
		} else if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {	//�����Χ���ͷ������
			if (btnState == CLICK) {																					//���֮ǰ��CLICK״̬����ô����RELEASE״̬����ʾ����
				setState(RELEASE);																						//����Ļ�ʲôҲ����
			}
		} else {																										//�������ƶ��Ļ�������ǲ��ǰ��ŵģ����Ǿͱ�ʾHOVER״̬��
			if (btnState != CLICK) {
				setState(HOVER);
			}
		}
	} else {																											//����ڰ�ť��Χ��
		if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {			//�ڷ�Χ���ͷ�������
			setState(NORMAL);																							//�ع�NORMAL״̬
		} else if (btnState == HOVER) {																					//�����HOVER��Ҳ����Ҳû�а��¹����ع�NORMAL״̬
			setState(NORMAL);																							//�����ͱ���ԭ�� ���簴ס���ŵ�ʱ��
		}
	}
	return btnState;																									//��󷵻ذ�ť״̬
}
void Button::offset(float _x, float _y) {
	setPosition(getPosition().x + _x, getPosition().y + _y);
}