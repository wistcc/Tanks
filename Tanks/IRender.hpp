#pragma once
#ifndef IRENDER_HPP
#define RENDER_HPP

namespace Engine
{
	class IRender
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		virtual void Render() = 0;
	};
}

#endif // !IRENDER_HPP