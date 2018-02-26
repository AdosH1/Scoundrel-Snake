#pragma once

#include "PlayerControl.hpp"

PlayerControl::Input PlayerControl::currInput = noAction;
PlayerControl::Input PlayerControl::prevInput = noAction;
PlayerControl::Mode PlayerControl::GameMode = Menu;

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
		return prevInput = UpRight;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = UpLeft;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = DownLeft;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = DownRight;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return prevInput = Up;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = Right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return prevInput = Down;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = Left;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return prevInput = Respawn;

	return prevInput;
}

void PlayerControl::processInput(Input input, Snake *snake)
{
	if (input == noAction)
		return;

	if (GameMode == InGame)
	{
		if (snake != NULL)
		{
			snake->LastPos = snake->Pos;
			snake->UpdateHeadTexture(input);
			if (input == Up) snake->Pos.Y -= snake->Speed;
			if (input == Right) snake->Pos.X += snake->Speed;
			if (input == Down) snake->Pos.Y += snake->Speed;
			if (input == Left) snake->Pos.X -= snake->Speed;
			if (input == UpRight)
			{
				snake->Pos.Y -= 0.71f*snake->Speed;
				snake->Pos.X += 0.71f*snake->Speed;
			}
			if (input == DownRight)
			{
				snake->Pos.Y += 0.71f*snake->Speed;
				snake->Pos.X += 0.71f*snake->Speed;
			}
			if (input == DownLeft)
			{
				snake->Pos.Y += 0.71f*snake->Speed;
				snake->Pos.X -= 0.71f*snake->Speed;
			}
			if (input == UpLeft)
			{
				snake->Pos.Y -= 0.71f*snake->Speed;
				snake->Pos.X -= 0.71f*snake->Speed;
			}
			snake->UpdateTail();
		}
	}

	/* TODO: Remember to add GameOver mechanic */
}

