#include "TexturePack.hpp"

bool TexturePack::load(const std::string& path, const std::string& name) {
    sf::Texture tex;
    if(!tex.loadFromFile(path)) {
        return false;
    }

    textures.emplace(name, std::move(tex));
    list.push_back(name);
    return true;
}

sf::Texture* TexturePack::get(const std::string& name) {
    auto it = textures.find(name);
    if(it == textures.end()) return nullptr;
    return &it->second;
}

std::vector<std::string> TexturePack::getList() const {
    return list;
}

bool TexturePack::has(const std::string name) const {
    return textures.find(name) != textures.end();
}