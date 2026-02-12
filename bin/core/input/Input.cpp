#include "Input.hpp"

Input::KeyboardContext Input::Keyboard;
Input::MouseContext Input::Mouse = { nullptr };

bool Input::KeyboardContext::KeyDown(Key key) {
	return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

Vec2 Input::MouseContext::getPosition() {
	auto& win = *static_cast<sf::RenderWindow*>(window);
	sf::Vector2i mpos = sf::Mouse::getPosition(win);
	return Vec2(static_cast<float>(mpos.x), static_cast<float>(mpos.y));
}

bool Input::MouseContext::buttonDown(MouseButton button) {
	return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}