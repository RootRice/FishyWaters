#include <SFML/Graphics.hpp>
#include "WorldClass.h"
#include "PlayerClass.h"
#include "MenuScreen.h"
#include "Vector2c.h"
#include "FishList.h"
#include "ShopScreenClass.h"
#include <iostream>


//WorldClass *pointerToWorldClass = new WorldClass(gameWindow);

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768, 32), "it works!", 7);
	WorldClass* pointerToWorldClass = new WorldClass(gameWindow);
	FishList* pointerToFishList = new FishList(gameWindow, *pointerToWorldClass);
	PlayerClass* pointerToPlayerClass = new PlayerClass (gameWindow, *pointerToWorldClass, *pointerToFishList);
	ShopScreenClass* pointerToShopClass = new ShopScreenClass(gameWindow);
	MenuScreen* pointerToMenuScreen = new MenuScreen(gameWindow);
	//std::cout << myWorldClass.GetLocVal(2,2);
	
	char gameState = 0;
	sf::Clock gameClock;
	float currentTime = 0;
	float waitTime = 0;

	while (gameWindow.isOpen()) //The "Game Loop"...
	{
		currentTime += gameClock.restart().asSeconds();
		if (currentTime > 0.03)
		{
			
			gameWindow.clear();
			if(gameState == 1)
			{
				pointerToWorldClass->Draw(pointerToPlayerClass->GetPosition(), pointerToPlayerClass->CalculateOffset());			
				pointerToFishList->Update(currentTime, pointerToPlayerClass->GetOffset().x, pointerToPlayerClass->GetOffset().y, pointerToPlayerClass->GetPosition().x, pointerToPlayerClass->GetPosition().y);
				pointerToPlayerClass->Draw();
				if(pointerToPlayerClass->Update(currentTime))
				{
					if(!pointerToFishList->CheckDeletions() && pointerToPlayerClass->GetCargo())
					{
						pointerToPlayerClass->SetFishing(pointerToFishList->CompareLocs(pointerToPlayerClass->GetPosition()));
					}
					if(pointerToPlayerClass->SetShopping(pointerToWorldClass->GetLocVal(pointerToPlayerClass->GetPosition().x, pointerToPlayerClass->GetPosition().y) == 19))
					{
						if(pointerToShopClass->Update())
						{
							if(pointerToShopClass->GetOption() == 1)
							{
								pointerToShopClass->AdjustMoney(pointerToPlayerClass->SellFish());
							}
							else if(pointerToShopClass->GetOption() == 6)
							{
								pointerToPlayerClass->SetShopping(false);
							}
							else if(pointerToShopClass->GetOption() > 0 && pointerToShopClass->GetOption() != 2)
							{
								pointerToPlayerClass->Upgrade(pointerToShopClass->GetOption());
							}

						}
					
					}
				
				
				}
				if(pointerToPlayerClass->GetPosition().x  == 75 && pointerToPlayerClass->GetPosition().y == 25)
				{
					gameState = 2;
					pointerToMenuScreen->SetScreen(3);
				}
			}
			else if(gameState == 0)
			{
				if(pointerToMenuScreen->Update() > 1)
				{
					gameState = 1;
					pointerToWorldClass = new WorldClass(gameWindow);
					pointerToFishList = new FishList(gameWindow, *pointerToWorldClass);
					pointerToPlayerClass = new PlayerClass(gameWindow, *pointerToWorldClass, *pointerToFishList);
					pointerToShopClass = new ShopScreenClass(gameWindow);
					pointerToMenuScreen = new MenuScreen(gameWindow);
				}
			}
			else if(gameState == 2)
			{
				waitTime += currentTime;
				pointerToMenuScreen->Update();
				if(waitTime > 3)
				{
					waitTime = 0;
					pointerToMenuScreen->SetScreen(0);
					gameState = 0;
				}
			}
			gameWindow.display();
			currentTime -= currentTime;
		}
	}
}
