#include "SkeletonDemon.h"

SkeletonDemon::SkeletonDemon(glm::vec2 pos) {
	action = actionState::WALK;
	attackDamage = 10;
	speed = -0.1;
	position = pos;
	attackSpeed = 200;
	textureStanding = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Standing.png");
	textureWalking[0] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_WalkLeft.png");
	textureWalking[1] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_WalkMid.png");
	textureWalking[2] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_WalkRight.png");
	textureAttacking[0] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Attacking1.png");
	textureAttacking[1] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Attacking2.png");
	textureAttacking[2] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Attacking3.png");
	textureAttacking[3] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Attacking3.png");
	textureAttacking[4] = GameEngine::ResourceManager::getTexture("textures/SkeletonDemon_Attacking4.png");
	texture = textureStanding;
	life = 100;
	sizeMultiplier = 2;
}