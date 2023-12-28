#include "Map.h"

// Default constructor for map:
//		Create walls, enemies, and keys

Map::Map(){

	// Start with main menu state
	mGameState = -1;

	//Right Hall Enemies
	this->ball1Right = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1115,375+50));
	this->ball2Right = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1200, 375 + 50));
	this->ball3Right = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1300, 375 + 50));
	this->ball4Right = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1400, 375 + 50));

	//Top Hall Enemies
	this->ball1Top = new Ball(sf::Color::Red, 8.f, sf::Vector2f(871, 50));
	this->ball2Top = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1110 - 16, 50));
	this->ball3Top = new Ball(sf::Color::Red, 8.f, sf::Vector2f(871, 100));
	this->ball4Top = new Ball(sf::Color::Red, 8.f, sf::Vector2f(1110 -	16, 100));


	//Left Hall Enemies
	this->ball1Left = new Ball(sf::Color::Red, 8.f, sf::Vector2f(570, 375 + 60));
	this->ball2Left = new Ball(sf::Color::Red, 8.f, sf::Vector2f(860, 375 + 60));
	this->ball3Left = new Ball(sf::Color::Red, 8.f, sf::Vector2f(700, 375 + 60));
	this->ball4Left = new Ball(sf::Color::Red, 8.f, sf::Vector2f(700, 375+60));

	//bottom hall enemies
	this->ball1Down = new Ball(sf::Color::Red, 8.f, sf::Vector2f(990, 530));
	this->ball2Down = new Ball(sf::Color::Red, 8.f, sf::Vector2f(990, 625));
	this->ball3Down = new Ball(sf::Color::Red, 8.f, sf::Vector2f(990, 725));
	this->ball4Down = new Ball(sf::Color::Red, 8.f, sf::Vector2f(990, 825));
	

	//construct key placement
	this->keyRight = new Key(sf::Color::Yellow, sf::Vector2f(40, 40), sf::Vector2f(1450, 375+60));
	this->keyRightCollected = false;

	this->keyUp = new Key(sf::Color::Yellow, sf::Vector2f(40, 40), sf::Vector2f(865+125,25));
	this->keyUpCollected = false;

	this->keyLeft = new Key(sf::Color::Yellow, sf::Vector2f(40, 40), sf::Vector2f(500, 375+60));
	this->keyLeftCollected = false;

	this->keyDown = new Key(Key(sf::Color::Yellow, sf::Vector2f(40, 40), sf::Vector2f(865+125, 895-50)));
	this->keyDownCollected = false;


	//Construct Upper Hallway
	this->rightWallUp = new Wall(sf::Color::White, sf::Vector2f(5, 375), sf::Vector2f(1115, 0), false);
	this->leftWallUp = new Wall(sf::Color::White, sf::Vector2f(5, 375), sf::Vector2f(865, 0), false);
	this->endWallUp = new Wall(sf::Color::White, sf::Vector2f(255, 5), sf::Vector2f(865, 0), false);

	//Construct Right Hallway
	this->upperWallRight = new Wall(sf::Color::White, sf::Vector2f(375, 5), sf::Vector2f(1115, 375), true);
	this->lowerWallRight = new Wall(sf::Color::White, sf::Vector2f(375, 5), sf::Vector2f(1115, 525), true);
	this->endWallRight = new Wall(sf::Color::White, sf::Vector2f(5, 155), sf::Vector2f(1485, 375), false);

	//construct Left Hallway
	this->upperWallLeft = new Wall(sf::Color::White, sf::Vector2f(380, 5), sf::Vector2f(490, 375), true);
	this->lowerWallLeft = new Wall(sf::Color::White, sf::Vector2f(380, 5), sf::Vector2f(490, 525), true);
	this->endWallLeft = new Wall(sf::Color::White, sf::Vector2f(5, 155), sf::Vector2f(490, 375), false);

	//construct Bottom Hallway
	this->rightWallDown = new Wall(sf::Color::White, sf::Vector2f(5, 400), sf::Vector2f(865, 525),false);
	this->leftWallDown = new Wall(sf::Color::White, sf::Vector2f(5, 400), sf::Vector2f(1115, 525),false);
	this->endWallDown = new Wall(sf::Color::White, sf::Vector2f(255, 5), sf::Vector2f(865, 895), false);


}



