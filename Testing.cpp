#include "Testing.h"
#include "Game.h"
#include <iostream>

// Testing constructor

Testing::Testing()
{
	//create render window and set the frame limit
	this->mWindow = new sf::RenderWindow(sf::VideoMode(1900, 900), "SFML works!");

	mWindow->setFramerateLimit(60);

	//create character
	this->mCharacter = new Character(sf::Color::White, sf::Vector2f(25, 25), sf::Vector2f(990 - (25 / 2), 425));

	//create game map -> set background, and load background texture
	this->gameMap = new Test_Map();

	this->background = new sf::RectangleShape(sf::Vector2f(1900, 900));
	this->background->setPosition(0, 0);

	backgroundTexture.loadFromFile("softColor.jpg");
	background->setTexture(&backgroundTexture);
	background->setTextureRect(sf::IntRect(0, 0, 300, 300));
	
}

	
// Game constructor (delete window, character, and gameMap)

Testing::~Testing()
{
	delete this->mWindow;
	delete this->mCharacter;
	delete this->gameMap;

}


// isRunning simply checks if the window is open, returns true if it is

bool Testing::isRunning() const
{
	return this->mWindow->isOpen();
}


/*************************************************************
 * Function: render()
 * Description: Renders the corresponding window to map's gameState
 *				0 = game screen
 *				-1 = main menu
 *				1 = win screen
 *				else = lost screen
 * Input parameters: Void
 * Returns:	Void
 * Preconditions: Game is already initialized, window is made
 * Postconditions:
 *************************************************************/


 // Update & rendering window
void Testing::render()
{
	// Clear old frame
	this->mWindow->clear();

	// Draw map/text/shapes

	// Game screen
	if (gameMap->getGameState() == -1) {

		// Draw the background
		this->mWindow->draw((*this->background));

		// Draw the window
		this->gameMap->drawMap(mWindow);

		// Draw the character lives
		this->mWindow->draw(livesText);

		// Draw the character
		this->mWindow->draw((*this->mCharacter));

	}	
	// Display window
	this->mWindow->display();
}

/*************************************************************
 * Function: update()
 * Description: Updates the character movement, enemy movement, does edge detecting, and constantly updates character lives
 * Input parameters: Void
 * Returns:	Void
 * Preconditions: There is a map/window already made
 * Postconditions: Void
 *************************************************************/

void Testing::update()
{
	//testWall->edgeDetect(mCharacter);

	// Update character interaction with window border
	mCharacter->edgeDetect(mWindow);

	// Update all of the map
	gameMap->updateMap(mCharacter);

	// Update character movement
	mCharacter->characterMovement();

	// Update character lives
	livesText.setString("Lives: " + std::to_string(mCharacter->getLives()));
}


/*************************************************************
 * Function: splashWindow()
 * Description: clears the window and displays the menu text
 * Input parameters: Void
 * Returns:	Void
 * Preconditions: There is a window already made
 * Postconditions: Void
 *************************************************************/

void Testing::splashWindow() {

	// Clear the window and draw the menu text
	this->mWindow->clear();
	this->mWindow->draw(menuText);
}


//getters

sf::RenderWindow* Testing::getWindow() {
	return this->mWindow;
}

Square* Testing::getChar() {
	return this->mCharacter;
}

