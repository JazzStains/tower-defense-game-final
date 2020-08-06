#include "Agent.h"
#include <iostream>
Agent::Agent() {
	sizeMultiplier = 1.5;
	walkCounter = 0;
	walkState = 0;
	attackCounter = 0;
	attackState = 0;
}
Agent::~Agent() {

}
void Agent::draw(GameEngine::SpriteBatch& spriteBatch) {
	GameEngine::ColorRGBA8 color;
	color = GameEngine::ColorRGBA8(255, 255,255,255);

	const glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 posAndSize = glm::vec4(position.x, position.y,texture.width * sizeMultiplier, texture.height * sizeMultiplier);
	spriteBatch.draw(posAndSize,uv, texture.id, 0.0f, color);

}
bool Agent::update() {

	switch (action)
	{
	case actionState::STAND:
		tempSpeed = 0;
		texture = textureStanding;
		break;
	case actionState::WALK:
		tempSpeed = speed;
		if( walkCounter == 250)
		{
			if (walkState < 3)
				texture = textureWalking[walkState];
			else{
				texture = textureWalking[1];
				walkState = -1;
			}
			
			walkState++;
			
			walkCounter = 0;
		}
		
		walkCounter++;
		break;
	case actionState::ATTACK:
		if (attackCounter == attackSpeed) {
			if (attackState < 4)
				texture = textureAttacking[attackState];
			if (attackState == 4)
				attackState = -1;
			if (attackState == 3)
				dealDamage = true;
			attackState++;

			attackCounter = 0;
		}
		attackCounter++;
		
		break;
	default:
		break;
	}
	position += glm::vec2(tempSpeed, 0.0f);
	if (life <= 0) {
		return true;
	}
	return false;
}

void Agent::setSpeed(int _speed) {
	tempSpeed = _speed;
}

void Agent::takeDamage(int damage) {
	life = life - damage;
}

int Agent::getDamage() {
	return attackDamage;
}

void Agent::attacking(Agent& target) {
	this->action = actionState::ATTACK;
	this->setSpeed(0);
	if (this->dealDamage == true) {
		target.takeDamage(this->getDamage());
		this->dealDamage = false;

	}
}