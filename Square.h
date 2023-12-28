#pragma once

#include <SFML/Graphics.hpp>

class Square : public sf::RectangleShape {

public:
	Square(const sf::Color& squareColor, const sf::Vector2f& newSize, const sf::Vector2f& newPos);
	void moveCharacter(sf::Keyboard::Key key);

	void setPlayerSpeed(float newSpeed);
	float getPlayerSpeed();

private:
	//nothin
};