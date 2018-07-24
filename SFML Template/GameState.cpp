#include <sstream>
#include <iostream>

#include "GameState.hpp"
#include "Definitions.hpp"

namespace Kreezy {
    GameState::GameState(GameDataRef data) : _data(data) {

    }

    void GameState::Init() {
	  _data->assets.LoadTexture("splashBackground", GAME_BACKGROUND_FILEPATH);

	  _data->assets.LoadTexture("pipeUp", PIPE_UP_FILEPATH);
	  _data->assets.LoadTexture("pipeDown", PIPE_DOWN_FILEPATH);

	  _data->assets.LoadTexture("land", LAND_FILEPATH);

	  _data->assets.LoadTexture("bird01", BIRD_FRAME_1_FILEPATH);
	  _data->assets.LoadTexture("bird02", BIRD_FRAME_2_FILEPATH);
	  _data->assets.LoadTexture("bird03", BIRD_FRAME_3_FILEPATH);
	  _data->assets.LoadTexture("bird04", BIRD_FRAME_4_FILEPATH);

	  _data->assets.LoadFont("arial", GAME_FONT_ARIAL_FILEPATH);

	  pipe = new Pipe(_data);
	  land = new Land(_data);
	  bird = new Bird(_data);
	  flash = new Flash(_data);

	  _background.setTexture(this->_data->assets.GetTexture("splashBackground"));
	  
	  _scoreText.setFont(this->_data->assets.GetFont("arial"));
	  _scoreText.setCharacterSize(25);
	  _scoreText.setStyle(sf::Text::Bold);
	  _scoreText.setFillColor(sf::Color::White);
	  _scoreText.setString("Score: 0");
	  _scoreText.setPosition((SCREEN_WIDTH / 2) - (_scoreText.getGlobalBounds().width / 2), 20);

	  _gameState = GameStates::STATE_READY;
	  _score = 0;
    }

    void GameState::GameOver() {
	  _gameState = GameStates::STATE_GAME_OVER;
	  _endTime.restart();
    }

    void GameState::HandleInput() {
	  sf::Event event;

	  while (_data->window.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
		    _data->window.close();
		}

		if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
		    if (_startTime.getElapsedTime().asSeconds() > GAME_START_TIME) {
			  if (_gameState != GameStates::STATE_GAME_OVER) {
				_gameState = GameStates::STATE_PLAYING;
				bird->Tap();
			  }
		    }
		}
	  }
    }

    void GameState::Update(float dt) {
	  if (_gameState != GameStates::STATE_GAME_OVER) {
		bird->Animate(dt);
		land->MoveLand(dt);
	  } else {
		if (_endTime.getElapsedTime().asSeconds() > 2.5f) {
		    _data->machine.AddState(StateRef(new GameOverState(_data)));
		}
	  }

	  if (_gameState == GameStates::STATE_PLAYING) {
		bird->Update(dt);
		pipe->MovePipes(dt);

		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {

		    pipe->RandomizePipeOffset();

		    pipe->SpawnInvisiblePipe();
		    pipe->SpawnTopPipe();
		    pipe->SpawnScorePipe();
		    pipe->SpawnBottomPipe();

		    _clock.restart();
		}
	  }

	  if (_gameState != GameStates::STATE_GAME_OVER) {
		std::vector<sf::Sprite> landSprites = land->GetSprites();

		for (unsigned int i = 0; i < landSprites.size(); i++) {
		    if (collision.CheckSpriteCollision(bird->GetSprite(), BIRD_SCALE - 0.35f, landSprites.at(i), 1.0f)) {
			  std::cout << "Game over!" << std::endl;
			  GameOver();
		    }
		}

		std::vector<sf::Sprite> pipes = pipe->GetPipes();

		for (unsigned int i = 0; i < pipes.size(); i++) {
		    if (collision.CheckSpriteCollision(bird->GetSprite(), BIRD_SCALE - 0.35f, pipes.at(i), 1.0f)) {
			  std::cout << "Game over!" << std::endl;
			  GameOver();
		    }
		}

		std::vector<sf::Sprite> scorePipes = pipe->GetScorePipes();

		for (unsigned int i = 0; i < scorePipes.size(); i++) {
		    if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scorePipes.at(i), 1.0f)) {
			  _score += 1;

			  _scoreText.setString("Score: " + std::to_string(_score));
			  _scoreText.setPosition((SCREEN_WIDTH / 2) - (_scoreText.getGlobalBounds().width / 2), 20);

			  pipe->RemoveScorePipe(i);
		    }
		}
	  } else {
		flash->Show(dt);
	  }
    }

    const int &GameState::GetScore() const {
	  return _score;
    }

    void GameState::Draw(float dt) {
	  _data->window.clear(sf::Color::Red);

	  _data->window.draw(_background);

	  pipe->DrawPipes();
	  land->DrawLand();
	  bird->DrawBird();
	  flash->DrawFlash();

	  _data->window.draw(_scoreText);
	  _data->window.display();
    }
}