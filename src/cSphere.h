/**
 * \file cSphere.h
 * \brief Header for the librairy of a sphere
 *
 * \author geewy
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "cObject.h"

/** 
 * \class cSphere
 * \brief Class which represents a sphere - Heritage from cObject
 */
class cSphere : public cObject
{
	private :
		float m_radius;	/*!< Radius of the sphere  */

	public:
		cSphere();		//constructor
		~cSphere();		//destructor

		void setRadius(double x);
		float getRadius();	//getter radius
};

#endif
