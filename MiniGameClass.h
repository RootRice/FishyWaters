#pragma once
#include <SFML/Graphics.hpp>

class MiniGameClass
{
public:
	MiniGameClass(char difficulty, sf::RenderWindow& myWindow);
	~MiniGameClass(void);

	char Update(float elapsedTime);
private:
	char CheckInputs();
	void Draw();

	sf::RenderWindow *myWindow;
	sf::Texture upArrow;
	sf::Texture rightArrow;
	sf::Texture leftArrow;
	sf::Texture downArrow;
	sf::Sprite arrowSprite;

	char difficulty;
	char keyToPress;
	char numberOfInputs;
	float currentTime;
};

