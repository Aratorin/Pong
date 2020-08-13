#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"

int main() {
	
	sf::Screen screen(800, 600, "Pong");
	screen.setBackground("Data/background.png");

	//Load font
	sf::Font font;
	if (!(font.loadFromFile("Data/arial.ttf"))) {
		return 1;
	}

	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setFillColor(sf::Color::Red);
	score.setPosition(375, 10);
	score.setString("0 : 0");

	//Load Textures
	sf::Texture padTexture;
	sf::Texture ballTexture;
	

	if (!(padTexture.loadFromFile("Data/pad.png"))) {
		return 1;
	}

	if (!(ballTexture.loadFromFile("Data/ball.png"))) {
		return 1;
	}

	
	//Load sound
	sf::SoundBuffer hitBuffer;
	sf::Sound hit;
	hit.setBuffer(hitBuffer);

	if (!(hitBuffer.loadFromFile("Data/hit.wav"))) {
		return 1;
	}

	//States
	bool upKey = false;
	bool downKey = false;

	//Variables
	int yVelocityPad1 = 0;
	int yVelocityPad2 = 0;
	int xVelocityBall = -4;
	int yVelocityBall = -4;
	int pad1Score = 0;
	int pad2Score = 0;

//Shapes
	

	//Pad1
	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(50, 100));
	pad1.setPosition(50, 200);
	pad1.setTexture(&padTexture);

	//Pad2
	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(50, 100));
	pad2.setPosition(700, 200);
	pad2.setTexture(&padTexture);

	//Ball
	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(400, 200);
	ball.setTexture(&ballTexture);

	screen.addDrawable(&pad1);
	screen.addDrawable(&pad2);
	screen.addDrawable(&ball);
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
		//Pad1
		if (upKey) {
			yVelocityPad1 = -5;
		}

		if (downKey) {
			yVelocityPad1 = 5;
		}

		if (upKey && downKey) {
			yVelocityPad1 = 0;
		}

		if (!upKey && !downKey) {
			yVelocityPad1 = 0;
		}

		pad1.move(0, yVelocityPad1);

		//Out of bounds check
		if (pad1.getPosition().y < 0) {
			pad1.setPosition(50, 0);
		}

		if (pad1.getPosition().y > 500) {
			pad1.setPosition(50, 500);
		}

		//Pad2
		if (ball.getPosition().y < pad2.getPosition().y) {
			yVelocityPad2 = -2;
		}

		if (ball.getPosition().y > pad2.getPosition().y) {
			yVelocityPad2 = 2;
		}

		pad2.move(0, yVelocityPad2);

		//Out of bounds check
		if (pad2.getPosition().y < 0) {
			pad2.setPosition(700, 0);
		}

		if (pad2.getPosition().y > 500) {
			pad2.setPosition(700, 500);
		}

		//Ball
		ball.move(xVelocityBall, yVelocityBall);

		//Out of bounds check
		if (ball.getPosition().y < 0) {
			yVelocityBall = -yVelocityBall;
		}

		if (ball.getPosition().y > 550) {
			yVelocityBall = -yVelocityBall;
		}

		if (ball.getPosition().x < -50) {
			pad2Score++;
			ball.setPosition(375, 275);
			xVelocityBall = -4;
		}

		if (ball.getPosition().x > 800) {
			pad1Score++;
			ball.setPosition(375, 275);
			xVelocityBall = -4;
		}

		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds())) {
			xVelocityBall = -xVelocityBall;
			hit.play();
		}

		if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds())) {
			xVelocityBall = -xVelocityBall;
			hit.play();
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

	//Clean up
	/*if (window.isOpen()) {
		window.close();
	}*/

	return 0;
}
