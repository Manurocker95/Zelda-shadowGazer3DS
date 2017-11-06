#include "Camera.h"

// * Constructor - Total = 25 (400/16)
Camera::Camera()
{
	m_x = 0;
	m_y = 0;

	m_width = 10;
	m_height = 10;
}

Camera::Camera(u16 _x, u16 _y)
{
	m_x = _x;
	m_y = _y;

	m_width = 10;
	m_height = 10;
}

Camera::Camera(u16 _x, u16 _y, u16 _width, u16 _height)
{
	m_x = _x;
	m_y = _y;

	m_width = _width;
	m_height = _height;
}

Camera::~Camera()
{
	
}

u16 Camera::getX()
{
	return m_x;
}

u16 Camera::getY()
{
	return m_y;
}

void Camera::setX(u16 _x)
{
	m_x = _x;
}

void Camera::setY(u16 _y)
{
	m_y = _y;
}

u16 Camera::getWidth()
{
	return m_width;
}

u16 Camera::getHeight()
{
	return m_height;
}

void Camera::setWidth(u16 _width)
{
	m_width = _width;
}

void Camera::setHeight(u16 _height)
{
	m_height = _height;
}