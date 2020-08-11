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

		window.display();
	}

	//Clean up
	if (window.isOpen()) {
		window.close();
	}

	return 0;
}
