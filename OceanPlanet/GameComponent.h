// GameComponent.h: interface for the GameComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMECOMPONENT_H__451C2DEF_CEDF_41D4_9696_04E28FC8AA3A__INCLUDED_)
#define AFX_GAMECOMPONENT_H__451C2DEF_CEDF_41D4_9696_04E28FC8AA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class GameComponent  
{
public:
	virtual Update(float delta) = 0;
	virtual Draw() = 0;
	virtual OnMessage(int, void* lpinfo = 0);
	virtual Enter();
	virtual Leave();
	GameComponent();
	virtual ~GameComponent();
};

#endif // !defined(AFX_GAMECOMPONENT_H__451C2DEF_CEDF_41D4_9696_04E28FC8AA3A__INCLUDED_)
