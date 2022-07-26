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
//	/**
//		@return void
//
//		Updates the enemy spawn timer and spawns enemies
//		When the total amount of enemies is smaller than the maximum.
//		Moves the enemies downwards.
//		Removes the enemies at the edge of the screen. //TODO
//	*/
//
//	//Updating the timer for enemy spawning
//	if (this->enemies.size() < this->maxEnemies)
//	{
//		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
//		{
//			//Spawn the enemy and reset the timer
//			this->spawnEnemy();
//			this->enemySpawnTimer = 0.f;
//		}
//		else
//			this->enemySpawnTimer += 1.f;
//	}
//
//	//Moving and updating enemies
//	for (int i = 0; i < this->enemies.size(); i++)
//	{
//		bool deleted = false;
//
//		this->enemies[i].move(0.f, 5.f);
//
//		if (this->enemies[i].getPosition().y > this->window->getSize().y)
//		{
//			this->enemies.erase(this->enemies.begin() + i);
//			this->health -= 1;
//			std::cout << "Health: " << this->health << "\n";
//		}
//	}
//
//	//Check if clicked upon
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//	{
//		if (this->mouseHeld == false)
//		{
//			this->mouseHeld = true;
//			bool deleted = false;
//			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
//			{
//				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
//				{
//					//Gain points
//					if(this->enemies[i].getFillColor() == sf::Color::Magenta)
//						this->points += 10;
//					else if (this->enemies[i].getFillColor() == sf::Color::Blue)
//						this->points += 7;
//					else if(this->enemies[i].getFillColor() == sf::Color::Cyan)
//						this->points += 5;
//					else if (this->enemies[i].getFillColor() == sf::Color::Red)
//						this->points += 3;
//					else if (this->enemies[i].getFillColor() == sf::Color::Green)
//						this->points += 1;
//
//					std::cout << "Points: " << this->points << "\n";
//
//					//Delete the enemy
//					deleted = true;
//					this->enemies.erase(this->enemies.begin() + i);
//				}
//			}
//		}
//	}
//	else
//	{
//		this->mouseHeld = false;
//	}
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
	
	

	window->display();
}
