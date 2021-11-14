#include "PlayerClass.h"
#include <iostream>

PlayerClass::PlayerClass(sf::RenderWindow& myWindow, WorldClass& pointerToWorldClass, FishList& pointerToFishList)
{
	this->myWindow = &myWindow;
	myWorldClass = &pointerToWorldClass;
	myMiniGameClass = NULL;
	screenOffsetX = 0;
	screenOffsetY = 0;

	playerPosX = 0;
	playerPosY = 0;

	currentAnimation = 0;

	spaceCoolDown = 0;

	pointerSet = false;

	canMove = true;
	moving = false;
	fishing = false;
	offsetXOrY;

	playerSprite.setPosition(512,384);
	playerSprite.setOrigin(32,32);

	if (!boatSheet.loadFromFile("Assets/BoatSheet.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!whirlPoolTexture.loadFromFile("Assets/Whirlpool.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	playerSprite.setTexture(boatSheet);
	whirlPoolSprite.setTexture(whirlPoolTexture);
	whirlPoolSprite.setScale(2,2);
	whirlPoolSprite.setOrigin(16,16);
	myAnimatorClass = new Animator(&boatSheet, sf::Vector2u(4,6), 0.12);
	fishBeingFished = 0;
	engineQuality = 1;
	rodQuality = 1;
	hullQuality = 1;
	cargoValue = 0;
	currentHealth = 4;
	fishInCargo = 0;
	shopping = false;
}

PlayerClass::~PlayerClass(void)
{
}

bool PlayerClass::Update( float currentTime)
{
	char valHolder;
	float calculator;
	Animate(currentTime);
	if (canMove)
	{
		
		return Move();
		
	}
	else if(fishing)
	{
		valHolder = myMiniGameClass->Update(currentTime);
		if(valHolder == 0)
		{
			calculator = fishBeingFished;
			cargoValue += (1/calculator)*500;
			fishBeingFished = 0;
			fishInCargo += 1;
			myMiniGameClass = NULL;
			fishing = false;
			canMove = true;
			return true;
		}
		else if(valHolder < 11)
		{
			return false;
		}
		else
		{
			fishBeingFished = 0;
			myMiniGameClass = NULL;
			fishing = false;
			canMove = true;
			return true;
		}
	}
	else if(shopping)
	{
		return true;
	}

	return false;
		
		

}

void PlayerClass::Animate(float elapsedTime)
{
	if(spaceCoolDown > 0)
	{
		spaceCoolDown-= elapsedTime;
	}
	if(moving)
	{
		if(keyPressed == 1)
		{
			myAnimatorClass->Update(3, elapsedTime, 4);
		}
		else if(keyPressed == 2)
		{
			myAnimatorClass->Update(4, elapsedTime, 4);
		}
		else if(keyPressed == 3)
		{
			myAnimatorClass->Update(5, elapsedTime, 4);
		}
		else if(keyPressed == 4)
		{
			myAnimatorClass->Update(5, elapsedTime, 4);
		}
	}
	else if(keyPressed > 2)
	{
		myAnimatorClass->Update(0, elapsedTime, 4);
	}
	else if(keyPressed == 1)
	{
		myAnimatorClass->Update(1, elapsedTime, 4);
	}
	else if(keyPressed == 2)
	{
		myAnimatorClass->Update(2, elapsedTime, 4);
	}
	playerSprite.setTextureRect(myAnimatorClass->uvRect);
}

bool PlayerClass::Move()
{
	sf::Event event;
		while (myWindow->pollEvent(event))
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && myWorldClass->GetSailable(playerPosX-1,playerPosY, engineQuality)) //Left
			{
					playerSprite.setScale(1,1);
					canMove = false;
					moving = true;
					keyPressed = 4;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && myWorldClass->GetSailable(playerPosX+1,playerPosY, engineQuality)) //Right
			{
					playerSprite.setScale(-1,1);
					canMove = false;
					moving = true;
					keyPressed = 3;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && myWorldClass->GetSailable(playerPosX,playerPosY-1, engineQuality)) //Up
			{
				
					canMove = false;
					moving = true;
					keyPressed = 1;
				
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)  && myWorldClass->GetSailable(playerPosX,playerPosY+1, engineQuality)) //Down
			{
				
					canMove = false;
					moving = true;
					keyPressed = 2;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && spaceCoolDown <= 0) //Space
			{
				return true;
			}
		}
		return false;
}

