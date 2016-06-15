#pragma once
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "IRender.hpp"

namespace Engine
{
	class Texture;
	class Sprite : IRender
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Sprite(const char* szFilePath, int rows, int columns);
		~Sprite();
		void Teleport(int _x, int _y) { x = _x; y = _y; }
		void Render();
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		int				m_rows;
		int				m_columns;
		float			m_frameWidth;
		float			m_frameHeight;
		int				m_frameOffsetX;
		int				m_frameOffsetY;
		int				m_currentFrame;
		Texture*		m_texture;
		int x;
		int y;
	};
}

#endif // !SPRITE_HPP