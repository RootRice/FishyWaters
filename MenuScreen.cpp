#include "MenuScreen.h"


MenuScreen::MenuScreen(sf::RenderWindow& myWindow)
{
	this -> myWindow = &myWindow;
	if(!optionsTexture.loadFromFile("Assets/ControlsBackground.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!mainTexture.loadFromFile("Assets/MainBackground.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!winTexture.loadFromFile("Assets/WinBackground.png"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if(!arialFont.loadFromFile("Assets/arial.ttf"))
	{
		//cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}

	

	menuBoxes[0].setSize(sf::Vector2f(128,32));
	menuBoxes[0].setOrigin(64,64);
	menuBoxes[0].setPosition(myWindow.getSize().x/2, (myWindow.getSize().y/2));

	playText.setPosition(menuBoxes[0].getPosition().x -24, menuBoxes[0].getPosition().y -64 );
	playText.setFont(arialFont);
	playText.setString("Play");
	playText.setCharacterSize(24);
	playText.setFillColor(sf::Color::Black);

	menuBoxes[1].setSize(sf::Vector2f(128,32));
	menuBoxes[1].setOrigin(64,64);
	menuBoxes[1].setPosition(myWindow.getSize().x/2, (myWindow.getSize().y/2)+64);

	optionsText.setPosition(menuBoxes[1].getPosition().x -44, menuBoxes[1].getPosition().y -64 );
	optionsText.setFont(arialFont);
	optionsText.setString("Controls");
	optionsText.setCharacterSize(24);
	optionsText.setFillColor(sf::Color::Black);

	menuBoxes[2].setSize(sf::Vector2f(128,32));
	menuBoxes[2].setOrigin(64,64);
	menuBoxes[2].setPosition(myWindow.getSize().x/2, (myWindow.getSize().y/2)+128);

	exitText.setPosition(menuBoxes[2].getPosition().x -24, menuBoxes[2].getPosition().y -64 );
	exitText.setFont(arialFont);
	exitText.setString("Exit");
	exitText.setCharacterSize(24);
	exitText.setFillColor(sf::Color::Black);

	sf::RectangleShape menuBoxes[3] = {playBox, optionsBox, exitBox};

	

	currentOption = 0;
	currentScreen = 0;

}


MenuScreen::~MenuScreen(void)
{
}

char MenuScreen::Update()
{
	PollEvents();
	Draw();
	if(currentScreen == 2)
	{
		currentScreen = 0;
		return 2;
	}
	return currentScreen;
}

void MenuScreen::PollEvents()
{
	sf::Event event;
	while (myWindow->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) 
		{
			if (event.key.code == sf::Keyboard::Key::Down)
			{
				currentOption +=1;
				if (currentOption > 2)
				{
					currentOption = 0;
				}
			}
			else if(event.key.code == sf::Keyboard::Key::Up)
			{
				
				currentOption -=1;
				if (currentOption < 0)
				{
					currentOption = 2;
				}
			}
			else if(event.key.code == sf::Keyboard::Key::Return)
			{

				if(currentOption == 0)
				{
					currentScreen = 2;
				}
				else if(currentOption == 1)
				{
					if(currentScreen == 1)
					{
						currentScreen = 0;	
					}
					else
					{
						currentScreen = 1;
					}
				}
				else
				{
					myWindow->close();
				}
				
			}			
		}
	}
}
void MenuScreen::SetScreen(char screenToSet)
{
	currentScreen = screenToSet;
}
void MenuScreen::Draw()
{
	sf::Sprite backGround;
	backGround.setScale(0.75,0.75);
	if (currentScreen == 0)
	{
		backGround.setTexture(mainTexture);
		myWindow->draw(backGround);

		menuBoxes[0].setFillColor(sf::Color::White);
		menuBoxes[1].setFillColor(sf::Color::White);
		menuBoxes[2].setFillColor(sf::Color::White);

		menuBoxes[currentOption].setFillColor(sf::Color::Green);

		myWindow->draw(menuBoxes[0]);
		myWindow->draw(menuBoxes[1]);
		myWindow->draw(menuBoxes[2]);

		myWindow->draw(playText);
		myWindow->draw(optionsText);
		myWindow->draw(exitText);
	}
	else if(currentScreen==1)
	{
		backGround.setTexture(optionsTexture);
		myWindow->draw(backGround);
	}
	else if(currentScreen == 3)
	{
		backGround.setTexture(winTexture);
		myWindow->draw(backGround);
	}
}

