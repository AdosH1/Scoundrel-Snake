#pragma once
#include "Snake.hpp"

/* FYI, you can't make static classes unless its managed C++ :( */
class PlayerControl 
{
	public:
		enum Input
		{
			noAction,
			Up,
			Right,
			Down,
			Left,
			UpRight,
			DownRight,
			DownLeft,
			UpLeft,
			Exit,
			Enter
		};

		enum Mode
		{
			Menu,
			InGame
		};

		static Input currInput;
		static Input prevInput;
		static Mode GameMode;
		static IGameObject* Player;

		PlayerControl();
		
		///Gets player input - if none, returns previous input.
		static Input getPlayerInput(Input &prevInput);

		static void processInput(Input input, IGameObject *player);

		static void PlayerAction();

};

