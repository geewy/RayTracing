/**
 * \file cCamera.h
 * \brief Define the cCamera class and its functions
 *
 * \author geewy
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "cVector.h"

/**
 * \class cCamera
 * \brief Class which represents the camera and the focal image
 */
class cCamera 
{
	private:
		cVector m_position;		/*!< Position of the camera */
		cVector directionnal_vector;
		float m_focal;			/*!< Distance between the camera and the future image */
		float m_width;			/*!< Width */
		float m_height;			/*!< Height */

	public :
		cCamera();
		~cCamera();

		void setWidth(float x);
		void setHeight(float y);
		void setPosition(cVector &v);
		void setFocal(float fov);
		void cCamera::set_directionnal_vector(cVector directionnal_vector);
		
		float getWidth();
		float getHeight();
		float getFocal();
		cVector getPosition();
		cVector cCamera::get_directionnal_vector();
};
#endif
