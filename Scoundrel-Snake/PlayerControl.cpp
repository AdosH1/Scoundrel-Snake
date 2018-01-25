#pragma once

#include "PlayerControl.hpp"

PlayerControl::Input PlayerControl::currInput = noAction;
PlayerControl::Input PlayerControl::prevInput = noAction;

PlayerControl::PlayerControl()
{

}

void PlayerControl::PlayerAction(Snake *snake)
{
	prevInput = currInput;
	currInput = getPlayerInput(prevInput);
	processInput(currInput, snake);
}

// We parse in prevInput in the case that no button is pressed, it will return the last known input
PlayerControl::Input PlayerControl::getPlayerInput(Input &prevInput)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return prevInput = Exit;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveNE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveNW;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveSW;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveSE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return prevInput = moveN;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return prevInput = moveS;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveW;

	return prevInput;
}

void PlayerControl::processInput(Input input, Snake *snake)
{
	if (input == noAction)
		return;

	snake->LastPos = snake->Pos;
	snake->UpdateHeadTexture(input);
	if (input == moveN) snake->Pos.Y -= snake->Speed;
	if (input == moveE) snake->Pos.X += snake->Speed;
	if (input == moveS) snake->Pos.Y += snake->Speed;
	if (input == moveW) snake->Pos.X -= snake->Speed;
	if (input == moveNE)
	{
		snake->Pos.Y -= 0.71f*snake->Speed;
		snake->Pos.X += 0.71f*snake->Speed;
	}
	if (input == moveSE)
	{
		snake->Pos.Y += 0.71f*snake->Speed;
		snake->Pos.X += 0.71f*snake->Speed;
	}
	if (input == moveSW)
	{
		snake->Pos.Y += 0.71f*snake->Speed;
		snake->Pos.X -= 0.71f*snake->Speed;
	}
	if (input == moveNW)
	{
		snake->Pos.Y -= 0.71f*snake->Speed;
		snake->Pos.X -= 0.71f*snake->Speed;
	}
	snake->UpdateTail();

	/* TODO: Remember to add GameOver mechanic */
}

