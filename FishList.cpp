#include "FishList.h"
#include <iostream>


FishList::FishList(sf::RenderWindow& myWindow, WorldClass& pointerToWorldClass)
{
	spawnTimer = 0;
	nodeCounter = 0;
	this -> myWindow = &myWindow;
	myWorldClass = &pointerToWorldClass;
	HeadNode = NULL;
	TailNode = NULL;
}


FishList::~FishList(void)
{

}

char FishList::CompareLocs(Vector2c location)
{
	int counter = 0;
	EnemyNode *ProbeNode = new EnemyNode;
	ProbeNode = HeadNode;
	
	while (ProbeNode != NULL)
	{
		if(ProbeNode->Enemy->GetPosition().x == location.x && ProbeNode->Enemy->GetPosition().y == location.y)
		{
			toBeDeleted = counter;
			ProbeNode->Enemy->SetMovement(false);
			return ProbeNode->Enemy->GetType();
		}
		else
		{
			ProbeNode = ProbeNode->NextNode;
			counter++;
		}

	}
	return 0;
}

void FishList::Update(float elapsedTime, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY)
{
	spawnTimer+= elapsedTime;
	EnemyNode *ProbeNode = new EnemyNode;
	EnemyNode *SafetyNode = new EnemyNode;
	int counter = 0;
	ProbeNode = HeadNode;
	char totalEnemies = CountList();
	bool storeResult = false;

	if(spawnTimer > 5 && totalEnemies < 15)
	{
		spawnTimer-=spawnTimer;
		char randSaverX = playerPosX+rand()%14-7;
		char randSaverY = playerPosY+rand()%14-7;
		while (myWorldClass->GetLocVal(randSaverX,randSaverY) > 9)
		{
			randSaverX = playerPosY+rand()%14-7;
			randSaverY = playerPosY+rand()%14-7;
		}

		randSaverX += (randSaverX < 0) * 100;

		randSaverX += (randSaverX < 0) * -100;

		randSaverY += (randSaverY < 0) * 100;

		randSaverY += (randSaverY < 0) * -100;
		
		MakeNew(randSaverX,randSaverY, (myWorldClass->GetLocVal(randSaverX, randSaverY)-4)*-2);
	}

	if(totalEnemies != 0)
	{
		while (ProbeNode != NULL)
		{
			SafetyNode = ProbeNode->NextNode;
			UpdateEnemy(ProbeNode, counter, elapsedTime, playerOffsetX, playerOffsetY, playerPosX, playerPosY);
			counter++;
			
			ProbeNode = SafetyNode;
		}

	}
}

bool FishList::UpdateEnemy(EnemyNode* ProbeNode, int location, float elapsedTime, char playerOffsetX, char playerOffsetY, char playerPosX, char playerPosY)
{
	int counter = 0;
	bool storeEnemyState;

	storeEnemyState = ProbeNode->Enemy->Update(elapsedTime, playerOffsetX, playerOffsetY, playerPosX, playerPosY);
	if(abs(abs(ProbeNode->Enemy->GetPosition().x) - abs(playerPosX)) > 8)
	{
		storeEnemyState = true;
	}
	else if(abs(abs(ProbeNode->Enemy->GetPosition().y) - abs(playerPosY)) > 8)
	{
		int x = ProbeNode->Enemy->GetPosition().y;
		storeEnemyState = true;
	}
	if(storeEnemyState)
	{
		if (location == 0)
		{
			DeleteFirstNode();
			
		}
		else if (location == CountList()-1)
		{
			DeleteLastNode();
		}
		else
		{
			Destroy(location);
		}

		return true;
	}
	else
	{
		return false;
	}

}

void FishList::MakeNew(char posX, char posY, char type)
{
	EnemyNode *NewNode = new EnemyNode;
	NewNode->ID = nodeCounter;
	nodeCounter +=1;
	int test = type;
	std::cout<<test<<std::endl;
	NewNode->Enemy = new EnemyFish(*myWindow, myWorldClass, type, posX, posY);
	NewNode->NextNode = NULL;

	if (HeadNode != NULL)
	{

		TailNode->NextNode = NewNode;
		TailNode = NewNode;

	}
	else
	{

		HeadNode = NewNode;
		TailNode = NewNode;

	}

}

int FishList::CountList()
{
	int counter = 0;
	EnemyNode *ProbeNode = new EnemyNode;
	ProbeNode = HeadNode;

	while (ProbeNode != NULL)
	{

		ProbeNode = ProbeNode->NextNode;
		counter++;

	}
	return counter;
}

void FishList::Destroy(char ID)
{

	
		int i;
    	EnemyNode *CurrentNode = new EnemyNode;
    	EnemyNode *PreviousNode = new EnemyNode;
    	CurrentNode = HeadNode;

    	for(i = 0;i < ID;i++)
    	{
      		PreviousNode = CurrentNode;
      		CurrentNode = CurrentNode -> NextNode;
    	}
		if(CurrentNode != NULL)
		{
    		PreviousNode -> NextNode = CurrentNode -> NextNode;
		}
		else
		{
			PreviousNode -> NextNode = nullptr;
		}
		delete CurrentNode;

}

void FishList::DeleteFirstNode()
{
    EnemyNode *DeletedNode = new EnemyNode;
    DeletedNode = HeadNode;
    HeadNode = HeadNode -> NextNode;
    delete DeletedNode;
}

void FishList::DeleteLastNode()
{
    EnemyNode *CurrentNode = new EnemyNode;
    EnemyNode *PreviousNode = new EnemyNode;
    CurrentNode = HeadNode;

    while(CurrentNode -> NextNode != NULL)
    	{
      	PreviousNode = CurrentNode;
      	CurrentNode = CurrentNode -> NextNode;
    	}

    TailNode = PreviousNode;
    PreviousNode -> NextNode = NULL;
    delete CurrentNode;
}

bool FishList::CheckDeletions()
{
	if(toBeDeleted < 0)
	{
		return false;
	}
	else if(toBeDeleted >= 0) 
	{
		if (toBeDeleted == 0)
		{
			DeleteFirstNode();
			toBeDeleted = -1;
		}
		else if(toBeDeleted == CountList())
		{
			DeleteLastNode();
			toBeDeleted = -1;
		}
		else
		{
			Destroy(toBeDeleted);
			toBeDeleted = -1;
		}
		
	}
	return true;
}