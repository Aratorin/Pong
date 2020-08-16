#include "ScoreBoard.h"

namespace sf {

	ScoreBoard::ScoreBoard(unsigned int fontSize, Color color, int xPosition, int yPosition):leftScore(0),rightScore(0) {
		text.setCharacterSize(fontSize);
		text.setFillColor(color);
		text.setPosition(xPosition, yPosition);
		updateString();
	}

	bool ScoreBoard::setFont(String fontPath) {
		if (!(font.loadFromFile(fontPath))) {
			return false;
		}

		text.setFont(font);

		return true;
	}

	void ScoreBoard::updateString() {
		std::stringstream string;
		string << leftScore << " : " << rightScore;
		text.setString(string.str());
	}

	Text& ScoreBoard::getText() {
		return text;
	}

	void ScoreBoard::addPointLeft() {
		leftScore++;
	}

	void ScoreBoard::addPointRight() {
		rightScore++;
	}

}