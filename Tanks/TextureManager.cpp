#include "TextureManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Texture.hpp"

namespace Engine
{
	std::unique_ptr< TextureManager > TextureManager::s_instance = nullptr;

	void TextureManager::Create()
	{
		if (!s_instance)
		{
			s_instance.reset(new TextureManager);
		}
	}

	void TextureManager::Destroy()
	{
		if (s_instance)
		{
			s_instance->m_textureIndex.clear();
			s_instance = nullptr;
		}
	}

	TextureManager& TextureManager::Instance()
	{
		if (!s_instance)
		{
			Create();
		}

		return *s_instance.get();
	}

	Texture* TextureManager::LoadTexture(const char* szFilePath)
	{
		std::map<std::string, Texture*>::iterator it;
		it = m_textureIndex.find(szFilePath);
		if (it != m_textureIndex.end())
		{
			return it->second;
		}

		Texture* texture = new Texture(szFilePath);
		m_textureIndex[szFilePath] = texture;
		return texture;
	}
}