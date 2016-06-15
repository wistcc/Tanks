#pragma once
#ifndef TANK_HPP
#define TANK_HPP

#include <SDL2/SDL_opengl.h>
#include "IRender.hpp"
#include "Sprite.hpp"

namespace Combat
{
	class Tank : Engine::IRender
	{
	public:
		Tank(const char* szFilePath, int rows, int columns);
		void Teleport(int _x, int _y) { m_sprite->Teleport(_x, _y); }
		void Render();
	private:
		Engine::Sprite* m_sprite;
	};
}

#endif // !TANK_HPP