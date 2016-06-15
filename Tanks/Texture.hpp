#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_opengl.h>

namespace Engine
{
	class Texture
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Texture(const char* szFilePath);
		void ApplyTexture();

		/* =============================================================
		* INLINE FUNCTIONS
		* ============================================================= */
		inline int GetWidth() { return m_width; }
		inline int GetHeight() { return m_height; }
	private:
		/* =============================================================
		* PRIVATE FUNCTIONS
		* ============================================================= */
		void LoadTexture(const char* szFilePath);

		/* =============================================================
		* MEMBERS
		* ============================================================= */
		GLuint						m_texture;
		int							m_width;
		int							m_height;
	};
}

#endif // !TEXTURE_HPP