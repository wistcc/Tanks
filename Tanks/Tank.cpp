#include "Tank.hpp"

//
#include <SDL2/SDL_opengl.h>
#include <cmath>

//
#include "TextureManager.hpp"
#include "Utilities.hpp"
#include "Texture.hpp"
#include "Primitives.hpp"
#include "InputManager.hpp"

namespace Combat
{
	const float DEFAULT_SCALE = 0.65f;
	const float DEFAULT_ANGLE_OFFSET = 90.f;
	const float MAX_VELOCITY = 150.0f;
	const float INPUT_BULLET_DELAY = 0.5f;
	const float MAX_THRUST = 2.5f;
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;

	Tank::Tank(int playerId)
		: Sprite::Sprite("resources/tank_body_1.png", 1, 1, false, 1, Engine::Vector2(0.5f, 0.5f))
	{
		m_playerId = playerId;
		Init();
	}

	Tank::~Tank()
	{
		m_turret.reset();
	}

	void Tank::Init()
	{
		m_dragForce = 0.9f;
		m_turret = std::make_shared< Turret >();
	}

	void Tank::Input()
	{
		if (Engine::InputManager::Instance().IsKeyDown('w'))
		{
			MoveForward();
		}

		if (Engine::InputManager::Instance().IsKeyUp(' '))
		{
			Shoot();
		}

		if (Engine::InputManager::Instance().IsKeyDown('a'))
		{
			RotateLeft();
		}

		if (Engine::InputManager::Instance().IsKeyDown('d'))
		{
			RotateRight();
		}

		m_turret->Input();
	}

	void Tank::Update()
	{
		m_turret->Update();
	}

	void Tank::Render()
	{
		glEnable(GL_TEXTURE_2D);
		// Take the current state of the matrix and save it on the stack
		//
		glPushMatrix();
		// Activate texture
		//
		m_texture->ApplyTexture();

		// Apply transformations
		//
		glTranslatef(m_position.x, m_position.y, 0.0f);
		glRotatef(m_angle, 0.f, 0.f, 1.0f);
		glScalef(m_scale.x, m_scale.y, 1.0f);

		// Draw the quad!
		//
		Primitives::DrawQuad(m_texture->GetWidth(), m_texture->GetHeight());

		// Render the turret!
		//
		m_turret->Render();

		// Restore the saved state of the matrix
		//
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}

	void Tank::MoveForward()
	{
		ApplyImpulse(MAX_THRUST, MAX_THRUST);
	}

	void Tank::RotateRight()
	{
		m_angle -= m_rotation * (DESIRED_FRAME_TIME);
	}

	void Tank::RotateLeft()
	{
		m_angle += m_rotation * (DESIRED_FRAME_TIME);
	}

	void Tank::Shoot()
	{
		m_turret->Shoot();
	}

	void Tank::ApplyImpulse(float impulseX, float impulseY)
	{
		if (m_mass > 0.f)
		{
			m_position.x += (impulseX / m_mass) * std::cosf(Engine::ConvertToRad(m_angle + DEFAULT_ANGLE_OFFSET));
			m_position.y += (impulseY / m_mass) * std::sinf(Engine::ConvertToRad(m_angle + DEFAULT_ANGLE_OFFSET));
		}
	}
}