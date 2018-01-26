#pragma once
#include "GameDirector.hpp"
#include "../Utility/Geometry.hpp"

GameDirector::GameDirector()
{
	CurrentDrawObjects.push_back(&BackgroundDrawObjects);
	CurrentDrawObjects.push_back(&MiddlegroundDrawObjects);
	CurrentDrawObjects.push_back(&ForegroundDrawObjects);
}

GameDirector::~GameDirector()
{

}

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
	for (IGameObject *object : CurrentGameObjects)
	{
		#pragma region Snake
		if (Snake *snake = dynamic_cast<Snake*>(object))
		{
			for (IEnvironmentObject *env : CurrentEnvironmentObjects)
			{
				if (Wall *wall = dynamic_cast<Wall*>(env))
				{
					if (Geometry::ContactCircleAndRectangle(snake->Pos, snake->HeadRadius, wall->Geo))
						snake->Pos = snake->LastPos;
				}
			}
		}
		#pragma endregion 

		#pragma region Rat
		if (Rat *rat = dynamic_cast<Rat*>(object))
		{
			for (IEnvironmentObject *env : CurrentEnvironmentObjects)
			{
				if (Wall *wall = dynamic_cast<Wall*>(env))
				{
					if (Geometry::ContactCircleAndRectangle(rat->Pos, rat->HeadRadius, wall->Geo))
						rat->Pos = rat->LastPos;
				}
			}
		}
		#pragma endregion 

	}
}

// Plays all non-player moves and referees the game
void GameDirector::GameTurn()
{
	for (IGameObject *object : CurrentGameObjects)
	{
		if (Rat *rat = dynamic_cast<Rat*>(object)) rat->PlayTurn();
	}
	
	Referee();
}

Rat* GameDirector::CreateRat(sf::RenderWindow *renderWindow, float x, float y, DrawLevel drawLevel)
{
	Rat *r = new Rat(renderWindow, x, y);
	CurrentGameObjects.push_back(r);
	
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


void GameDirector::Remove(IObject *object)
{
	if (IGameObject *obj = dynamic_cast<IGameObject*>(object)) CurrentGameObjects.remove(obj);
	if (IDrawable *obj = dynamic_cast<IDrawable*>(object)) MiddlegroundDrawObjects.remove(obj);

	delete object;
	object = NULL;
}

void GameDirector::RemoveGameObject(IGameObject *object)
{
	CurrentGameObjects.remove(object);
}

void GameDirector::RemoveDrawObject(IDrawable *object)
{
	MiddlegroundDrawObjects.remove(object);
}

void GameDirector::Reset()
{
	for (IGameObject *object : CurrentGameObjects)
	{
		object->Dispose();
	}
	CurrentGameObjects.clear();
	MiddlegroundDrawObjects.clear();
}




