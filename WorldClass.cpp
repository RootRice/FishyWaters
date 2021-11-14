#include "WorldClass.h"
#include <iostream>


WorldClass::WorldClass(sf::RenderWindow &myWindow)
{
	this -> myWindow = &myWindow;
	//Initialise();
	if (!land.loadFromFile("Assets/land.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!arch.loadFromFile("Assets/arch.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!bot.loadFromFile("Assets/bot.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!botLeft.loadFromFile("Assets/botLeft.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!botRight.loadFromFile("Assets/botRight.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!left.loadFromFile("Assets/left.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!shopLeft.loadFromFile("Assets/shopLeft.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!openSea.loadFromFile("Assets/openSea.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!openSea1.loadFromFile("Assets/openSea1.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!openSea2.loadFromFile("Assets/openSea2.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!openSea3.loadFromFile("Assets/openSea3.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!right.loadFromFile("Assets/right.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!top.loadFromFile("Assets/top.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!topLeft.loadFromFile("Assets/topLeft.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}
	if (!topRight.loadFromFile("Assets/topRight.png")) //The "Player" Image...
	{
		std::cout << "Error 1: Loading The Game Image(s) Failed. Make Sure ALL Images Are 8-bit-RGBA Images..." << "\n";
		system("pause");
	}

	Initialise();

}


WorldClass::~WorldClass(void)
{
}

char WorldClass::GetLocVal(char X, char Y)
{
	return gameWorld[Y][X];
}

void WorldClass::Initialise()
{
	srand(time(NULL));
	char i;
	char j;
	char k;
	char l;
	char horizontalBar;
	char verticalBar;
	char area1Chunks;
	char area2Chunks;
	char area3Chunks;
	char area4Chunks;

	char emptySea[5][5] =
	{
		{00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00},
		{00, 00, 00, 00, 00}
	};

	char tiles[16][5][5] =
	{
		{
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 18, 11, 12, 00},
			{00, 17, 20, 13, 00},
			{00, 16, 15, 14, 00}
		},
		{
			{00, 00, 18, 11, 12},
			{00, 00, 17, 20, 13},
			{00, 00, 16, 15, 14},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 18, 11, 12, 00},
			{00, 17, 20, 13, 00},
			{00, 16, 15, 14, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 18, 11, 12},
			{00, 00, 17, 20, 13},
			{00, 00, 16, 15, 14}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 00, 18, 11, 12},
			{00, 00, 17, 20, 13},
			{00, 00, 16, 15, 14}
		},
		{
			{00, 25, 00, 00, 00},
			{00, 00, 00, 25, 00},
			{25, 00, 00, 00, 00},
			{00, 00, 00, 00, 25},
			{00, 25, 00, 00, 00}
		},
		{
			{25, 00, 00, 25, 00},
			{00, 25, 00, 00, 00},
			{00, 00, 00, 25, 00},
			{00, 00, 00, 00, 00},
			{00, 25, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{25, 00, 25, 00, 00},
			{00, 00, 00, 00, 00},
			{00, 25, 00, 25, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 25, 00, 25, 00},
			{00, 00, 00, 00, 00},
			{00, 25, 00, 25, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 00, 25, 00, 25},
			{00, 00, 00, 00, 00},
			{25, 00, 25, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{18, 11, 11, 11, 12},
			{17, 20, 20, 20, 13},
			{16, 15, 15, 15, 14},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 18, 11, 12, 00},
			{00, 17, 20, 13, 00},
			{00, 17, 20, 14, 00},
			{00, 16, 14, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{18, 12, 00, 00, 00},
			{17, 20, 12, 00, 00},
			{17, 20, 13, 00, 00},
			{16, 15, 15, 00, 00},
			{00, 00, 00, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{00, 18, 12, 00, 00},
			{00, 17, 13, 00, 00},
			{00, 17, 13, 00, 00},
			{00, 16, 14, 00, 00}
		},
		{
			{00, 00, 00, 00, 00},
			{18, 11, 11, 11, 12},
			{16, 15, 15, 15, 13},
			{00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00}
		},

	};
	
	char shopIsland_0[5][5] =
	{
		{00, 00, 00, 00, 00},
		{18, 11, 11, 12, 00},
		{19, 20, 20, 13, 00},
		{16, 15, 15, 14, 00},
		{00, 00, 00, 00, 00}
	};

	char shopIsland_1[5][5] =
	{
		{00, 18, 11, 12, 00},
		{00, 17, 20, 13, 00},
		{00, 19, 20, 13, 00},
		{00, 16, 15, 14, 00},
		{00, 00, 00, 00, 00}
	};

	char shopIsland_2[5][5] =
	{
		{00, 00, 00, 00, 00},
		{00, 18, 12, 00, 00},
		{00, 19, 13, 00, 00},
		{00, 16, 14, 00, 00},
		{00, 00, 00, 00, 00}
	};

	char horizontalBoundary[5][5] =
	{
		{11, 11, 11, 11, 11},
		{20, 20, 20, 20, 20},
		{20, 20, 20, 20, 20},
		{20, 20, 20, 20, 20},
		{15, 15, 15, 15, 15}
	};

	char verticalBoundary[5][5] =
	{
		{17, 20, 20, 20, 13},
		{17, 20, 20, 20, 13},
		{17, 20, 20, 20, 13},
		{17, 20, 20, 20, 13},
		{17, 20, 20, 20, 13}
	};

	char intersectionBoundary[5][5] =
	{
		{18, 20, 20, 20, 12},
		{20, 20, 20, 20, 20},
		{20, 20, 20, 20, 20},
		{20, 20, 20, 20, 20},
		{16, 20, 20, 20, 14}
	};

	char horizontalOpening[5][5] =
	{
		{11, 12, 00, 18, 11},
		{20, 13, 00, 17, 20},
		{20, 13, 00, 17, 20},
		{20, 13, 00, 17, 20},
		{15, 14, 00, 16, 15}
	};

	char verticalOpening[5][5] =
	{
		{17, 20, 20, 20, 13},
		{16, 15, 15, 15, 14},
		{00, 00, 00, 00, 00},
		{18, 11, 11, 11, 12},
		{17, 20, 20, 20, 13}
	};

	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			gameWorld[i][j] = 0;
		}
	}
	horizontalBar = rand() %10+5;
	verticalBar = rand() %10+5;
	char calcSaverI;
	char calcSaverJ;
	char randSaver;
	
	j = 0;
	l = 0;
	for (i = 0; i < horizontalBar; j++)
	{
		l = calcSaverJ = (j*5);
		k = calcSaverI = (i*5);
		randSaver = rand()%30;
		if(randSaver > 15)
		{
			randSaver = 0;
		}
			for(k; k < calcSaverI+5; l++)
			{
				if(l == calcSaverJ+5)
				{
					
					k++;
					l = calcSaverJ;
					if (k == calcSaverI+5)
					{
						break;
					}
				}
				gameWorld[k][l] = tiles[randSaver][k-calcSaverI][l-calcSaverJ];		

			}
		
		if(j == verticalBar)
		{
			i++;
			j = 0;
		}
	}
	j = 0;
	l = 0;
	for (i = horizontalBar+1; i < 20; j++)
	{
		l = calcSaverJ = (j*5);
		k = calcSaverI = (i*5);
		randSaver = rand()%45;
		if(randSaver > 15)
		{
			randSaver = 0;
		}
			for(k; k < calcSaverI+5; l++)
			{
				if(l == calcSaverJ+5)
				{
					
					k++;
					l = calcSaverJ;
					if (k == calcSaverI+5)
					{
						break;
					}
				}
				gameWorld[k][l] = tiles[randSaver][k-calcSaverI][l-calcSaverJ];		

			}
		
		if(j == verticalBar)
		{
			i++;
			j = 0;
		}
	}
	j = verticalBar+1;
	l = 0;
	for (i = 0; i < horizontalBar; j++)
	{
		l = calcSaverJ = (j*5);
		k = calcSaverI = (i*5);
		randSaver = rand()%60;
		if(randSaver > 15)
		{
			randSaver = 0;
		}
			for(k; k < calcSaverI+5; l++)
			{
				if(l == calcSaverJ+5)
				{
					
					k++;
					l = calcSaverJ;
					if (k == calcSaverI+5)
					{
						break;
					}
				}
				gameWorld[k][l] = tiles[randSaver][k-calcSaverI][l-calcSaverJ];		

			}
		
		if(j == 19)
		{
			i++;
			j = verticalBar+1;
		}
	}
	j = verticalBar+1;
	l = 0;
	for (i = 0; i < 20; j++)
	{
		l = calcSaverJ = (j*5);
		k = calcSaverI = (i*5);
		randSaver = rand()%100;
		if(randSaver > 15)
		{
			randSaver = 0;
		}
			for(k; k < calcSaverI+5; l++)
			{
				if(l == calcSaverJ+5)
				{
					
					k++;
					l = calcSaverJ;
					if (k == calcSaverI+5)
					{
						break;
					}
				}
				gameWorld[k][l] = tiles[randSaver][k-calcSaverI][l-calcSaverJ];		

			}
		
		if(j == 19)
		{
			i++;
			j = verticalBar+1;
		}
	}
	k = (rand()%verticalBar)*5;
	l= (rand()%horizontalBar)*5;
	j = k;
	for (i = l; i < l+5; j++)
	{
		
		gameWorld[i][j] = shopIsland_0[i - l][j - k];
		if(gameWorld[i][j] == 19)
		{
			int tellMe = 1;
		}
		if(j == k+4)
		{
			j = k-1;
			i++;
		}

	}

	k = (19 - rand()%verticalBar)*5;
	l= (19 - rand()%horizontalBar)*5;
	j = k;
	for (i = l; i < l+5; j++)
	{
		
		gameWorld[i][j] = shopIsland_0[i - l][j - k];
		if(gameWorld[i][j] == 19)
		{
			int tellMe = 1;
		}
		if(j == k+4)
		{
			j = k-1;
			i++;
		}

	}
	k = (19 - rand()%verticalBar)*5;
	l= (rand()%horizontalBar)*5;
	j = k;
	for (i = l; i < l+5; j++)
	{
		
		gameWorld[i][j] = shopIsland_0[i - l][j - k];
		if(gameWorld[i][j] == 19)
		{
			int tellMe = 1;
		}
		if(j == k+4)
		{
			j = k-1;
			i++;
		}

	}
	k = (rand()%verticalBar)*5;
	l= (19 - rand()%horizontalBar)*5;
	j = k;
	for (i = l; i < l+5; j++)
	{
		
		gameWorld[i][j] = shopIsland_0[i - l][j - k];
		if(gameWorld[i][j] == 19)
		{
			int tellMe = 1;
		}
		if(j == k+4)
		{
			j = k-1;
			i++;
		}

	}
	horizontalBar = horizontalBar*5;
	i = 0;
	k = horizontalBar;
	for (i = 0; i < 100; i+=5)
	{
		k = horizontalBar;
		for(l = i; k < horizontalBar+5; l++)
			{
				if(l == i+5)
				{
					
					k++;
					l = i;
					if (k == horizontalBar+5)
					{
						k = horizontalBar;
						break;
					}
				}
				gameWorld[k][l] = horizontalBoundary[k-horizontalBar][l-i];


			}

	}
	verticalBar = verticalBar*5;
	i = 0;
	k = verticalBar;
	for (i = 0; i < 100; i+=5)
	{
		k = verticalBar;
		for(l = i; k < verticalBar+5; l++)
			{
				if(l == i+5)
				{
					
					k++;
					l = i;
					if (k == verticalBar+5)
					{
						k = verticalBar;
						break;
					}
				}
				gameWorld[l][k] = verticalBoundary[l-i][k-verticalBar];


			}

	}

	k = horizontalBar;
	verticalBar = verticalBar/5;
	j = (rand() %verticalBar-1) * 5;
	l = j;
	for(k = horizontalBar; k < horizontalBar+5; l++)
	{
		if(l == j+5)
		{
					
			k++;
			l = j;
			if (k == horizontalBar+5)
			{
				k = horizontalBar;
				break;
			}
		}
		gameWorld[k][l] = horizontalOpening[k-horizontalBar][l-j];
	}

	verticalBar = verticalBar*5;
	horizontalBar = horizontalBar/5;
	j = (19-(rand() %horizontalBar)) * 5;
	l = j;
	for(k = verticalBar; k < verticalBar+5; l++)
	{
		if(l == j+5)
		{
					
			k++;
			l = j;
			if (k == verticalBar+5)
			{
				k = verticalBar;
				break;
			}
		}
		gameWorld[l][k] = verticalOpening[l-j][k-verticalBar];
	}

	horizontalBar = horizontalBar*5;
	j = verticalBar;
	l = j;
	for(k = horizontalBar; k < horizontalBar+5; l++)
	{
		if(l == j+5)
		{
			k++;
			l = j;
			if (k == horizontalBar+5)
			{
				k = horizontalBar;
				break;
			}
		}
		gameWorld[k][l] = intersectionBoundary[k-horizontalBar][l-j];

	}
	j = 0;
	for(i = horizontalBar; i < 100; j++)
	{
		if(gameWorld[i][j] == 0)
		{
			gameWorld[i][j] = 1;
		}
		if(j ==verticalBar)
		{
			j = -1;
			i++;
		}

	}
	j = verticalBar;
	for(i = horizontalBar; i<100; j++)
	{
		if(gameWorld[i][j] == 0)
		{
			gameWorld[i][j] = 2;
		}
		if(j == 99)
		{
			j = verticalBar-1;
			i++;
		}
	}
	j = verticalBar;
	for(i = horizontalBar; i>=0; j++)
	{
		if(gameWorld[i][j] == 0)
		{
			gameWorld[i][j] = 3;
		}
		if(j == 99)
		{
			j = verticalBar-1;
			i--;
		}
	}
	

	gameWorld[24][74] = 0;
	gameWorld[24][75] = 0;
	gameWorld[24][76] = 0;
	gameWorld[25][74] = 0;
	gameWorld[25][75] = 0;
	gameWorld[25][76] = 0;
	gameWorld[26][74] = 0;
	gameWorld[26][75] = 0;
	gameWorld[26][76] = 0;

	sf::Sprite texture0;
	sf::Sprite texture1;
	sf::Sprite texture2;
	sf::Sprite texture3;
	sf::Sprite texture4;
	sf::Sprite texture5;
	sf::Sprite texture6;
	sf::Sprite texture7;
	sf::Sprite texture8;
	sf::Sprite texture9;
	sf::Sprite texture10;
	sf::Sprite texture11;

	


	worldTextures[25].setOrigin(sf::Vector2f(32, 32));
	worldTextures[25].setTexture(arch);
	worldTextures[0] = texture0;
	worldTextures[1] = texture10;
	worldTextures[11] = texture1;
	worldTextures[12] = texture2;
	worldTextures[13] = texture3;
	worldTextures[14] = texture4;
	worldTextures[15] = texture5;
	worldTextures[16] = texture6;
	worldTextures[17] = texture7;
	worldTextures[18] = texture8;
	worldTextures[19] = texture9;
	worldTextures[20] = texture10;
	worldTextures[25] = texture11;



	worldTextures[0].setOrigin(sf::Vector2f(16, 16));
	worldTextures[0].setTexture(openSea);
	worldTextures[0].setScale(2,2);
	
	worldTextures[1].setOrigin(sf::Vector2f(16, 16));
	worldTextures[1].setTexture(openSea1);
	worldTextures[1].setScale(2,2);

	worldTextures[2].setOrigin(sf::Vector2f(16, 16));
	worldTextures[2].setTexture(openSea2);
	worldTextures[2].setScale(2,2);

	worldTextures[3].setOrigin(sf::Vector2f(16, 16));
	worldTextures[3].setTexture(openSea3);
	worldTextures[3].setScale(2,2);

	worldTextures[11].setOrigin(sf::Vector2f(16, 16));
	worldTextures[11].setTexture(top);
	worldTextures[11].setScale(2,2);

	worldTextures[12].setOrigin(sf::Vector2f(16, 16));
	worldTextures[12].setTexture(topRight);
	worldTextures[12].setScale(2,2);

	worldTextures[13].setOrigin(sf::Vector2f(16, 16));
	worldTextures[13].setTexture(right);
	worldTextures[13].setScale(2,2);

	worldTextures[14].setOrigin(sf::Vector2f(16, 16));
	worldTextures[14].setTexture(botRight);
	worldTextures[14].setScale(2,2);

	worldTextures[15].setOrigin(sf::Vector2f(16, 16));
	worldTextures[15].setTexture(bot);
	worldTextures[15].setScale(2,2);

	worldTextures[16].setOrigin(sf::Vector2f(16, 16));
	worldTextures[16].setTexture(botLeft);
	worldTextures[16].setScale(2,2);

	worldTextures[17].setOrigin(sf::Vector2f(16, 16));
	worldTextures[17].setTexture(left);
	worldTextures[17].setScale(2,2);

	worldTextures[18].setOrigin(sf::Vector2f(16, 16));
	worldTextures[18].setTexture(topLeft);
	worldTextures[18].setScale(2,2);


	worldTextures[19].setOrigin(sf::Vector2f(16, 16));
	worldTextures[19].setTexture(shopLeft);
	worldTextures[19].setScale(2,2);



	worldTextures[20].setOrigin(sf::Vector2f(16, 16));
	worldTextures[20].setTexture(land);
	worldTextures[20].setScale(2,2);

	worldTextures[25].setOrigin(sf::Vector2f(16, 16));
	worldTextures[25].setTexture(arch);
	worldTextures[25].setScale(2,2);
}

void WorldClass::Draw(Vector2c playerPos, Vector2c screenOffset)
{
	char xLoc;
	char yLoc;
	char xScreen = -4;
	char yScreen = -3;
	for (int i = playerPos.y - 8; i < playerPos.y + 8; i++)
	{
		yScreen++;
		if (i < 0)
		{

			yLoc = 100 - abs(i);

		}
		else if (i > 99)
		{

			yLoc = i - 100;

		}
		else
		{
			yLoc = i;
		}

		for (int j = playerPos.x - 11; j < playerPos.x + 11; j++)
		{
			if (xScreen < 19)
			{
				xScreen++;
			}
			else
			{
				xScreen = -2;
			}
			if (j < 0)
			{

				xLoc = 100 - abs(j);

			}
			else if (j > 99)
			{

				xLoc = j - 100;

			}
			else
			{

				xLoc = j;

			}

			worldTextures[gameWorld[yLoc][xLoc]].setPosition((xScreen * 64) + screenOffset.x , (yScreen * 64) + screenOffset.y );
			myWindow->draw(worldTextures[gameWorld[yLoc][xLoc]]);

			

		}
		
	}

}

bool WorldClass::GetSailable(char X, char Y, char engineQuality)
{
	char test = gameWorld[Y][X];
	if(X < 0)
	{
		X+=100;
	}
	if(Y < 0)
	{
		Y+=100;
	}
	if(gameWorld[Y][X] > 9 && gameWorld[Y][X] < 20)
	{
		return true;
	}
	else if(gameWorld[Y][X] <= engineQuality-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


