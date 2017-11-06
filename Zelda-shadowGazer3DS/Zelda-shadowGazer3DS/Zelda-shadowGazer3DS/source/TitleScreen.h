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
#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include "Settings.h"

#include "sound.h"
#include "scene.h"
#include "SceneManager.h"
#include "pp2d/pp2d/pp2d.h"

class TitleScreen : public Scene
{

public:


	TitleScreen();						// Constructor
	~TitleScreen();

	void Start() override;
	void Draw() override;
	void CheckInputs() override;
	void Update() override;
	void GoToGame();

private:

	u16 m_opacity;
	bool m_goToGame;
	bool m_transitioning;
};

#endif