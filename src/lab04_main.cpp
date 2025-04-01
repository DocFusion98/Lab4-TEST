// lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Owen's Lab4");
    sf::CircleShape test(100.0f);
    sf::Image background("\..\media\space.png");
    sf::Texture texture;
    texture.loadFromImage(background);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    test.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        window.clear();
        
        window.draw(sprite);
        window.display();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