Vector2c PlayerClass::GetPosition()
{
	return Vector2c(playerPosX, playerPosY);
}

Vector2c PlayerClass::GetOffset()
{
	return Vector2c(screenOffsetX, screenOffsetY);
}

Vector2c PlayerClass::CalculateOffset()
{
	if(moving)
	{
		if (keyPressed == 1)
		{
			screenOffsetY += engineQuality*4;
		}
		else if (keyPressed == 2)
		{
			screenOffsetY -= engineQuality*4;
		}
		else if(keyPressed == 3)
		{
			screenOffsetX -= engineQuality*4;
		}
		else if (keyPressed == 4)
		{
			screenOffsetX += engineQuality*4;
		}
		if (abs(screenOffsetX) == 64)
		{

			screenOffsetX = 0;
		
			canMove = true;
			moving = false;
			int x = playerPosX;
			int y = playerPosY;
			std::cout<<x<<std::endl<<y<<std::endl<<std::endl;
			if (keyPressed == 3)
			{
				playerPosX += 1;
				if (playerPosX > 99)
				{

					playerPosX -= 100;

				}
			}
		
			else if (keyPressed == 4)
			{
				playerPosX -= 1;
				if (playerPosX < 0)
				{

					playerPosX += 100;

				}
			}
		
		}
		else if (abs(screenOffsetY) == 64)
		{
			if (keyPressed == 1)
			{
				playerPosY -= 1;
				if (playerPosY < 0)
				{

					playerPosY += 100;

				}


			}

			else if (keyPressed == 2)
			{
				playerPosY += 1;
				if (playerPosY > 99)
				{

					playerPosY -= 100;

				}
			}
			screenOffsetY = 0;
			canMove = true;
			moving = false;
		
		}
	}
	return Vector2c(screenOffsetX, screenOffsetY);
	
}

void PlayerClass::Draw()
{
	char screenPositionX = 75 - playerPosX;
	char screenPositionY = 25 - playerPosY;
	
	if(abs(screenPositionX) < 12 && abs(screenPositionY) < 9)
	{
		whirlPoolSprite.setPosition(512+(screenPositionX*64)+screenOffsetX, 384+(screenPositionY*64)+screenOffsetY);
		myWindow->draw(whirlPoolSprite);
	}
	myWindow->draw(playerSprite);
	

}

void PlayerClass::SetFishing(char fishType)
{

	if(fishType != 0 && fishInCargo <= hullQuality*4)
	{
		fishBeingFished = fishType;
		myMiniGameClass = new MiniGameClass(fishType*rodQuality, *myWindow);
		fishing = true;
		canMove = false;
	}
}

bool PlayerClass::GetCargo()
{
	return fishInCargo <= hullQuality*4;
}

int PlayerClass::SellFish()
{
	int valHolder = cargoValue;
	cargoValue = 0;
	fishInCargo = 0;
	return valHolder;
}

bool PlayerClass::SetShopping(bool state)
{
	if(canMove == state && fishing == false)
	{
		shopping = state;
		canMove = !state;
	}
	spaceCoolDown = 0.3;
	return shopping;
}

void PlayerClass::Repair()
{
	currentHealth = hullQuality*4;
}

void PlayerClass::Upgrade(char upgrade)
{
	char upgrades[3] = {engineQuality, rodQuality, hullQuality};
	upgrades[upgrade-3]+=1;
	engineQuality = upgrades[0];
	rodQuality = upgrades[1];
	hullQuality = upgrades[2];
}