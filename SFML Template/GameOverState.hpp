#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"

namespace Kreezy {
    class GameOverState : public State {
    public:
	  GameOverState(GameDataRef data);

	  void Init();

	  void HandleInput();
	  void Update(float dt);
	  void Draw(float dt);

    private:
	  GameDataRef _data;

	  StateRef _gameState;

	  sf::Sprite _background;
	  sf::Sprite _title;
	  sf::Sprite _body;
	  sf::Sprite _playButton;

	  sf::Text _scoreText;
	  sf::Text _bestText;
    };
}