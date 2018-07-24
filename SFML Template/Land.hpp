#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

namespace Kreezy {
    class Land {
	  public:
		Land(GameDataRef land);

		void MoveLand(float dt);
		void DrawLand();

		const std::vector<sf::Sprite> &GetSprites() const;
	  
	  private:
		GameDataRef _data;

		std::vector<sf::Sprite> _landSprites;
    };
}