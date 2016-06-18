#include "InputManager.hpp"

namespace Engine
{
	std::unique_ptr< InputManager > InputManager::s_instance = nullptr;

	void InputManager::Create()
	{
		if (!s_instance)
		{
			s_instance.reset(new InputManager);
		}
	}

	void InputManager::Destroy()
	{
		if (s_instance)
		{
			s_instance.reset();
		}
	}

	InputManager& InputManager::Instance()
	{
		if (!s_instance)
		{
			Create();
		}

		return *s_instance.get();
	}

	bool InputManager::IsKeyDown(unsigned char key)
	{
		return m_isDown[key];
	}

	bool InputManager::IsKeyUp(unsigned char key)
	{
		return m_isUp[key];
	}

	void InputManager::KeyDown(unsigned char key)
	{
		m_isDown[key] = true;
	}

	void InputManager::KeyUp(unsigned char key)
	{
		m_isDown[key] = false;
		m_isUp[key] = true;
	}

	void InputManager::ResetInput()
	{
		std::generate(m_isUp, m_isUp + 256, []() { return false; });
	}

	void OnKeyboardDownEvent(unsigned char key)
	{
		InputManager::Instance().KeyDown(key);
	}

	void OnKeyboardUpEvent(unsigned char key)
	{
		InputManager::Instance().KeyUp(key);
	}
}