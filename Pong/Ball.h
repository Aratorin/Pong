#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace sf {

	class Ball {
	public:

	private:
		Vector2f size;
		Texture texture;
		int xVelocity;
		int yVelocity;
		RectangleShape shape;
		SoundBuffer soundBuffer;
		Sound sound;

	public:
		Ball(int xPosition, int yPosition, int xVelocity, int yVelocity, Vector2f size);
		bool setTexture(String texturePath);
		bool setSound(String soundPath);
		void setxVelocity(int xVelocity);
		void setyVelocity(int yVelocity);
		void move();
		RectangleShape& getShape();
		const Vector2f& getPosition();
		sf::FloatRect getGlobalBounds();
		void setPosition(int xPosition, int yPosition);
		void xBounce();
		void playSound();

	private:
		
	};

}
