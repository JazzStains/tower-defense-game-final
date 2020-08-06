#pragma once
#include "Defender.h"
#include "SkeletonDemon.h"
#include <GameEngine/ResourceManager.h>

class BoarMan : public Defender
{
public:
	BoarMan(glm::vec2 pos);
	BoarMan();
	void setPosition(glm::vec2 pos);
	void walking(SkeletonDemon& target, int screenWidth);
	

};



