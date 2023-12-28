#include "Square.h"

Square::Square(const sf::Color& squareColor, const sf::Vector2f& newSize, const sf::Vector2f& newPos) : sf::RectangleShape(newSize)
{
	this->setFillColor(squareColor);
	this->setPosition(newPos);
}
