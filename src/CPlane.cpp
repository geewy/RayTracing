/**
 * \file cPlane.cpp
 * \brief Librairie of a plane object
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cPlane.h"

/**
 * \fn cPlane::cPlane()
 * \brief Contructor of a plane
 */
cPlane::cPlane(){}


/**
 * \fn cPlane::~cPlane()
 * \brief Destructor of a plane
 */
cPlane::~cPlane(){}

/**
 * \fn cVector getDirX()
 * \brief Get the directionnal vector X of the plane
 */
cVector cPlane::getDirX(){return m_dirX;}

/**
 * \fn cVector getDirY()
 * \brief Get the directionnal vector Y of the plane
 */
cVector cPlane::getDirY(){return m_dirY;}

/**
 * \fn float cPlane::getOriginX()
 * \brief Get the x coordinate of the origine plane point
 */
float cPlane::getOriginX(){return m_originX;}

/**
 * \fn float cPlane::getOriginY()
 * \brief Get the y coordinate of the origine plane point
 */
float cPlane::getOriginY(){return m_originY;}

/**
 * \fn float cPlane::getOriginZ()
 * \brief Get the z coordinate of the origine plane point
 */
float cPlane::getOriginZ(){return m_originZ;}
