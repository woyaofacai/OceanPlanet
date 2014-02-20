// GameState.h: interface for the GameState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMESTATE_H__7F515F67_F58A_48CE_A94F_873F86912791__INCLUDED_)
#define AFX_GAMESTATE_H__7F515F67_F58A_48CE_A94F_873F86912791__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class T>
class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual Enter(T*) = 0;
	virtual Update(T*, float) = 0;
	virtual Draw(T*) = 0;
	virtual Leave(T*) = 0;
};

#endif // !defined(AFX_GAMESTATE_H__7F515F67_F58A_48CE_A94F_873F86912791__INCLUDED_)
