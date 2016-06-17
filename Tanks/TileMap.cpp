#include "TileMap.hpp"
#include <iostream>
#include <fstream>

namespace Combat
{
	TileMap::TileMap(int worldWidth, int worldHeight, int mapId)
		: m_worldWidth(worldWidth)
		, m_worldHeight(worldHeight)
		, m_mapId(mapId)
	{
		LoadMapContents();
	}

	void TileMap::Generate(int width, int height, int tileSize)
	{
		assert(width > 0);
		assert(height > 0);
		assert(tileSize > 0);

		// Setting proportional values
		//
		m_height = height;
		m_width = width;
		m_worldUnitsPerTile = tileSize;

		// Loading map		
		const char* levelString = m_rawContent.c_str();

		// Clear tiles
		m_tiles.clear();

		// Re-dimension tile space based on width and height
		m_tiles.resize(m_width * m_height);

		std::vector< Tile >::iterator iter = m_tiles.begin();

		for (const char * p = levelString; *p != '\0'; p += 2)
		{
			if (iter == m_tiles.end())
			{
				std::cerr << "WARNING: Ran out of tiles before we ran out of levelString.\n";
				std::cerr << "Remaining level string " << p << std::endl;
				break;
			}

			if (*p == 10 || *p == 13)
			{
				continue;
			}

			Tile& tile = *iter;

			switch (*p)
			{
			case '#':
				tile.IsSolid = true;
				break;
			case ' ':
				tile.IsSolid = false;
				break;
			default:
				assert(false);
				break;
			}

			++iter;
		}

		if (iter != m_tiles.end())
		{
			std::cerr << "WARNING: Ran out of levelString before we ran out of tiles.\n";
		}

		// The level string comes in Y+ == down order. We want Y+ == up order.
		// Reorder the tiles so that the top row is swapped with the bottom row and so forth
		//
		for (int x = 0; x < m_width; ++x)
		{
			// Swap the elements of the row.
			//
			for (int topY = 0; topY < m_height / 2; ++topY)
			{
				const int bottomY = m_height - topY - 1;
				std::swap(AtTileLocation(x, topY), AtTileLocation(x, bottomY));
			}
		}
	}

	TileMap::Tile & TileMap::AtTileLocation(int x, int y)
	{
		assert(x >= 0 && x < m_width);
		assert(y >= 0 && y < m_height);
		return m_tiles[y * m_width + x];
	}

	const TileMap::Tile & TileMap::AtTileLocation(int x, int y) const
	{
		return const_cast<TileMap*>(this)->AtTileLocation(x, y);
	}

	TileMap::Tile & TileMap::AtWorldLocation(Engine::Vector2 & pos)
	{
		float fractionX = (pos.x + m_worldWidth) / (m_worldWidth * 2);
		float fractionY = (pos.y + m_worldHeight) / (m_worldHeight * 2);

		int newValueX = static_cast<int>(fractionX * m_width);
		int newValueY = static_cast<int>(fractionY * m_height);

		return AtTileLocation(newValueX, newValueY);
	}

	void TileMap::LoadMapContents()
	{
		std::string filename = "maps/map1.cbl";
		std::ifstream in(filename, std::ios::in | std::ios::binary);

		if (in)
		{
			//Reading the file
			in.seekg(0, std::ios::end);
			m_rawContent.resize(static_cast<unsigned int>(in.tellg()));
			in.seekg(0, std::ios::beg);
			in.read(&m_rawContent[0], m_rawContent.size());
			in.close();
		}
		else
		{
			std::cout << "Could not locate " << filename << std::endl;
		}
	}
}