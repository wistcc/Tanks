#include "Turret.hpp"

#include <cmath>

#include <SDL2/SDL_opengl.h>
#include "Vector2.hpp"
#include "Primitives.hpp"
#include "Texture.hpp"
#include "InputManager.hpp"

namespace Combat
{
	const float deltaTime = 1 / 60.f;

	Turret::Turret()
		: Sprite::Sprite("resources/tank_small_turret_1.png", 1, 1, false, 1, Engine::Vector2(1.0f, 1.0f))
	{}

	void Turret::Input()
	{
		if (Engine::InputManager::Instance().IsKeyDown('i'))
		{
			RotateUp(deltaTime);
		}

		if (Engine::InputManager::Instance().IsKeyDown('j'))
		{
			RotateLeft(deltaTime);
		}

		if (Engine::InputManager::Instance().IsKeyDown('l'))
		{
			RotateRight(deltaTime);
		}

		if (Engine::InputManager::Instance().IsKeyDown('k'))
		{
			RotateDown(deltaTime);
		}
	}

	void Turret::Update()
	{}

	void Turret::Render()
	{
		// Take the current state of the matrix and save it on the stack
		//
		glPushMatrix();

		// Activate texture
		m_texture->ApplyTexture();

		// Apply transformations
		//
		glTranslatef(m_position.y, m_position.x, 0.0f);
		glRotatef(this->m_angle, 0.f, 0.f, 1.0f);
		glScalef(m_scale.x, m_scale.y, 1.0f);

		// Draw quad!
		//
		Primitives::DrawQuad(m_texture->GetWidth(), m_texture->GetHeight());

		// Restore the saved state of the matrix
		//
		glPopMatrix();
	}

	void Turret::RotateUp(float deltatime)
	{
		m_rotationOrientation = m_angle > 0 ? 1 : -1;
		float angle = fmodf(fabs(m_angle), 360.0f);
		if (angle > 180)
		{
			angle = 360 - angle;
			angle *= -1.f;
		}

		angle *= m_rotationOrientation;

		if (angle != 0)
		{
			if (angle > 0)
				m_angle -= m_rotation * deltatime;//0.5f; //* 1 / 60.f;
			else
				m_angle += m_rotation * deltatime;//0.5f;
		}
	}

	void Turret::RotateDown(float deltatime)
	{
		m_rotationOrientation = m_angle > 0 ? 1 : -1;
		float angle = fmodf(fabs(m_angle), 360.0f);
		if (angle > 180)
		{
			angle = 360 - angle;
			angle *= -1.f;
		}

		angle *= m_rotationOrientation;

		if (angle != 180)
		{
			if (angle <= 0.f)
				m_angle -= m_rotation * deltatime;//0.5f;
			else
				m_angle += m_rotation * deltatime;//0.5f;					
		}
	}

	void Turret::RotateRight(float deltatime)
	{
		m_rotationOrientation = m_angle > 0 ? 1 : -1;
		float angle = fmodf(fabs(m_angle), 360.0f);
		if (angle > 180)
		{
			angle = 360 - angle;
			angle *= -1.f;
		}

		angle *= m_rotationOrientation;

		if (angle != -90)
		{
			if (angle > -90.f || angle == 180.f)
				m_angle -= m_rotation * deltatime;//0.5f;
			else
				m_angle += m_rotation * deltatime;//0.5f;					
		}
	}

	void Turret::RotateLeft(float deltatime)
	{
		m_rotationOrientation = m_angle > 0 ? 1 : -1;
		float angle = fmodf(fabs(m_angle), 360.0f);
		if (angle > 180)
		{
			angle = 360 - angle;
			angle *= -1.f;
		}

		angle *= m_rotationOrientation;

		if (angle != 90)
		{
			if (angle > 90.f || angle == 180.f)
				m_angle -= m_rotation * deltatime; //0.5f;
			else
				m_angle += m_rotation * deltatime; //0.5f ;
		}
	}
	void Turret::Shoot()
	{

	}
}