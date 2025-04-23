#include <SFML/Graphics.hpp>

int w = 200;
int h = 200;

int main() {
    sf::RenderWindow window(sf::VideoMode(w, h), "SFML");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
