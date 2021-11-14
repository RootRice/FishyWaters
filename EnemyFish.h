#pragma once
#include <SFML\Graphics.hpp>
#include "WorldClass.h"
#include "Vector2c.h"
#include "Animator.h"

class EnemyFish
{
public:
	EnemyFish(sf::RenderWindow& myWindow, WorldClass* pointerToWorldClass, char type, char posX, char posY);
	~EnemyFish(void);

	bool Update(float elapsedTime, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY);
	Vector2c GetPosition();
	char GetType();
	void Draw(char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY);
	void SetMovement(bool);

private:
	WorldClass *myWorldClass;
	sf::RenderWindow *myWindow;
	Animator* myAnimator;

	sf::Sprite fishSprite;
	sf::Texture fishTexture;

	void Move();
	float moveTimer;
	bool canMove;
	bool moving;
	char movementDirection;

	char fishPosX;
	char fishPosY;
	char fishType;

	Vector2c CalculateOffset();
	char screenOffsetX;
	char screenOffsetY;

	void Draw();


	
};

