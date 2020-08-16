#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
		Music music;

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
		bool setMusic(String musicPath);
		void setVolume(float volume);
		void playMusic();

	private:

	};

}
