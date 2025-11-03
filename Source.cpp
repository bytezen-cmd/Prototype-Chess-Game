#include "Header.h"

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Simple SFML 3.0 Program");
    window.setFramerateLimit(60);

    // Create a circle that follows the mouse
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin({ 50.f, 50.f });

    // Create a rectangle
    sf::RectangleShape rectangle({ 100.f, 80.f });
    rectangle.setPosition({ 400.f, 300.f });
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin({ 50.f, 40.f });

    // Animation variables
    float rotation = 0.f;
    sf::Clock clock;

    // Main loop
    while (window.isOpen()) {
        // Handle events
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            // Close on Escape key
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                    window.close();
            }
        }

        // Update circle position to follow mouse
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        circle.setPosition(sf::Vector2f(mousePos));

        // Rotate the rectangle
        float deltaTime = clock.restart().asSeconds();
        rotation += 50.f * deltaTime;
        rectangle.setRotation(sf::degrees(rotation));

        // Change rectangle color based on mouse button
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            rectangle.setFillColor(sf::Color::Blue);
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            rectangle.setFillColor(sf::Color::Yellow);
        }
        else {
            rectangle.setFillColor(sf::Color::Red);
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw shapes
        window.draw(rectangle);
        window.draw(circle);

        // Display
        window.display();
    }

    return 0;
}