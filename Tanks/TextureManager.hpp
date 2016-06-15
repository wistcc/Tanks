#pragma once
#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <map>
#include <string>
#include <memory>

namespace Engine
{
	class Texture;
	class TextureManager
	{
	public:
		static void Create();
		static void Destroy();
		static TextureManager& Instance();
		Texture* LoadTexture(const char* szFilePath);
	private:
		// Setting the entity as non-copyable
		//
		TextureManager() { };
		TextureManager(TextureManager const&) {};
		TextureManager& operator=				  (TextureManager const&) {};

		std::map<std::string, Texture*>			  m_textureIndex;
		static std::unique_ptr < TextureManager > s_instance;
	};
}

#endif // !TEXTURE_MANAGER_HPP