#pragma once
#include <SFML\Graphics.hpp>
#include "EnemyFish.h"
#include "Vector2c.h"

class FishList
{
public:
	FishList(sf::RenderWindow& myWindow, WorldClass& pointerToWorldClass);
	~FishList(void);

	void Update(float, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY);
	void MakeNew(char posX, char posY, char type);
	char CompareLocs(Vector2c location);
	bool CheckDeletions();
private:
	WorldClass *myWorldClass;
	sf::RenderWindow *myWindow;
	
	float spawnTimer;

	struct EnemyNode
	{
		int ID;
		EnemyFish *Enemy;
		EnemyNode *NextNode;
	};

	EnemyNode *HeadNode;
	EnemyNode *TailNode;

	int toBeDeleted;

	int CountList();
	char nodeCounter;

	bool UpdateEnemy(EnemyNode*, int, float, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY);

	void Destroy(char);
	void DeleteFirstNode();
	void DeleteLastNode();
};

