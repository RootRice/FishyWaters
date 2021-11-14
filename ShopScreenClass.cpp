#include "ShopScreenClass.h"


ShopScreenClass::ShopScreenClass(sf::RenderWindow& myWindow)
{

	this -> myWindow = &myWindow;
	if(!arialFont.loadFromFile("Assets/arial.ttf"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!moneyTexture.loadFromFile("Assets/MoneyTexture.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!shopTexture.loadFromFile("Assets/ShopTexture.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!glowTexture.loadFromFile("Assets/GlowTexture.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	currentOption = 0;
	money = 0;

	prices[0] = 1000;
	prices[1] = 1000;
	prices[2] = 1000;

	shopActive = false;
}


ShopScreenClass::~ShopScreenClass(void)
{
}


bool ShopScreenClass::Update()
{
	if(currentOption == 0)
	{
		shopActive = true;
		currentOption = 1;
		return false;
	}
	Draw();
	if (CheckKeys())
	{
		if(currentOption < 3)
		{
			transaction = currentOption;
			return true;
		}
		else if(currentOption == 6)
		{
			transaction = 6;
			shopActive = false;
			return true;
		}
		else
		{
			if(prices[currentOption-3] <= money)
			{
	
					money -= prices[currentOption-3];
					transaction = currentOption;
					prices[currentOption-3] += 1000;
					if(prices[currentOption-3] > 3000)
					{
						prices[currentOption-3] = 999999;
					}
					return true;
				
			}
		}
		
	}
	return false;
	

}

void ShopScreenClass::AdjustMoney(int adjustAmount)
{
	money += adjustAmount;	
}

bool ShopScreenClass::CheckKeys()
{
	char valHolder;
	sf::Event event;
	while (myWindow->pollEvent(event))
	{

		if (event.type == sf::Event::KeyReleased) 
		{
			if (event.key.code == sf::Keyboard::Key::Up) //Up
			{
				
				currentOption -= 1;
				if (currentOption < 1)
				{
					currentOption = 6;
				}
				
			}
			else if (event.key.code == sf::Keyboard::Key::Down) //Down
			{
			
				currentOption += 1;
				if (currentOption > 6)
				{
					currentOption = 1;
				}	

			}
			else if (event.key.code == sf::Keyboard::Key::Space) //Space
			{

				return true;
				
			}
		}
	}
	return false;

}

void ShopScreenClass::Draw()
{
	sf::Sprite moneySprite;
	sf::Sprite shopSprite;
	sf::Sprite glowSprite;

	sf::Text moneyText;
	sf::Text repairText;
	sf::Text sellText;
	sf::Text engineText;
	sf::Text rodText;
	sf::Text hullText;

	sf::Vector2f glowPositions[6] = {sf::Vector2f(120, 74), sf::Vector2f(120, 168), sf::Vector2f(590, 234), sf::Vector2f(590, 354), sf::Vector2f(590, 472), sf::Vector2f(590, 618)};


	moneySprite.setPosition(0, 640);
	moneySprite.setTexture(moneyTexture);
	myWindow->draw(moneySprite);

	shopSprite.setTexture(shopTexture);
	myWindow->draw(shopSprite);
	glowSprite.setTexture(glowTexture);
	glowSprite.setPosition(glowPositions[currentOption-1]);
	myWindow->draw(glowSprite);

	moneyText.setString(std::to_string(money));
	moneyText.setCharacterSize(24);
	moneyText.setFont(arialFont);
	moneyText.setColor(sf::Color::Black);
	moneyText.setPosition(140,670);
	myWindow->draw(moneyText);

	engineText.setString(std::to_string(prices[0]));
	engineText.setCharacterSize(24);
	engineText.setFont(arialFont);
	engineText.setColor(sf::Color::Black);
	engineText.setPosition(758,260);
	myWindow->draw(engineText);

	rodText.setString(std::to_string(prices[1]));
	rodText.setCharacterSize(24);
	rodText.setFont(arialFont);
	rodText.setColor(sf::Color::Black);
	rodText.setPosition(708,380);
	myWindow->draw(rodText);

	hullText.setString(std::to_string(prices[2]));
	hullText.setCharacterSize(24);
	hullText.setFont(arialFont);
	hullText.setColor(sf::Color::Black);
	hullText.setPosition(708,500);
	myWindow->draw(hullText);
}

char ShopScreenClass::GetOption()
{
	char returnVal = transaction;
	return returnVal;
}