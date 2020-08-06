#include "BoarMan.h"

BoarMan::BoarMan(glm::vec2 pos) {
	action = actionState::WALK;
	attackDamage = 30;
	speed = 0.1;
	tempSpeed = 0.1;
	attackSpeed = 250;
	position = glm::vec2(pos.x - 30, pos.y - 35);
	textureStanding = GameEngine::ResourceManager::getTexture("textures/BoarMan_Standing.png");
	textureWalking[0] = GameEngine::ResourceManager::getTexture("textures/BoarMan_WalkLeft.png");
	textureWalking[1] = GameEngine::ResourceManager::getTexture("textures/BoarMan_WalkMid.png");
	textureWalking[2] = GameEngine::ResourceManager::getTexture("textures/BoarMan_WalkRight.png");
	textureAttacking[0] = GameEngine::ResourceManager::getTexture("textures/BoarMan_Attacking1.png");
	textureAttacking[1] = GameEngine::ResourceManager::getTexture("textures/BoarMan_Attacking2.png");
	textureAttacking[2] = GameEngine::ResourceManager::getTexture("textures/BoarMan_Attacking3.png");
	textureAttacking[3] = GameEngine::ResourceManager::getTexture("textures/BoarMan_Attacking4.png");
	textureAttacking[4] = GameEngine::ResourceManager::getTexture("textures/BoarMan_Attacking5.png");
	texture = textureStanding;
	life = 100;
	cost = 15;
}
BoarMan::BoarMan() {
	textureStanding = GameEngine::ResourceManager::getTexture("textures/BoarMan_Standing.png");
	texture = textureStanding;
	position = glm::vec2(0,0);
}

void BoarMan::setPosition(glm::vec2 pos){
	position = glm::vec2(pos.x - 30, pos.y - 35);
}

void BoarMan::walking(SkeletonDemon& target,int screenWidth) {
	if (((target.position.x - this->position.x) < (screenWidth)) && ((target.position.x - this->position.x) > 0)) {
		if (((target.position.y - this->position.y) < 10) && ((target.position.y - this->position.y) > -10)) {
			if (this->action != actionState::ATTACK)
				this->action = actionState::WALK;
		}
	}
}



