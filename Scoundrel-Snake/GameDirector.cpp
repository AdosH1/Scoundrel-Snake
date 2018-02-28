#pragma once
#include "GameDirector.hpp"
#include "../Utility/Geometry.hpp"
#include "GraphicsFactory.hpp"

GameDirector::GameDirector()
{
	GameOver = true;
	CurrentDrawObjects.push_back(&BackgroundDrawObjects);
	CurrentDrawObjects.push_back(&MiddlegroundDrawObjects);
	CurrentDrawObjects.push_back(&ForegroundDrawObjects);

	EnemyCount["Rat"] = 0;
}

GameDirector::~GameDirector() = default;

void GameDirector::AddDrawObject(IDrawable *object)
{
	MiddlegroundDrawObjects.push_back(object);
}

void GameDirector::AddGameObject(IGameObject *object)
{
	CurrentGameObjects.push_back(object);
}

void GameDirector::DrawGameObjects()
{
	for (std::list<IDrawable*> *drawList : CurrentDrawObjects)
	{
		for (IDrawable *object : *drawList)
		{
			if (GhostRectangle *rect = dynamic_cast<GhostRectangle*>(object)) rect->Draw();

			if (Snake *snake = dynamic_cast<Snake*>(object)) snake->Draw();
			if (Rat *rat = dynamic_cast<Rat*>(object)) rat->Draw();
			if (Wall *wall = dynamic_cast<Wall*>(object)) wall->Draw();

		}
	}
	
}

void GameDirector::Referee()
{
	bool SnakeAteRat = false;
	// Loop through all game objects
	for (IGameObject *object : CurrentGameObjects)
	{
		#pragma region Snake
		if (Snake *snake = dynamic_cast<Snake*>(object))
		{
			for (IEnvironmentObject *env : CurrentEnvironmentObjects)
			{
				// If Snake hits wall
				if (Wall *wall = dynamic_cast<Wall*>(env))
				{
					if (Geometry::ContactCircleAndRectangle(snake->Pos, snake->HeadRadius, wall->Geo))
						snake->Pos = snake->LastPos;
				}
			}
			for (IGameObject *object : CurrentGameObjects)
			{
				// If Snake head hits Rat
				if (Rat *rat = dynamic_cast<Rat*>(object))
				{
					if(Geometry::ContactCircleAndCircle(snake->Pos, snake->HeadRadius, rat->Pos, rat->HeadRadius))
					{
						rat->Dispose = true;
						EnemyCount["Rat"] -= 1;
						//snake->Lengthen(15);
						SnakeAteRat = true;
					}
				}
			}
			continue; //if cast, it won't be anything else
		}
		#pragma endregion 

		#pragma region Rat
		if (Rat *rat = dynamic_cast<Rat*>(object))
		{
			for (int i = 0; i < CurrentEnvironmentObjects.size(); i++)
			{
				IEnvironmentObject* env = CurrentEnvironmentObjects.at(i);
				// If Rat hits Wall
				if (Wall *wall = dynamic_cast<Wall*>(env))
				{
					if (Geometry::ContactCircleAndRectangle(rat->Pos, rat->HeadRadius, wall->Geo))
						rat->Pos = rat->LastPos;
				}
			}
			for (int i = 0; i < CurrentGameObjects.size(); i++)
			{
				IGameObject* object = CurrentGameObjects.at(i);
				// If Rat hits Snake tail
				if (Snake *snake = dynamic_cast<Snake*>(object))
				{
					if (SnakeAteRat) continue;
					for (int i = 0; i < snake->TailPos.size(); i++)
					{
						if (Geometry::ContactCircleAndCircle(rat->Pos, rat->HeadRadius, snake->TailPos.at(i), snake->TailRadius))
						{
							snake->Dispose = true;
						}
					}
				}
			}
			continue;
		}
		#pragma endregion 

	}
}

// Plays all non-player moves and referees the game
void GameDirector::GameTurn()
{
	for (IGameObject *object : CurrentGameObjects)
	{
		// Add other game objects here
		if (Rat *rat = dynamic_cast<Rat*>(object)) rat->PlayTurn();
	}
	Referee();
	Cleanup();
}

void GameDirector::Cleanup()
{
	for (std::vector<IGameObject*>::iterator it = CurrentGameObjects.begin(); it < CurrentGameObjects.end(); ++it)
	{
		auto object = *it;
		if (object->Dispose)
		{
			if (IDrawable *obj = dynamic_cast<IDrawable*>(object))
			{
				ForegroundDrawObjects.remove(obj);
				MiddlegroundDrawObjects.remove(obj);
				BackgroundDrawObjects.remove(obj);
			}
			CurrentGameObjects.erase(std::remove(CurrentGameObjects.begin(), CurrentGameObjects.end(), object), CurrentGameObjects.end());
			object = NULL;
		}
	}
}

