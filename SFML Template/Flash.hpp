#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Definitions.hpp"

namespace Kreezy {
    class Flash {
	  public:
		Flash(GameDataRef data);

		void Show(float dt);
		void DrawFlash();

	  private:
		GameDataRef _data;

		sf::RectangleShape _shape;

		bool _flashOn;
    };
}