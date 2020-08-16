#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"
#include "Paddle.h"
#include "Ball.h"

int main() {

	sf::Screen screen(800, 600, "Pong");
	if (!screen.setBackground("Data/background.png")) {
		return 1;
	}

	//Load font
	sf::Font font;
	if (!(font.loadFromFile("Data/arial.ttf"))) {
		return 2;
	}

	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setFillColor(sf::Color::Red);
	score.setPosition(375, 10);
	score.setString("0 : 0");

	//States
	bool upKey = false;
	bool downKey = false;

	//Variables
	int pad1Score = 0;
	int pad2Score = 0;

//Shapes

	//Left Paddle
	sf::Paddle leftPaddle(50, 200, sf::Vector2f(50, 100));
	if (!(leftPaddle.setTexture("Data/pad.png"))) {
		return 3;
	}

	//Right Paddle
	sf::Paddle rightPaddle(700, 200, sf::Vector2f(50, 100));
	if (!(rightPaddle.setTexture("Data/pad.png"))) {
		return 4;
	}

	//Ball
	sf::Ball ball(400, 200, -4, -4, sf::Vector2f(50, 50));
	if (!(ball.setTexture("Data/ball.png"))) {
		return 5;
	}

	if (!(ball.setSound("Data/hit.wav"))) {
		return 6;
	}

	//Add Shapes to Screen
	screen.addDrawable(&leftPaddle.getShape());
	screen.addDrawable(&rightPaddle.getShape());
	screen.addDrawable(&ball.getShape());
	screen.addDrawable(&score);

	//Event object
	sf::Event event;

	//Game loop
	while (screen.isOpen()) {

		//Event handling loop
		while (screen.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				screen.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					upKey = true;
					break;

				case sf::Keyboard::Down:
					downKey = true;
					break;

				default:
					break;
				}
				break;

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					upKey = false;
					break;

				case sf::Keyboard::Down:
					downKey = false;
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}

		//Logic
		//Left Paddle
		if (upKey) {
			leftPaddle.setVelocity(-5);
		}

		if (downKey) {
			leftPaddle.setVelocity(5);
		}

		if (upKey && downKey) {
			leftPaddle.setVelocity(0);
		}

		if (!upKey && !downKey) {
			leftPaddle.setVelocity(0);
		}

		leftPaddle.move();

		//Right Paddle
		if (ball.getPosition().y < rightPaddle.getPosition().y) {
			rightPaddle.setVelocity(-2);
		}

		if (ball.getPosition().y > rightPaddle.getPosition().y) {
			rightPaddle.setVelocity(2);
		}

		rightPaddle.move();

		//Ball
		ball.move();

		
		//Incrementing Score
		if (ball.getPosition().x < -50) {
			pad2Score++;
			ball.setPosition(375, 275);
			ball.setxVelocity(-4);
		}

		if (ball.getPosition().x > 800) {
			pad1Score++;
			ball.setPosition(375, 275);
			ball.setxVelocity(-4);
		}

		//Collision Detection
		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds())) {
			ball.xBounce();
			ball.playSound();
		}

		if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
			ball.xBounce();
			ball.playSound();
		}

		//Rendering
		screen.clear();

		//Drawing the shapes
		std::stringstream text;
		text << pad1Score << " : " << pad2Score;
		score.setString(text.str());
		screen.draw();

		//Score

		screen.display();
	}

	return 0;
}