Rat* GameDirector::CreateRat(sf::RenderWindow *renderWindow, float x, float y, DrawLevel drawLevel)
{
	Rat *r = new Rat(renderWindow, x, y);
	CurrentGameObjects.push_back(r);
	EnemyCount["Rat"] += 1;
	
	if (drawLevel == Foreground) ForegroundDrawObjects.push_back(r);
	if (drawLevel == Middleground) MiddlegroundDrawObjects.push_back(r);
	if (drawLevel == Background) BackgroundDrawObjects.push_back(r);

	return r;
}

Snake* GameDirector::CreateSnake(sf::RenderWindow *renderWindow, float x, float y, DrawLevel drawLevel)
{
	Snake *s = new Snake(renderWindow, x, y);
	CurrentGameObjects.push_back(s);
	
	if (drawLevel == Foreground) ForegroundDrawObjects.push_back(s);
	if (drawLevel == Middleground) MiddlegroundDrawObjects.push_back(s);
	if (drawLevel == Background) BackgroundDrawObjects.push_back(s);

	return s;
}

Wall* GameDirector::CreateWall(sf::RenderWindow* renderWindow, Rectangle rect, DrawLevel drawLevel)
{
	Wall *w = new Wall(renderWindow, rect);
	CurrentEnvironmentObjects.push_back(w);
	
	if (drawLevel == Foreground) ForegroundDrawObjects.push_back(w);
	if (drawLevel == Middleground) MiddlegroundDrawObjects.push_back(w);
	if (drawLevel == Background) BackgroundDrawObjects.push_back(w);

	return w;
}

GhostRectangle* GameDirector::CreateGhostRectangle(sf::RenderWindow* renderWindow, Rectangle rect, sf::Texture* texture, DrawLevel drawLevel, std::string name)
{
	GhostRectangle *g = (texture == NULL) ? new GhostRectangle(renderWindow, rect) : new GhostRectangle(renderWindow, rect, texture, name);
	
	if (drawLevel == Foreground) ForegroundDrawObjects.push_back(g);
	if (drawLevel == Middleground) MiddlegroundDrawObjects.push_back(g);
	if (drawLevel == Background) BackgroundDrawObjects.push_back(g);

	return g;
}

void GameDirector::LoadMenu(sf::RenderWindow *renderWindow)
{
	Rectangle rMenu = Rectangle(0, 0, 600, 600);
	CreateGhostRectangle(renderWindow, rMenu, GraphicsFactory::pMenuScreenTexture, Background, "MenuScreen");

	Rectangle rPlayButton = Rectangle(0, 0, 100, 60);
	GhostRectangle* play = CreateGhostRectangle(renderWindow, rPlayButton, GraphicsFactory::pPlayButtonTexture, Foreground, "PlayButton");
	play->Geo.MoveTopLeftTo(Point(100, 400));

	Rectangle rExitButton = Rectangle(0, 0, 100, 60);
	GhostRectangle* exit = CreateGhostRectangle(renderWindow, rExitButton, GraphicsFactory::pExitButtonTexture, Foreground, "ExitButton");
	exit->Geo.MoveTopLeftTo(Point(100, 480));

	Rectangle rSelector = Rectangle(0, 0, 25, 25);
	GhostRectangle* selector = CreateGhostRectangle(renderWindow, rSelector, GraphicsFactory::pSelectorTexture, Foreground, "Selector");
	selector->Geo.MoveCenterTo(Point(80, 370));

}

void GameDirector::Remove(IObject *object)
{
	//if (IGameObject *obj = dynamic_cast<IGameObject*>(object)) CurrentGameObjects.remove(obj);
	if (IGameObject *obj = dynamic_cast<IGameObject*>(object)) std::remove(CurrentGameObjects.begin(), CurrentGameObjects.end(), obj);
	if (IDrawable *obj = dynamic_cast<IDrawable*>(object))
	{
		ForegroundDrawObjects.remove(obj);
		MiddlegroundDrawObjects.remove(obj);
		BackgroundDrawObjects.remove(obj);
	}

	delete object;
	//object = NULL;
}

void GameDirector::RemoveGameObject(IGameObject *object)
{
	//CurrentGameObjects.remove(object);
	//CurrentGameObjects.erase(CurrentGameObjects.begin());
}

void GameDirector::RemoveDrawObject(IDrawable *object)
{
	MiddlegroundDrawObjects.remove(object);
}

void GameDirector::Reset()
{
	ForegroundDrawObjects.clear();
	MiddlegroundDrawObjects.clear();
	BackgroundDrawObjects.clear();

	CurrentEnvironmentObjects.clear();
	CurrentGameObjects.clear();
}




