#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
using namespace std;

Ball::Ball(float X, float Y, float Angle, float Radius, sf::Color color)
{
    x = X;
    y = Y;
    angle = Angle;
    R = Radius;
    mass = 1;
    push_force = 1;
    circle.setFillColor((sf::Color::White));
    circle.setRadius(R);
    circle.setPosition(x, y);
    circle.setOrigin(R, R);
    circle.setFillColor(color);
    direction.x = 0;
    direction.y = 0;
}

void Ball::draw(sf::RenderWindow &w)
{
    w.draw(circle);
}

void Ball::set_position(float X, float Y)
{
    x = X;
    y = Y;
    circle.setPosition(x, y);
}

void Ball::getAngle(sf::RenderWindow &w)
{
    float screen_a;
    float screen_b;
    float screen_c;
    if(sf::Mouse::getPosition(w).x < x || sf::Mouse::getPosition(w).y < y)
    {
        screen_a = circle.getPosition().x - sf::Mouse::getPosition(w).x;
        screen_b = circle.getPosition().y - sf::Mouse::getPosition(w).y;
    }
    else if(sf::Mouse::getPosition(w).x > x || sf::Mouse::getPosition(w).y > y)
    {
        screen_a = sf::Mouse::getPosition(w).x - circle.getPosition().x;
        screen_b = sf::Mouse::getPosition(w).y - circle.getPosition().y;
    }
    screen_c = sqrt(pow(screen_a, 2) + pow(screen_b, 2));
    if(sf::Mouse::getPosition(w).x > x && sf::Mouse::getPosition(w).y > y)
    {
        angle = 180 - acos(screen_b/screen_c) * 180/M_PI;
    }
    else if(sf::Mouse::getPosition(w).x > x && sf::Mouse::getPosition(w).y < y)
    {
        angle = acos(screen_b/screen_c) * 180/M_PI;
    }
    else if(sf::Mouse::getPosition(w).x < x && sf::Mouse::getPosition(w).y > y)
    {
        angle = 360 - acos(screen_b/screen_c) * 180/M_PI;
    }
    else if(sf::Mouse::getPosition(w).x < x && sf::Mouse::getPosition(w).y < y)
    {
        angle = 360 - acos(screen_b/screen_c) * 180/M_PI;
    }
}
void Ball::move_ball()
{
    x += direction.x;
    y += direction.y;
    circle.move(direction);
}
void Ball::set_direction()
{
    direction.x = sin(angle*M_PI/180) * -push_force;
    direction.y = -cos(angle*M_PI/180) * -push_force;
}
void Ball::friction()
{
    direction.x -= direction.x * 0.01;
    direction.y -= direction.y * 0.01;
    if(abs(direction.x) < 0.001 && abs(direction.y) < 0.001)
    {
        direction.x = 0;
        direction.y = 0;
    }
}
void Ball::checkBallCollision(Ball &b)
{
    float distance = sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
    if(distance <= R + b.R)
    {
        float nx = (b.x - x)/distance; //Tworzê znormalizowane sk³adowe prêdkoœci
        float ny = (b.y - y)/distance;

        float tx = -ny; //Prostopad³a do normalnej
        float ty = nx;

        float dpTan1 = direction.x * tx + direction.y *ty; //Rozk³ad kierunków wektrorów prêdkoœci
        float dpTan2 = b.direction.x * tx + b.direction.y * ty;

        float dpNorm1 = direction.x * nx + direction.y * ny; //Okreœlenie kierunku dla sk³adowej prêdkoœci
        float dpNorm2 = b.direction.x * nx + b.direction.y * ny;

        float m1 = (dpNorm1 * (mass - b.mass) + 2.0f * b.mass * dpNorm2) / (mass + b.mass); //Obliczenie prêdkoœci ka¿dej z bili
        float m2 = (dpNorm2 * (b.mass - mass) + 2.0f * mass *dpNorm1) / (mass + b.mass);

        direction.x = tx * dpTan1 + nx * m1;
        direction.y = ty * dpTan1 + ny * m1;
        b.direction.x = tx * dpTan2 + nx * m2;
        b.direction.y = ty * dpTan2 + ny * m2;
    }

    if(distance <= R + b.R)
    {
        float overlap = distance - R - b.R;

        x -= overlap * (x - b.x )/distance;
        y -= overlap * (y - b.y )/distance;

        b.x += overlap * (x - b.x)/distance;
        b.y += overlap * (y - b.y)/distance;

        circle.setPosition(x, y);
        b.circle.setPosition(b.x, b.y);
    }
}

bool Ball::checkPocketCollision(sf::CircleShape &p)
{
    float distance = sqrt(pow(x - p.getPosition().x, 2) + pow(y - p.getPosition().y, 2));
    if(distance <= R + p.getRadius()){return true;}
    else{return false;}
}

void Ball::checkTableCollision(sf::RectangleShape &t)
{
    if(x + 10 >= 800 - (800 - t.getSize().x)/2 || x-10 <= (800 - t.getSize().x)/2){direction.x = -direction.x;}
    else if(y + 10 >= 600 - (600 - t.getSize().y)/2 || y-10 <= (600 - t.getSize().y)/2){direction.y = -direction.y;}
}
