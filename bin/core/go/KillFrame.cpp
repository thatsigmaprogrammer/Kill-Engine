#include "KillFrame.hpp"
#include "../render/render.hpp"

KillFrame::KillFrame(unsigned int spri) : spri(spri) {}

void KillFrame::setPosition(float x, float y) {
	KE::Core::Render::get().setSpritePos(spri, x, y);
	transform.position = { x, y };
}

void KillFrame::setPosition(Vec2 vector) {
	KE::Core::Render::get().setSpritePos(spri, vector.X, vector.Y);
	transform.position = vector;
}

bool KillFrame::checkCollistion(const KillFrame& other) const {
	sf::FloatRect me = KE::Core::Render::get().getBounds(spri);
	sf::FloatRect otherR = KE::Core::Render::get().getBounds(other.spri);

	return me.intersects(otherR);
}