#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <random>
#include <cmath>
#include <thread>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

class Object
{
	sf::RectangleShape object;
	sf::Vector2f size = sf::Vector2f(0, 0);
	sf::Color color = sf::Color::White;

	sf::Vector2f position = sf::Vector2f(0, 0);
	sf::Vector2f speed = sf::Vector2f(0, 0);
	sf::Vector2f acceleration = sf::Vector2f(0, 0);

public:

	void setSize(double sizeX, double sizeY)
	{
		size = sf::Vector2f(sizeX, sizeY);

		object.setSize(size);
	}

	void setSize(sf::Vector2f s)
	{
		size = s;

		object.setSize(size);
	}

	void setSizeX(double sizeX)
	{
		size.x = sizeX;

		object.setSize(size);
	}

	void setSizeY(double sizeY)
	{
		size.y = sizeY;

		object.setSize(size);
	}

	void setColor(double red, double green, double blue)
	{
		color = sf::Color(red, green, blue);

		object.setFillColor(color);
	}

	void setColor(sf::Color c)
	{
		color = c;

		object.setFillColor(color);
	}

	void setPosition(double positionX, double positionY)
	{
		position = sf::Vector2f(positionX, positionY);

		object.setPosition(position);
	}

	void setPosition(sf::Vector2f p)
	{
		position = p;

		object.setPosition(position);
	}

	void setPositionX(double positionX)
	{
		position.x = positionX;

		object.setPosition(position);
	}

	void setPositionY(double positionY)
	{
		position.y = positionY;

		object.setPosition(position);
	}

	void setSpeed(double speedX, double speedY)
	{
		speed = sf::Vector2f(speedX, speedY);
	}

	void setSpeed(sf::Vector2f s)
	{
		speed = s;
	}

	void setAcceleration(double accelerationX, double accelerationY)
	{
		acceleration = sf::Vector2f(accelerationX, accelerationY);
	}

	void setAcceleration(sf::Vector2f a)
	{
		acceleration = a;
	}

	void setSpeedX(double speedX)
	{
		speed.x = speedX;
	}

	void setSpeedY(double speedY)
	{
		speed.y = speedY;
	}

	void setAccelerationX(double accelerationX)
	{
		acceleration.x = accelerationX;
	}

	void setAccelerationY(double accelerationY)
	{
		acceleration.y = accelerationY;
	}

	void increaseSpeed(double bonusX, double bonusY)
	{
		speed += sf::Vector2f(bonusX, bonusY);
	}

	void increaseSpeed(sf::Vector2f bonus)
	{
		speed += bonus;
	}

	void increaseAcceleration(double bonusX, double bonusY)
	{
		acceleration += sf::Vector2f(bonusX, bonusY);
	}

