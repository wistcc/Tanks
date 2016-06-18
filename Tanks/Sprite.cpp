#include "Sprite.hpp"
#include "Texture.hpp"
#include "TextureManager.hpp"

namespace Engine
{
	Sprite::Sprite(const char* szFilePath, int rows, int columns, bool animate, int speed, Engine::Vector2 scale)
		: m_rows(rows)
		, m_columns(columns)
		, m_currentFrame(0)
		, m_frameOffsetX(0)
		, m_frameOffsetY(0)
		, m_scale(scale)
		, m_animate(animate)
		, m_framesPerSprite(speed)
	{
		m_texture =
			TextureManager::Instance().LoadTexture(szFilePath);
		m_frameWidth = 1.0f / m_columns;
		m_frameHeight = 1.0f / m_rows;
	}

	Sprite::~Sprite()
	{
		delete m_texture;
	}

	void Sprite::Render()
	{
		// TODO: Implement code to handle manual setup of the frames
		//
		if (m_animate) m_currentFrame++;

		if (m_framesPerSprite > 0)
		{
			if (m_currentFrame % m_framesPerSprite == 0)
			{
				m_frameOffsetX++;
				if (m_frameOffsetX >= m_columns)
				{
					m_frameOffsetX = 0;
					m_frameOffsetY++;

					if (m_frameOffsetY >= m_rows)
					{
						m_frameOffsetY = 0;
					}
				}
			}

			if (!m_animate)
				m_framesPerSprite = 0;
		}

		float uv1_x = m_frameWidth  * m_frameOffsetX;
		float uv1_y = m_frameHeight * m_frameOffsetY;

		float uv4_x = m_frameWidth  * (m_frameOffsetX + 1);
		float uv4_y = m_frameHeight * (m_frameOffsetY + 1);

		float uv2_x = uv4_x;
		float uv2_y = uv1_y;

		float uv3_x = uv1_x;
		float uv3_y = uv4_y;

		m_texture->ApplyTexture();
		glLoadIdentity();
		glTranslatef(m_position.x, m_position.y, 0);

		glEnable(GL_TEXTURE_2D);
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(uv1_x, uv1_y); glVertex2f(-110.0f, 200.0f);
		glTexCoord2f(uv2_x, uv2_y); glVertex2f(110.0f, 200.0f);
		glTexCoord2f(uv3_x, uv3_y); glVertex2f(-110.0f, -200.0f);
		glTexCoord2f(uv4_x, uv4_y); glVertex2f(110.0f, -200.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}