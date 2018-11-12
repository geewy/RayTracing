/**
 * \file cIntersection.cpp
 * \brief Librairie for intersection between a ray and an object (sphere, cube etc...)
 *
 * \author geewy
 */

#include "stdafx.h"
#include "cIntersection.h"
#include <math.h>

/**
 * \fn cIntersection::cIntersection()
 * \brief Classic constructor of intersection
 */
cIntersection::cIntersection(){}

/**
 * \fn cIntersection::~cIntersection()
 * \brief Destructor of intersection
 */
cIntersection::~cIntersection(){}

float* cIntersection::getIntersec(){
	return m_intersec;
}

void cIntersection::setIntersec(float * i){
	m_intersec = i;
}

/*float * cIntersection::calcul_abc (cVector camera,cVector direction,cVector sphere,float Rayon){
	float * abc;
	float norme = 0;
	float X,Y,Z;
	cVector D;
	abc = (float*) calloc (3,sizeof(float));

	if (direction.norm() < sphere.norm())
		return NULL;
	

	D = camera.getDirection(direction);

	X = (camera.getX() - sphere.getX());
	Y = (camera.getY() - sphere.getY());
	Z = (camera.getZ() - sphere.getZ());

	abc[0] =  D.getX() * D.getX() + D.getY() * D.getY()	+ D.getZ() * D.getZ();
	abc[1] = 2 * (X * D.getX() + Y * D.getY() + Z * D.getZ());
	abc[2] = (X*X + Y*Y + Z*Z) - Rayon * Rayon;

	return abc;
}

float* cIntersection::calcul_intersection(float a,float b,float c){
	float* resultat;
	float delta;


	delta = b*b - 4 * a * c;
	if ( delta < 0)
		return NULL;

	else if (delta == 0){
		resultat = (float*) calloc (1,sizeof(float));
		resultat[0] = -b / (2 * a);
		return resultat;
	}

	else if (delta > 0){
		resultat = (float*) calloc (2,sizeof(float));
		resultat[0] = (-b -sqrtf(delta)) / (2 * a);
		resultat[1] = (-b +sqrtf(delta)) / (2 * a);

		if ( fabs(resultat[0]) < fabs(resultat[1]))
			resultat[1] = resultat[0];

		else
			resultat[0] = resultat[1];

		return resultat;
	}
	return NULL;
}*/

float cIntersection::Test_intersection(cRay* ray, float radius, cVector centerObject){
	cVector *rayon_origine;
	cVector *rayon_direction;
	cVector centre_sphere;

	float rayon_sphere = radius;
	float X0;
	float Y0;
	float Z0;
	
	float A;
	float B;
	float C;  //VALEURS EQUATION
	float Delta;

	float res0;
	float res1;
	float res2;

	rayon_direction = ray->get_direction_ray();
	rayon_origine = ray->get_origine_ray();
	centre_sphere = centerObject;

	X0 = rayon_origine->getX() - centre_sphere.getX();
	Y0 = rayon_origine->getY() - centre_sphere.getY();
	Z0 = rayon_origine->getZ() - centre_sphere.getZ();

	A = rayon_direction->getX() * rayon_direction->getX() + rayon_direction->getY() * rayon_direction->getY() + rayon_direction->getZ() * rayon_direction->getZ(); 
	B = 2 * (X0 * rayon_direction->getX() + Y0 * rayon_direction->getY() + Z0 * rayon_direction->getZ());
	C = X0 * X0 + Y0 * Y0 + Z0 * Z0 - (rayon_sphere * rayon_sphere);
	Delta = B*B- (4 * A *C);

	// if delta > 0 : 2 intersections
	if (Delta > 0.0F)
	{
		res1 = (-B + sqrt(Delta)) / (2 * A);
		res2 = (-B - sqrt(Delta)) / (2 * A);

		if( (res1 < res2) && (res1 > 0.0F))
			return res1;
		else if ( (res1 > res2) && (res2 > 0.0F) )
			return res2;
	}

	// if delat = 0 : 1 intersecion
	else if (Delta == 0.0F)
	{
		res0 = (-B) / (2 * A);

		if(res0 > 0.0F)
			return res0;

	}

	return -1.0;
}
