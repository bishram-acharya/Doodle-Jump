#include "Game.h"

//Private functions
void Game::initVariables()
{
//	this->window = nullptr;
	
	//Game logic
	this->endGame = false;

	
	
}

void Game::initWindow()
{   
	this->videoMode.height = 1200;
	this->videoMode.width = 1600;
	
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(600);
}

void Game::initBackground()
{
	sf::Texture t3;
    
    t3.loadFromFile("images/background.png");

    sf::Sprite s3(t3);

    
	
	
	s3.setPosition(10.f, 10.f);
	
	
};
void Game::initPlatform()
{
	sf::Texture t2;
    
    t2.loadFromFile("images/platform.png");

    sf::Sprite s2(t2);

    
	
	
	s2.setPosition(60.f, 60.f);
	

	
};

void Game::initDoodle()

{   sf::Texture t1;
    
    t1.loadFromFile("images/doodle.png");

    sf::Sprite s1(t1);

    
	
	
	s1.setPosition(10.f, 10.f);
	

}

//Constructors / Destructors
Game::Game()
{   last_pos_x=0;
	new_pos_x=0;
	last_pos_y=0;
	new_pos_y=0;
	
	this->initVariables();
	this->initWindow();
//	this->initFonts();
//	this->initText();
	
    this->initBackground();
    this->initPlatform();
    this->initDoodle();
}
//Game::Game(float b){
//	
//	last_pos=b;
//	new_pos=last_pos+200;
//}

Game::~Game()
{
	delete this->window;
}


//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}


void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}




//void Game::updateEnemies()
//{
//	
//}

void Game::update()
{
	this->pollEvents();
	
    
	if (this->endGame == false)
	{
	
	
 	this->updateDoodle();
//	last_pos=new_pos;
   
	//this->updatePlatform();
	}
	 

	//End game condition
	
}


void Game::updateDoodle() 
{  
  	last_pos_x=new_pos_x;
  	new_pos_x= last_pos_x+1;
  	last_pos_y=new_pos_y;
	new_pos_y=last_pos_y+1;
	
   
	
}

void Game::renderPlatform()
{
	sf::Texture t2;
    
    t2.loadFromFile("images/platform.png");

    sf::Sprite s2(t2);
   
    
    this->window->draw(s2);
     
 	
		
}


//void Game::Game(float)
//{ 
//	float last_pos,new_pos;
//
//}

void Game::renderDoodle()
{
	sf::Texture t1;
    
    t1.loadFromFile("images/doodle.png");

    sf::Sprite s1(t1);
    s1.setPosition(this->new_pos_x, new_pos_y);
    this->window->draw(s1);
    

}
void Game::renderBackground()
{
	
	sf::Texture t3;
    
    t3.loadFromFile("images/background.png");

    sf::Sprite s3(t3);
    this->window->draw(s3);

    
	
}

void Game::render()
{
	/**
		@return void

		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/

	this->window->clear();

	//Draw game objects
	this->renderBackground();
	this->renderPlatform();
	this->renderDoodle();
	
	

	this->window->display();
}
