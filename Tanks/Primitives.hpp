#pragma once
#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Vector2.hpp"

namespace Combat
{
	class Primitives
	{
	public:
		static void DrawQuad(int sizeX, int sizeY,
			const Engine::Vector2& uv1 = Engine::Vector2(0.f, 0.f),
			const Engine::Vector2& uv2 = Engine::Vector2(1.f, 0.f),
			const Engine::Vector2& uv3 = Engine::Vector2(0.f, 1.f),
			const Engine::Vector2& uv4 = Engine::Vector2(1.f, 1.f)
		);;
	};
}

#endif // !PRIMITIVES_HPP
