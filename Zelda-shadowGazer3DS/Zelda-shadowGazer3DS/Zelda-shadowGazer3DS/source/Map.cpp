#include "Map.h"

Map::Map()
{
	m_texture = 2;
	m_width = 720;
	m_height = 960;
	pp2d_load_texture_png(m_texture, "romfs:/resources/Art/Tiles/zelda01.png");
	m_mapLoaded = false;
}

bool Map::LoadMap(std::string path)
{
	if (map->load(path))
	{
		m_mapLoaded = true;

	

		return true;
	}
	m_mapLoaded = false;
	return false;
}

//Layer
void Map::Draw(Camera & Camera)
{
	if (m_mapLoaded)
	{
		const auto& layers = map->getLayers();
		for (const auto& layer : layers)
		{
			if (layer->getType() == tmx::Layer::Type::Object)
			{
				const auto& objects = dynamic_cast<tmx::ObjectGroup*>(layer.get())->getObjects();
			}

			if (layer->getType() == tmx::Layer::Type::Tile)
			{
				const auto& tiles = dynamic_cast<tmx::Tileset*>(layer.get())->getTiles();
				pp2d_draw_texture_part(m_texture, 0, 0, Camera.getX(), Camera.getY(), TOP_WIDTH, HEIGHT);

			}
		}
	}
	
	//pp2d_draw_texture_part(m_texture, 0, 0, Camera.getX(), Camera.getY(), TOP_WIDTH, HEIGHT);
}