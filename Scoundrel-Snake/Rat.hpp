#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "IGameObject.hpp"
#include "IDrawable.hpp"
#include "../Utility/Point.hpp"

class Rat : public IGameObject, public IDrawable
{
    public:
		Rat(sf::RenderWindow *renderWindow, float x, float y);
		Rat(sf::RenderWindow *renderWindow, float x, float y, float speed);
		~Rat() {};

		sf::RenderWindow *Window;
        Point Pos;
		sf::CircleShape Head;
		float Speed;
		
		void Draw() override;
		void PlayTurn();
		

        // deprecated variables
        int hit;
        int d;
        int delay;
        int count1;

    private:
        const float HeadRadius = 8;
        double step; // take x steps? will probably need this variable
        int dir;

		void ChooseDirection();
		void Move();

		// deprecated functions - please rewrite
		//int checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r);
};
