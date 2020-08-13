#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
	//Creating and configuring the RenderWindow
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	//Load font
	sf::Font font;
	if (!(font.loadFromFile("Data/arial.ttf"))) {
		return 1;
	}

	//Load Textures
	sf::Texture padTexture;
	sf::Texture ballTexture;
	sf::Texture backgroundTexture;

	if (!(padTexture.loadFromFile("Data/pad.png"))) {
		return 1;
	}

	if (!(ballTexture.loadFromFile("Data/ball.png"))) {
		return 1;
	}

	if (!(backgroundTexture.loadFromFile("Data/background.png"))) {
		return 1;
	}

	//Load sound
	sf::SoundBuffer hitBuffer;

	if (!(hitBuffer.loadFromFile("Data/hit.wav"))) {
		return 1;
	}

	//States

	//Variables

//Shapes
	//Background
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(0, 0);
	background.setTexture(&backgroundTexture);

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

	//Event object
	sf::Event event;

	//Game loop
	while (window.isOpen()) {

		//Event handling loop
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();

			default:
				break;
			}
		}

		//Rendering
		window.clear();
		window.draw(background);
		window.draw(pad1);
		window.draw(pad2);
		window.draw(ball);
		window.display();
	}

	//Clean up
	if (window.isOpen()) {
		window.close();
	}

	return 0;
}
