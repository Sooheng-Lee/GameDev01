#include "devSpriteRenderer.h"

namespace dev
{
	SpriteRenderer::SpriteRenderer(INT width, INT height) : _image(nullptr), _width(width), _height(height)
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
			graphics.DrawImage(_image, (INT)GetOwner()->GetPosition().x, (INT)GetOwner()->GetPosition().y, static_cast<INT>(_width * GetOwner()->GetScale().x), static_cast<INT>(_height * GetOwner()->GetScale().y));
		}
	}

	void SpriteRenderer::SetImagePath(const wchar_t* imagePath)
	{
		_image = new Image(imagePath);
	}
}