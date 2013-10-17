#include "Bullet.h"

Bullet::Bullet(CCLayer* _layer, CCPoint _pos)
{
	m_Col = false;
	m_Active = false;
	m_maxV = 8;
	layer = _layer;
	m_pos = _pos;
	m_V = CCPoint(0,0);
	m_target =  _pos;
	m_bullet = CCSprite::create("bullet.png");
	m_bullet->setAnchorPoint(CCPoint(0.5,0.5));
	m_bullet->setPosition(m_pos);
	
	layer->addChild(m_bullet);
}


Bullet::Bullet(CCLayer* _layer, CCPoint _pos, CCPoint _target)
{
	m_maxV = 3;
	layer = _layer;
	m_pos = _pos;
	m_target = _target;
	m_bullet = CCSprite::create("bullet.png");
	m_bullet->setAnchorPoint(CCPoint(0.5,0.5));
	m_bullet->setPosition(m_pos);
	m_V = ccpNormalize( ccpSub(m_target,m_pos) );
	m_V =  ccpMult(m_V,m_maxV);

	layer->addChild(m_bullet);
}


Bullet::~Bullet(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Bullet:: setTarget(CCPoint _target)
{
	m_target = _target;
}
void Bullet::removeBullet()
{
	layer->removeChild(m_bullet);
}
void Bullet ::Collision(Character*  _enemy)
{
	if( m_bullet->boundingBox().intersectsRect(_enemy->coin->boundingBox()))
	{
		m_Col = true;
		CCLOG("trung roi nay ");
	}
	
}
void Bullet ::update(float dt)
{
	if(m_Active ==true)
	{

		m_V = ccpNormalize( ccpSub(m_target,m_pos) );
		m_V =  ccpMult(m_V,m_maxV);
		m_pos = ccpAdd(m_pos,m_V);
		m_bullet->setPosition(m_pos);
	}
	
}
