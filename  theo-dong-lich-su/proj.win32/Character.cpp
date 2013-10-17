#include "Character.h"


Character::Character(CCLayer* _layer, Path* _path)
{
	path = _path;
	currentNode = 0;
	nodes = path->getNodes(); //get path
	m_position = CCPoint( 379,620);
	m_velocity = CCPoint(-1,-1);
	m_desiredV = CCPoint (0,0);
	m_steeringV = CCPoint (0,0);
	m_targetPosition = nodes->at(currentNode); //get target
	

	maxVelocity = 1;
	max_force = maxVelocity*3;
	mass = 0.05;
	layer = _layer;

	coin = CCSprite::create("coint.png");
	coin->setPosition(ccp(m_position.x,m_position.y));
	coin->setScale(0.4);
	coin->setTag(1);
	
	layer->addChild(coin);
	
}


Character::~Character(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Character::update(float dt)
{
	  ///	m_steeringV = seek(m_targetPosition);

	    m_steeringV = pathFollowing();
	  	m_steeringV = truncate(m_steeringV,max_force);
	  	m_steeringV =  ccpMult(m_steeringV, mass);
	 
	 	m_velocity = ccpAdd(m_velocity,m_steeringV);
	 	m_velocity = truncate(m_velocity,maxVelocity); //vector velocity of character - target of tower

	 	coin->setPosition(CCPoint (coin->getPositionX() + m_velocity.x, coin->getPositionY() + m_velocity.y  ));
}
CCPoint Character::pathFollowing()
{
	if(path!=NULL)
	{
		m_targetPosition = nodes->at(currentNode);  
		if(Distance(this->coin,m_targetPosition) <= path->getRadisPath())
		{
			currentNode +=1;
			if(currentNode >=nodes->size() ){
				
				currentNode = nodes->size() -1;
			}
		}
	
	}
		return seek(m_targetPosition) ;
}
float Character::Distance(CCSprite* a, CCPoint b)
{
	return sqrt((a->getPositionX() - b.x) * (a->getPositionX() - b.x)  + (a->getPositionY() - b.y) * (a->getPositionY() - b.y));
}

CCPoint Character::seek(CCPoint target) //return steering vecto
{
	m_desiredV = ccpSub(m_targetPosition, coin->getPosition());
	m_desiredV = ccpNormalize(m_desiredV);
	m_desiredV = ccpMult(m_desiredV,maxVelocity);
	return ccpSub(m_desiredV, m_velocity);
}
CCPoint Character::truncate(CCPoint vector, float max)
{
	float i = ccpLength(vector)/ max ;
	i = i<1.0 ? 1.0 :1/i;
	return ccpMult(vector,i);
}
