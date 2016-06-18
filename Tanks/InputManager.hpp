#pragma once
#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <memory>
#include <algorithm>

namespace Engine
{
	class InputManager
	{
	public:
		/* =============================================================
		* STATIC FUNCTIONS
		* ============================================================= */
		static void Create();
		static void Destroy();
		static InputManager& Instance();

		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		bool IsKeyDown(unsigned char key);
		bool IsKeyUp(unsigned char key);
		void KeyDown(unsigned char key);
		void KeyUp(unsigned char key);
		void ResetInput();
	private:
		/* =============================================================
		* PRIVATE FUNCTIONS
		* ============================================================= */
		InputManager() { std::generate(m_isDown, m_isDown + 256, []() { return false; });	ResetInput(); }
		InputManager(InputManager const&) {};
		InputManager& operator=					(InputManager const&) {};

		/* =============================================================
		* MEMBERS
		* ============================================================= */
		bool									m_isDown[256];
		bool									m_isUp[256];
		static std::unique_ptr < InputManager > s_instance;
	};

	extern void OnKeyboardDownEvent(unsigned char key);
	extern void OnKeyboardUpEvent(unsigned char key);
}

#endif // !INPUT_MANAGER_HPP