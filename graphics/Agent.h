#pragma once
#include<GameEngine/SpriteBatch.h>
#include <glm/glm.hpp>
#include <GameEngine/GLTexture.h>
#include <GameEngine/Vertex.h>

enum class actionState { STAND, WALK, ATTACK };

class Agent
{
public:
	Agent();
	virtual ~Agent();
	void draw(GameEngine::SpriteBatch& spriteBatch);
	bool update();
	void setSpeed(int _speed);
	glm::vec2 position;
	double sizeMultiplier;
	GameEngine::GLTexture texture;
	actionState action;
	bool dealDamage;
	void takeDamage(int damage);
	int getDamage();
	void attacking(Agent& victim);
protected:
	float tempSpeed;
	float speed;
	float life;
	float attackDamage;
	float attackSpeed;
	float defense;
	float height;
	float width;
	GameEngine::GLTexture textureStanding;
	GameEngine::GLTexture textureWalking[3];
	GameEngine::GLTexture textureAttacking[5];
	int  walkCounter;
	int attackCounter;
	int walkState;
	int attackState;
	
	


	
};

