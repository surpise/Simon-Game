#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include <array>
#include <random>
#include <iostream>
#include "button.h"

using namespace sf;
using namespace std;

class buttonPlay
{
private:
	vector<button>boxes;
	array<Color, 10>colors;
	SoundBuffer buffer;
public:
	bool playerTurn;
	Sound sound;
	buttonPlay(int diff);
	void makeMission(vector<int>& mission);
	void levelPlay(int idx, bool on);
	void draw(RenderWindow& _window);
	bool checkCorrect(int idx, Vector2f _mousePos);
};