#pragma once

#include "PlayerControl.hpp"

PlayerControl::Input PlayerControl::currInput = noAction;
PlayerControl::Input PlayerControl::prevInput = noAction;
PlayerControl::Mode PlayerControl::GameMode = Menu;
IGameObject* PlayerControl::Player = NULL;

PlayerControl::PlayerControl()
{

}

void PlayerControl::PlayerAction()
{
	prevInput = currInput;
	currInput = getPlayerInput(prevInput);
	processInput(currInput, Player);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return prevInput = Up;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return prevInput = Down;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return prevInput = Left;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return prevInput = Right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		return prevInput = Enter;

	return prevInput;
}

void PlayerControl::processInput(Input input, IGameObject *player)
{
	if (input == noAction)
		return;

	if (GameMode == InGame)
	{
		if (player != NULL)
		{
			Point pos = player->GetPosition();
			double speed = player->GetSpeed();
			player->SetLastPosition(pos);

			if (input == Up) pos.Y -= speed;
			if (input == Right) pos.X += speed;
			if (input == Down) pos.Y += speed;
			if (input == Left) pos.X -= speed;
			if (input == UpRight)
			{
				pos.Y -= 0.71f*speed;
				pos.X += 0.71f*speed;
			}
			if (input == DownRight)
			{
				pos.Y += 0.71f*speed;
				pos.X += 0.71f*speed;
			}
			if (input == DownLeft)
			{
				pos.Y += 0.71f*speed;
				pos.X -= 0.71f*speed;
			}
			if (input == UpLeft)
			{
				pos.Y -= 0.71f*speed;
				pos.X -= 0.71f*speed;
			}

			player->SetPosition(pos);
			player->Update(input);
		}
	}

	if (GameMode == Menu)
	{
		
	}

	/* TODO: Remember to add GameOver mechanic */
}

