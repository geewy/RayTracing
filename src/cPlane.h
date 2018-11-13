/**
 * \file cPlane.h
 * \brief Header for the librairie of the spot light source
 *
 * \author geewy
 */
#ifndef PLANE_H
#define PLANE_H

#include "cObject.h"
#include "cVector.h"

/**
 * \class cPlane
 * \brief Class for a plane in the scene - Heritage from cObject
 */
class cPlane : public cObject
{
	private :
		cVector m_dirX;								/*!< Directionnal vector x */
		cVector m_dirY;								/*!< Directionnal vector y */
		float	m_originX, m_originY, m_originZ;	/*!< Original point */

	public:
		cPlane();	//constructor
		~cPlane();	//destructor

		cVector getDirX();
		cVector getDirY();
		float getOriginX();
		float getOriginY();
		float getOriginZ();
};

#endif
