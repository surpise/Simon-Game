#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class button
{
private:
	RectangleShape box;
	float x;
	float y;
	Color c;
public:
	button(float _x, float _y, Color _c);
	void draw(RenderWindow& _window);
	void blink(bool on);
	FloatRect getArea();
};
