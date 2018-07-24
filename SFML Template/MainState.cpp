#include <sstream>
#include <iostream>

#include "MainState.hpp"
#include "GameState.hpp"
#include "Definitions.hpp"

namespace Kreezy {
    MainState::MainState(GameDataRef data) : _data(data) {

    }

    void MainState::Init() {
	  _data->assets.LoadTexture("mainBackground", MAIN_STATE_BACKGROUND_FILEPATH);
	  _data->assets.LoadTexture("gameTitle", GAME_TITLE_FILEPATH);
	  _data->assets.LoadTexture("playButton", PLAY_BUTTON_FILEPATH);

	  _background.setTexture(this->_data->assets.GetTexture("mainBackground"));
	  _title.setTexture(this->_data->assets.GetTexture("gameTitle"));
	  _playButton.setTexture(this->_data->assets.GetTexture("playButton"));

	  _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
	  _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
    }

    void MainState::HandleInput() {
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

    void MainState::Update(float dt) {

    }

    void MainState::Draw(float dt) {
	  _data->window.clear(sf::Color::Red);

	  _data->window.draw(_background);
	  _data->window.draw(_title);
	  _data->window.draw(_playButton);

	  _data->window.display();
    }
}