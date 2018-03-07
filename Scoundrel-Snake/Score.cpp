#pragma once
#include "Score.hpp"


int Score::CurrentScore = 0;
sf::Text* Score::Text = new sf::Text();
sf::Font* Score::Font =  new sf::Font();

void Score::Initialize()
{
	Text->setCharacterSize(18);
	Text->setFillColor(sf::Color::White);
	Text->setString("Score: 0");
	Text->setPosition(500, 560);
	if (!Font->loadFromFile("Resources/Fonts/Tahoma.ttf"))
	{
		std::cout << "Unable to load font Tahoma.ttf" << std::endl;
	}
	Text->setFont(*Font);
}


bool Score::AddScore(int amount)
{
	CurrentScore += amount;
	Text->setString(std::string("Score: ") + std::to_string(CurrentScore));
	return true;
}

bool Score::SubtractScore(int amount)
{
	CurrentScore -= amount;
	Text->setString(std::string("Score: ") + std::to_string(CurrentScore));
	return true;
}

int Score::GetScore()
{
	return CurrentScore;
}

bool Score::Reset()
{
	CurrentScore = 0;
	Text->setString(std::string("Score: ") + std::to_string(CurrentScore));
	return true;
}


