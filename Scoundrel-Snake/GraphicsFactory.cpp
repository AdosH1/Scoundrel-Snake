#include "GraphicsFactory.hpp"
#include <iostream>

/* Declarations - these must be included for static references*/
sf::Texture *GraphicsFactory::pBorderTexture;

sf::Texture *GraphicsFactory::pSnakeHeadN;
sf::Texture *GraphicsFactory::pSnakeHeadE;
sf::Texture *GraphicsFactory::pSnakeHeadS;
sf::Texture *GraphicsFactory::pSnakeHeadW;
sf::Texture *GraphicsFactory::pSnakeHeadNE;
sf::Texture *GraphicsFactory::pSnakeHeadNW;
sf::Texture *GraphicsFactory::pSnakeHeadSE;
sf::Texture *GraphicsFactory::pSnakeHeadSW;
sf::Texture *GraphicsFactory::pSnakeBody;

sf::Texture *GraphicsFactory::pRatHeadN;
sf::Texture *GraphicsFactory::pRatHeadE;
sf::Texture *GraphicsFactory::pRatHeadS;
sf::Texture *GraphicsFactory::pRatHeadW;

GraphicsFactory::GraphicsFactory(int WindowX, int WindowY, int borderWidth = 12)
{
    WindowSize.x = WindowX;
    WindowSize.y = WindowY;
    BorderSize.x = (float)WindowX;
    BorderSize.y = (float)borderWidth;
}

void GraphicsFactory::LoadMenu() 
{
        if (!MenuTexture.loadFromFile("Resources/Graphics/Scoundrel_menu.png"))
            std::cout << "Error loading menu texture." << std::endl;
        MenuSprite.setTexture(MenuTexture);

        if (!PlayTexture.loadFromFile("Resources/Graphics/Play.png"))
            std::cout << "Error loading play button texture." << std::endl;
        PlaySprite.setTexture(PlayTexture);
        PlaySprite.setPosition(80,320);

        if (!ExitTexture.loadFromFile("Resources/Graphics/Exit.png"))
            std::cout << "Error loading exit button texture." << std::endl;
        ExitSprite.setTexture(ExitTexture);
        ExitSprite.setPosition(80,400);

        if (!SelectorTexture.loadFromFile("Resources/Graphics/Selector.png"))
            std::cout << "Error loading selector texture." << std::endl;
        SelectorSprite.setTexture(SelectorTexture);
        SelectorSprite.setPosition(60,332);
}

void GraphicsFactory::LoadBoard()
{
    //Border Texture
    if (!BorderTexture.loadFromFile("Resources/Graphics/wood_border.png"))
        std::cout << "Error loading border texture." << std::endl;
    //Floor Texture
    if (!FloorTexture.loadFromFile("Resources/Graphics/wood_floor.png"))
        std::cout << "Error loading border texture." << std::endl;

    pBorderTexture = &BorderTexture;
    FloorSprite.setTexture(FloorTexture);

    //Please note:
    //The border texture is simply rotated to fit the screen size

    /*BorderTop.setSize(BorderSize);
    BorderTop.setTexture(pBorderTexture);

    BorderLeft.setSize(BorderSize);
    BorderLeft.setTexture(pBorderTexture);
    BorderLeft.setPosition((float)WindowSize.x,0);
    BorderLeft.rotate(90);

    BorderBottom.setSize(BorderSize);
    BorderBottom.setTexture(pBorderTexture);
    BorderBottom.setPosition(0, (float)WindowSize.y - BorderSize.y);

    BorderRight.setSize(BorderSize);
    BorderRight.setTexture(pBorderTexture);
    BorderRight.setPosition((float)WindowSize.x,0);
    BorderRight.rotate(90);*/
}

void GraphicsFactory::LoadSnake()
{
	if (!SnakeHeadN.loadFromFile("Resources/Graphics/SnakeHeadN.png"))
		std::cout << "Error loading SnakeHeadN texture." << std::endl;
	pSnakeHeadN = &SnakeHeadN;
	pSnakeHeadN->setSmooth(true);

	if (!SnakeHeadE.loadFromFile("Resources/Graphics/SnakeHeadE.png"))
		std::cout << "Error loading SnakeHeadE texture." << std::endl;
	pSnakeHeadE = &SnakeHeadE;
	pSnakeHeadE->setSmooth(true);

	if (!SnakeHeadS.loadFromFile("Resources/Graphics/SnakeHeadS.png"))
		std::cout << "Error loading SnakeHeadS texture." << std::endl;
	pSnakeHeadS = &SnakeHeadS;
	pSnakeHeadS->setSmooth(true);

	if (!SnakeHeadW.loadFromFile("Resources/Graphics/SnakeHeadW.png"))
		std::cout << "Error loading SnakeHeadW texture." << std::endl;
	pSnakeHeadW = &SnakeHeadW;
	pSnakeHeadW->setSmooth(true);

	if (!SnakeHeadNE.loadFromFile("Resources/Graphics/SnakeHeadNE.png"))
		std::cout << "Error loading SnakeHeadNE texture." << std::endl;
	pSnakeHeadNE = &SnakeHeadNE;
	pSnakeHeadNE->setSmooth(true);

	if (!SnakeHeadNW.loadFromFile("Resources/Graphics/SnakeHeadNW.png"))
		std::cout << "Error loading SnakeHeadNW texture." << std::endl;
	pSnakeHeadNW = &SnakeHeadNW;
	pSnakeHeadNW->setSmooth(true);

	if (!SnakeHeadSE.loadFromFile("Resources/Graphics/SnakeHeadSE.png"))
		std::cout << "Error loading SnakeHeadSE texture." << std::endl;
	pSnakeHeadSE = &SnakeHeadSE;
	pSnakeHeadSE->setSmooth(true);

	if (!SnakeHeadSW.loadFromFile("Resources/Graphics/SnakeHeadSW.png"))
		std::cout << "Error loading SnakeHeadSW texture." << std::endl;
	pSnakeHeadSW = &SnakeHeadSW;
	pSnakeHeadSW->setSmooth(true);

	if (!SnakeBody.loadFromFile("Resources/Graphics/SnakeBody.png"))
		std::cout << "Error loading SnakeBody texture." << std::endl;
	pSnakeBody = &SnakeBody;
	pSnakeBody->setSmooth(true);
}

void GraphicsFactory::LoadRat()
{
	if (!RatHeadN.loadFromFile("Resources/Graphics/RatHeadN.png"))
		std::cout << "Error loading RatHeadN texture." << std::endl;
	pRatHeadN = &RatHeadN;
	pRatHeadN->setSmooth(true);

	if (!RatHeadE.loadFromFile("Resources/Graphics/RatHeadE.png"))
		std::cout << "Error loading RatHeadE texture." << std::endl;
	pRatHeadE = &RatHeadE;
	pRatHeadE->setSmooth(true);

	if (!RatHeadS.loadFromFile("Resources/Graphics/RatHeadS.png"))
		std::cout << "Error loading RatHeadS texture." << std::endl;
	pRatHeadS = &RatHeadS;
	pRatHeadS->setSmooth(true);

	if (!RatHeadW.loadFromFile("Resources/Graphics/RatHeadW.png"))
		std::cout << "Error loading RatHeadW texture." << std::endl;
	pRatHeadW = &RatHeadW;
	pRatHeadW->setSmooth(true);
}

void GraphicsFactory::Initialise()
{
	LoadMenu();
	LoadBoard();
	LoadSnake();
	LoadRat();
}


