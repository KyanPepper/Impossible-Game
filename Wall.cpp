#include "Wall.h"
#include <iostream>

// Constructor for wall, inherits from type RectangleShape

Wall::Wall(const sf::Color& wallColor, const sf::Vector2f& newSize, const sf::Vector2f& newPos, bool horizontal):
	sf::RectangleShape(newSize)
{
	this->setFillColor(wallColor);
	this->setPosition(newPos);
	//this->door = passable;

	//initialize as 1 so movement doesn't break
	this->widthDiff = 1;
	this->horizontal = horizontal;

	this->setOutlineThickness(3);
	this->setOutlineColor(sf::Color::Black);

}

/*************************************************************
 * Function: edgeDetect(Character* mCharacter)
 * Description: Checks if the character is intersecting with the wall, moves character away from it
 * Input parameters: Character* myCharacter -> game character
 * Returns:	Void
 * Preconditions: There is a map already made, walls are initialized, and character is initialized
 * Postconditions: Void
 *************************************************************/

void Wall::edgeDetect(Character* mCharacter) {

	// If the wall is a horizontal wall, define character interaction
	if (this->horizontal == true) {

		// Top edge of character detect IF HORIZONTAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().top - (mCharacter->getGlobalBounds().top) <= 0) {

			mCharacter->move(0, mCharacter->getPlayerSpeed());
		}

		// Bottom edge of character detect IF HORIZONTAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().top - (mCharacter->getGlobalBounds().top + mCharacter->getSize().y) <= 0) {

			mCharacter->move(0, -(mCharacter->getPlayerSpeed()));

		}

		// Left edge of character detect IF HORIZONTAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().left - (mCharacter->getGlobalBounds().left) <= 0) {

			mCharacter->move(mCharacter->getPlayerSpeed(), mCharacter->getPlayerSpeed());

		}

		// Right edge of character detect IF HORIZONTAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().left - (mCharacter->getGlobalBounds().left + mCharacter->getSize().x) <= 0) {

			mCharacter->move(-(mCharacter->getPlayerSpeed()), mCharacter->getPlayerSpeed());

		}

	}

	//checks if wall is a vertical wall first
	else {

		// Top edge of character detect IF VERTICAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().top - (mCharacter->getGlobalBounds().top) <= 0) {

			mCharacter->move(0, mCharacter->getPlayerSpeed());
		}

		// Bottom edge of character detect IF VERTICAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().top - (mCharacter->getGlobalBounds().top + mCharacter->getSize().y) <= 0) {

			mCharacter->move(0, -(mCharacter->getPlayerSpeed()));

		}

		// Left edge of character detect IF VERTICAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().left - (mCharacter->getGlobalBounds().left) <= 0) {

			mCharacter->move(mCharacter->getPlayerSpeed(), 0);

		}

		// Right edge of character detect IF VERTICAL
		if (mCharacter->getGlobalBounds().intersects(this->getGlobalBounds()) && this->getGlobalBounds().left - (mCharacter->getGlobalBounds().left + mCharacter->getSize().x) <= 0) {

			mCharacter->move(-(mCharacter->getPlayerSpeed()), 0);

		}

	}
	
}
