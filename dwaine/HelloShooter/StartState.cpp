#include "StartState.h"
#include <XEngine.h>

StartState::StartState()
	: GameState(State::Start)
{
	
}
StartState::~StartState()
{

}

void StartState::Load()
{

}
State StartState::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::ENTER))
	{
		return State::RunGame;
	}

	return State::Start;
}
void StartState::Render()
{
	const float textSize = 100.0f;
	const char* title = "START SCREEN";
	float textWidth = X::GetTextWidth(title, textSize);
	X::DrawScreenText(title, (X::GetScreenWidth() - textWidth) * 0.5f, 30.0f, textSize, X::Colors::Green);
}
void StartState::Unload()
{

}