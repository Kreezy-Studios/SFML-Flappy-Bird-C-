#include "Pipe.hpp"
#include "Definitions.hpp"

#include <iostream>

namespace Kreezy {
    Pipe::Pipe(GameDataRef data) : _data(data) {
	  _landHeight = _data->assets.GetTexture("land").getSize().y;
	  _pipeSpawnYOffest = 0;
    }

    void Pipe::SpawnBottomPipe() {
	  sf::Sprite sprite(_data->assets.GetTexture("pipeUp"));

	  sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffest);
	  pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnTopPipe() {
	  sf::Sprite sprite(_data->assets.GetTexture("pipeDown"));

	  sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffest);
	  pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnInvisiblePipe() {
	  sf::Sprite sprite(_data->assets.GetTexture("pipeDown"));

	  sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffest);
	  sprite.setColor(sf::Color(0, 0, 0, 0));

	  pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnScorePipe() {
	  sf::Sprite sprite(_data->assets.GetTexture("pipeDown"));

	  sprite.setPosition(_data->window.getSize().x + sprite.getGlobalBounds().width, -_pipeSpawnYOffest + sprite.getGlobalBounds().height);
	  scoreSprites.push_back(sprite);
    }

    void Pipe::MovePipes(float dt) {
	  for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
		float movement = PIPE_MOVEMENT_SPEED * dt;
		pipeSprites.at(i).move(-movement, 0);

		if (pipeSprites.at(i).getPosition().x < (0 - pipeSprites.at(i).getGlobalBounds().width)) {
		    pipeSprites.erase(pipeSprites.begin() + i);
		}
	  }

	  for (unsigned short int i = 0; i < scoreSprites.size(); i++) {
		float movement = PIPE_MOVEMENT_SPEED * dt;
		scoreSprites.at(i).move(-movement, 0);

		if (scoreSprites.at(i).getPosition().x < (0 - scoreSprites.at(i).getGlobalBounds().width)) {
		    scoreSprites.erase(scoreSprites.begin() + i);
		}
	  }
    }

    void Pipe::RandomizePipeOffset() {
	  _pipeSpawnYOffest = rand() % (_landHeight + 1);
    }

    void Pipe::DrawPipes() {
	 for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
		_data->window.draw(pipeSprites.at(i));
	 }
    }

    void Pipe::RemoveScorePipe(int i) {
	  scoreSprites.erase(scoreSprites.begin() + i);
    }

    const std::vector<sf::Sprite> &Pipe::GetPipes() const {
	  return pipeSprites;
    }

    const std::vector<sf::Sprite> &Pipe::GetScorePipes() const {
	  return scoreSprites;
    }
}