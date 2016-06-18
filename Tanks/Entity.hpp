#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IRender.hpp"
#include "Sprite.hpp"
#include "Vector2.hpp"

namespace Combat
{
	class Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Entity();
		virtual void Init();
		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void ApplyDrag();
		virtual void ApplyImpulse(float impulseX, float impulseY);
		virtual void SetImpulse(float impulseX, float impulseY);
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		bool							m_collided;
		bool							m_die;
		int								m_playerId;
		int								m_score;
		float							m_lifeSpan;
		float							m_frameSpan;
		float							m_radius;
		float							m_angle;
		float							m_currentSpeed;
		float							m_rotation;
		float							m_mass;
		float							m_dragForce;
		Engine::Vector2					m_impulse;
		Engine::Vector2					m_velocity;
	};
}

#endif // !ENTITY_HPP