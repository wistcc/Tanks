#pragma once
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "IRender.hpp"
#include "Vector2.hpp"

namespace Engine
{
	class Texture;
	class Sprite : IRender
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Sprite(const char* szFilePath, int rows, int columns, bool animate = false, int speed = 1, Engine::Vector2 scale = Engine::Vector2(0, 0));
		~Sprite();
		void Teleport(int _x, int _y) { m_position.x = static_cast<float>(_x); m_position.y = static_cast<float>(_y); }
		void SetCurrentFrame(int currentFrame) { m_currentFrame = currentFrame; }
		virtual void Render();
	protected:
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
		int				m_framesPerSprite;
		bool			m_animate;
		Engine::Vector2 m_position;
		Engine::Vector2 m_scale;

	};
}

#endif // !SPRITE_HPP