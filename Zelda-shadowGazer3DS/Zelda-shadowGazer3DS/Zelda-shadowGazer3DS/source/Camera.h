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
#ifndef _CAMERA_H
#define _CAMERA_H

// Libraries Needed
#include <3ds.h>

class Camera
{

private:

	u16 m_x;
	u16 m_y;
	u16 m_width;
	u16 m_height;
	u16 m_minX;
	u16 m_minY;


public:

	Camera();
	Camera(u16 _x, u16 _y);
	Camera(u16 _x, u16 _y, u16 _width, u16 _height);

	~Camera();

	u16 getX();
	u16 getY();

	void setX(u16 _x);
	void setY(u16 _y);

	u16 getWidth();
	u16 getHeight();

	void setWidth(u16 _width);
	void setHeight(u16 _height);

	u16 getMinX();
	u16 getMinY();

	void setMinX(u16 _x);
	void setMinY(u16 _y);

	void Move(u16 x, u16 y);
};

#endif