#include "game.h"
#include <cstdlib>

using namespace game;

void Player::draw(RenderWindow* window)
{
	window->draw(duckSprite);
}

void Player::jump(RenderWindow* window, Enemy* enemy, Sprite* backgroundSprite)
{
	isGrnd = false;
	Clock clock;
	float time;
	float timer = 0, delay = 0.005;
	int up = 0, down = 0, freeze = 0;;

	while (up < 10) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (timer > delay)
		{
			enemy->back(window);
			duckSprite.move(0, -20.f);
			enemy->move();
			window->clear();
			window->draw(*backgroundSprite);
			enemy->draw(window);
			window->draw(duckSprite);
			window->display();
			up++;
			timer = 0;
		}
	}
	while (freeze < 20) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (timer > delay)
		{
			enemy->back(window);
			enemy->move();
			window->clear();
			window->draw(*backgroundSprite);
			enemy->draw(window);
			window->draw(duckSprite);
			window->display();
			freeze++;
			timer = 0;
		}
	}
	while (down < 10) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (timer > delay)
		{
			enemy->back(window);
			duckSprite.move(0, 20.f);
			enemy->move();
			window->clear();
			window->draw(*backgroundSprite);
			enemy->draw(window);
			window->draw(duckSprite);
			window->display();
			down++;
			timer = 0;
		}
	}
	isGrnd = true;
}

void game::Player::reset(RenderWindow* window)
{
	duckSprite.setTexture(duckTexture);
	duckSprite.setPosition(Vector2f(50, window->getSize().y - size.y));
}

void game::Player::dead()
{
	duckTexture.loadFromFile("dead_duck.png");
	duckSprite.setTexture(duckTexture);
}

void game::Player::alive()
{
	duckTexture.loadFromFile("duck_1.png");
	duckSprite.setTexture(duckTexture);
}

Player::Player(RenderWindow* window)
{
	duckTexture.loadFromFile("duck_1.png");
	duckSprite.setTexture(duckTexture);
	duckSprite.setPosition(Vector2f(50, window->getSize().y - size.y));

}

Enemy::Enemy(RenderWindow* window)
{
	enemyTexture.loadFromFile("enemy_1.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setPosition(Vector2f(window->getSize().x - size.x, window->getSize().y - size.x));
}

void Enemy::draw(RenderWindow* window)
{
	window->draw(enemySprite);
}

void game::Enemy::move()
{
	enemySprite.move(-speed, 0);
}

void game::Enemy::back(RenderWindow* window)
{
	if (enemySprite.getPosition().x + size.x <= 0)enemySprite.setPosition(Vector2f(window->getSize().x, window->getSize().y - size.y));
}

void game::Enemy::reset(RenderWindow* window)
{
	enemySprite.setTexture(enemyTexture);
	enemySprite.setPosition(Vector2f(window->getSize().x - size.x, window->getSize().y - size.x));
}

