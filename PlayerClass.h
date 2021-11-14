#pragma once
#include <SFML/Graphics.hpp>
#include "WorldClass.h"
#include "Vector2c.h"
#include "FishList.h"
#include "MiniGameClass.h"
#include "Animator.h"

class PlayerClass
{
public:
	PlayerClass(sf::RenderWindow& myWindow, WorldClass& pointerToWorldClass, FishList& pointerToFishList);
	~PlayerClass(void);

	bool Update(float);
	void Draw();
	void SetFishing(char fishType);
	bool SetShopping(bool state);
	int SellFish();
	void Repair();
	void Upgrade(char upgrade);
	Vector2c CalculateOffset();
	
	Vector2c GetPosition();
	Vector2c GetOffset();

	void AdjustQualities(char qualityToAdjust);

	bool GetCargo();

	

private:
	WorldClass *myWorldClass;
	FishList *myFishList;
	MiniGameClass *myMiniGameClass;
	Animator *myAnimatorClass;
	sf::RenderWindow *myWindow;
	char screenOffsetX;
	char screenOffsetY;

	sf::Sprite playerSprite;
	sf::Texture boatSheet;
	char currentAnimation;

	sf::Sprite whirlPoolSprite;
	sf::Texture whirlPoolTexture;

	char playerPosX;
	char playerPosY;

	char keyPressed;

	bool pointerSet;

	bool canMove;
	bool moving;
	bool fishing;
	bool shopping;
	bool offsetXOrY;

	char fishedFish;

	float waitTime;

	char fishInCargo;
	char fishBeingFished;
	float cargoValue;

	char engineQuality;
	char rodQuality;
	char hullQuality;
	char currentHealth;

	bool Move();
	float spaceCoolDown;
	void Animate(float elapsedTime);
};

