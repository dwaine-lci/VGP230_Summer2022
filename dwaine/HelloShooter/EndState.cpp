#include "EndState.h"
#include <XEngine.h>

EndState::EndState()
	: GameState(State::End)
{

}
EndState::~EndState()
{

}

void EndState::Load()
{

}
State EndState::Update(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::ENTER))
	{
		return State::Start;
	}

	return State::End;
}
void EndState::Render()
{
	const float textSize = 100.0f;
	const char* title = "GAME OVER";
	float textWidth = X::GetTextWidth(title, textSize);
	X::DrawScreenText(title, (X::GetScreenWidth() - textWidth) * 0.5f, 30.0f, textSize, X::Colors::Red);
}
void EndState::Unload()
{

}