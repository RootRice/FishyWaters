#include "Animator.h"


Animator::Animator(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this -> imageCount = imageCount;
	this -> switchTime = switchTime;
	totalTime = 0;

	currentImage.x = 0;

	uvRect.width = texture->getSize().x / imageCount.x;
	uvRect.height = texture->getSize().y / imageCount.y;
}

Animator::~Animator()
{
}

bool Animator::GetAnimationEnd(int rowMax)
{
	if (currentImage.x == rowMax)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Animator::Reset()
{

	currentImage.x = 0;

}

void Animator::Update(int row, float deltaTime, int rowMax)
{

	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{

		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= rowMax)
		{

			currentImage.x = 0;

		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}
