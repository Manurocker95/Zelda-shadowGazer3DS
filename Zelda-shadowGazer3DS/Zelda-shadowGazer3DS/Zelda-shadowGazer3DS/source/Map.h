/* This file is part of Zelda ShadowGazer 3DS!

Copyright (C) 2017 Manuel Rodríguez Matesanz
>    This program is free software: you can redistribute it and/or modify
>    it under the terms of the GNU General Public License as published by
>    the Free Software Foundation, either version 3 of the License, or
>    (at your option) any later version.
>
>    This program is distributed in the hope that it will be useful,
>    but WITHOUT ANY WARRANTY; without even the implied warranty of
>    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>    GNU General Public License for more details.
>
>    You should have received a copy of the GNU General Public License
>    along with this program.  If not, see <http://www.gnu.org/licenses/>.
>    See LICENSE for information.
*/

#pragma once
#ifndef _MAP_H
#define _MAP_H

// Libraries Needed
#include <3ds.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include "pp2d/pp2d/pp2d.h"
#include "Camera.h"
#include "Settings.h"
#include "Filepaths.h"
#include "tmxlite/Map.hpp"

using namespace std;

class Map
{

private:

	size_t m_texture;
	bool m_mapLoaded;
public:

	u16 m_width, m_height, map_width, map_height;
	tmx::Map * map;

public:

	Map();
	void Draw(Camera & camera);
	bool LoadMap(std::string path);
};

#endif