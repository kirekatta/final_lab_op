#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;

namespace game {

	class Enemy{
	public:
		Enemy(RenderWindow* window);
		void draw(RenderWindow* window);
		void move();
		void back(RenderWindow* window);
		void reset(RenderWindow* window);
		Vector2f getSize() { return size; };
		Vector2f getPosition() { return enemySprite.getPosition(); }
		float speed = 7.f;

	private:
		Texture enemyTexture;
		Sprite enemySprite;
		Vector2f size = Vector2f(128, 128);
	};

	class Player {
	public:
		Player(RenderWindow* window);
		void draw(RenderWindow* window);
		void jump(RenderWindow* window, Enemy* enemy,Sprite* backgroundSprite);
		void reset(RenderWindow* window);
		void dead();
		void alive();
		Vector2f getSize() { return size; };
		Vector2f getPosition() { return duckSprite.getPosition(); }
		bool isGround() { return isGrnd; };
	private:
		Texture duckTexture;
		Sprite duckSprite;
		Vector2f size = Vector2f(128, 128);
		bool isGrnd = true;
	};
}

