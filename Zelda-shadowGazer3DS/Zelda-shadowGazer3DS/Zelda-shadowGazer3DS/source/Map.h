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

using namespace std;

class Map
{

private:

	std::vector<u16> m_idsX;
	std::vector<u16> m_idsY;

public:

	Map();
	Map(std::string path);

};

#endif