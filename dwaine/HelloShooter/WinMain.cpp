#include <XEngine.h>
#include "Game.h"

Game sGame;
void GameInit()
{
	sGame.Load();
}

bool GameUpdate(float deltaTime)
{
	sGame.Update(deltaTime);
	sGame.Render();
	return X::IsKeyPressed(X::Keys::ESCAPE);
}

void GameCleanup()
{
	sGame.Unload();
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