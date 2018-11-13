#ifndef SCENE_H
#define SCENE_H


#include "cVector.h"
#include "cObject.h"
#include "cLightSource.h"
#include "cCamera.h"
#include "cRay.h"

#include "FreeImage\FreeImage.h"

#include "vector"

using namespace std;


class cScene
{
	public:

		vector<cObject*>  scene_objects;					// objects of the scene
		vector<cLightSource*> scene_lightsources;			// lightsources of the scene
		vector<cCamera*>  scene_cameras;					// cameras of the scene

	public:
	
		cVector resultRay(cRay ray, int iter);					// return the value of a pixel 
		FIBITMAP* getImage(unsigned int cameras_number);		// create the image with the calculated scene
};

#endif
