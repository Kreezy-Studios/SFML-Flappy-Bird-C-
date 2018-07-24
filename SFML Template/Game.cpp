#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Game.hpp"
#include "SplashState.hpp"

namespace Kreezy {
    Game::Game(int width, int height, std::string title) {
	  srand(time(NULL));

	  _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	  _data->machine.AddState(StateRef(new SplashState(this->_data)));

	  this->Run();
    }

    void Game::Run() {
	  float newTime, frameTime, interpolation;

	  float curTime = this->_clock.getElapsedTime().asSeconds();
	  float accumulator = 0.0f;

	  while (this->_data->window.isOpen()) {
		this->_data->machine.ProcessStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - curTime;

		if (frameTime > 0.25f) {
		    frameTime = 0.25f;
		}

		curTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
		    this->_data->machine.GetActiveState()->HandleInput();
		    this->_data->machine.GetActiveState()->Update(dt);

		    accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw(interpolation);
	  }
    }
}