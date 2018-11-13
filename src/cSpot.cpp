/**
 * \file cSpot.cpp
 * \brief Librairy of a spot light source
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cSpot.h"

/**
 * \fn cSpot::cSpot()
 * \brief Contructor of a spot light source
 */
cSpot::cSpot(){}

/**
 * \fn cSpot::cSpot(float angle)
 * \brief Custom Contructor of a spot light source
 */
cSpot::cSpot(float angle){
	m_angle = angle;
}

/**
 * \fn cSpot::~cSpot(){}
 * \brief Destructor of a spot light source
 */
cSpot::~cSpot(){}

/**
 * \fn float getAngle()
 * \brief Get the angle of the ray
 */
float cSpot::getAngle(){return m_angle;}
