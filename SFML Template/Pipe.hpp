#pragma once

#include <SFML/Graphics.hpp>
#include <Vector>

#include "Game.hpp"

namespace Kreezy {
    class Pipe {
	  public:
		Pipe(GameDataRef data);

		void SpawnTopPipe();
		void SpawnBottomPipe();
		void SpawnInvisiblePipe();
		void SpawnScorePipe();
		void MovePipes(float dt);
		void RandomizePipeOffset();
		void RemoveScorePipe(int i);

		void DrawPipes();

		const std::vector<sf::Sprite> &GetPipes() const;
		const std::vector<sf::Sprite> &GetScorePipes() const;

	  private:
		GameDataRef _data;

		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoreSprites;
		//d::vector<sf::Sprite> realPipeSprites;

		int _landHeight;
		int _pipeSpawnYOffest;
    };
}