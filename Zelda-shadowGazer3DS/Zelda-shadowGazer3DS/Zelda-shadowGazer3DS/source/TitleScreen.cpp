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

#include "TitleScreen.h"

// * Constructor 
TitleScreen::TitleScreen() : Scene()
{
	Start();
}

// * Destructor
TitleScreen::~TitleScreen()
{

}

// * Start - We initialize the variables
void TitleScreen::Start()
{
	m_transitioning = false;
	m_goToGame = false;
	m_opacity = 255;
}

// * Draw the images every frame
void TitleScreen::Draw()
{
	pp2d_begin_draw(GFX_TOP, GFX_LEFT);
	pp2d_draw_texture_part_blend(SceneManager::instance()->getTexture(), 0, 0, TOP_WIDTH, 0, TOP_WIDTH, HEIGHT, RGBA8(255,255,255, m_opacity));
	pp2d_draw_text(150, 220, 0.3f, 0.3f, RGBA8(255, 255, 255, m_opacity), "Manurocker95(C) 2017-2018.");

	// Bottom screen (We just show an image)
	pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
	pp2d_draw_texture_part_blend(SceneManager::instance()->getTexture(), 0, 0, TOP_WIDTH, HEIGHT, BOTTOM_WIDTH, HEIGHT, RGBA8(255, 255, 255, m_opacity));
	pp2d_draw_wtext(100, 112, 0.6f, 0.6f, RGBA8(255, 255, 255, m_opacity), L"Pulsa \uE000 para jugar");
	pp2d_end_draw();
}

// * Update game stuff (SplashScreen opacity)
void TitleScreen::Update()
{
	if (m_transitioning)
	{
		if (m_opacity > 0)
			m_opacity -= 3;
		else
			GoToGame();
	}
}

// * We go to the game
void TitleScreen::GoToGame()
{
	SceneManager::instance()->setActualScene(SceneManager::GAME);
	delete(this);
}

// * We check the inputs
void TitleScreen::CheckInputs()
{
	hidScanInput();

	// Pressing select we exit
	if ((hidKeysDown() & KEY_SELECT))
	{
		SceneManager::instance()->exitGame();
	}

	if ((hidKeysDown() & KEY_A) || (hidKeysDown() & KEY_TOUCH))
	{
		m_transitioning = true;
	}
}