#include "render.hpp"
#include "../input/Input.hpp"


int KE::Core::Render::renderMain(const std::string& gamename, std::function<void()> func) {
    window.create(sf::VideoMode(800,600), gamename);
    if (loaded.empty()) return 1;

    Input::Mouse.window = &window;

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        func();

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
        if (!tex) continue;
        sf::Sprite spr(*tex);
        spr.setScale({ 0.2, 0.2 });
        loaded.push_back(spr);
    }
    
}

std::vector<sf::Sprite> KE::Core::Render::getSprites() {
    return loaded;
}

KillFrame& KE::Core::Render::createKframe(const std::string name, unsigned int spri)
{
    auto [it, inserted] = kframes.try_emplace(name, KillFrame(spri));
    KillFrame& frame = it->second;

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

sf::FloatRect KE::Core::Render::getBounds(unsigned int spri) const {
    if (spri < loaded.size()) {
        return loaded[spri].getGlobalBounds();
    }
    auto real = loaded[spri].getGlobalBounds();
    return sf::FloatRect(
        real.left + (real.width - 32.0f) / 2.0f,
        real.top + (real.height - 32.0f) / 2.0f,
        32.0f,
        32.0f
    );
}