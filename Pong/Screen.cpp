#include "Screen.h"

namespace sf {

	Screen::Screen(int width, int height, String title, Uint32 style) :window(VideoMode(width, height), title, style) {
		window.setFramerateLimit(60);
		window.setKeyRepeatEnabled(false);
		this->width = window.getSize().x;
		this->height = window.getSize().y;
	}

	Screen::~Screen() {
		window.close();
	}

	bool Screen::setBackground(String backgroundPath) {
		if (!(backgroundTexture.loadFromFile(backgroundPath))) {
			return false;
		}

		background.setSize(Vector2f(width, height));
		background.setPosition(0, 0);
		background.setTexture(&backgroundTexture);
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
		for (auto drawable:drawables) {
			window.draw(*drawable);
		}
	}

	void Screen::display() {
		window.display();
	}

}
