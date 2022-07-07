#include <XEngine.h>

X::TextureId _image;
X::Math::Vector2 _position = X::Math::Vector2::Zero();
X::Math::Vector2 _direction = X::Math::Vector2::Zero();
float _rotation = 0.0f;

void GameInit()
{
	_image = X::LoadTexture("mario.png");
	float halfScreenWidth = X::GetScreenWidth() * 0.5f;
	float halfScreenHeight = X::GetScreenHeight() * 0.5f;
	_position.x = halfScreenWidth;
	_position.y = halfScreenHeight;
	_rotation = 0.0f;
}

void GameRender()
{
	X::DrawSprite(_image, _position, _rotation);

	float halfImageWidth = X::GetSpriteWidth(_image) * 0.5f;
	float halfImageHeight = X::GetSpriteHeight(_image) * 0.5f;
	X::Math::Rect imageRect(-halfImageWidth, -halfImageHeight, halfImageWidth, halfImageHeight);
	imageRect.min += _position;
	imageRect.max += _position;
	X::DrawScreenRect(imageRect, X::Colors::Red);

	float textSize = 20.0f;
	float halfScreenWidth = X::GetScreenWidth() * 0.5f;
	float halfTextWidth = X::GetTextWidth("Assignment 1", textSize) * 0.5f;
	X::DrawScreenText("Assignment 1", halfScreenWidth - halfTextWidth, 40.0f, textSize, X::Colors::Green);
}

bool GameUpdate(float deltaTime)
{
	// game items update
	// physics updates
	// ai updates
	const float speed = 100.0f;
	const float rotationSpeed = X::Math::kPiByTwo;
	_direction = X::Math::Vector2::Zero();
	if (X::IsKeyDown(X::Keys::UP))
	{
		_direction.y = -1.0f;
	}
	else if (X::IsKeyDown(X::Keys::DOWN))
	{
		_direction.y = 1.0f;
	}
	if (X::IsKeyDown(X::Keys::LEFT))
	{
		_direction.x = -1.0f;
	}
	else if (X::IsKeyDown(X::Keys::RIGHT))
	{
		_direction.x = 1.0f;
	}

	if (X::IsKeyDown(X::Keys::A))
	{
		_rotation -= rotationSpeed * deltaTime;
	}
	else if (X::IsKeyDown(X::Keys::D))
	{
		_rotation += rotationSpeed * deltaTime;
	}

	if (X::Math::MagnitudeSqr(_direction) > 0.0f)
	{
		_direction = X::Math::Normalize(_direction);
		_position += _direction * speed * deltaTime;
	}
	GameRender();
	return X::IsKeyPressed(X::Keys::ESCAPE);
}

void GameCleanup()
{

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