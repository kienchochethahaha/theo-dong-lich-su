#pragma once
#ifndef __Tower_H__
#define __Tower_H__
#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
#include "Bullet.h"
#include "BulletManager.h"

using namespace cocos2d;
class Tower : public cocos2d ::CCNode
{
public:

	
	CCSprite* circle;
	BulletManager* m_bulletManager;
	Character* m_choosedEnemy;
	bool isAttacking;
	CCSprite* m_Stower;
	
    CCLayer* layer;
	float fireRate;
	float m_Damage;
	float m_range;
	CCPoint m_pos;
	void Collision(Character*, float );
	void shoot(Character*,float);

	void update (float dt);
	void removeBullet (CCNode* sender);
    virtual void draw();


	Tower(CCLayer*,CCPoint);
	~Tower(void);
};
#endif

