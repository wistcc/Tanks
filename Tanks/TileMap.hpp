#pragma once
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <string>
#include <cassert>
#include "IRender.hpp"
#include "Vector2.hpp"

namespace Combat
{
	class TileMap : public Engine::IRender
	{
	public:
		struct Tile
		{
			bool IsSolid;
		};

		TileMap(int worldWidth, int worldHeight, int mapId);
		void Generate(int rows, int columns, int tileSize);
		Tile& AtTileLocation(int x, int y);
		const Tile& AtTileLocation(int x, int y) const;
		Tile& AtWorldLocation(Engine::Vector2& pos);
		void Render() override;

		inline bool IsInBounds(int tileX, int tileY) const
		{
			return tileX >= 0 &&
				tileX < m_width &&
				tileY >= 0 &&
				tileY < m_height;
		}
		inline int Width() const { return m_width; }
		inline int Height() const { return m_height;	}
		inline int WorldUnitsPerTile() const { return m_worldUnitsPerTile; }
		inline int WorldSpaceToTileSpace(float WorldSpaceCoord) const
		{
			assert(m_worldUnitsPerTile > 0);
			return static_cast<int>(WorldSpaceCoord / m_worldUnitsPerTile);
		}
	private:
		void				LoadMapContents();

		//
		int					m_mapId;
		int					m_width;
		int					m_height;
		int					m_worldWidth;
		int					m_worldHeight;
		int					m_worldUnitsPerTile;
		std::string			m_rawContent;
		std::vector<Tile>   m_tiles;
	};
}
#endif // !TILEMAP_HPP