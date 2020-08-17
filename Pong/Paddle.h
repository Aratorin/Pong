#pragma once
#include <SFML/Graphics.hpp>

namespace sf {

	class Paddle {
	public:
	
	private:
		int xPosition;
		int yPosition;
		Vector2f size;
		Texture texture;
		double velocity;
		RectangleShape shape;
	public:
		Paddle(int xPosition, int yPosition, Vector2f size);
		bool setTexture(String texturePath);
		void setVelocity(double velocity);
		void move();
		RectangleShape& getShape();
		const Vector2f& getPosition();
		sf::FloatRect getGlobalBounds();
	
	private:
		void setPosition(int xPosition, int yPosition);
	};

}
