#include "Texture.hpp"
#include "stb_image.h"
#define STBI_HEADER_FILE_ONLY

#include <SDL2/SDL.h>

namespace Engine
{
	Texture::Texture(const char* szFilePath)
		: m_texture(0)
		, m_width(0)
		, m_height(0)
	{
		LoadTexture(szFilePath);
	}

	void Texture::ApplyTexture()
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}

	void Texture::LoadTexture(const char* szFilePath)
	{
		int nChannels;

		// Loading file in memory
		//
		unsigned char* pixels =
			stbi_load(szFilePath, &m_width, &m_height, &nChannels, 4);

		if (!pixels)
		{
			SDL_Log("%s could not be loaded.", szFilePath);
			return;
		}

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		//
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(
			GL_TEXTURE_2D,
			0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
			pixels
		);

		// Removing file from memory
		//
		stbi_image_free(pixels);
	}
}