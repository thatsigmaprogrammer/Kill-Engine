#include "bin/core/render/render.hpp"
#include "bin/core/textures/TexturePack.hpp"
#include "bin/core/go/KillFrame.hpp"
#include "bin/core/input/Input.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	std::cout << "KILL DEBUG\n";
	sf::RenderWindow loadwin(sf::VideoMode(800, 600), "temp");
	auto& render = KE::Core::Render::get();
	TexturePack pack;
	bool loaded = pack.load("C:\\Users\\Tim\\OneDrive\\Рабочий стол\\killtest\\x64\\Debug\\hscheme.png", "le");

	if (!loaded) {
		std::cerr << "texture was not loaded\n";
		return 1;
	}

	loadwin.close();

	render.loadTexturePack(pack);
	auto frame = render.createKframe("lel", 0);
	frame.setPosition(100.0, 100.0);

	render.renderMain("game", [&]() {
		if (Input::Keyboard.KeyDown(Key::D)) {
			std::cout << "D\n";
			frame.setPosition(frame.transform.position.X + 1, frame.transform.position.Y);
		}
	});
	
}