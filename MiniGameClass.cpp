#include "MiniGameClass.h"
#include <iostream>


MiniGameClass::MiniGameClass(char difficulty, sf::RenderWindow& myWindow)
{
	float calculateKeys;
	float valHolder = difficulty;
	this-> difficulty = difficulty;
	calculateKeys = (1.0f/valHolder)*4.0f;
	numberOfInputs = calculateKeys;
	if(numberOfInputs <= 0)
	{
		numberOfInputs = 1;
	}

	this->myWindow = &myWindow;
	
	currentTime =  0;
	keyToPress = rand() %3;
	if (!upArrow.loadFromFile("Assets/UpArrow.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!leftArrow.loadFromFile("Assets/LeftArrow.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!downArrow.loadFromFile("Assets/DownArrow.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!rightArrow.loadFromFile("Assets/RightArrow.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	arrowSprite.setOrigin(16,16);
	arrowSprite.setPosition(512, 330);

	
}


MiniGameClass::~MiniGameClass(void)
{
}


char MiniGameClass::Update(float elapsedTime)
{
	currentTime+= elapsedTime;
	if(currentTime > difficulty)
	{
		return 11;
	}
	Draw();
	return CheckInputs();
}

char MiniGameClass::CheckInputs()
{
	sf::Event event;
	sf::Keyboard::Key keyList[4] =
	{
		sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down
	};
	while (myWindow->pollEvent(event))
	{

		if (sf::Keyboard::isKeyPressed(keyList[keyToPress]))
		{
			keyToPress = rand()%3;
			currentTime = 0;
			numberOfInputs -= 1;
			return numberOfInputs;

		}
		else if(sf::Keyboard::isKeyPressed(keyList[0]))
		{
			return 11;
		}
		else if(sf::Keyboard::isKeyPressed(keyList[1]))
		{
			return 11;
		}
		else if(sf::Keyboard::isKeyPressed(keyList[2]))
		{
			return 11;
		}
		else if(sf::Keyboard::isKeyPressed(keyList[3]))
		{
			return 11;
		}


	}
	return 10;
}

void MiniGameClass::Draw()
{
	sf::Texture arrowTextures[4];
	arrowTextures[0] = leftArrow;
	arrowTextures[1] = rightArrow;
	arrowTextures[2] = upArrow;
	arrowTextures[3] = downArrow;

	arrowSprite.setTexture(arrowTextures[keyToPress]);

	myWindow->draw(arrowSprite);


}