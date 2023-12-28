#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
#include"Testing.h"

/*******************************************************************************
 * Programmer: Matthew Butler, Matthew Wolfe, Kyan Kotschevar-Smead,Kyle Jang
 * Class: CptS 122
 * Programming Assignment: Final programming assignment
 * Date:   12/7/2022
 *
 * Description: This game is simple top down, 2D movement arcade game.
 *				The player spawns in the center, and needs to navigate 4 corridors and collect all keys to win the game
 *				For each key the character collects, their speed is increased by 25%
 *				If the character hits an enemy (red ball), the speed is set back to the base speed and they lose one life
 *				Only a maximum of 3 lives are given
 *
 *	README.txt: Refer to in "Pong" folder
 * 
 * Relevant Formulas: Refer to each function definition.
 *
 ******************************************************************************/


int main()
{
	//initializes main game wrapper
	Game myGame;

	/*
	Using an event variable initialized in the Game class doesn't work because of "uninitialized memory" error. 
	Only way I could fix this is by initializing it in the main loop.
	-Matt B.
	*/

	// Create event and music instances
	sf::Event newEvent;
	sf::Music mySong;

	// Open the song file, if it doesn't open display error
	
	if (!mySong.openFromFile("Aphex-Twin.wav")) {
		std::cout << "Error loading song" << std::endl;
	}


	//load song, loop it, and play
	mySong.setVolume(1.f);
	mySong.setLoop(true);
	mySong.play();


	//main game loop
	 while (myGame.isRunning())
	{
		// While the window is open, poll to see if window is closed
		while (myGame.getWindow()->pollEvent(newEvent)) {
			if (newEvent.type == sf::Event::Closed) {
				myGame.getWindow()->close();
			}
		}

		//Game wrapper functions to update events, character movement, and rendering
		myGame.update();
		myGame.render();
	} 
	

	 //Test function UNCOMMENT FOR TESTCASES IN CONSOLE BUT COMMENT THE ABOVE CODE
	/*Testing test;
	while (test.isRunning())
	{
		while (test.getWindow()->pollEvent(newEvent)) {
			if (newEvent.type == sf::Event::Closed) {
				test.getWindow()->close();
			}
		}

		//Game wrapper functions to update events, character movement, and rendering
		test.update();
		test.render();
	}*/
	 return 0;
}
	
	



	





