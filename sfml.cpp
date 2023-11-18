#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <random>
#include <cmath>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

class Player
{
	sf::Vector2f speed = sf::Vector2f(0, 0);
	sf::Vector2f acceleration = sf::Vector2f(0, 0);

	double cordX = 0;
	double cordY = 0;

	double length(sf::Vector2f vec)
	{
		return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	}

	void normalize(sf::Vector2f& vec)
	{
		if (length(vec) != 1)
		{
			double l = length(vec);

			vec.x /= l;
			vec.y /= l;
		}
	}

public:

	void setPosition(double x, double y)
	{
		cordX = x;
		cordY = y;
	}

	void setSpeed(double x, double y)
	{
		speed.x = x;
		speed.y = y;
	}

	void setAcceleration(double x, double y)
	{
		acceleration.x = x;
		acceleration.y = y;
	}

	void setSpeedX(double x)
	{
		speed.x = x;
	}

	void setSpeedY(double y)
	{
		speed.y = y;
	}

	void setAccelerationX(double x)
	{
		acceleration.x = x;
	}

	void setAccelerationY(double y)
	{
		acceleration.y = y;
	}

	void increaseSpeed(double bonusX, double bonusY)
	{
		speed.x += bonusX;
		speed.y += bonusY;
	}

	void increaseAcceleration(double bonusX, double bonusY)
	{
		acceleration.x += bonusX;
		acceleration.y += bonusY;
	}

	void increaseSpeedX(double bonusX)
	{
		speed.x += bonusX;
	}

	void increaseSpeedY(double bonusY)
	{
		speed.y += bonusY;
	}

	void increaseAccelerationX(double bonusX)
	{
		acceleration.x += bonusX;
	}

	void increaseAccelerationY(double bonusY)
	{
		acceleration.y += bonusY;
	}


	sf::Vector2f getPosition()
	{
		return sf::Vector2f(cordX, cordY);
	}

	double getPositionX()
	{
		return cordX;
	}

	double getPositionY()
	{
		return cordY;
	}

	sf::Vector2f getSpeed()
	{
		return speed;
	}

	double getSpeedX()
	{
		return speed.x;
	}

	double getSpeedY()
	{
		return speed.y;
	}

	sf::Vector2f getAcceleration()
	{
		return acceleration;
	}

	double getAccelerationX()
	{
		return acceleration.x;
	}

	double getAccelerationY()
	{
		return acceleration.y;
	}


	void move()
	{
		cordX += speed.x;
		cordY += speed.y;

		speed.x += acceleration.x;
		speed.y += acceleration.y;
	}


	void statsOutput()
	{
		system("cls");

		cout << "position:" << endl;
		cout << "x: " << cordX << endl;
		cout << "y: " << cordY << endl;

		cout << endl;

		cout << "speed:" << endl;
		cout << "x: " << speed.x << endl;
		cout << "y: " << speed.y << endl;
		cout << "speed module: " << length(speed) << endl;

		cout << endl;

		cout << "acceleration:" << endl;
		cout << "x: " << acceleration.x << endl;
		cout << "y: " << acceleration.y << endl;
		cout << "acceleration module: " << length(acceleration) << endl;

		cout << endl;
	}
};

void output(Player& player)
{
	while (true)
	{
		player.statsOutput();

		this_thread::sleep_for(milliseconds(1));
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "window");
	//sf::View view(sf::Vector2f(250, 250), sf::Vector2f(500, 500));


	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color(127, 127, 127));


	Player player;

	player.setPosition(200, 200);

	player.setSpeed(0, -20);
	player.setAcceleration(0, 1);


	thread(output, ref(player)).detach();


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
				switch (event.key.scancode)
				{
				case sf::Keyboard::Scan::Up:

					player.setSpeedY(-20);

					break;

				case sf::Keyboard::Scan::Down:

					player.setSpeedX(0);

					break;

				case sf::Keyboard::Scan::Left:

					player.setSpeedX(-5);

					break;

				case sf::Keyboard::Scan::Right:

					player.setSpeedX(5);

					break;

				default:

					break;
				}
			}
		}

		//window.setView(view);

		window.clear();
		window.draw(rectangle);
		window.display();

		player.move();

		rectangle.setPosition(player.getPosition());

		//view.move(player.getSpeedX(), 0);

		this_thread::sleep_for(milliseconds(1));
	}
}
