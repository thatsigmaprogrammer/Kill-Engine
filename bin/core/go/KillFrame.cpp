#include "KillFrame.hpp"
#include "../render/render.hpp"

KillFrame::KillFrame(unsigned int spri) : spri(spri) {}

void KillFrame::setPosition(float x, float y) {
	KE::Core::Render::get().setSpritePos(spri, x, y);
}