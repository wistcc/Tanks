#include "Tank.hpp"
#include "TextureManager.hpp"

namespace Combat
{
	Tank::Tank(const char* szFilePath, int rows, int columns)
	{
		m_sprite = new Engine::Sprite(szFilePath, rows, columns);
	}

	void Tank::Render()
	{
		m_sprite->Render();
	}
}