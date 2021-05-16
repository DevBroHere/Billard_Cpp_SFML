#include <SFML/Graphics.hpp>
#ifndef BALL_H
#define BALL_H


class Ball
{
    public:
        sf::CircleShape circle;
        float x,y,angle,R,mass,push_force;
        sf::Vector2f direction;

        Ball(float, float, float, float, sf::Color);

        void draw(sf::RenderWindow &);
        void getAngle(sf::RenderWindow &);
        void move_ball();
        void friction();
        void set_position(float, float);
        void set_direction();
        void checkBallCollision(Ball &);
        bool checkPocketCollision(sf::CircleShape &);
        void checkTableCollision(sf::RectangleShape &);
};

#endif // BALL_H
