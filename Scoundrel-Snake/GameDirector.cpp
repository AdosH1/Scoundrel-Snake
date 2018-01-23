#pragma once
#include "GameDirector.hpp"
GameDirector::GameDirector()
{

}

GameDirector::~GameDirector()
{

}

void GameDirector::AddDrawObject(IDrawable *object)
{
	currentDrawObjects.push_back(object);
}

void GameDirector::AddGameObject(IGameObject *object)
{
	currentGameObjects.push_back(object);
}

void GameDirector::DrawGameObjects()
{
	for (IDrawable *object : currentDrawObjects)
	{
		if (Snake *snake = dynamic_cast<Snake*>(object)) snake->Draw();
		if (Rat *rat = dynamic_cast<Rat*>(object)) rat->Draw();
	}
}

void GameDirector::GameTurn()
{
	for (IGameObject *object : currentGameObjects)
	{
		if (Rat *rat = dynamic_cast<Rat*>(object)) rat->PlayTurn();
	}
}

Rat* GameDirector::CreateRat(sf::RenderWindow *renderWindow, float x, float y)
{
	Rat *r = new Rat(renderWindow, x, y);
	currentGameObjects.push_back(r);
	currentDrawObjects.push_back(r);

	return r;
}

Snake* GameDirector::CreateSnake(sf::RenderWindow *renderWindow, float x, float y)
{
	Snake *s = new Snake(renderWindow, x, y);
	currentGameObjects.push_back(s);
	currentDrawObjects.push_back(s);

	return s;
}

void GameDirector::Remove(IObject *object)
{
	if (IGameObject *obj = dynamic_cast<IGameObject*>(object)) currentGameObjects.remove(obj);
	if (IDrawable *obj = dynamic_cast<IDrawable*>(object)) currentDrawObjects.remove(obj);

	delete object;
	object = NULL;
}

void GameDirector::RemoveGameObject(IGameObject *object)
{
	currentGameObjects.remove(object);
}

void GameDirector::RemoveDrawObject(IDrawable *object)
{
	currentDrawObjects.remove(object);
}

void GameDirector::Reset()
{
	for (IGameObject *object : currentGameObjects)
	{
		object->Dispose();
	}
	currentGameObjects.clear();
	currentDrawObjects.clear();
}




