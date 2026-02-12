#include "bin/core/render/render.hpp"
#include "bin/core/textures/TexturePack.hpp"
#include "bin/core/go/KillFrame.hpp"
#include "bin/core/input/Input.hpp"
#include <iostream>

int main() {
	std::cout << "KILL DEBUG\n";
	auto& render = KE::Core::Render::get();
	//initialisation
	render.renderMain("game", [&]() {
		//loop
	});
	
}