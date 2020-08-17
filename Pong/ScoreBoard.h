#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

namespace sf {

	class ScoreBoard {
	public:
	
	private:
		Font font;
		Text text;
		int leftScore;
		int rightScore;

	public:
		ScoreBoard(unsigned int fontSize, Color color, int xPosition, int yPosition);
		bool setFont(String fontPath);
		void updateString();
		Text& getText();
		void addPointLeft();
		void addPointRight();

	private:
	
	};

}
