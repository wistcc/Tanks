#include "Texture.hpp"
#include "stb_image.h"
#define STBI_HEADER_FILE_ONLY

#include <SDL2/SDL.h>

namespace Engine
{
	GLuint Texture::LoadTexture(const char* szFilePath)
	{
		int width;
		int height;
		int nChannels;

		// Loading file in memory
		//
		unsigned char* pixels =
			stbi_load(szFilePath, &width, &height, &nChannels, 4);

		if (!pixels)
		{
			SDL_Log("%s could not be loaded.", szFilePath);
			return -1;
		}

		GLuint textureId;
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);

		//
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(
			GL_TEXTURE_2D,
			0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
			pixels
		);

		// Removing file from memory
		//
		stbi_image_free(pixels);

		return textureId;
	}
}