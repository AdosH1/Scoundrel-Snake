////Scoundrel Snake, a reimagining of the classic game snake
//// By Aden Huen
//
//
#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

#include "Snake.hpp"
#include "GameDirector.hpp"
#include "GraphicsFactory.hpp"
#include "Rat.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "PlayerControl.hpp"


int main() 
{
	/* Initialization */
	sf::Vector2<int> windowSize;
	windowSize.x = 600;
	windowSize.y = 600;
	const int border_width = 12;
	sf::RenderWindow Window(sf::VideoMode(windowSize.x, windowSize.y), "Scoundrel Snake");
	Window.setFramerateLimit(30);

	srand((unsigned)time(NULL));
	sf::Event event;

	/* Game objects */
	GameDirector *Game = new GameDirector();
	GraphicsFactory *Graphics = new GraphicsFactory(windowSize.x, windowSize.y, border_width);
	Graphics->Initialise();

	Snake *s = Game->CreateSnake(&Window, 10, 10);
	Rat *r = Game->CreateRat(&Window, 300, 300);
	Game->CreateWall(&Window, Rectangle(Point(0, 0), Point(15, 600)));
	Game->CreateWall(&Window, Rectangle(Point(15, 0), Point(600, 15)));
	Game->CreateWall(&Window, Rectangle(Point(585, 15), Point(600, 600)));
	Game->CreateWall(&Window, Rectangle(Point(15, 585), Point(585, 600)));

	while (Window.isOpen())
	{
		if (s != NULL) PlayerControl::PlayerAction(s);
		Game->GameTurn();

		//Draw game objects
		Window.clear();
		Game->DrawGameObjects();
		Window.display();

		//If the window is crossed, exit the window
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}
	}
	return 0;
}

//
//
//void randvect(sf::Vector2f& vect, const int window_x, const int window_y, const int border_width)
//{
//    vect.x = rand() % 500 + 50;
//    vect.y = rand() % 500 + 50;
//}
//
//bool isAnyKeyPressed()
//	{
//		for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
//		{
//			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
//				return true;
//		}
//		return false;
//	}
//

// Main bracket
//    //Startup variables
//
//    int score = 0;
//    int hit, count1;
//    bool gameOver = true;
//    const int rat_spawn_distance = 200;
//    enum dir{STOP = 0, N, NE, E, SE, S, SW, W, NW};
//    dir python = STOP;
//    enum menu{Play = 0, Exit};
//    menu select = Play;
//
//    sf::Vector2f vect(0,0);
//
//    //create board object
//    Board* board = new Board(window, window_render_x, window_render_y);
//
//
//    //new snake
//    Snake snake;
//    //new rat
//    randvect(vect, window_render_x, window_render_y, border_width);
//    Rat rat(vect);
//    rat.delay = rand() % 60 + 10;
//
//    //seed random function
//    srand(time(NULL));
//
  // WHILE LOOP FOR GAME BEGIN
//
//        //play screen
//        board->draw_menu(window, score);
//
//        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
//            {
//                if (select == Exit)
//                {
//                    select = Play;
//                    board->selector.setPosition(60,332);
//                }
//            }
//        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
//            {
//                if (select == Play)
//                {
//                    select = Exit;
//                    board->selector.setPosition(60,412);
//                }
//            }
//        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
//            {
//                switch (select)
//                {
//                case Play:
//                    gameOver = false;
//                    //reset score
//                    score = 0;
//                    break;
//
//                case Exit:
//                    window.close();
//                    break;
//                }
//            }
//
//        while (gameOver == false)
//        {
//        //if window closed
//        while(window.pollEvent(event))
//        {
//        if(event.type == sf::Event::Closed)
//            window.close();
//        }
//        snake.last_pos.x = snake.pos.x;
//        snake.last_pos.y = snake.pos.y;
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        //    {
        //        gameOver = true;
        //    }

//if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        //    {
        //        if (python != E)
        //        {
        //        python = W;
        //        snake.shape.setTexture(snake.psnake_head_left);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        //    {
        //        if (python != W)
        //        {
        //        python = E;
        //        snake.shape.setTexture(snake.psnake_head_right);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        //    {
        //        if (python != S)
        //        {
        //        python = N;
        //        snake.shape.setTexture(snake.psnake_head_up);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        //    {
        //        if (python != N)
        //        {
        //        python = S;
        //        snake.shape.setTexture(snake.psnake_head_down);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)  )
        //    {
        //        if (python != SW /*&& python != S && python != W*/)
        //        {
        //        python = NE;
        //        snake.shape.setTexture(snake.psnake_head_ne);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        //    {
        //        if (python != SE /*&& python != S && python != E*/)
        //        {
        //        python = NW;
        //        snake.shape.setTexture(snake.psnake_head_nw);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //    {
        //        if (python != NE /*&& python != N && python != E*/)
        //        {
        //        python = SW;
        //        snake.shape.setTexture(snake.psnake_head_sw);
        //        }
        //    }
        //if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        //    {
        //        if (python != NW /*&& python != N && python != W*/)
        //        {
        //        python = SE;
        //        snake.shape.setTexture(snake.psnake_head_se);
        //        }
        //    }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) )
