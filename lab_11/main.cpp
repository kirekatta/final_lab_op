#include"game.h"

using namespace sf;
using namespace game;

int main()
{
	RenderWindow window(VideoMode(800, 300), "Stay Alive!");
	Clock clock;
	Texture backgroundTexture;
	Font font;
	font.loadFromFile("font.ttf");
	Text text;

	text.setFont(font);
	text.setCharacterSize(70);
	text.setPosition(window.getSize().x/2,window.getSize().y/2);
	text.setString("Game Over");
	text.setScale(0, 0);

	backgroundTexture.loadFromFile("background.png");
	Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	float time,timer=0,delay = 0.01;
	bool pause = true, gameIsOver = false;
	Player player(&window);
	Enemy enemy(&window);
	window.clear();
	window.draw(backgroundSprite);
	enemy.draw(&window);
	player.draw(&window);
	window.display();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up && !pause){
					if (player.isGround() && enemy.getPosition().x <= player.getPosition().x + player.getSize().x / 1.6 &&
						enemy.getPosition().x + enemy.getSize().x / 1.1 > player.getPosition().x) {
						gameIsOver = true;
						pause = true;
						player.dead();
						window.clear();
						backgroundSprite.setColor(Color::Red);
						window.draw(backgroundSprite);
						text.setScale(1, 1);
						window.draw(text);
						player.draw(&window);
						enemy.draw(&window);
						window.display();
					}
					else
						player.jump(&window,&enemy,&backgroundSprite);
				}
				if (event.key.code == Keyboard::P&&!gameIsOver) {
					pause = !pause;
				}
				if (event.key.code == Keyboard::R) {
					text.setScale(0, 0);
					player.alive();
					backgroundSprite.setColor(Color::White);
					gameIsOver = false;
					enemy.reset(&window);
					player.reset(&window);
					pause = true;
					window.clear();
					window.draw(backgroundSprite);
					enemy.draw(&window);
					player.draw(&window);
					window.display();

				}
			}
		}
		if (!pause) {
			time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;
			if (timer > delay)
			{
				enemy.back(&window);
				enemy.move();
				if (player.isGround() && enemy.getPosition().x <= player.getPosition().x + player.getSize().x / 1.6 &&
					enemy.getPosition().x + enemy.getSize().x / 1.1> player.getPosition().x) {
					gameIsOver = true;
					pause = true;
					player.dead();
					backgroundSprite.setColor(Color::Red);

					window.clear();
					text.setScale(1, 1);
					window.display();
				}
				timer = 0;
			}
			window.clear();
			window.draw(backgroundSprite);
			window.draw(text);
			enemy.draw(&window);
			player.draw(&window);
			window.display();
		}
	}
	return 0;
}