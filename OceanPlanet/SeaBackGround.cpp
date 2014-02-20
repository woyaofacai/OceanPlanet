// SeaBackGround.cpp: implementation of the SeaBackGround class.
//
//////////////////////////////////////////////////////////////////////

#include "constants.h"
#include "SeaBackGround.h"

extern HGE* hge;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SeaBackGround::SeaBackGround(HTEXTURE texture):nCols(16), nRows(16), t(0)
{		
	disMesh=new hgeDistortionMesh(16, 16);
	disMesh->SetTexture(texture);
	disMesh->SetTextureRect(0,0,hge->Texture_GetWidth(texture),hge->Texture_GetHeight(texture));
	disMesh->SetBlendMode(BLEND_COLORADD | BLEND_ALPHABLEND | BLEND_ZWRITE);
	disMesh->Clear(0xFF000000);
}

SeaBackGround::~SeaBackGround()
{
	delete disMesh;
}

SeaBackGround::Update(float delta)
{
	t += delta;
	int i,j;
	int color;
	for(i=0;i<nRows;i++) {
		for(j=1;j<nCols-1;j++)
		{
			disMesh->SetDisplacement(j,i,cosf(t*10+(i+j)/2)*5,sinf(t*10+(i+j)/2)*5,HGEDISP_NODE);
			
			/*
			disMesh->SetDisplacement(j,i,cosf(t*5+j/2)*15,0,HGEDISP_NODE);
			color = int((cosf(t*5+(i+j)/2)+1)*35);
			disMesh->SetColor(j,i,0xFF<<24 | color<<16 | color<<8 | color);
			*/
		 }
	}
}

SeaBackGround::Draw()
{
	disMesh->Render(-10, -10);
}
