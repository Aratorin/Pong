#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"
#include "Paddle.h"
#include "Ball.h"
#include "ScoreBoard.h"
#include <iostream>

/*Sounds and Sprites from https://opengameart.org/
Sprites by Nicolás A. Ortega (Deathsbreed)- copyright DeathsbreedGames
Collision sound by Bart Kelsey
Music by Trevor Lentz*/

int main() {
	//Create the render window
	sf::Screen screen(800, 600, "Pong");
	if (!screen.setBackground("Data/background.jpg")) {
		return 1;
	}

	if (!screen.setMusic("Data/music.wav")) {
		return 2;
	}

	screen.setVolume(5);

	//Create scoreboard
	sf::ScoreBoard scoreboard(30, sf::Color::Red, 375, 10);
	if (!(scoreboard.setFont("Data/arial.ttf"))) {
		return 3;
	}

	//States
	bool upKey = false;
	bool downKey = false;
	bool leftCollision = false;
	bool rightCollision = false;

//Shapes

	//Left Paddle
	sf::Paddle leftPaddle(10, 200, sf::Vector2f(10, 108));
	if (!(leftPaddle.setTexture("Data/leftPaddle.png"))) {
		return 4;
	}

	//Right Paddle
	sf::Paddle rightPaddle(780, 200, sf::Vector2f(10, 108));
	if (!(rightPaddle.setTexture("Data/rightPaddle.png"))) {
		return 5;
	}

	//Ball
	sf::Ball ball(400, 200, -4, -4, sf::Vector2f(21, 21));
	if (!(ball.setTexture("Data/ball.png"))) {
		return 6;
	}

	if (!(ball.setSound("Data/bounce.wav"))) {
		return 7;
	}

	ball.setVolume(10);

	//Add Shapes to Screen
	screen.addDrawable(&leftPaddle.getShape());
	screen.addDrawable(&rightPaddle.getShape());
	screen.addDrawable(&ball.getShape());
	screen.addDrawable(&scoreboard.getText());

	//Event object
	sf::Event event;

	//Game loop
	screen.playMusic();
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
			rightPaddle.setVelocity(-3.75);
		}

		if (ball.getPosition().y > rightPaddle.getPosition().y) {
			rightPaddle.setVelocity(3.75);
		}

		rightPaddle.move();

		//Ball
		ball.move();


		//Incrementing Score
		if (ball.getPosition().x < -50) {
			scoreboard.addPointRight();
			ball.setPosition(375, 275);
			ball.setxVelocity(-4);
		}

		if (ball.getPosition().x > 800) {
			scoreboard.addPointLeft();
			ball.setPosition(375, 275);
			ball.setxVelocity(-4);
		}

		//Collision Detection
		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) && !leftCollision) {
			ball.xBounce();
			ball.playSound();
			leftCollision = true;
		} else if (!(ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))) {
			leftCollision = false;
		}

		if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()) && !rightCollision) {
			ball.xBounce();
			ball.playSound();
			rightCollision = true;
		} else if (!(ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))) {
			rightCollision = false;
		}

		//Rendering
		screen.clear();

		//Drawing the shapes
		scoreboard.updateString();
		screen.draw();

		//Score

		screen.display();
	}

	return 0;
}
