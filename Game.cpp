#include "Game.h"
#include <random>
#include <ctime>
//Private functions
void Game::initVariables()
{
//	this->window = nullptr;
	
	//Game logic
	this->endGame = false;
	this->StartScreen = true;
	this->firstplatforms = false;
    this->GameOver=false;

	
	
}

void Game::initWindow()
{   
	this->videoMode.height = 800;
	this->videoMode.width = 600;
	
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initBackground()
{
	sf::Texture t3;
    
    t3.loadFromFile("images/bg1.png");

    sf::Sprite s3(t3);

    
	
	
	s3.setPosition(10.f, 10.f);
	
	
};



void Game::initializePlatform()
{

};

void Game::initDoodle()

{   sf::Texture t1;
    
    t1.loadFromFile("images/doodle.png");

    sf::Sprite s1(t1);

    
	
	
	s1.setPosition(10.f, 10.f);
	

}

//Constructors / Destructors
Game::Game()
{   
	
	new_pos_x=300;

	new_pos_y=600;
	dy=0;
	
	this->initVariables();
	this->initWindow();
//	this->initFonts();
//	this->initText();
	
    this->initBackground();
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
			if (this->ev.key.code == sf::Keyboard::Left)
				this->new_pos_x -= 6;
			if (this->ev.key.code == sf::Keyboard::Right)
				this->new_pos_x += 6;
			break;
		}
	}
}

void Game::renderGameOver()
{
	sf::Texture t4;
    
    t4.loadFromFile("images/gameover.png");

    sf::Sprite s4(t4);

    
	
	
	s4.setPosition(0.f, 0.f);
	
	
	this->window->clear();
	this->window->draw(s4);
    this->window->display();
    
	
	
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
  	
  	dy+=0.5;
  	new_pos_y+=dy;
  	if (new_pos_y>625)
  	{dy=-20;
	  }
	  
	if (new_pos_x <= 0)
		new_pos_x += this->videoMode.width;
	new_pos_x = static_cast <unsigned> (new_pos_x) % this->videoMode.width;
	 /*
	 y;
	 dy = 10;
	 dy+=ddy;
	ddy =-.6;
	
	 
	 */ 
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//can be replaced by anything
		 {
 	    this->GameOver=true;	
		 
 	  
 		}
  	
	
   
	
}
int Game::random_XPosition()
{
	std::mt19937 mt(time(0));
	return (mt()% this->videoMode.width);
}
int Game::random_YPosition()
{
	std::mt19937 mt(time(0));
	return (mt()% this->videoMode.height);
}
void Game::renderPlatform()
{
	  int x1,y1;
	  sf::Texture t2;
      t2.loadFromFile("images/platform.png");
      std::vector<sf::Sprite> s2(10, sf::Sprite(t2));

      for(int i=0;i<10;i++)
      {
      	if(this->firstplatforms == true)
      	{   
			this->platformX[i] = rand() % 400;
      		this->platformY[i] = rand() % 800;
        }
		s2[i].setPosition(this->platformX[i], this->platformY[i]);
      	this->window->draw(s2[i]);
	  }
	  this->firstplatforms = false;
	

		
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
    
    t3.loadFromFile("images/bg1.png");

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

void Game::displayStartScreen()
{
		
	sf::Texture t2;
    
    t2.loadFromFile("images/start2.png");

    sf::Sprite s2(t2);
    s2.setPosition(300,350);
   
    
    this->window->draw(s2);
    this->window->display();
}
