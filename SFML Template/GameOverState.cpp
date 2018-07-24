#include <sstream>
#include <iostream>

#include "GameOverState.hpp"
#include "Definitions.hpp"

namespace Kreezy {
    GameOverState::GameOverState(GameDataRef data) : _data(data) {

    }

    void GameOverState::Init() {
	  _data->assets.LoadTexture("background", GAME_OVER_BACKGROUND_FILEPATH);
	  _data->assets.LoadTexture("title", GAME_OVER_TITLE_FILEPATH);
	  _data->assets.LoadTexture("body", GAME_OVER_BODY_FILEPATH);
	  _data->assets.LoadTexture("playButton", GAME_OVER_PLAY_FILEPATH);

	  _background.setTexture(this->_data->assets.GetTexture("background"));
	  _title.setTexture(this->_data->assets.GetTexture("title"));
	  _body.setTexture(this->_data->assets.GetTexture("body"));
	  _playButton.setTexture(this->_data->assets.GetTexture("playButton"));

	  _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
	  _body.setPosition((SCREEN_WIDTH / 2) - (_body.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_body.getGlobalBounds().height / 2));
	  _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), SCREEN_HEIGHT - _playButton.getGlobalBounds().height - 50);

	  _scoreText.setFont(this->_data->assets.GetFont("arial"));
	  _scoreText.setCharacterSize(45);
	  _scoreText.setStyle(sf::Text::Bold);
	  _scoreText.setFillColor(sf::Color::White);
	  _scoreText.setString("0");
	  _scoreText.setPosition((SCREEN_WIDTH / 2) + (_body.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2);
    }

    void GameOverState::HandleInput() {
	  sf::Event event;

	  while (_data->window.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
		    _data->window.close();
		}

		if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
		    _data->machine.AddState(StateRef(new GameState(_data)));
		}
	  }
    }

    void GameOverState::Update(float dt) {

    }

    void GameOverState::Draw(float dt) {
	  _data->window.clear(sf::Color::Red);

	  _data->window.draw(_background);
	  _data->window.draw(_title);
	  _data->window.draw(_body);
	  _data->window.draw(_playButton);

	  _data->window.display();
    }
}