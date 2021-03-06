/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <base/vmath.h>

class CCollision
{
	int *m_pPhysicsTiles;
	int m_PhysicsWidth;
	int m_PhysicsHeight;
	
	int *m_pZoneTiles;
	int m_ZoneWidth;
	int m_ZoneHeight;
	
	class CLayers *m_pLayers;

	bool IsTileSolid(int x, int y);
	int GetTile(int x, int y);
	int GetZoneTile(int x, int y);

public:
	enum
	{
		COLFLAG_SOLID=1,
		COLFLAG_NOHOOK=2,
		COLFLAG_WATER=4,
		
		ZONEFLAG_DEATH=1,
		ZONEFLAG_INFECTION=2,
		ZONEFLAG_NOSPAWN=4,
	};

	CCollision();
	~CCollision();
	void Init(class CLayers *pLayers);
	bool CheckPoint(float x, float y) { return IsTileSolid(round(x), round(y)); }
	bool CheckPoint(vec2 Pos) { return CheckPoint(Pos.x, Pos.y); }
	int GetCollisionAt(float x, float y) { return GetTile(round(x), round(y)); }
	int GetWidth() { return m_PhysicsWidth; };
	int GetHeight() { return m_PhysicsHeight; };
	int IntersectLine(vec2 Pos0, vec2 Pos1, vec2 *pOutCollision, vec2 *pOutBeforeCollision);
	void MovePoint(vec2 *pInoutPos, vec2 *pInoutVel, float Elasticity, int *pBounces);
	void MoveBox(vec2 *pInoutPos, vec2 *pInoutVel, vec2 Size, float Elasticity);
	bool TestBox(vec2 Pos, vec2 Size);
	
/* INFECTION MODIFICATION START ***************************************/
	bool CheckPhysicsFlag(vec2 Pos, int Flag);
	bool CheckZoneFlag(vec2 Pos, int Flag);
/* INFECTION MODIFICATION END *****************************************/
};

#endif
