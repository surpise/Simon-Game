#include "button.h"

button::button(float _x, float _y, Color _c) :x(_x), y(_y), c(_c)
{
	box = RectangleShape(Vector2f(50, 50));
	box.setFillColor(Color::White);
	box.setPosition(x, y);
}

void button::draw(RenderWindow& _window)
{
	_window.draw(box);
}

void button::blink(bool on)
{
	if (on == true)
	{
		box.setFillColor(c);
	}
	else
	{
		box.setFillColor(Color::White);
	}
}

FloatRect button::getArea()
{
	return box.getGlobalBounds();
}
