#include "render.hpp"


int KE::Core::Render::renderMain(const std::string& gamename) {
    sf::RenderWindow window(sf::VideoMode(800,600), gamename);
    if (loaded.empty()) return 1;

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (const auto& sprite : loaded) {
            window.draw(sprite);
        }

        window.display();
    }

    return 0;
}

void KE::Core::Render::loadTexturePack(TexturePack& pack) {
    for (auto& name : pack.getList())
    {
        sf::Texture* tex = pack.get(name);
        if(!tex) continue;
        sf::Sprite spr(*tex);
        loaded.push_back(spr);
    }
    
}

std::vector<sf::Sprite> KE::Core::Render::getSprites() {
    return loaded;
}

KillFrame KE::Core::Render::createKframe(std::string name, unsigned int spri)
{
    KillFrame frame(spri);

    if (spri >= 0 && static_cast<size_t>(spri) < loaded.size()) {
        frame.setSpri(spri);
    }
    else {
        frame.setSpri(0);
    }

    kframes.emplace(name, frame);
    return frame;
}

void KE::Core::Render::setSpritePos(unsigned int spri, float x, float y) {
    if (spri >= 0 && spri < (int)loaded.size()) {
        loaded[spri].setPosition(x, y);
    }
}