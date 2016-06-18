#include "Entity.hpp"

namespace Combat
{
	Entity::Entity()
		: m_radius(0.0f)
		, m_angle(0.0f)
		, m_rotation(120.0f)
		, m_mass(1.0f)
		, m_impulse(0.0f, 0.0f)
		, m_dragForce(1.0f)
		, m_velocity(0.0f, 0.0f)
		, m_lifeSpan(0.0f)
		, m_frameSpan(0.0f)
		, m_die(false)
		, m_collided(false)
		, m_score(0)
	{}

	void Entity::Init()
	{}

	/*void Entity::Render()
	{}*/

	void Entity::ApplyDrag()
	{
		m_velocity.x *= m_dragForce;
		m_velocity.y *= m_dragForce;
	}

	void Entity::ApplyImpulse(float impulseX, float impulseY)
	{
		if (m_mass > 0.f)
		{
			m_velocity.x += (impulseX / m_mass);
			m_velocity.y += (impulseY / m_mass);
		}
	}

	void Entity::SetImpulse(float impulseX, float impulseY)
	{
		if (m_mass > 0.f)
		{
			m_velocity.x = (impulseX / m_mass);
			m_velocity.y = (impulseY / m_mass);
		}
	}
}