//            {
//                score++;
//                snake.t_length += 6;
//                snake.lengthen();
//            }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) )
//            {
//                python = STOP;
//            }
//
//        switch (python)
//        {
//            case N:
//                if ( (snake.pos.y - snake.rad) >= border_width)
//                    {
//                    snake.pos.y -= snake.spd; //moves snake coordinates up
//                    snake.shape.move(0,-snake.spd); //moves snake graphics up
//                    }
//                break;
//            case E:
//                if((snake.pos.x + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.x += snake.spd; //moves snake coordinates right
//                    snake.shape.move(+snake.spd,0); //moves snake graphics right
//                    }
//                break;
//            case S:
//                if ( (snake.pos.y + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.y += snake.spd; //moves snake coordinates down
//                    snake.shape.move(0,+snake.spd); //moves snake graphics down
//                    }
//                break;
//            case W:
//                if((snake.pos.x - snake.rad) >= border_width)
//                    {
//                    snake.pos.x -= snake.spd; //moves snake coordinates left
//                    snake.shape.move(-snake.spd,0); //moves snake graphics left
//                    }
//                break;
//            case NE:
//                if ( (snake.pos.y - snake.rad) >= border_width)
//                    {
//                    snake.pos.y -= (0.7*snake.spd); //moves snake coordinates up
//                    snake.shape.move(0,-(0.7*snake.spd)); //moves snake graphics up
//                    }
//                if((snake.pos.x + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.x += (0.7*snake.spd); //moves snake coordinates right
//                    snake.shape.move(+(0.7*snake.spd),0); //moves snake graphics right
//                    }
//                break;
//            case SE:
//                if ( (snake.pos.y + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.y += (0.7*snake.spd); //moves snake coordinates down
//                    snake.shape.move(0,+(0.7*snake.spd)); //moves snake graphics down
//                    }
//                if((snake.pos.x + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.x += (0.7*snake.spd); //moves snake coordinates right
//                    snake.shape.move(+(0.7*snake.spd),0); //moves snake graphics right
//                    }
//                break;
//            case SW:
//                if ( (snake.pos.y + snake.rad) <= (window_render_y - border_width))
//                    {
//                    snake.pos.y += (0.7*snake.spd); //moves snake coordinates down
//                    snake.shape.move(0,+(0.7*snake.spd)); //moves snake graphics down
//                    }
//                if((snake.pos.x - snake.rad) >= border_width)
//                    {
//                    snake.pos.x -= (0.7*snake.spd); //moves snake coordinates left
//                    snake.shape.move(-(0.7*snake.spd),0); //moves snake graphics left
//                    }
//                break;
//            case NW:
//                if ( (snake.pos.y - snake.rad) >= border_width)
//                    {
//                    snake.pos.y -= (0.7*snake.spd); //moves snake coordinates up
//                    snake.shape.move(0,-(0.7*snake.spd)); //moves snake graphics up
//                    }
//                if((snake.pos.x - snake.rad) >= border_width)
//                    {
//                    snake.pos.x -= (0.7*snake.spd); //moves snake coordinates left
//                    snake.shape.move(-(0.7*snake.spd),0); //moves snake graphics left
//                    }
//                break;
//        } //switch bracket
//
//        window.clear();
//        board->draw(window, score);
//
//        rat.rmove();
//        rat.draw(window, rat.shape);
//
//        hit = rat.checkhit(snake.pos,snake.rad,snake.t_x,snake.t_y,snake.t_rad);
//
//        if (hit == 1)
//        {//snake eats rat
//            score++;
//
//            //create new rat
//            count1 = 0;
//            randvect(vect, window_render_x, window_render_y, border_width);
//            rat.~Rat();
//            Rat rat(vect);
//            rat.delay = rand() % 60 + 10;
//            snake.t_length += snake.t_seg;
//            snake.lengthen();
//
//            while (rat.checkhit(snake.pos,rat_spawn_distance,snake.t_x,snake.t_y,rat_spawn_distance) == (1 || 2))
//            {
//            randvect(vect, window_render_x, window_render_y, border_width);
//            rat.pos.x = vect.x;
//            rat.pos.y = vect.y;
//            }
//        }
//        if (hit == 2)
//        {//rat eats snake
//            gameOver = true;
//        }
//
//
//        if(snake.last_pos.x != snake.pos.x || snake.last_pos.y != snake.pos.y)
//        {
//            snake.mktail();
//        }
//        snake.drawtail(window);
//        window.draw(snake.shape);
//        if (snake.t_length > 18)
//        {
//            if(snake.tailhit() == true)
//            {
//                gameOver = true;
//            }
//        }
//        if (gameOver == true)
//        {
//            //new game objects
//            snake.~Snake();
//            Snake snake;
//            python = STOP;
//            rat.~Rat();
//            randvect(vect, window_render_x, window_render_y, border_width);
//            Rat rat(vect);
//            rat.delay = rand() % 60 + 10;
//        }
//
//        window.display();
//        }//gameOver loop
//    window.display();
//    } //while window open bracket
