#include "SFML/Graphics/RectangleShape.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

int main() {
  // create the window
  sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

  sf::RectangleShape rect({30, 30});
  rect.setFillColor(sf::Color(0, 255, 255));
  rect.setPosition({60, 60});

  // run the program as long as the window is open
  while (window.isOpen()) {
    rect.setPosition({rect.getPosition().x + 2, rect.getPosition().y + 2});
    while (const std::optional event = window.pollEvent()) {
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    // clear the window with black color
    window.clear(sf::Color::Black);
    
    window.draw(rect);

    window.display();

    std::chrono::milliseconds t(10);
    std::this_thread::sleep_for(t);
  }
}
