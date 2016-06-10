#include "Tank.hpp"

namespace Combat
{
	Tank::Tank(const char* szFilePath)
	{
		m_texture = Engine::Texture::LoadTexture(szFilePath);
	}

	void Tank::Render()
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2i(0, 0); glVertex2f(-0.5f, 0.5f);
		glTexCoord2i(1, 0); glVertex2f(0.5f, 0.5f);
		glTexCoord2i(0, 1); glVertex2f(-0.5f, -0.5f);
		glTexCoord2i(1, 1); glVertex2f(0.5f, -0.5f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}