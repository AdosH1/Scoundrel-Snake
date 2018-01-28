#pragma once

#ifndef _GRAPHICSFACTORY_HPP_
#define _GRAPHICSFACTORY_HPP_

#include "SFML/Graphics.hpp"

class GraphicsFactory
{
    public:

    sf::Vector2<int> WindowSize;
    sf::Vector2f BorderSize;

    // Menu Screen
    sf::Sprite MenuSprite;
    sf::Texture MenuScreenTexture;
	static sf::Texture *pMenuScreenTexture;
    sf::Sprite PlaySprite;
    sf::Texture PlayButtonTexture;
	static sf::Texture *pPlayButtonTexture;
    sf::Sprite ExitSprite;
    sf::Texture ExitButtonTexture;
	static sf::Texture *pExitButtonTexture;
    sf::Sprite SelectorSprite;
    sf::Texture SelectorTexture;
	static sf::Texture *pSelectorTexture;

    // Board
    sf::Texture BorderTexture;
    static sf::Texture *pBorderTexture;
    sf::Sprite FloorSprite;
    sf::Texture FloorTexture;
	static sf::Texture *pFloorTexture;

    // Snake
    sf::CircleShape SnakeHead;
    sf::CircleShape SnakeTail;

    sf::Texture SnakeHeadN;
    static sf::Texture *pSnakeHeadN;
    sf::Texture SnakeHeadE;
	static sf::Texture *pSnakeHeadE;
    sf::Texture SnakeHeadS;
	static sf::Texture *pSnakeHeadS;
    sf::Texture SnakeHeadW;
	static sf::Texture *pSnakeHeadW;
    sf::Texture SnakeHeadNE;
	static sf::Texture *pSnakeHeadNE;
    sf::Texture SnakeHeadNW;
	static sf::Texture *pSnakeHeadNW;
    sf::Texture SnakeHeadSE;
	static sf::Texture *pSnakeHeadSE;
    sf::Texture SnakeHeadSW;
	static sf::Texture *pSnakeHeadSW;
    sf::Texture SnakeBody;
	static sf::Texture *pSnakeBody;

    // Rat
    sf::CircleShape RatHead;

	sf::Texture RatHeadN;
	static sf::Texture *pRatHeadN;
	sf::Texture RatHeadE;
	static sf::Texture *pRatHeadE;
	sf::Texture RatHeadS;
	static sf::Texture *pRatHeadS;
	sf::Texture RatHeadW;
	static sf::Texture *pRatHeadW;

    GraphicsFactory(int WindowX, int WindowY, int borderWidth);
	void Initialise();
    void LoadMenu();
    void LoadBoard();
    void LoadSnake();
    void LoadRat();
};

#endif // _GRAPHICSFACTORY_HPP_
