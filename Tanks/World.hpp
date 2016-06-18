#pragma once
#ifndef WORLD_HPP
#define WORLD_HPP

#include "Entity.hpp"

namespace Combat
{
	class World : public Entity
	{
	public:
		// CTOR
		//
		explicit World(int width_, int height_, int amountOfPlayers);
		~World();

		// FUNCTIONS
		//
		void		 Render();
		void		 Init();
		virtual void Update() override;
		virtual void Input() override;
	};
}

#endif // !WORLD_HPP
