#include <iostream>
#include <SFML/Graphics.hpp>

#include "BezuirCurve.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "title");

    sf::Event event;
    Curve curve;
    curve.setPosition(
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y),
                sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));

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