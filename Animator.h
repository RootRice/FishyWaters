#pragma once
#include <SFML\Graphics.hpp>
class Animator
{
public:
	Animator(sf::Texture* texture, sf::Vector2u myImageCount, float mySwitchTime);
	~Animator();

	void Update(int row, float deltaTime, int rowMax);
	void Reset();
	bool GetAnimationEnd(int);
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

	

};
