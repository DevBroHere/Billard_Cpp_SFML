#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>
#include "Ball.h"
using namespace std;

int main()
{
    srand(time(NULL));
    const int promien = 10;

    //Tworzenie bili gracza
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    bool is_run_win_1 = true;
    bool is_run_win_2 = false;
    bool is_run_win_3 = false;

    //dla okna 1

    Ball ball_win_1(window.getSize().x/2, window.getSize().y/2, 0, 50, sf::Color::Red);

    //dla okna 2

    Ball ball_win_2(window.getSize().x/2, window.getSize().y/2, 0, 20, sf::Color::Green);

    vector <Ball> balls_win_2;
    for(int i = 0; i < 11; i++)
    {
        Ball ball(rand()%window.getSize().x, rand()&window.getSize().y, 0, 20, sf::Color::Black);
        balls_win_2.push_back(ball);
    }

    //dla okna 3

    Ball ball(500, 300, 0, promien, sf::Color::White);

    //Tworzenie pod³ogi
    sf::Texture floor_texture;
    floor_texture.loadFromFile("background.jpg");
    sf::Sprite floor_background(floor_texture);

    sf::RectangleShape table;
    table.setSize(sf::Vector2f(600, 400));
    table.setFillColor(sf::Color(0, 130, 0));
    table.setOutlineThickness(15.0f);
    table.setOutlineColor(sf::Color(75, 25, 0));
    table.setOrigin(table.getSize().x/2, table.getSize().y/2);
    table.setPosition(400, 300);

    //Tworzenie ³uz
    vector <sf::CircleShape> luzy;
    sf::CircleShape luz_1;
    luz_1.setRadius(15.0f);
    luz_1.setFillColor(sf::Color::Black);
    luz_1.setOrigin(luz_1.getRadius(), luz_1.getRadius());
    luz_1.setPosition(sf::Vector2f(100, 100));
    sf::CircleShape luz_2;
    luz_2.setRadius(15.0f);
    luz_2.setFillColor(sf::Color::Black);
    luz_2.setOrigin(luz_2.getRadius(), luz_2.getRadius());
    luz_2.setPosition(sf::Vector2f(400, 100));
    sf::CircleShape luz_3;
    luz_3.setRadius(15.0f);
    luz_3.setFillColor(sf::Color::Black);
    luz_3.setOrigin(luz_3.getRadius(), luz_3.getRadius());
    luz_3.setPosition(sf::Vector2f(700, 100));
    sf::CircleShape luz_4;
    luz_4.setRadius(15.0f);
    luz_4.setFillColor(sf::Color::Black);
    luz_4.setOrigin(luz_4.getRadius(), luz_4.getRadius());
    luz_4.setPosition(sf::Vector2f(700, 500));
    sf::CircleShape luz_5;
    luz_5.setRadius(15.0f);
    luz_5.setFillColor(sf::Color::Black);
    luz_5.setOrigin(luz_5.getRadius(), luz_5.getRadius());
    luz_5.setPosition(sf::Vector2f(400, 500));
    sf::CircleShape luz_6;
    luz_6.setRadius(15.0f);
    luz_6.setFillColor(sf::Color::Black);
    luz_6.setOrigin(luz_6.getRadius(), luz_6.getRadius());
    luz_6.setPosition(sf::Vector2f(100, 500));
    luzy.push_back(luz_1);
    luzy.push_back(luz_2);
    luzy.push_back(luz_3);
    luzy.push_back(luz_4);
    luzy.push_back(luz_5);
    luzy.push_back(luz_6);

    //Tworzenie bili obecnych w grze
    vector <Ball> balls;

    Ball ball_1(300, 300, 0, promien, sf::Color(246,16, 16));
    Ball ball_2(280, 290, 0, promien, sf::Color(246,16, 16));
    Ball ball_3(280, 310, 0, promien, sf::Color(188,0, 255));
    Ball ball_4(260, 300, 0, promien, sf::Color(188,0, 255));
    Ball ball_5(260, 320, 0, promien, sf::Color(252,252, 20));
    Ball ball_6(260, 280, 0, promien, sf::Color(252,252, 20));
    Ball ball_7(240, 290, 0, promien, sf::Color(12,12, 189));
    Ball ball_8(240, 310, 0, promien, sf::Color(12,12, 189));
    Ball ball_9(240, 330, 0, promien, sf::Color(255,94, 0));
    Ball ball_10(240, 270, 0, promien, sf::Color(255,94, 0));
    Ball ball_11(220, 340, 0, promien, sf::Color(255,0, 230));
    Ball ball_12(220, 320, 0, promien, sf::Color(255,0, 230));
    Ball ball_13(220, 300, 0, promien, sf::Color(28,209, 28));
    Ball ball_14(220, 280, 0, promien, sf::Color(28,209, 28));
    Ball ball_15(220, 260, 0, promien, sf::Color(0,0,0));
    balls.push_back(ball_1);
    balls.push_back(ball_2);
    balls.push_back(ball_3);
    balls.push_back(ball_4);
    balls.push_back(ball_5);
    balls.push_back(ball_6);
    balls.push_back(ball_7);
    balls.push_back(ball_8);
    balls.push_back(ball_9);
    balls.push_back(ball_10);
    balls.push_back(ball_11);
    balls.push_back(ball_12);
    balls.push_back(ball_13);
    balls.push_back(ball_14);
    balls.push_back(ball_15);

    //Tworzenie linii pchniêcia
    sf::VertexArray line(sf::Lines, 2);

    window.setFramerateLimit(100);

    sf::Event event;
    while(window.isOpen()){
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
                break;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                is_run_win_1 = true;
                is_run_win_2 = false;
                is_run_win_3 = false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                is_run_win_1 = false;
                is_run_win_2 = true;
                is_run_win_3 = false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                is_run_win_1 = false;
                is_run_win_2 = false;
                is_run_win_3 = true;
            }
            if(is_run_win_3)
            {
                if(event.type == sf::Event::MouseButtonReleased)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        float a = (sf::Mouse::getPosition(window).x - ball.x);
                        float b = (sf::Mouse::getPosition(window).y - ball.y);
                        float distance = sqrt(pow(a, 2) + pow(b, 2))/30;
                        cout << a << ", " << b << ", " << distance << endl;
                        ball.getAngle(window);
                        ball.push_force = distance;
                        ball.set_direction();
                        cout << "Released" << endl;
                    }
                }
            }

        }
        if(is_run_win_1)
        {
            float distance = sqrt(pow(ball_win_1.x - sf::Mouse::getPosition(window).x, 2) + pow(ball_win_1.y - sf::Mouse::getPosition(window).y, 2));
            window.clear(sf::Color::White);
            ball_win_1.draw(window);
            if(distance < ball_win_1.R)
            {
                ball_win_1.circle.setFillColor(sf::Color::Green);
            }
            else
            {
                ball_win_1.circle.setFillColor(sf::Color::Red);
            }
            window.display();
        }
        if(is_run_win_2)
        {
            window.clear(sf::Color::White);
            ball_win_2.set_position(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            for(size_t i = 0; i < balls_win_2.size(); i++)
            {
                ball_win_2.draw(window);
                balls_win_2[i].draw(window);
                ball_win_2.checkBallCollision(balls_win_2[i]);
                balls[i].move_ball();
                for(size_t j = 0; j< balls_win_2.size(); j++)
                {
                    if(i != j)
                    {
                        balls_win_2[i].checkBallCollision(balls_win_2[j]);
                    }
                }
            }
            window.display();
        }
        if(is_run_win_3)
        {
        {
            window.clear(sf::Color(81, 104, 104));
            window.draw(floor_background);
            window.draw(table);
            for(size_t i = 0; i<luzy.size() ; i++)
            {
                window.draw(luzy[i]);
            }
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            line[0].position = sf::Vector2f(ball.x, ball.y);
            line[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            window.draw(line);
        }
        for(size_t i = 0; i < balls.size(); i++)
        {
            balls[i].draw(window);
            ball.checkBallCollision(balls[i]);
            balls[i].checkTableCollision(table);
            for(size_t j = 0; j < luzy.size(); j++)
            {
                if(balls[i].checkPocketCollision(luzy[j]))
                {
                    balls.erase(balls.begin() + i);
                }
            }
            balls[i].friction();
            balls[i].move_ball();
            for(size_t j = 0; j < balls.size(); j++)
            {
                if(i != j)
                {
                    balls[i].checkBallCollision(balls[j]);
                }
            }
        }
        ball.move_ball();
        ball.checkTableCollision(table);
        for(size_t i = 0; i < luzy.size() ; i++)
        {
            if(ball.checkPocketCollision(luzy[i]))
            {
                ball.set_position(500, 300);
                ball.direction.x = 0;
                ball.direction.y = 0;
            }
        }
        ball.friction();
        ball.draw(window);
        window.display();
        }
    }
}
