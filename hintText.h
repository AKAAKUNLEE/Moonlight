#pragma once
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Color.hpp>
using namespace sf;
using namespace std;
class hintText {
public:
	hintText();
	Color color;
	Font textFont;
	Text hint;
	Clock clock;
	bool isShow = false;			//�Ƿ����ڻ���
	void setText(int);
	void showHint(RenderWindow*);
};

