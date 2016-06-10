#pragma once
#ifndef TANK_HPP
#define TANK_HPP

#include <SDL2/SDL_opengl.h>
#include "Texture.hpp"

namespace Combat
{
	class Tank
	{
	public:
		Tank(const char* szFilePath);
		void Render();
	private:
		GLuint m_texture;
	};
}

#endif // !TANK_HPP