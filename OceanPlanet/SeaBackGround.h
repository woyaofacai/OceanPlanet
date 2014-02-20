// SeaBackGround.h: interface for the SeaBackGround class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEABACKGROUND_H__52E0D9B1_6994_4902_85B0_B5B8221D1E90__INCLUDED_)
#define AFX_SEABACKGROUND_H__52E0D9B1_6994_4902_85B0_B5B8221D1E90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>
#include <hgedistort.h>
#include <math.h>

class SeaBackGround  
{
public:
	SeaBackGround(HTEXTURE);
	~SeaBackGround();
	Draw();
	Update(float);
private:
	float t;
	const int nRows;
	const int nCols;
	hgeDistortionMesh* disMesh;
};

#endif // !defined(AFX_SEABACKGROUND_H__52E0D9B1_6994_4902_85B0_B5B8221D1E90__INCLUDED_)
