#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "BezuirCurve.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "title");

    sf::Font font;
    if(!font.loadFromFile("calibri.ttf"))
    {
        std::cout << "error loading Font" << std::endl;
    }

    sf::Text fps_text;

    fps_text.setFont(font);

    sf::Event event;
    Curve curve;
        unsigned short random = rand () % 3;
        if(random == 0)
        {
            curve.setPosition(
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
        }
        if(random == 1)
        {
            curve.setPosition(
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
        }
        if(random == 2)
        {
            curve.setPosition(
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
        }

	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
        }
        curve.startDrawing();
        window.clear();
        curve.drawCurve(window); 

    }   
}