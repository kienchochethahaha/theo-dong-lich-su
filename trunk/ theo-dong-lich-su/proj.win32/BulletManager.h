#pragma once
#include "cocos2d.h"
#include <vector>
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>       
#include "Path.h"
#include "Character.h"

#include "Bullet.h"
using namespace cocos2d;
using namespace std;
class BulletManager
{

protected:
	vector<Bullet*> m_listBullet;
	
public:
	BulletManager(void);
	~BulletManager(void);

	void update(float dt);
	void collision(Character* _enemy);
	void addBullet (Bullet* bullet);

	Bullet* getBullet(int index)
	{
		return m_listBullet[index];
		
	}
	vector<Bullet*> getListBullet()
	{
		return m_listBullet;

	}
};

