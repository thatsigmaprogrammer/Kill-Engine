#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../textures/TexturePack.hpp"
#include "../go/KillFrame.hpp"
#include <map>
#include <vector>
#include <string>
#include <functional>

namespace KE {
    namespace Core {
        class Render
        {
        public:

            sf::RenderWindow window;
            std::map<std::string, KillFrame> kframes;

            int renderMain(const std::string& gamename, std::function<void()> usercode);
            void loadTexturePack(TexturePack& pack);
            std::vector<sf::Sprite> getSprites();
            static Render& get() { static Render ins; return ins; }
            KillFrame& createKframe(const std::string name, unsigned int spri);
            void setSpritePos(unsigned int spri, float x, float y);
        private:
            std::vector<sf::Sprite> loaded;
        };
    }
}
