#include "EnemyFish.h"


EnemyFish::EnemyFish(sf::RenderWindow& myWindow, WorldClass* pointerToWorldClass, char type, char posX, char posY)
{
	myWorldClass = pointerToWorldClass;
	this->myWindow = &myWindow;
	fishPosX = posX;
	fishPosY = posY;
	screenOffsetX = 0;
	screenOffsetY = 0;
	moveTimer = 0;
	fishType = type;
	canMove = true;
	fishSprite.setOrigin(32, 32);

	fishTexture.loadFromFile("Assets/Fish.png"); //The "Player" Image...
	fishSprite.setTexture(fishTexture);
	sf::Texture *pointerToFishTexture = &fishTexture;
	myAnimator = new Animator(pointerToFishTexture, sf::Vector2u(5, 1), 0.16);
	
}

EnemyFish::~EnemyFish(void)
{
}

void EnemyFish::SetMovement(bool moveToSet)
{

	canMove = moveToSet;

}

bool EnemyFish::Update(float elapsedTime, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY)
{
	myAnimator->Update(0, elapsedTime, 5);
	moveTimer += elapsedTime;
	if (moveTimer > 4 && canMove)
	{
		Move();
	}
	if(moving)
	{
		CalculateOffset();
	}
	fishSprite.setTextureRect(myAnimator->uvRect);
	
	
	Draw(playerOffsetX, playerOffsetY, playerPosX, playerPosY);

	return false;
}

void EnemyFish::Move()
{
	float calculator;
	float fishCalculator = fishType;
	if(fishType == 8)
	{
		calculator = 0;
	}
	else
	{
		calculator = ((1/fishCalculator)*7)+0.25;
	}
	char swimmableTile = calculator;
	if(swimmableTile != 0)
	{
		int x = 3;
	}
	char directionToMove = rand()%4+1;
	if (directionToMove == 4 && myWorldClass->GetLocVal((fishPosX)-1, fishPosY) == swimmableTile) //Left
	{
			moveTimer -= moveTimer;	
			canMove = false;
			moving = true;
			movementDirection = 4;
	}
	else if (directionToMove == 2 && myWorldClass->GetLocVal((fishPosX)+1, fishPosY) == swimmableTile) //Right
	{
			moveTimer -= moveTimer;	
			canMove = false;
			moving = true;
			movementDirection = 2;

	}
	else if (directionToMove == 1 && myWorldClass->GetLocVal(fishPosX, fishPosY-1) == swimmableTile) //Up
	{
			moveTimer -= moveTimer;	
			canMove = false;
			moving = true;
			movementDirection = 1;
				
	}
	else if (directionToMove == 3  && myWorldClass->GetLocVal(fishPosX, fishPosY+1) == swimmableTile) //Down
	{
			moveTimer -= moveTimer;	
			canMove = false;
			moving = true;
			movementDirection = 3;

	}

}

Vector2c EnemyFish::CalculateOffset()
{
	if(moving)
	{
		if (movementDirection == 1)
		{
			screenOffsetY -= 4;
		}
		else if (movementDirection == 2)
		{
			screenOffsetX += 4;
		}
		else if(movementDirection == 3)
		{
			screenOffsetY += 4;
		}
		else if (movementDirection == 4)
		{
			screenOffsetX -= 4;
		}

		if (abs(screenOffsetX) == 64)
		{

			screenOffsetX = 0;
		
			canMove = true;
			moving = false;

		
			if (movementDirection == 2)
			{
				fishPosX += 1;
				if (fishPosX > 99)
				{

					fishPosX -= 100;

				}
			}
		
			else if (movementDirection == 4)
			{
				fishPosX -= 1;
				if (fishPosX < 0)
				{

					fishPosX += 100;

				}
			}
		
		}
		else if (abs(screenOffsetY) == 64)
		{
			if (movementDirection == 1)
			{
				fishPosY -= 1;
				if (fishPosY < 0)
				{

					fishPosY += 100;

				}


			}

			else if (movementDirection == 3)
			{
				fishPosY += 1;
				if (fishPosY > 99)
				{

					fishPosY -= 100;

				}
			}
			screenOffsetY = 0;
			canMove = true;
			moving = false;
		
		}
	}
	return Vector2c(screenOffsetX, screenOffsetY);
	
}

void EnemyFish::Draw(char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY)
{
	char screenPositionX = fishPosX - playerPosX;
	char screenPositionY = fishPosY - playerPosY;
	//if(screenPositionX > 50)
	//{
	//	screenPositionX-=100;
	//}
	//if(screenPositionY > 50)
	//{
	//	screenPositionY-=100;
	//}
	
	if(abs(screenPositionX) < 12 && abs(screenPositionY) < 9)
	{
		fishSprite.setPosition(512+(screenPositionX*64)+playerOffsetX+screenOffsetX, 384+(screenPositionY*64)+playerOffsetY+screenOffsetY);
		myWindow->draw(fishSprite);
	}

}

Vector2c EnemyFish::GetPosition()
{
	return Vector2c(fishPosX, fishPosY);
}

char EnemyFish::GetType()
{
	return fishType;
}