#include "Screen.h"

namespace sf {

	int Screen::WIDTH = NULL;
	int Screen::HEIGHT = NULL;

	Screen::Screen(int width, int height, String title, Uint32 style) :window(VideoMode(width, height), title, style) {
		window.setFramerateLimit(60);
		window.setKeyRepeatEnabled(false);
		WIDTH = window.getSize().x;
		HEIGHT = window.getSize().y;
	}

	Screen::~Screen() {
		window.close();
	}

	bool Screen::setBackground(String backgroundPath) {
		if (!(backgroundTexture.loadFromFile(backgroundPath))) {
			return false;
		}

		background.setSize(Vector2f(WIDTH, HEIGHT));
		background.setPosition(0, 0);
		background.setTexture(&backgroundTexture);

		return true;
	}

	bool Screen::isOpen() {
		return window.isOpen();
	}

	void Screen::close() {
		window.close();
	}

	bool Screen::pollEvent(Event& event) {
		return window.pollEvent(event);
	}

	void Screen::addDrawable(Drawable* drawable) {
		drawables.push_back(drawable);
	}

	void Screen::clear() {
		window.clear();
	}

	void Screen::draw() {
		window.draw(background);
		for (auto drawable : drawables) {
			window.draw(*drawable);
		}
	}

	void Screen::display() {
		window.display();
	}

	bool Screen::setMusic(String musicPath) {
		if (!(music.openFromFile(musicPath))) {
			return false;
		}

		music.setLoop(true);

		return true;
	}

	void Screen::setVolume(float volume) {
		music.setVolume(volume);
	}

	void Screen::playMusic() {
		music.play();
	}

}
