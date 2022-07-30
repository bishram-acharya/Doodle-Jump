#pragma once

#include<iostream>
//#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Game logic
	bool endGame;

	float last_pos_x;
	float new_pos_x;
	float last_pos_y;
	float new_pos_y;
	float dy;
	int platformX[10];
	int platformY[10];

	//Game objects
	
	//Private functions
	void initVariables();
	void initWindow();
//	void initFonts();
//	void initText();

	
public:
	//Constructors / Destructors
//	Game();
//	virtual ~Game();
	
	Game();
	virtual ~Game();
	bool StartScreen;
	bool firstplatforms;
	bool firstrender;
	bool GameOver;

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void initBackground();
	void initDoodle();
	void initializePlatform();
	int random_XPosition();
	int random_YPosition();

	void pollEvents();
	
	void updatePlatform();
	void updateDoodle();
	void update();
    void renderBackground();
	void renderPlatform();
	void renderDoodle();
	void renderGameOver();
	void displayStartScreen();
	void render();
};
