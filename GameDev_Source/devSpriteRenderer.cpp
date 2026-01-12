#include "devSpriteRenderer.h"

namespace dev
{
	SpriteRenderer::SpriteRenderer() : _image(nullptr)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (_image)
		{
			Graphics graphics(hdc);
			graphics.DrawImage(_image, (INT)GetOwner()->GetPosition().x, (INT)GetOwner()->GetPosition().y, 100, 100);
		}
	}

	void SpriteRenderer::SetImagePath(const wchar_t* imagePath)
	{
		_image = new Image(imagePath);
	}
}