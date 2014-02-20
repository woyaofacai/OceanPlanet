// BombState.h: interface for the BombState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBSTATE_H__B91260E7_895F_41E0_ACDB_F6D8D0211437__INCLUDED_)
#define AFX_BOMBSTATE_H__B91260E7_895F_41E0_ACDB_F6D8D0211437__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000

class Bomb;

class BombState
{
public:
	//virtual SendMessage(int, Bomb*) = 0;
	BombState();
	virtual ~BombState();
	virtual Enter(Bomb*) = 0;
	virtual Update(Bomb*, float) = 0;
	virtual Draw(Bomb*) = 0;
	virtual Leave(Bomb*) = 0;
//	virtual SendMessage(Bomb*);
};

#endif // !defined(AFX_BOMBSTATE_H__B91260E7_895F_41E0_ACDB_F6D8D0211437__INCLUDED_)
 