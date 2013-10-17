#pragma once
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
using namespace cocos2d;
class Bullet : public cocos2d ::CCNode
{
public:

	bool m_Col ;
	bool m_Active;
	CCPoint m_target;
	CCPoint m_pos;
	CCPoint staringpoint;
	CCLayer* layer;
	CCSprite* m_bullet;
	CCPoint m_V;
	float m_maxV;
	void setTarget(CCPoint);
	void update(float dt);
	void Collision(Character* );
	void removeBullet ();
	Bullet(CCLayer*, CCPoint);
	Bullet(CCLayer*, CCPoint, CCPoint);
	~Bullet(void);
};

#endif 

