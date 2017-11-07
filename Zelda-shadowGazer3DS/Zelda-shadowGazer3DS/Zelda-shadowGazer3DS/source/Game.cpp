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


#include "Game.h"

GameScreen::GameScreen() : Scene ()
{
	// we initialize data
	Start();
}

GameScreen::~GameScreen()
{
	//pp2d_free_texture(TEXTURE_SPRITESHEET_ID2);
}

void GameScreen::Start()
{
	// We will use 2 channels for sounds: 1 = BGM, 2= Sound effects so they can be played at same time. You can set as channels as you want.

	// We clear the channels
	ndspChnWaveBufClear(1);
	ndspChnWaveBufClear(2);

	// We initialize our game variables
	m_offset = 0;
	m_map = new Map();
	m_camera = new Camera();
}

void GameScreen::Draw()
{	
	pp2d_begin_draw(GFX_TOP, GFX_LEFT);
	pp2d_draw_texture_part(SceneManager::instance()->getTexture(), 0, 0, TOP_WIDTH, 0, TOP_WIDTH, HEIGHT);
	m_map->Draw(*m_camera);

	// Bottom screen (We just show an image)
	pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
	pp2d_draw_texture_part(SceneManager::instance()->getTexture(), 0, 0, TOP_WIDTH, HEIGHT, BOTTOM_WIDTH, HEIGHT);
	pp2d_end_draw();
}

void GameScreen::Update()
{
	if (m_camera->getX() <= 0)
		m_camera->setX(0);

	if (m_camera->getY() <= 0)
		m_camera->setY(0);

	if (m_camera->getX() >= m_map->m_width-TOP_WIDTH)
		m_camera->setX(m_map->m_width - TOP_WIDTH);

	if (m_camera->getY() >= m_map->m_height - HEIGHT)
		m_camera->setY(m_map->m_height - HEIGHT);
}

void GameScreen::CheckInputs()
{
	hidScanInput();
	m_held = hidKeysHeld();
	
	if ((m_held & KEY_UP))
	{
		m_camera->Move(0,-1);
	}

	if ((m_held & KEY_DOWN))
	{
		m_camera->Move(0, 1);
	}

	if ((m_held & KEY_RIGHT))
	{
		m_camera->Move(1, 0);
	}

	if ((m_held & KEY_LEFT))
	{
		m_camera->Move(-1, 0);
	}

	// We Exit pressing Select
	if ((hidKeysDown() & KEY_SELECT))
	{
		SceneManager::instance()->SaveDataAndExit();
		delete(this);
	}
}

