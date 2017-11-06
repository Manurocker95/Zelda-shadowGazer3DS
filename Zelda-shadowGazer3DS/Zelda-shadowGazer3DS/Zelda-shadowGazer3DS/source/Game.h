/* This file is part of Zelda ShadowGazer 3DS!

Copyright (C) 2017 Manuel Rodr�guez Matesanz
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
#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include "Settings.h"

#include "sound.h"
#include "scene.h"
#include "SceneManager.h"
#include "pp2d/pp2d/pp2d.h"
#include <stdio.h>


class GameScreen : public Scene
{

// Public Variables
public:

	enum GAME_STATES { TITLESCREEN, GAMESCREEN };


// Private variables
private:

	float m_offset;				// Offset for 3D
	u32 m_held;

public:

	GameScreen();				// Constructor
	~GameScreen();				// Destructor
	void Start();				// initialize
	void Draw();				// Draw
	void CheckInputs();			// CheckInput
	void Update();				// Update



};

#endif