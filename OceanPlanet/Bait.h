// Bait.h: interface for the Bait class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BAIT_H__90B8D5BC_DD9D_4A12_9DC5_FE6865A3BAE1__INCLUDED_)
#define AFX_BAIT_H__90B8D5BC_DD9D_4A12_9DC5_FE6865A3BAE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgerect.h>
#include <hgevector.h>
#include "constants.h"

extern HGE* hge;

class Bait  
{
public:
	Bait();
	~Bait();
	hgeVector& GetCenter();
	int Amount;
private:
	hgeVector center;
};

#endif // !defined(AFX_BAIT_H__90B8D5BC_DD9D_4A12_9DC5_FE6865A3BAE1__INCLUDED_)
