#pragma once
#include "Transform.hpp"
#include <string>

class KillFrame 
{
public:
    float speedX = 0.f;
    float speedY = 0.f;
    KillFrame(unsigned int spri);
    ~KillFrame() = default;
    void setPosition(float x, float y);
    void setSpri(unsigned int spria) { spri = spria; }
private:
    unsigned int spri;
};