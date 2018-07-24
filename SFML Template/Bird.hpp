#pragma once

#include <SFML/Graphics.hpp>

#include "Definitions.hpp"
#include "Game.hpp"

#include <vector>

namespace Kreezy {
    class Bird {
	  public:
		Bird(GameDataRef data);

		void DrawBird();

		void Animate(float dt);
		void Update(float dt);
		void Tap();

		const sf::Sprite &GetSprite() const;

	  private:
		GameDataRef _data;

		sf::Sprite _bird;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _curAnim;
		
		sf::Clock _clock;
		sf::Clock _movementClock;

		int _birdState;
		float _rotation;
    };
}