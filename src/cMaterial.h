/**
 * \file cMaterial.h
 * \brief Header for the librairy of the material of the object
 *
 * \author geewy
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "cVector.h"

/** 
 * \class cMaterial
 * \brief class which represents a material
 */
class cMaterial
{
	private :
		float m_ka;			/*!< Ambient reflection coefficient  */
		float m_kd;			/*!< Differential reflection coefficient */
		float m_ke;			/*!< Shininess */
		float m_ks;			/*!< Specular reflection coefficient */
		
		cVector m_color;

	public:
		cMaterial();	//constructor
		cMaterial(float ka, float kd, float ke, float ks);
		~cMaterial();	//destructor

		float getKa();
		float getKd();
		float getKe();
		float getKs();

		cVector getColor();
		void setColor(float red, float green, float blue);
		void setCoefficient(float ka, float kd, float ke, float ks);
		
};

#endif
