/**
 * \file cVector.h
 * \brief Header for vector
 *
 * \author geewy
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "cVecteurHomogene.h"

/** 
 * \class cVector
 * \brief Class for a vector (coordinates, direction and color (for pixel))
 */
class cVector 
{
	private :
		float m_x, m_y, m_z;								/*!< Coordinates of a vector */
		float m_red;
		float m_green;
		float m_blue;
		
	public:
		cVector();		//constructeur
		cVector(float x, float y, float z);
		~cVector();		//destructeur

		void setVecteur(float x, float y, float z);
		void setX(float posX);
		void setY(float posY); 
		void setZ(float posZ);

		float getX();
		float getY();
		float getZ();

		float getRedColor();
		float getGreenColor();
		float getBlueColor();
		void setColor(float red, float green, float blue);
};

#endif
