#include <XEngine.h>
#include "StartState.h"
#include "RunGameState.h"
#include "EndState.h"

State sActiveState = State::Start;
StartState sStartState;
RunGameState sRunGameState;
EndState sEndState;
void GameInit()
{
	switch (sActiveState)
	{
	case State::Start: sStartState.Load(); break;
	case State::RunGame: sRunGameState.Load(); break;
	case State::End: sEndState.Load(); break;
	default:
		break;
	}
}

bool GameUpdate(float deltaTime)
{
	State currentState = sActiveState;
	switch (sActiveState)
	{
	case State::Start: 
		sActiveState = sStartState.Update(deltaTime); 
		sStartState.Render(); 
		break;
	case State::RunGame: 
		sActiveState = sRunGameState.Update(deltaTime);
		sRunGameState.Render();
		break;
	case State::End: 
		sActiveState = sEndState.Update(deltaTime);
		sEndState.Render();
		break;
	default:
		break;
	}
	if (currentState != sActiveState)
	{
		GameInit();
	}
	return X::IsKeyPressed(X::Keys::ESCAPE);
}

void GameCleanup()
{
	sStartState.Unload();
	sStartState.Unload();
	sStartState.Unload();
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start("xconfig.json");
	GameInit();

	X::Run(GameUpdate);

	GameCleanup();
	X::Stop();

	return 0;
}