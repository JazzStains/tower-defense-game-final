#pragma once
#include <GameEngine/ResourceManager.h>
#include <glm/glm.hpp>
#include <GameEngine/SpriteBatch.h>
#include <GameEngine/GLTexture.h>

class BackGround
{
public:
	BackGround();
	void init(int width, int height,std::string pathFile);
	void draw(GameEngine::SpriteBatch& spriteBatch);
	void setBackGround(std::string filePath);
private:
	int _height;
	int _width;
	GameEngine::GLTexture _texture;
	GameEngine::SpriteBatch _spriteBatch;
	

};

