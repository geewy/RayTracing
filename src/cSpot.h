/**
 * \file cSpot.h
 * \brief Header for the librairy of the spot light source
 *
 * \author geewy
 */

#ifndef SPOT_H
#define SPOT_H

#include "cLightSource.h"

/** 
 * \class cSpot
 * \brief Class which represents a spot light source - Heritage from cLightSource
 */
class cSpot : public cLightSource
{
	private:
		float m_angle;		/*!< Angle of diffusion */

	public:
		cSpot();	//constructor
		cSpot(float angle);
		~cSpot();	//destructor

		float getAngle();
};

#endif
