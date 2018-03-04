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

		/* Base Class Implementations*/
		Point GetPosition() override;
		Point GetLastPosition() override;
		double GetSpeed() override;
		bool GetDispose() override;

		bool SetPosition(Point pos) override;
		bool SetLastPosition(Point pos) override;
		bool SetSpeed(double speed) override;
		bool SetDispose(bool dispose) override;

		bool Update(int input) override;

		sf::RenderWindow *Window;
        Point Pos;
		Point LastPos;

		sf::CircleShape Head;
		const double HeadRadius = 8;
		float Speed;
		bool Dispose = false;
		
		void Draw() override;
		void PlayTurn();
		

        // deprecated variables
        int hit;
        int d;
        int delay;
        int count1;

    private:
        double step; // take x steps? will probably need this variable
        int dir;

		void ChooseDirection();
		void Move();

		// deprecated functions - please rewrite
		//int checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r);
};
