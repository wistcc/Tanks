#pragma once
#ifndef TANK_HPP
#define TANK_HPP

// C++ STL
//
#include <memory>

// Game
//
#include "Entity.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"

namespace Combat
{
	class Tank : public Entity, public Engine::Sprite
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Tank(int playerId);

		// CTOR
		//
		~Tank();

		// BASE CLASS FUNCTIONS
		//
		void ApplyImpulse(float impulseX, float impulseY) override;
		void Init() override;
		void Update() override;
		void Input() override;
		void Render() override;

		void MoveForward();
		void RotateRight();
		void RotateLeft();
		void Shoot();

	private:
		std::shared_ptr< Turret >			m_turret;
	};
}

#endif // !TANK_HPP