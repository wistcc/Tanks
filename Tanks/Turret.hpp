#pragma once
#ifndef TURRET_HPP
#define TURRET_HPP

#include "Entity.hpp"
#include "Sprite.hpp"

namespace Combat
{
	class Turret : public Entity, Engine::Sprite
	{
	public:
		Turret();
		void Input() override;
		void Update() override;
		void Render() override;

		void RotateUp(float deltatime);
		void RotateDown(float deltatime);
		void RotateRight(float deltatime);
		void RotateLeft(float deltatime);
		void Shoot();
	private:
		int							m_rotationOrientation;
	};
}

#endif // !TURRET_HPP