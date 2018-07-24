#include "Collision.hpp"

namespace Kreezy {
    Collision::Collision() {

    }

    bool Collision::CheckSpriteCollision(sf::Sprite spriteOne, sf::Sprite spriteTwo) {
	  sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
	  sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();

	  return rectOne.intersects(rectTwo);
    }

    bool Collision::CheckSpriteCollision(sf::Sprite spriteOne, float scaleOne, sf::Sprite spriteTwo, float scaleTwo) {
	  spriteOne.setScale(scaleOne, scaleOne);
	  spriteTwo.setScale(scaleTwo, scaleTwo);

	  sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
	  sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();

	  return rectOne.intersects(rectTwo);
    }
}