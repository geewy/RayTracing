/**
 * \file cIntersection.h
 * \brief Header for the librairie of the intersection between a ray and an object
 *
 * \author geewy
 */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "cSphere.h"
#include "cVector.h"
#include "cRay.h"

/** 
 * \class cIntersection
 * \brief class which represents the intersection between an object and a ray
 */
class cIntersection  
{
	private :
		float* m_intersec;

	public :
		cIntersection();		//constructor
		~cIntersection();		//destructor

		//float* calcul_intersection(float a, float b, float c);
		//float* calcul_abc (cVector camera, cVector direction, cVector sphere, float Rayon);
		float Test_intersection(cRay* ray, float radius, cVector centerObject);
	
		float* getIntersec();
		void setIntersec(float * i);

};

#endif
