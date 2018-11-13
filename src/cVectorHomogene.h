/**
 * \file cVectorHomogene.h
 * \brief Header for the librairy of vector operation
 *
 * \author geewy
 */

#ifndef VECTORHOMOGENE_H
#define VECTORHOMOGENE_H

/** 
 * \class cVectorHomogene
 * \brief Class for an homogene vector (coordinates)
 */
class cVectorHomogene
{
	private:
		float m_x,m_y,m_z,m_w;			/*!< Coordinates of an homogene vector */

	public:
		
		cVectorHomogene();		//constructor
		~cVectorHomogene();	//destructor

		
		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setW(float w);

		float getX();
		float getY();
		float getZ();
		float getW();
	
};


#endif
