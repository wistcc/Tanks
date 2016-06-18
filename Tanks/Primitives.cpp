#include "Primitives.hpp"

#include <SDL2/SDL_opengl.h>

namespace Combat
{
	void Primitives::DrawQuad(int sizeX, int sizeY,
		const Engine::Vector2& uv1,
		const Engine::Vector2& uv2,
		const Engine::Vector2& uv3,
		const Engine::Vector2& uv4)
	{
		glBegin(GL_TRIANGLE_STRIP);

		glTexCoord2f(uv1.x, uv1.y);
		glVertex2i(-sizeX, sizeY);

		glTexCoord2f(uv2.x, uv2.y);
		glVertex2i(sizeX, sizeY);

		glTexCoord2f(uv3.x, uv3.y);
		glVertex2i(-sizeX, -sizeY);

		glTexCoord2f(uv4.x, uv4.y);
		glVertex2i(sizeX, -sizeY);

		glEnd();
	}
}