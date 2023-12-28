#pragma once
//#include "Square.h"
#include "Character.h"
#include "Wall.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Test_Map.h"

class Testing
{
public:
	// Constructors & destructors
	Testing();
	virtual ~Testing();

	bool isRunning() const;
	bool pollEvents(sf::Event& evnt);

	//getters

	sf::RenderWindow* getWindow();

	Square* getChar();

	sf::Event* getEvent();

	//event is not working
	void setEvent(sf::Event* newEvent);
	void resetPlayer();

	// Update & rendering window
	void render();
	void update();
	void splashWindow();



private:

	sf::RenderWindow* mWindow;
	Character* mCharacter;

	sf::RectangleShape* background;
	sf::Texture backgroundTexture;

	sf::Font font;
	sf::Text winText;
	sf::Text lostText;
	sf::Text menuText;
	sf::Text livesText;

	Test_Map* gameMap;
	//track win/loss/menu(?) states
	//int gameState[2];
};
