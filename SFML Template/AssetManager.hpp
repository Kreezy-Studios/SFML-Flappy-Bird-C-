#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Kreezy {
    class AssetManager {
	  public:
		AssetManager() {}
		~AssetManager() {}

		bool LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fontName);
		sf::Font &GetFont(std::string name);

	  private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
    };
}