#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Score
{
public:
	static sf::Text* Text;
	static sf::Font* Font;

	static void Initialize();
	static int GetScore();
	static bool AddScore(int amount);
	static bool SubtractScore(int amount);
	static bool Reset();

private:
	static int CurrentScore;
};