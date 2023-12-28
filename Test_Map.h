#pragma once

#include "GameMap.h"
#include"Test_Map.h"

class Test_Map  {

public:
	Test_Map();
	~Test_Map();
	//wall functions
	void updateMap(Character* mCharacter);
	void drawMap(sf::RenderWindow* mWindow);
	void unloadMap();

	//enemy functions
	void leftHallEnemyCollision();
	void moveEnemies();

	//character functions
	void characterEnemyCollision(Character* myCharacter);
	void characterKeyCollision(Character* myCharacter);

	bool checkCharacterLost(Character* mCharacter);

	//game state functions
	int getGameState();
	void setGameState(int newState);



private:

	float defaultPlayerSpeed;
	int mGameState;
	Ball* ball1Left;

	Key* keyLeft;
	bool keyLeftCollected;
	Wall* upperWallLeft;
	int wincount = 0;
	int losecount = 0;

};

