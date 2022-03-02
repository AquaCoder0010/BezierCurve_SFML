#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "sleep.hpp"

class Curve
{
    public:
    Curve()
    :point_1(), point_2(), point_3(), path(), curve()
    {
        point_1.setRadius(5.f);
        point_2.setRadius(5.f);
        point_3.setRadius(5.f);
        curve.setRadius(5.f);

        point_1.setOrigin(sf::Vector2f(5.f, 5.f));
        point_2.setOrigin(sf::Vector2f(5.f, 5.f));
        point_3.setOrigin(sf::Vector2f(5.f, 5.f));
        curve.setOrigin(sf::Vector2f(5.f, 5.f));

        curve.setFillColor(sf::Color(255, 0, 0));
        drawing = false;
        finishedDrawing = false;
        drawQuadratic = false;
        drawLinear = false;
        path.setPrimitiveType(sf::LineStrip);
        t = 0;
    }

    void setPosition
    (sf::Vector2f p_point1, sf::Vector2f p_point2
    ,sf::Vector2f p_point3)
    {
        point_1.setPosition(p_point1);
        point_2.setPosition(p_point2);
        point_3.setPosition(p_point3);
        drawQuadratic = true;
        drawLinear = false;
        startDrawing();
    }
    void setPosition
    (sf::Vector2f p_point1, sf::Vector2f p_point2)
    {
        point_1.setPosition(p_point1);
        point_2.setPosition(p_point2);
        drawLinear = true;
        drawQuadratic = false;
        startDrawing();
    }
    void startDrawing()
    {
        drawing = true;
    }

    void drawCurve(sf::RenderWindow &window)
    {
        while(t <= 1 && drawing == true)
            {    
                drawing = true;
                aq::sleep(0.01);
                t += 0.01; 
                if(drawLinear)
                {
                    window.clear();
                    calc(t);
                    window.draw(point_1);
                    window.draw(point_2);
                    window.draw(curve);
                    window.draw(path);
                    window.display();
                }
                if(drawQuadratic)
                {
                    window.clear();
                    calc_quad(t);
                    window.draw(point_1);
                    window.draw(point_2);
                    window.draw(point_3);
                    window.draw(curve);
                    window.draw(path);
                    window.display(); 
                }
                
            }
        if(t > 1 && drawLinear == true)
        {
            drawing = false;
            window.clear();
            window.draw(point_1);
            window.draw(point_2);
            window.draw(curve);
            window.draw(path);
            window.display();
        }
        if(t > 1 && drawQuadratic == true)
        {
            drawing = false;
            window.clear();
            window.draw(point_1);
            window.draw(point_2);
            window.draw(curve);
            window.draw(path);
            window.display();
        }

    }
    private:
    sf::CircleShape point_1;
    sf::CircleShape point_2;
    sf::CircleShape point_3;
    sf::CircleShape curve;
    sf::VertexArray path;
    bool drawing;
    bool finishedDrawing;
    bool drawQuadratic;
    bool drawLinear;
    float t;

    private:
    void calc(float t)
    {
        sf::Vector2f vec_point_1 = point_1.getPosition();
        sf::Vector2f vec_point_2 = point_2.getPosition();

        sf::Vector2f vec_linearPos;
        vec_linearPos.x = vec_point_1.x*(1 - t) + vec_point_2.x*t;
        vec_linearPos.y = vec_point_1.y*(1 - t) + vec_point_2.y*t;
           
        
        path.append(sf::Vertex(vec_linearPos));
        curve.setPosition(vec_linearPos);
    }

    void calc_quad(float t)
    {
        sf::Vector2f vec_point_1 = point_1.getPosition();
        sf::Vector2f vec_point_2 = point_2.getPosition();
        sf::Vector2f vec_point_3 = point_3.getPosition();

        sf::Vector2f vec_linearPos_1;
        sf::Vector2f vec_linearPos_2;
        sf::Vector2f vec_QuadPos;

        vec_linearPos_1.x = vec_point_1.x*(1 - t) + vec_point_2.x*t;
        vec_linearPos_1.y = vec_point_1.y*(1 - t) + vec_point_2.y*t;

        vec_linearPos_2.x = vec_point_2.x*(1 - t) + vec_point_3.x*t;
        vec_linearPos_2.y = vec_point_2.y*(1 - t) + vec_point_3.y*t;

        vec_QuadPos.x = vec_linearPos_1.x*(1 - t) + vec_linearPos_2.x*t;
        vec_QuadPos.y = vec_linearPos_1.y*(1 - t) + vec_linearPos_2.y*t;

           
        path.append(sf::Vertex(vec_QuadPos));
        curve.setPosition(vec_QuadPos);
    }
};