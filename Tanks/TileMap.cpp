#include "TileMap.hpp"
#include <iostream>
#include <fstream>
#include <string>

namespace Combat
{
	TileMap::TileMap(int worldWidth, int worldHeight, int mapId)
		: m_worldWidth(worldWidth)
		, m_worldHeight(worldHeight)
		, m_mapId(mapId)
	{
		LoadMapContents();
	}

	void TileMap::Generate(int rows, int columns, int tileSize)
	{
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

			std::cout << m_rawContent << std::endl;
			std::cin.get();
		}
		else
		{
			std::cout << "Could not locate " << filename << std::endl;
		}
	}
}