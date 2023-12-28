#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"

class Wall : public sf::RectangleShape
{
public:
	Wall(const sf::Color& wallColor, const sf::Vector2f& newSize, const sf::Vector2f& newPos, bool horizontal);

	void edgeDetect(Character *mCharacter);

	
	

private:
	
	//bool door;  //use this to differentiate a wall and a door
	float widthDiff;
	bool horizontal;
};