/**
 * \file cSphere.cpp
 * \brief Librairy of sphere object
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cSphere.h"

/**
 * \fn cSphere::cSphere()
 * \brief Contructor of a sphere
 */
cSphere::cSphere(){}


/**
 * \fn cSphere::~cSphere()
 * \brief Destructor of a sphere
 */
cSphere::~cSphere(){}

/**
 * \fn cVector getRadius()
 * \brief Get the radius of the sphere
 */
float cSphere::getRadius(){return m_radius;}

void cSphere::setRadius(double x){
	m_radius = x;
}
