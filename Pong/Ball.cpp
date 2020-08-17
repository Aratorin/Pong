#include "Ball.h"
#include "Screen.h"

namespace sf {

	Ball::Ball(int xPosition, int yPosition, int xVelocity, int yVelocity, Vector2f size) :size(size), xVelocity(xVelocity), yVelocity(yVelocity) {
		shape.setSize(size);
		setPosition(xPosition, yPosition);
	}

	bool Ball::setTexture(String texturePath) {
		if (!(texture.loadFromFile(texturePath))) {
			return false;
		}

		shape.setTexture(&texture);

		return true;
	}

	bool Ball::setSound(String soundPath) {
		if (!(soundBuffer.loadFromFile(soundPath))) {
			return false;
		}

		sound.setBuffer(soundBuffer);

		return true;
	}

	void Ball::setxVelocity(int xVelocity) {
		this->xVelocity = xVelocity;
	}

	void Ball::setyVelocity(int yVelocity) {
		this->yVelocity = yVelocity;
	}

	void Ball::move() {
		shape.move(xVelocity, yVelocity);

		if (shape.getPosition().y < 0) {
			shape.setPosition(shape.getPosition().x, 0);
			yVelocity = -yVelocity;
		}

		if (shape.getPosition().y > Screen::HEIGHT - size.y) {
			shape.setPosition(shape.getPosition().x, (Screen::HEIGHT - size.y));
			yVelocity = -yVelocity;
		}
	}

	RectangleShape& Ball::getShape() {
		return shape;
	}

	const Vector2f& Ball::getPosition() {
		return shape.getPosition();
	}

	sf::FloatRect Ball::getGlobalBounds() {
		return shape.getGlobalBounds();
	}

	void Ball::setPosition(int xPosition, int yPosition) {
		shape.setPosition(xPosition, yPosition);
	}

	void Ball::xBounce() {
		setxVelocity(-xVelocity);
	}

	void Ball::playSound() {
		sound.play();
	}

	void Ball::setVolume(float volume) {
		sound.setVolume(volume);
	}

}
