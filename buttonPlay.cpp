#include "buttonPlay.h"

buttonPlay::buttonPlay(int diff)
{
	colors = { Color::Red,Color::Color(255,128,0),Color::Yellow,Color::Color(128,255,0), Color::Green,
	           Color::Cyan, Color::Blue,Color::Color(128,0,255),Color::Magenta, Color::Color(255,0,238) };

	for (int i = 0; i < diff; i++)
	{
		float _x = 50.0f + (150 * i);
		float _y = 200.0f;
		if (i > 4)
		{
			_x -= 750;
			_y += 100;
		}
		button box(_x, _y, colors[i]);
		boxes.push_back(box);
	}

	playerTurn = true;

	if (!buffer.loadFromFile("sound.wav"))
	{
		exit(1);
	}
	sound.setBuffer(buffer);
}

void buttonPlay::makeMission(vector<int>& mission)
{
	random_device rng;
	uniform_int_distribution <int>dist(0, boxes.size() - 1);
	int idx = dist(rng);
	mission.push_back(idx);
}

void buttonPlay::levelPlay(int idx, bool on)
{
	if (on == true)
	{
		boxes[idx].blink(true);
	}
	else
	{
		boxes[idx].blink(false);
	}
}

void buttonPlay::draw(RenderWindow& _window)
{
	for (auto& e : boxes)
	{
		e.draw(_window);
	}
}

bool buttonPlay::checkCorrect(int idx, Vector2f _mousePos)
{
	if (boxes[idx].getArea().contains(_mousePos.x, _mousePos.y))
	{
		return true;
	}
	else
	{
		cout << endl << "Game Over" << endl;
		return false;
	}
}