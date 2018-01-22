#pragma once
#include "Snake.hpp"

/* FYI, you can't make static classes unless its managed C++ :( */
class PlayerControl 
{
	public:
		enum Input
		{
			noAction,
			moveN,
			moveE,
			moveS,
			moveW,
			moveNE,
			moveSE,
			moveSW,
			moveNW,
			Exit
		};

		static Input currInput;
		static Input prevInput;

		PlayerControl();
		
		///Gets player input - if none, returns previous input.
		static Input getPlayerInput(Input &prevInput);

		static void processInput(Input input, Snake *snake);

		static void PlayerAction(Snake *snake);

};

