#include "Paddle.h"
#include "Screen.h"

namespace sf {

	Paddle::Paddle(int xPosition, int yPosition, Vector2f size) :xPosition(xPosition), yPosition(yPosition), size(size), velocity(0) {
		shape.setSize(size);
		setPosition(xPosition, yPosition);
	}

	bool Paddle::setTexture(String texturePath) {
		if (!(texture.loadFromFile(texturePath))) {
			return false;
		}

		shape.setTexture(&texture);

		return true;
	}

	void Paddle::setVelocity(int velocity) {
		this->velocity = velocity;
	}

	void Paddle::move() {
		shape.move(0, velocity);

		if (shape.getPosition().y < 0) {
			shape.setPosition(xPosition, 0);
		}

		if (shape.getPosition().y > Screen::HEIGHT - size.y) {
			shape.setPosition(xPosition, (Screen::HEIGHT - size.y));
		}
	}

	RectangleShape& Paddle::getShape() {
		return shape;
	}

	const Vector2f& Paddle::getPosition() {
		return shape.getPosition();
	}

	sf::FloatRect Paddle::getGlobalBounds() {
		return shape.getGlobalBounds();
	}

	void Paddle::setPosition(int xPosition, int yPosition) {
		shape.setPosition(xPosition, yPosition);
	}

}
