#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_opengl.h>

namespace Engine
{
	class Texture
	{
	public:
		static GLuint LoadTexture(const char* szFilePath);
	};
}

#endif // !TEXTURE_HPP