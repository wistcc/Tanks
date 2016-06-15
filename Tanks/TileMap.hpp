#pragma once
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <string>

namespace Combat
{
	class TileMap
	{
	public:
		struct Tile
		{
			bool IsSolid;
		};

		TileMap(int worldWidth, int worldHeight, int mapId);
		void Generate(int rows, int columns, int tileSize);
	private:
		void				LoadMapContents();

		//
		int					m_mapId;
		int					m_width;
		int					m_height;
		int					m_worldWidth;
		int					m_worldHeight;
		int					m_worldUnitsPerTile;
		std::string					m_rawContent;
		std::vector<Tile*>  m_tiles;
	};
}
#endif // !TILEMAP_HPP