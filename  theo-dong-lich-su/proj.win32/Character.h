#pragma once

#ifndef __Character_H__
#define __Character_H__
#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Path.h"

using namespace cocos2d;
class Character : public cocos2d::CCNode
{
public:
	CCLayer* layer;
	CCSprite* coin;
	Path* path;
	std::vector<CCPoint>* nodes;
	// Node dang huong' toi'
	int currentNode ;

	// vi tri cua thang châracter
	CCPoint m_position;

	//3 cai nay lien quan den van toc
	CCPoint m_targetPosition;
	CCPoint m_desiredV;
	CCPoint m_velocity;

	CCPoint m_steeringV;
	float max_force;
	//gia tri max cua van toc va khoi luong cua character, mass khong can cung dc
	float maxVelocity;
	float mass;

	CCPoint pathFollowing();
	CCPoint seek (CCPoint );
	CCPoint truncate(CCPoint, float);
	CCPoint getAngle(CCPoint vector);

	float Distance (CCSprite*, CCPoint);
	void update(float delta);

	Character(CCLayer*, Path*);
	~Character(void);
};

#endif  // __Path_H__