// Defualt deconstructor

Map::~Map() {
	//enemies
	delete ball1Right;
	delete ball2Right;
	delete ball3Right;
	delete ball4Right;

	delete ball1Top;
	delete ball2Top;
	delete ball3Top;
	delete ball4Top;

	delete ball1Left;
	delete ball2Left;
	delete ball3Left;
	delete ball4Left;

	delete ball1Down;
	delete ball2Down;
	delete ball3Down;
	delete ball4Down;

	//keys
	delete keyRight;
	delete keyUp;
	delete keyLeft;
	delete keyDown;


	//upper hallway
	delete rightWallUp;
	delete leftWallUp;
	delete endWallUp;

	//lower hallway
	delete rightWallDown;
	delete leftWallDown;
	delete endWallDown;

	//right hallway
	delete upperWallRight;
	delete lowerWallRight;
	delete endWallRight;

	//left hallway
	delete upperWallLeft;
	delete lowerWallLeft;
	delete endWallLeft;
}


/*************************************************************
 * Function: updateMap(Character* mCharacter)
 * Description: Writes all collision between character, walls, keys, and enemies
 * Input parameters: Character* mCharacter (member of Game)
 * Returns:	Void
 * Preconditions: There is a map/window already made, and a character already made
 * Postconditions: Void
 *************************************************************/

