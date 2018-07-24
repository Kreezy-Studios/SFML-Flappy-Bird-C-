#pragma once

#include "SFML/Graphics.hpp"

namespace Kreezy {
    class Collision {
	  public:
		Collision();

		bool CheckSpriteCollision(sf::Sprite spriteOne, sf::Sprite spriteTwo);
		bool CheckSpriteCollision(sf::Sprite spriteOne, float scaleOne, sf::Sprite spriteTwo, float scaleTwo);
    };
}