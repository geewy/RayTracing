#ifndef RAY_H
#define RAY_H

#include "cVector.h"

class cRay
{
	private:
		cVector* origine_ray;
		cVector* direction_ray;

	public:
		cRay();
		cRay(cVector* origine_ray_init, cVector* direction_ray_init);

		void cRay::set_origine_ray(cVector* origine_ray_init);
		void cRay::set_direction_ray(cVector* direction_ray_init);

		cVector* cRay::get_origine_ray();
		cVector* cRay::get_direction_ray();
};

#endif