void Map::updateMap(Character* mCharacter) {

	//upper hallway character collision
	this->rightWallUp->edgeDetect(mCharacter);
	this->leftWallUp->edgeDetect(mCharacter);
	this->endWallUp->edgeDetect(mCharacter);

	//lower hallway character collision
	this->rightWallDown->edgeDetect(mCharacter);
	this->leftWallDown->edgeDetect(mCharacter);
	this->endWallDown->edgeDetect(mCharacter);

	//right hallway character collision
	this->upperWallRight->edgeDetect(mCharacter);
	this->lowerWallRight->edgeDetect(mCharacter);
	this->endWallRight->edgeDetect(mCharacter);

	//right hallway character collision
	this->upperWallLeft->edgeDetect(mCharacter);
	this->lowerWallLeft->edgeDetect(mCharacter);
	this->endWallLeft->edgeDetect(mCharacter);

	// key - character collision
	this->characterKeyCollision(mCharacter);

	//Enemy movement and character collision
	this->moveEnemies();

	this->rightHallEnemyCollision();

	this->leftHallEnemyCollision();

	this->upHallEnemyCollision();

	this->downHallEnemyCollision();

	this->characterEnemyCollision(mCharacter);

	// If all keys are collected, character wins game (change GameState to win state)
	if (keyDownCollected && keyUpCollected && keyLeftCollected && keyRightCollected) 
	{
		mGameState = 2;
	}

	// If character loses all lives, change GameState to lost state
	if (this->checkCharacterLost(mCharacter))
	{
		mGameState = 1;
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

void Map::drawMap(sf::RenderWindow *mWindow) {
	
	// Draw keys
	if (!keyRightCollected) {
		mWindow->draw((*this->keyRight));
	}

	if (!keyUpCollected) {
		mWindow->draw((*this->keyUp));

	}

	if (!keyLeftCollected) {
		mWindow->draw((*this->keyLeft));
	}
	
	if (!keyDownCollected) {
		mWindow->draw((*this->keyDown));
	}
	
	// Draw right Hall enemies
	mWindow->draw((*this->ball1Right));
	mWindow->draw((*this->ball2Right));
	mWindow->draw((*this->ball3Right));
	mWindow->draw((*this->ball4Right));

	// Draw top Hall enemies
	mWindow->draw((*this->ball1Top));
	mWindow->draw((*this->ball2Top));
	mWindow->draw((*this->ball3Top));
	mWindow->draw((*this->ball4Top));

	// Draw left hall enemies
	mWindow->draw((*this->ball1Left));
	mWindow->draw((*this->ball2Left));
	mWindow->draw((*this->ball3Left));
	mWindow->draw((*this->ball4Left));

	// Draw down hall enemies
	mWindow->draw((*this->ball1Down));
	mWindow->draw((*this->ball2Down));
	mWindow->draw((*this->ball3Down));
	mWindow->draw((*this->ball4Down));


	//Draw upper hallway
	mWindow->draw((*this->rightWallUp));
	mWindow->draw((*this->leftWallUp));
	mWindow->draw((*this->endWallUp));

	// Draw lower hallway
	mWindow->draw((*this->rightWallDown));
	mWindow->draw((*this->leftWallDown));
	mWindow->draw((*this->endWallDown));

	// Draw right hallway
	mWindow->draw((*this->upperWallRight));
	mWindow->draw((*this->lowerWallRight));
	mWindow->draw((*this->endWallRight));

	// Draw left hallway
	mWindow->draw((*this->upperWallLeft));
	mWindow->draw((*this->lowerWallLeft));
	mWindow->draw((*this->endWallLeft));

}


/*************************************************************
 * Function: moveEnemies()
 * Description: Moves the enemies according to their speed and directions
 * Input parameters: Void
 * Returns:	Void
 * Preconditions: Enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Map::moveEnemies() {

	// Right hall enemy movement
	ball1Right->move(0, (ball1Right->getYDirection() * ball1Right->getEnemySpeed()));
	ball2Right->move(0, (ball2Right->getYDirection() * ball2Right->getEnemySpeed()));
	ball3Right->move(0, (ball3Right->getYDirection() * ball3Right->getEnemySpeed()));
	ball4Right->move(0, (ball4Right->getYDirection() * ball4Right->getEnemySpeed()));

	// Upper hall ennemy movement
	ball1Top->move((ball1Top->getXDirection() * ball1Top->getEnemySpeed()), (ball1Top->getYDirection() * ball1Top->getEnemySpeed()));
	ball2Top->move((ball2Top->getXDirection() * ball2Top->getEnemySpeed()), (ball2Top->getYDirection() * ball2Top->getEnemySpeed() * -1));
	ball3Top->move((ball3Top->getXDirection() * ball3Top->getEnemySpeed()), (ball3Top->getYDirection() * ball3Top->getEnemySpeed()));
	ball4Top->move((ball4Top->getXDirection() * ball4Top->getEnemySpeed()), (ball4Top->getYDirection() * ball4Top->getEnemySpeed()) * -1);

	// Left hall enemy movement
	ball1Left->move(0, (ball1Left->getYDirection() * ball1Left->getEnemySpeed()));
	ball2Left->move(0, (ball2Left->getYDirection() * ball2Left->getEnemySpeed()));
	ball3Left->move(2 * (ball3Left->getXDirection() * ball3Left->getEnemySpeed()), -1 * (ball3Left->getYDirection() * ball3Left->getEnemySpeed()));
	ball4Left->move(2 * (ball4Left->getXDirection() * ball4Left->getEnemySpeed()), (ball4Left->getYDirection() * ball4Left->getEnemySpeed()));

	// Lower hall enemy movement
	ball1Down->move(-(ball1Down->getXDirection() * ball1Down->getEnemySpeed()), 0);
	ball2Down->move((ball2Down->getXDirection() * ball2Down->getEnemySpeed()), 0);
	ball3Down->move(-(ball3Down->getXDirection() * ball3Down->getEnemySpeed()), 0);
	ball4Down->move((ball4Down->getXDirection() * ball3Down->getEnemySpeed()), 0);

}

/*************************************************************
 * Function: rightHallEnemyCollision
 * Description: Defines enemy collision between right enemies and right hall walls
 * Input parameters: void
 * Returns:	Void
 * Preconditions: There is a map/window already made, and right enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Map::rightHallEnemyCollision()
{
	// Collision with upper wall
	if (ball1Right->getGlobalBounds().intersects(upperWallRight->getGlobalBounds())) {
		ball1Right->setYDirection(ball1Right->getYDirection() * -1);
	}

	if (ball2Right->getGlobalBounds().intersects(upperWallRight->getGlobalBounds())) {
		ball2Right->setYDirection(ball2Right->getYDirection() * -1);
	}

	if (ball3Right->getGlobalBounds().intersects(upperWallRight->getGlobalBounds())) {
		ball3Right->setYDirection(ball3Right->getYDirection() * -1);
	}

	if (ball4Right->getGlobalBounds().intersects(upperWallRight->getGlobalBounds())) {
		ball4Right->setYDirection(ball4Right->getYDirection() * -1);
	}

	// Collision with lower wall
	if (ball1Right->getGlobalBounds().intersects(lowerWallRight->getGlobalBounds())) {
		ball1Right->setYDirection(ball1Right->getYDirection() * -1);
	}
	if (ball2Right->getGlobalBounds().intersects(lowerWallRight->getGlobalBounds())) {
		ball2Right->setYDirection(ball2Right->getYDirection() * -1);
	}
	if (ball3Right->getGlobalBounds().intersects(lowerWallRight->getGlobalBounds())) {
		ball3Right->setYDirection(ball3Right->getYDirection() * -1);
	}
	if (ball1Right->getGlobalBounds().intersects(lowerWallRight->getGlobalBounds())) {
		ball4Right->setYDirection(ball4Right->getYDirection() * -1);
	}
}

/*************************************************************
 * Function: leftHallEnemyCollision
 * Description: Defines enemy collision between left enemies and left hall walls
 * Input parameters: void
 * Returns:	Void
 * Preconditions: There is a map/window already made, and left enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Map::leftHallEnemyCollision()
{
	// Collision with upper wall AND lower wall for balls 1 and 2
	if (ball1Left->getGlobalBounds().intersects(upperWallLeft->getGlobalBounds()) || ball1Left->getGlobalBounds().intersects(lowerWallLeft->getGlobalBounds())) {
		ball1Left->setYDirection(ball1Left->getYDirection() * -1);
	}

	if (ball2Left->getGlobalBounds().intersects(upperWallLeft->getGlobalBounds()) || ball2Left->getGlobalBounds().intersects(lowerWallLeft->getGlobalBounds())) {
		ball2Left->setYDirection(ball2Left->getYDirection() * -1);
	}


	//collision with upper wall AND lower wall for balls 3 and 4
	if (ball3Left->getGlobalBounds().intersects(upperWallLeft->getGlobalBounds()) || ball3Left->getGlobalBounds().intersects(lowerWallLeft->getGlobalBounds())) {
		ball3Left->setYDirection(ball3Left->getYDirection() * -1);
		ball3Left->setXDirection(ball3Left->getXDirection() * -1);
	}

	if (ball4Left->getGlobalBounds().intersects(upperWallLeft->getGlobalBounds()) || ball4Left->getGlobalBounds().intersects(lowerWallLeft->getGlobalBounds())) {
		ball4Left->setYDirection(ball4Left->getYDirection() * -1);
		ball4Left->setXDirection(ball4Left->getXDirection() * -1);

	}

}

/*************************************************************
 * Function: upHallEnemyCollision
 * Description: Defines enemy collision between upper enemies and upper hall walls
 * Input parameters: void
 * Returns:	Void
 * Preconditions: There is a map/window already made, and upper enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Map::upHallEnemyCollision()
{
	// Collision with right wall
	if (ball1Top->getGlobalBounds().intersects(rightWallUp->getGlobalBounds())) {
		ball1Top->setXDirection(ball1Top->getXDirection() * -1);
		ball1Top->setYDirection(ball1Top->getYDirection() * -1);
	}

	if (ball2Top->getGlobalBounds().intersects(rightWallUp->getGlobalBounds())) {
		ball2Top->setXDirection(ball2Top->getXDirection() * -1);
		ball2Top->setYDirection(ball2Top->getYDirection() * -1);
	}

	if (ball3Top->getGlobalBounds().intersects(rightWallUp->getGlobalBounds())) {
		ball3Top->setXDirection(ball3Top->getXDirection() * -1);
		ball3Top->setYDirection(ball3Top->getYDirection() * -1);
	}

	if (ball4Top->getGlobalBounds().intersects(rightWallUp->getGlobalBounds())) {
		ball4Top->setXDirection(ball4Top->getXDirection() * -1);
		ball4Top->setYDirection(ball4Top->getYDirection() * -1);
	}


	//collision with left wall
	if (ball1Top->getGlobalBounds().intersects(leftWallUp->getGlobalBounds())) {
		ball1Top->setXDirection(ball1Top->getXDirection() * -1);
		ball1Top->setYDirection(ball1Top->getYDirection() * -1);
	}

	if (ball2Top->getGlobalBounds().intersects(leftWallUp->getGlobalBounds())) {
		ball2Top->setXDirection(ball2Top->getXDirection() * -1);
		ball2Top->setYDirection(ball2Top->getYDirection() * -1);
	}

	if (ball3Top->getGlobalBounds().intersects(leftWallUp->getGlobalBounds())) {
		ball3Top->setXDirection(ball3Top->getXDirection() * -1);
		ball3Top->setYDirection(ball3Top->getYDirection() * -1);
	}

	if (ball4Top->getGlobalBounds().intersects(leftWallUp->getGlobalBounds())) {
		ball4Top->setXDirection(ball4Top->getXDirection() * -1);
		ball4Top->setYDirection(ball4Top->getYDirection() * -1);
	}
}


/*************************************************************
 * Function: downHallEnemyCollision
 * Description: Defines enemy collision between lower enemies and lower hall walls
 * Input parameters: void
 * Returns:	Void
 * Preconditions: There is a map/window already made, and lower enemies are already initialized
 * Postconditions: Void
 *************************************************************/

void Map::downHallEnemyCollision()
{
	//collision with right and left walls of lower hall
	if (ball1Down->getGlobalBounds().intersects(leftWallDown->getGlobalBounds()) || ball1Down->getGlobalBounds().intersects(rightWallDown->getGlobalBounds())) {
		ball1Down->setXDirection(ball1Down->getXDirection() * -1);
	}

	if (ball2Down->getGlobalBounds().intersects(leftWallDown->getGlobalBounds()) || ball2Down->getGlobalBounds().intersects(rightWallDown->getGlobalBounds())) {
		ball2Down->setXDirection(ball2Down->getXDirection() * -1);
	}

	if (ball3Down->getGlobalBounds().intersects(leftWallDown->getGlobalBounds()) || ball3Down->getGlobalBounds().intersects(rightWallDown->getGlobalBounds())) {
		ball3Down->setXDirection(ball3Down->getXDirection() * -1);
	}

	if (ball4Down->getGlobalBounds().intersects(leftWallDown->getGlobalBounds()) || ball4Down->getGlobalBounds().intersects(rightWallDown->getGlobalBounds())) {
		ball4Down->setXDirection(ball4Down->getXDirection() * -1);
	}
}


/*************************************************************
 * Function: characterEnemyCollision(Character* myCharacter)
 * Description: Defines enemy collision between enemies and character
 * Input parameters: Character* myCharacter -> game character
 * Returns:	Void
 * Preconditions: There is a map already made, enemies are initialized, and character is initialized
 * Postconditions: Void
 *************************************************************/

void Map::characterEnemyCollision(Character* myCharacter)
{
	// Check intersect (collision) boounds between charaacter and all enemies
	// Spawn character at start and lose a life
	if (ball1Right->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball2Right->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball3Right->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball4Right->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball1Top->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball2Top->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball3Top->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball4Top->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball1Left->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball2Left->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball3Left->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball4Left->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball1Down->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball2Down->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball3Down->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) ||
		ball4Down->getGlobalBounds().intersects(myCharacter->getGlobalBounds())) 
	{
		myCharacter->setPosition(sf::Vector2f(990 - (25 / 2), 425));
		resetPlayer(myCharacter);
		myCharacter->setLives(myCharacter->getLives() - 1);
	}
}

/*************************************************************
 * Function: characterKeyCollision(Character* myCharacter)
 * Description: Defines key collision between keys and character
 * Input parameters: Character* myCharacter -> game character
 * Returns:	Void
 * Preconditions: There is a map already made, keys are initialized, and character is initialized
 * Postconditions: Void
 *************************************************************/

void Map::characterKeyCollision(Character* myCharacter)
{
	// If character collides with right hall key
	if (keyRight->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) && keyRightCollected == false) {
		// Stop rendering key
		this->keyRightCollected = true;

		// Every time a character picks up a key, the player speed increases by 25%
		myCharacter->setPlayerSpeed((myCharacter->getPlayerSpeed()) * 1.25);
	}

	// If character collides with upper hall key
	if (keyUp->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) && keyUpCollected == false) {
		// Stop rendering key
		this->keyUpCollected = true;

		// Every time a character picks up a key, the player speed increases by 25%
		myCharacter->setPlayerSpeed((myCharacter->getPlayerSpeed()) * 1.25);
	}

	// If character collides with left hall key
	if (keyLeft->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) && keyLeftCollected == false) {
		// Stop rendering key
		this->keyLeftCollected = true;

		// Every time a character picks up a key, the player speed increases by 25%
		myCharacter->setPlayerSpeed((myCharacter->getPlayerSpeed()) * 1.25);
	}
	
	// If character collides with lower hall key
	if (keyDown->getGlobalBounds().intersects(myCharacter->getGlobalBounds()) && keyDownCollected == false) {
		// Stop rendering key
		this->keyDownCollected = true;

		// Every time a character picks up a key, the player speed increases by 25%
		myCharacter->setPlayerSpeed((myCharacter->getPlayerSpeed()) * 1.25);
	}
}


/*************************************************************
 * Function: resetPlayer(Character* mCharacter)
 * Description: Resets player speed after hitting enemy
 * Input parameters: Character* myCharacter -> game character
 * Returns:	Void
 * Preconditions: There is a map already made, enemies and keys are initialized, and character is initialized
 * Postconditions: Void
 *************************************************************/

void Map::resetPlayer(Character* mCharacter) {

	mCharacter->setPlayerSpeed(2.5);
	//keyDownCollected = false;
	//keyUpCollected = false;
	//keyRightCollected = false;
	//keyLeftCollected = false;
}


/*************************************************************
 * Function: checkCharacterLost(Character* mCharacter)
 * Description: Checks if the character is out of lives or not
 * Input parameters: Character* myCharacter -> game character
 * Returns:	bool - true if character is out of lives
 * Preconditions: There is a map already made, enemies and keys are initialized, and character is initialized
 * Postconditions: Void
 *************************************************************/

bool Map::checkCharacterLost(Character* mCharacter)
{
	if (mCharacter->outOfLives())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Setters

void Map::setGameState(int newState) {
	this->mGameState = newState;
}


int Map::getGameState() {
	return mGameState;
}