	void increaseAcceleration(sf::Vector2f bonus)
	{
		acceleration += bonus;
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


	sf::RectangleShape getShape()
	{
		return object;
	}

	sf::Color getColor()
	{
		return color;
	}

	double getColorRed()
	{
		return color.r;
	}

	double getColorGreen()
	{
		return color.g;
	}

	double getColorBlue()
	{
		return color.b;
	}

	sf::Vector2f getSize()
	{
		return size;
	}

	double getSizeX()
	{
		return size.x;
	}

	double getSizeY()
	{
		return size.y;
	}

	sf::Vector2f getPosition()
	{
		return position;
	}

	double getPositionX()
	{
		return position.x;
	}

	double getPositionY()
	{
		return position.y;
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
		position += speed;

		speed += acceleration;

		object.setPosition(position);
	}
};


int randomValue(int lower, int upper)
{
	return lower + rand() % (upper - lower + 1);
}

void output(Object& player)
{
	while (true)
	{
		system("cls");

		cout << "size:" << endl;
		cout << "x: " << player.getSizeX() << endl;
		cout << "y: " << player.getSizeY() << endl;

		cout << endl;

		cout << "color:" << endl;
		cout << "red: " << player.getColorRed() << endl;
		cout << "green: " << player.getColorGreen() << endl;
		cout << "blue: " << player.getColorBlue() << endl;

		cout << endl;

		cout << "position:" << endl;
		cout << "x: " << player.getPositionX() << endl;
		cout << "y: " << player.getPositionY() << endl;

		cout << endl;

		cout << "speed:" << endl;
		cout << "x: " << player.getSpeedX() << endl;
		cout << "y: " << player.getSpeedY() << endl;

		cout << endl;

		cout << "acceleration:" << endl;
		cout << "x: " << player.getAccelerationX() << endl;
		cout << "y: " << player.getAccelerationY() << endl;

		cout << endl;

		this_thread::sleep_for(milliseconds(1));
	}
}


int main()
{
	srand(time(NULL));

	high_resolution_clock::time_point start;
	high_resolution_clock::time_point end;


	double winX = 1000, winY = 500;

	sf::Vector2f player_size = sf::Vector2f(100, 100);
	sf::Color player_color = sf::Color(255, 0, 0);
	sf::Vector2f player_position = sf::Vector2f(200, 200);
	sf::Vector2f player_speed = sf::Vector2f(0, 0);
	sf::Vector2f player_acceleration = sf::Vector2f(0, 1);

	sf::Vector2f tube_size = sf::Vector2f(100, winY);
	sf::Color tube_color = sf::Color(0, 255, 0);
	sf::Vector2f tube_position = sf::Vector2f(winX, 0);
	sf::Vector2f tube_speed = sf::Vector2f(0, 0);
	sf::Vector2f tube_acceleration = sf::Vector2f(0, 0);

	sf::Vector2f space_size = sf::Vector2f(100, 0.5 * winY);
	sf::Color space_color = sf::Color(52, 207, 235);
	sf::Vector2f space_position = sf::Vector2f(winX, randomValue(0, winY - space_size.y));
	sf::Vector2f space_speed = sf::Vector2f(0, 0);
	sf::Vector2f space_acceleration = sf::Vector2f(0, 0);


	sf::RenderWindow window(sf::VideoMode(winX, winY), "flappy cube");
	sf::View view(sf::Vector2f(winX / 2, winY / 2), sf::Vector2f(winX, winY));


	Object player;
	player.setSize(player_size);
	player.setColor(player_color);
	player.setPosition(player_position);
	player.setSpeed(player_speed);
	player.setAcceleration(player_acceleration);

	Object tube;
	tube.setSize(tube_size);
	tube.setColor(tube_color);
	tube.setPosition(tube_position);
	tube.setSpeed(tube_speed);
	tube.setAcceleration(tube_acceleration);

	Object space;
	space.setSize(space_size);
	space.setColor(space_color);
	space.setPosition(space_position);
	space.setSpeed(space_speed);
	space.setAcceleration(space_acceleration);


	thread(output, ref(player)).detach();


	while (window.isOpen())
	{
		start = high_resolution_clock::now();

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

					player.setSpeedY(-15);

					break;

				case sf::Keyboard::Scan::Down:

					player.setSpeedX(0);

					break;

				case sf::Keyboard::Scan::Left:

					player.setSpeedX(-10);

					break;

				case sf::Keyboard::Scan::Right:

					player.setSpeedX(10);

					break;

				default:

					break;
				}
			}
		}

		window.setView(view);


		window.clear(sf::Color(52, 207, 235));

		window.draw(tube.getShape());
		window.draw(space.getShape());
		window.draw(player.getShape());

		window.display();


		player.move();

		view.move(player.getSpeedX(), 0);

		if (player.getPositionX() - tube.getPositionX() >= player_position.x + tube.getSizeX())
		{
			tube.setPositionX(player.getPositionX() + winX - player_position.x);

			space.setPositionX(tube.getPositionX());
			space.setPositionY(randomValue(0, winY - space.getSizeY()));
		}

		this_thread::sleep_for(milliseconds(1));

		end = high_resolution_clock::now();

		double fps = 1000000000.0f / duration_cast<std::chrono::nanoseconds>(end - start).count();

		string title = "flappy cube FPS[" + to_string(fps) + "]";
		window.setTitle(title.c_str());
	}
}
