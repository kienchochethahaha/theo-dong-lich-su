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
class ManagerObject
{
private:
	vector<Character*> *m_listEnemy;
	ManagerObject(void);
	static ManagerObject* m_Instance;
public:


	static ManagerObject* Instance()
	{
		if (m_Instance==NULL)
		{
			m_Instance = new ManagerObject();
		}
		return m_Instance;
	}	
	vector<Character*>*getListEnemy()
	{

		return m_listEnemy;
	}
	void setListEnemy (vector<Character*>* _list)
	{
		m_listEnemy = _list;
	}

	~ManagerObject(void);
};

