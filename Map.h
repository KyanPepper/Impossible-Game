#pragma once

#include "GameMap.h"

class Map : public virtual GameMap {

public:
	Map();
	~Map();

	
	//wall functions
	void updateMap(Character* mCharacter);
	void drawMap(sf::RenderWindow* mWindow);
	void unloadMap();

	//enemy functions
	void rightHallEnemyCollision();
	void leftHallEnemyCollision();
	void upHallEnemyCollision();
	void downHallEnemyCollision();
	void moveEnemies();

	//character functions
	void characterEnemyCollision(Character* myCharacter);
	void characterKeyCollision(Character* myCharacter);
	void resetPlayer(Character* mCharacter);
	bool checkCharacterLost(Character* mCharacter);

	//game state functions
	int getGameState();
	void setGameState(int newState);

	

private:

	float defaultPlayerSpeed;
	int mGameState;

	//Right Hall Enemies
	Ball* ball1Right;
	Ball* ball2Right;
	Ball* ball3Right;
	Ball* ball4Right;

	//Top Hall Enemies
	Ball* ball1Top;
	Ball* ball2Top;
	Ball* ball3Top;
	Ball* ball4Top;

	//Left Hall enemies
	Ball* ball1Left;
	Ball* ball2Left;
	Ball* ball3Left;
	Ball* ball4Left;

	//Bottom Hall enemies
	Ball* ball1Down;
	Ball* ball2Down;
	Ball* ball3Down;
	Ball* ball4Down;

	//Keys
	Key* keyRight;
	bool keyRightCollected;

	Key* keyUp;
	bool keyUpCollected;

	Key* keyLeft;
	bool keyLeftCollected;

	Key* keyDown;
	bool keyDownCollected;

	//hallway UP
	Wall* rightWallUp;
	Wall* leftWallUp;
	Wall* endWallUp;

	
	//hallway DOWN
	Wall* rightWallDown;
	Wall* leftWallDown;
	Wall* endWallDown;

	
	//hallway RIGHT
	Wall* upperWallRight;
	Wall* lowerWallRight;
	Wall* endWallRight;
	
	
	//hallway LEFT
	Wall* upperWallLeft;
	Wall* lowerWallLeft;
	Wall* endWallLeft;
	
	
};