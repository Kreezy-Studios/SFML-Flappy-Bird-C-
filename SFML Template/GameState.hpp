#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"

#include "Collision.hpp"
#include "Flash.hpp"
#include "GameOverState.hpp"

namespace Kreezy {
    class GameState : public State {
    public:
	  GameState(GameDataRef data);

	  void Init();

	  void HandleInput();
	  void Update(float dt);
	  void Draw(float dt);

	  void GameOver();
	  

	  const int &GetScore() const;

    private:
	  GameDataRef _data;

	  sf::Sprite _background;
	  sf::Text _scoreText;

	  sf::Clock _clock;
	  sf::Clock _startTime;
	  sf::Clock _endTime;

	  Pipe *pipe;
	  Land *land;
	  Bird *bird;
	  Flash *flash;

	  Collision collision;

	  int _gameState;
	  int _score;
    };
}