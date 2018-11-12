/**
 * \file cObject.h
 * \brief Header for the librairy of the object loaded
 *
 * \author geewy
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "cVector.h"
#include "cMaterial.h"

#define SPHERE 1
#define CUBE 2
#define PYRAMIDAL 3

/** 
 * \class cObject
 * \brief class which represents an object
 */
class cObject 
{
	protected :
		cVector m_position;		/*!< Position of the object in the plane */
		cMaterial m_material;
		int m_type;

	public:
		cObject();		//constructor
		~cObject();		//destructor

		
		cVector getPosition();
		void setPosition(cVector v);

		void setColorMaterial(float red, float green, float blue);
		void setCoefficientMaterial(float ka, float kd, float ke, float ks);

		float getKaMaterial();
		float getKdMaterial();
		float getKeMaterial();
		float getKsMaterial();
		
		cMaterial getMaterial();

		int getType();
};

#endif
