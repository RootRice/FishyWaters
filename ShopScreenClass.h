#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2c.h"
class ShopScreenClass
{
public:
	ShopScreenClass(sf::RenderWindow& myWindow);
	~ShopScreenClass(void);

	bool Update();
	void AdjustMoney(int fishAmount);
	bool GetActive();
	char GetOption();
private:
	sf::RenderWindow* myWindow;


	sf::Font arialFont;

	

	sf::Texture moneyTexture;
	sf::Texture shopTexture;
	sf::Texture glowTexture;

	void Draw();
	bool CheckKeys();

	bool shopActive;

	int money;

	int prices[3];

	char currentOption;
	char currentScreen;
	char transaction;
};

