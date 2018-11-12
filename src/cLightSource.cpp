/**
 * \file cLightSource.cpp
 * \brief Librairy of a light source
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cLightSource.h"

/**
 * \fn cLightSource::cLightSource()
 * \brief Contructor of a light source
 */
cLightSource::cLightSource(){}


/**
 * \fn cLightSource::~cLightSource()
 * \brief Destructor of a light source
 */
cLightSource::~cLightSource(){}

cVector cLightSource::getPos(){
	return m_position;
}

void cLightSource::setPos(cVector pos){
	m_position = pos;
}


void cLightSource::setColorLight(float red, float green, float blue){
	m_color.setColor(red, green, blue);
}

cVector cLightSource::getColor(){
	return m_color;
}
