#include "Tower.h"


Tower::Tower(CCLayer* _layer, CCPoint _m_pos)
{

	isAttacking =false;
	layer = _layer;
	m_Stower = CCSprite::create("tower.png");
	m_pos = _m_pos;
	m_Stower->setAnchorPoint(CCPoint(0.5,0.5));
	m_Stower->setPosition(m_pos);
	layer->addChild(m_Stower);
	m_range = 80;
	fireRate = 0;
	m_bulletManager = new BulletManager();
	

	circle = CCSprite::create("circle1.png");
	circle->setAnchorPoint(CCPoint(0.5,0.5));
	circle->setPosition(m_pos);
	layer->addChild(circle);
	circle->setOpacity(100);
	
	
}

Tower::~Tower(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Tower ::draw()
{

	glLineWidth(1);
	ccDrawColor4B(255, 255, 255, 255);
	cocos2d::ccDrawCircle( m_Stower->getPosition(), m_range, CC_DEGREES_TO_RADIANS(90), 50, false);
	
}
void Tower ::shoot(Character* m_enemy, float dt)
{
	
	CCPoint totarget =  ccpSub(m_enemy->coin->getPosition(), this->m_pos);
	float a = ccpDot(m_enemy->m_velocity,m_enemy->m_velocity) - (3.5 *3.5);
	float b = 2 * ccpDot(m_enemy->m_velocity, totarget);
	float c = ccpDot(totarget,totarget);

	float p = -b / (2 * a);
	float q = (float)sqrt((b * b) - 4 * a * c) / (2 * a);

	float t1 = p - q;
	float t2 = p + q;
	float t;

	if (t1 > t2 && t2 > 0)
	{
		t = t2;
	}
	else
	{
		t = t1;
	}

	//CCLOG("thoi gian :%f",t);
	CCPoint aimSpot = ccpAdd(m_enemy->coin->getPosition() ,ccpMult(m_enemy->m_velocity,t)); //position of target in future after t seconds

	m_bulletManager->addBullet(new Bullet(layer, m_pos));

	for (int i =0; i < m_bulletManager->getListBullet().size(); i++)
	{
		m_bulletManager->getBullet(i)->setTarget(aimSpot);
		m_bulletManager->getBullet(i)->m_Active = true;

	}

// 	CCPoint bulletPath = ccpSub(aimSpot,this->m_pos); 
// 	float timeToImpact = ccpLength(bulletPath) / bullet->m_maxV;//speed must be in units per second
}

void Tower ::update(float dt)
{
	m_bulletManager->update(dt);
	


}
void Tower ::removeBullet(CCNode* sender)
{
	CCSprite *sprite = (CCSprite *)sender;
    layer->removeChild(sprite, true);
}
void Tower ::Collision(Character* m_enemy, float dt)
{


	//m_choosedEnemy = m_enemy;
	if( circle->boundingBox().intersectsRect(m_enemy->coin->boundingBox()) ){
		fireRate+=dt;
		if(fireRate >=1 )
		{
			fireRate = 0;
		    shoot(m_enemy,dt);
		}
	}
	m_bulletManager->collision(m_enemy);
}


