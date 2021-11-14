#pragma once
#include <SFML/Graphics.hpp>

class MenuScreen
{
public:
	MenuScreen(sf::RenderWindow& myWindow);
	~MenuScreen(void);


	char Update();
	void SetScreen(char);
private:
	sf::RenderWindow* myWindow;
	
	sf::Texture optionsTexture;
	sf::Texture mainTexture;
	sf::Texture winTexture;
	sf::Font arialFont;

	sf::RectangleShape Banner;
	sf::Text bannerText;

	sf::RectangleShape playBox;
	sf::Text playText;


	sf::RectangleShape optionsBox;
	sf::Text optionsText;

	sf::RectangleShape exitBox;
	sf::Text exitText;

	sf::RectangleShape menuBoxes[3];

	char currentOption;
	char currentScreen;

	void Draw();
	void PollEvents();


};

