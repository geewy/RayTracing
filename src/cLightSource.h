/**
 * \file cLightSource.h
 * \brief Header for the librairy of the light source display
 *
 * \author geewy
 */

#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "cVector.h"

/** 
 * \class cLightSource
 * \brief class which represents a light source
 */
class cLightSource 
{
	protected :
		cVector  m_position;					/*!< Initial Position */
		cVector m_color;			/*!< Color */

	public :
		cLightSource();		//constructor
		~cLightSource();	//destructor

		cVector getPos();
		void setPos(cVector pos);
		
		void setColorLight(float red, float green, float blue);
		cVector getColor();
};

#endif
