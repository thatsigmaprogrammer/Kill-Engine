#include <SFML/Graphics.hpp>

#pragma once

struct Vec2 {
    float X, Y;
    Vec2(float x, float y) { X = x; Y = y; }
};

struct Transform
{
    Vec2 position{ 0.f, 0.f };
    float rotation = 0.f;
    Vec2 scale {1.f, 1.f};
};