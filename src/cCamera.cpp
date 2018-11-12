/**
 * \file cCamera.cpp
 * \brief Librairie to define the camera
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cCamera.h"

/**
 * \fn cCamera::cCamera()
 * \brief Basic Contructor of the camera
 */
cCamera::cCamera(){}

/**
 * \fn cCamera::~cCamera()
 * \brief Destructor of the camera
 */
cCamera::~cCamera(){}

void cCamera::setWidth(float x){
	m_width = x;
}

void cCamera::setHeight(float y){
	m_height = y;
}

void cCamera::setPosition(cVector &v){
	m_position = v;
}

float cCamera::getHeight(){
	return m_height;
}

float cCamera::getWidth(){
	return m_width;
}


cVector cCamera::getPosition(){
	return m_position;
}


void cCamera::set_directionnal_vector(cVector set_directionnal_vector)
{
	directionnal_vector = set_directionnal_vector;
}

cVector cCamera::get_directionnal_vector()
{
	return directionnal_vector;
}

void cCamera::setFocal(float fov)
{
	m_focal = fov;
}

float cCamera::getFocal()
{
	return m_focal;
}
