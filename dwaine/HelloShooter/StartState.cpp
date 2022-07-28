#include "StartState.h"
#include <XEngine.h>
#include "AnimSpriteArray.h"

AnimSpriteArray _testShipSpin;
StartState::StartState()
	: GameState(State::Start)
{
	
}
StartState::~StartState()
{

}

void StartState::Load()
{
	_testShipSpin.Load();

	X::Math::Vector2 spawnPos(X::GetScreenWidth() * 0.5f, X::GetScreenHeight() * 0.5f);
	_testShipSpin.SetActive(spawnPos, true);
}
State StartState::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::ENTER))
	{
		return State::RunGame;
	}

	_testShipSpin.Update(deltaTime);
	return State::Start;
}
void StartState::Render()
{
	_testShipSpin.Render();
	const float textSize = 100.0f;
	const char* title = "START SCREEN";
	float textWidth = X::GetTextWidth(title, textSize);
	X::DrawScreenText(title, (X::GetScreenWidth() - textWidth) * 0.5f, 30.0f, textSize, X::Colors::Green);
}
void StartState::Unload()
{
	_testShipSpin.Unload();
}