#include "Test_Map.h"
using namespace std;
#include <iostream>
Test_Map::Test_Map() {

	// Start with main menu state
	mGameState = -1;
	//Left Hall Enemies
	this->ball1Left = new Ball(sf::Color::Red, 8.f, sf::Vector2f(570, 375 + 60));
	//construct key placement
	this->keyLeft = new Key(sf::Color::Yellow, sf::Vector2f(40, 40), sf::Vector2f(500, 375 + 60));
	this->keyLeftCollected = false;
	//construct Left Hallway
	this->upperWallLeft = new Wall(sf::Color::White, sf::Vector2f(380, 5), sf::Vector2f(490, 375), true);
	
}


// Defualt deconstructor

Test_Map::~Test_Map() {
	//enemies

	delete ball1Left;
	//keys
	
	delete keyLeft;

	//left hallway
	delete upperWallLeft;
}


/*************************************************************
 * Function: updateMap(Character* mCharacter)
 * Description: Writes all collision between character, walls, keys, and enemies
 * Input parameters: Character* mCharacter (member of Game)
 * Returns:	Void
 * Preconditions: There is a map/window already made, and a character already made
 * Postconditions: Void
 *************************************************************/

void Test_Map::updateMap(Character* mCharacter) {

	//right hallway character collision
	this->upperWallLeft->edgeDetect(mCharacter);
	if (mCharacter->getBottomDetect() == true
		|| mCharacter->getLeftDetect()==true||mCharacter->getRightDetect()==true||
			mCharacter->getTopDetect() == true){
		cout << "Bounds Collision Test Passed" << endl; // bounds collision tester
	}
	
	if (mCharacter->getGlobalBounds().intersects(upperWallLeft->getGlobalBounds()))
	{
		cout << "Wall Collision Test Passed" << endl;
	}
	this->characterKeyCollision(mCharacter);

	//Enemy movement and character collision
	this->moveEnemies();


	this->characterEnemyCollision(mCharacter);
	// key collection detector
	// If all keys are collected, character wins game (change GameState to win state)
	if  (keyLeftCollected)
	{
		if (wincount < 10) {
			cout << "Win condition test passed " << endl; // win condition tester
			wincount++;
		}

	}

	// If character loses all lives, change GameState to lost state
	if (this->checkCharacterLost(mCharacter))
	{
		
	}
}

/*************************************************************
 * Function: drawMap(sf::RenderWindow *mWindow)
 * Description: Draws character, enemies, and walls
 * Input parameters: sf::RenderWindow *mWindow -> main game window
 * Returns:	Void
 * Preconditions: There is a map/window already made, and map is already initialized
 * Postconditions: Void
 *************************************************************/

void Test_Map::drawMap(sf::RenderWindow* mWindow) {

	// Draw keys

	if (!keyLeftCollected) {
		mWindow->draw((*this->keyLeft));
	}



	// Draw left hall enemies
	mWindow->draw((*this->ball1Left));
	

	// Draw left hallway
	mWindow->draw((*this->upperWallLeft));
}


/*************************************************************
 * Function: moveEnemies()
 * Description: Moves the enemies according to their speed and directions
 * Input parameters: Void
 * Returns:	Void
 * Preconditions: Enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Test_Map::moveEnemies() {
	// Left hall enemy movement
	ball1Left->move(0, 0);
}





void Test_Map::characterEnemyCollision(Character* myCharacter)
{
	// Check intersect (collision) boounds between charaacter and all enemies
	// Spawn character at start and lose a life
	if (ball1Left->getGlobalBounds().intersects(myCharacter->getGlobalBounds()))
	{
		myCharacter->setPosition(sf::Vector2f(990 - (25 / 2), 425));
		myCharacter->setLives(myCharacter->getLives() - 1);
		for (int i = 1; i <= 10; i++) { // enemy collision tester
			cout << "Enemy Collsion Test Passed" << endl;
		}
	}
}


void Test_Map::characterKeyCollision(Character* myCharacter)
{
	

	// If character collides with left hall key
	if (keyLeft->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) && keyLeftCollected == false) {
		// Stop rendering key
		this->keyLeftCollected = true;

		// Every time a character picks up a key, the player speed increases by 25%
		myCharacter->setPlayerSpeed((myCharacter->getPlayerSpeed()) * 1.25);
		for (int i = 0; i <= 10; i++) {
			cout << "Key Test Passed" << endl; // test collector test
		}
	}

}




bool Test_Map::checkCharacterLost(Character* mCharacter)
{
	int firstval=0;
	if (mCharacter->outOfLives())
	{
		if (losecount < 10) {
			cout << "Game Lost TEST PASSED" << endl; // game lost detector
			losecount++;
		}
		return true;
		
	}
	else
	{
		return false;
	}
}
// Setters
void Test_Map::setGameState(int newState) {
	this->mGameState = newState;
}

int Test_Map::getGameState() {
	return mGameState;
}