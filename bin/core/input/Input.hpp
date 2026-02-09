#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../go/Transform.hpp"

typedef sf::Keyboard::Key Key;

enum class MouseButton { Left, Right, Middle};

class Input {
public:
    struct KeyboardContext {
        bool KeyDown(Key key);
    };

    struct MouseContext {
        void* window;
        Vec2 getPosition();
        bool buttonDown(MouseButton button);
    };

    static KeyboardContext Keyboard;
    static MouseContext Mouse;

    static void init(void* sfmlWindow) {
        Mouse.window = sfmlWindow;
    }
};