#pragma once
#include <SFML/Graphics.hpp>
#include <list>

namespace sf {

	class Screen {
	public:
		static int WIDTH;
		static int HEIGHT;

	private:
		RenderWindow window;
		Texture backgroundTexture;
		RectangleShape background;
		std::list<Drawable*> drawables;

	public:
		Screen(int width, int height, String title, Uint32 style = Style::Default);
		~Screen();
		bool setBackground(String backgroundPath);
		bool isOpen();
		void close();
		bool pollEvent(Event& event);
		void addDrawable(Drawable* drawable);
		void clear();
		void draw();
		void display();

	private:

	};

}
