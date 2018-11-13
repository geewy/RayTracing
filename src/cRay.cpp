#include "stdafx.h"
#include "cRay.h"


cRay::cRay()
{
	origine_ray = &cVector();
	direction_ray = &cVector();
}

cRay::cRay(cVector* origine_ray_init, cVector* direction_ray_init)
{
	origine_ray = origine_ray_init;
	direction_ray = direction_ray_init;
}

void cRay::set_origine_ray(cVector* set_origine_ray)
{
	origine_ray = set_origine_ray;

}
void cRay::set_direction_ray(cVector* set_direction_ray)
{
	direction_ray = set_direction_ray;
}

cVector* cRay::get_origine_ray()
{
	return origine_ray;
}
cVector* cRay::get_direction_ray()
{
	return direction_ray;
}
