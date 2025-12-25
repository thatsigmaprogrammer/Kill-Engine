#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>

class TexturePack {
public:
    bool load(const std::string& path, const std::string& name);
    sf::Texture* get(const std::string& name);
    bool has(const std::string name) const;
    std::vector<std::string> getList() const;
private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::vector<std::string> list;
    TexturePack(const TexturePack&) = delete;
    TexturePack& operator=(const TexturePack&) = delete;
};