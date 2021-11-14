#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2c.h"

class WorldClass
{
public:
	WorldClass(sf::RenderWindow &myWindow);
	~WorldClass(void);

	char GetLocVal(char X, char Y);
	void SetLocVal(int X, int Y, int newVal);
	void Draw(Vector2c playerPos, Vector2c screenOffset);
	void Initialise();
	bool GetSailable(char X, char Y, char engineQuality);

private:
	sf::RenderWindow *myWindow;

	sf::Texture arch;
	sf::Texture shopLeft;
	sf::Texture bot;
	sf::Texture botLeft;
	sf::Texture botRight;
	sf::Texture land;
	sf::Texture left;
	sf::Texture right;
	sf::Texture top;
	sf::Texture topLeft;
	sf::Texture topRight;
	sf::Texture openSea;
	sf::Texture openSea1;
	sf::Texture openSea2;
	sf::Texture openSea3;

	sf::Sprite worldTextures[26];


	
	char  gameWorld[100][100];

};

