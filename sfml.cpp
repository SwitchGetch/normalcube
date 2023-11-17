#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <random>
#include <cmath>
#include <thread>
using namespace std;

class Player
{
	sf::Vector2f direction;

	float cordX;
	float cordY;

	float speed;
	float acceleration;

	float length(sf::Vector2f vec)
	{
		return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	}

	void normalize(sf::Vector2f& vec)
	{
		if (length(vec) != 1)
		{
			float l = length(vec);

			vec.x /= l;
			vec.y /= l;
		}
	}

public:

	void setPosition(float x, float y)
	{
		cordX = x;
		cordY = y;
	}

	void setSpeed(float s)
	{
		speed = s;
	}

	void setAcceleration(float a)
	{
		acceleration = a;
	}

	void setDirection(float x, float y)
	{
		direction.x = x;
		direction.y = y;

		normalize(direction);
	}

	sf::Vector2f getPosition()
	{
		return sf::Vector2f(cordX, cordY);
	}

	float getSpeed()
	{
		return speed;
	}

	float getAcceleration()
	{
		return acceleration;
	}

	sf::Vector2f getDirection()
	{
		return direction;
	}

	void move()
	{
		cordX += direction.x * speed;
		cordY += direction.y * speed;

		speed += acceleration;
	}

	void statsOutput()
	{
		system("cls");

		cout << "position:" << endl;
		cout << "x: " << cordX << endl;
		cout << "y: " << cordY << endl;

		cout << endl;

		cout << "direction:" << endl;
		cout << "x: " << direction.x << endl;
		cout << "y: " << direction.y << endl;

		cout << endl;

		cout << "speed: " << speed << endl;

		cout << endl;

		cout << "acceleration: " << acceleration << endl;

		cout << endl;
	}
};

void output(Player& player)
{
	while (true) player.statsOutput();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "window");
	sf::RectangleShape rectangle;
	Player player;

	player.setPosition(200, 200);
	player.setSpeed(0.1);
	player.setAcceleration(0.001);
	player.setDirection(0, 1);

	thread(output, ref(player)).detach();

	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color(127, 127, 127));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.scancode == sf::Keyboard::Scan::Space)
				{
					player.setSpeed(-0.5);
				}
			}
		}

		window.clear();
		window.draw(rectangle);
		window.display();

		player.move();

		rectangle.setPosition(player.getPosition());
	}
}