#include "stdafx.h"
#include "cScene.h"
#include "libMath.h"
#include "cIntersection.h"

#define MAX_ITERATION 4

cVector cScene::resultRay(cRay rayon, int iter)
{
	//Couleur de base noir
	cVector pixel, tmp2, P, N, L, pl, n, R, V;
	cRay rayon_test;
	cRay nouveau_rayon;
	cIntersection i1,i2;
	float * abc=NULL, *abc2 = NULL;
	float t, t2;
	int nombre_sphere, nombre_sphere2;
	float tmp;
	unsigned int light, sphere, sphere2, camera;
	float Id, Is, angle, fatt, ratio, scalaire; 
	

	pixel.setX(0);
	pixel.setY(0);
	pixel.setZ(0);

	// retrieve the nearest point
	if (iter <= 0)
		return pixel;

	
	t = 0.0F;
	nombre_sphere = -1;

	/* For each object */
	for(int object = 0; object <scene_objects.size(); object++){
		/* Get the type */
		if(scene_objects[object]->getType() == SPHERE){
			for(sphere = 0; sphere < scene_objects.size(); sphere++)
			{
				tmp = i1.Test_intersection(&rayon, ((cSphere*)(scene_objects[sphere]))->getRadius(), scene_objects[sphere]->getPosition());

				if( (tmp > 0) && (tmp < t || t == 0.0F)) // if intersection
				{
					t = tmp;
					nombre_sphere = sphere;
				}

				if(nombre_sphere != -1)
				{
					P = add(*rayon.get_origine_ray(), multiply(*rayon.get_direction_ray(), t));
					N = substract(P, scene_objects[nombre_sphere]->getPosition());
					nombre_sphere2 = -1;
					Id = 0.0F;
					Is = 0.0F;

					for(light = 0; light < scene_lightsources.size(); light++)
					{
						// check if light reaches the point
						*rayon_test.get_origine_ray() = scene_lightsources[light]->getPos();
						*rayon_test.get_direction_ray() = substract(P, *rayon_test.get_origine_ray());
						*rayon_test.get_direction_ray() = normalize(*rayon_test.get_direction_ray());
						t2 = 0.0F;

						for(sphere2 = 0; sphere2 < scene_objects.size(); sphere2++)
						{
							tmp = i2.Test_intersection(&rayon_test, ((cSphere*)(scene_objects[sphere2]))->getRadius(), scene_objects[sphere2]->getPosition());

							if((tmp > 0) && ((tmp < t2) || (t2 == 0.0F)))
							{
								t2 = tmp;
								nombre_sphere2 = sphere2;
							}

						}

						// if light lights the point

						tmp2 = add(*rayon_test.get_origine_ray(), multiply(*rayon_test.get_direction_ray(), t2));
						if(egal_vect(&tmp2, &P))
						{

							L = substract(*rayon_test.get_origine_ray(), P);
							pl = multiply(L, -1.0);
							n = substract(P, scene_objects[nombre_sphere2]->getPosition());
							R = substract(multiply(multiply(N, 2), dot_product(N, L)), L);

							angle = (float)dot_product(n, pl);
							fatt = 0.0f;
							ratio = 0.0f;

							if(angle < 0)
								ratio = (-angle*100.0f) /90.0f;
							else
								ratio = (angle*100.0f) / 90.0f;

							V = multiply(*rayon.get_direction_ray(), (-ratio));

							if(1.0F / 1 + norm(L) + norm(L) * norm(L) > 1.0F)
								fatt = 1.0F;
							else
								fatt = 1.0F / 1 + norm(L) + norm(L) * norm(L);

							N = normalize(N);
							L = normalize(L);
							V = normalize(V);
							R = normalize(R);

							Id += fatt *(scene_objects[nombre_sphere]->getKaMaterial() + scene_objects[nombre_sphere]->getKdMaterial()) * dot_product(N, L);
							scalaire = (dot_product(V, R) > 0.0F) ? dot_product(V, R) : 0.0F;
							Is += fatt *(scene_objects[nombre_sphere]->getKaMaterial() + scene_objects[nombre_sphere]->getKdMaterial() + scene_objects[nombre_sphere]->getKsMaterial()) * scalaire;

							pixel = multiply(add(add(pixel, multiply(scene_objects[nombre_sphere]->getMaterial().getColor(), Id)), scene_lightsources[light]->getColor()), Is);

						}
					}

					pixel = add(pixel, multiply(scene_objects[nombre_sphere]->getMaterial().getColor(), scene_objects[nombre_sphere]->getKaMaterial()));

					// if the object reflect

					if (scene_objects[nombre_sphere]->getKeMaterial() > 0.001F)
					{
						pixel = multiply(pixel, 1.0F - scene_objects[nombre_sphere]->getKaMaterial());
						*nouveau_rayon.get_origine_ray() = P;
						*nouveau_rayon.get_direction_ray() = substract(*rayon.get_direction_ray(), multiply(multiply(N, 2.0), dot_product(N, *rayon.get_direction_ray())));
						pixel = add(pixel, multiply(resultRay(nouveau_rayon, iter - 1), scene_objects[nombre_sphere]->getKeMaterial()));
					}
					if (scene_objects[nombre_sphere]->getKeMaterial() > 0.001F)
					{

						pixel = (multiply(pixel, scene_objects[nombre_sphere]->getKeMaterial()));
						*nouveau_rayon.get_origine_ray() = P;
						*nouveau_rayon.get_direction_ray() = *rayon.get_origine_ray();
						pixel = add(pixel, multiply(resultRay(nouveau_rayon, iter -1), scene_objects[nombre_sphere]->getKeMaterial()));
					}
				}
			}
			pixel = saturation(pixel);
			return pixel;

		} else if(scene_objects[object]->getType() == CUBE){

		} else if(scene_objects[object]->getType() == PYRAMIDAL){

		}

	}

	
}

FIBITMAP* cScene::getImage(unsigned int nombre_cameras)
{
	int divisor;
	int i;
	int j;

	cVector verticale, droite, height, pixel;
	cRay ray;
	RGBQUAD color;

	if(scene_cameras.size() > nombre_cameras)
	{
		// picture allocation
		FIBITMAP* Image = FreeImage_Allocate(scene_cameras[nombre_cameras]->getWidth(), scene_cameras[nombre_cameras]->getHeight(), 24);

		divisor = max(scene_cameras[nombre_cameras]->getWidth(), scene_cameras[nombre_cameras]->getHeight());

		verticale.setX(0.0f);
		verticale.setY(1.0f);
		verticale.setZ(0.0f);

		droite = matrix_product(scene_cameras[nombre_cameras]->get_directionnal_vector(), verticale);	
		height = matrix_product(droite, scene_cameras[nombre_cameras]->get_directionnal_vector());

		droite = normalize(droite);
		height = normalize(height);

		
		// for each pixel of the picture
		for(i = 0; i < scene_cameras[nombre_cameras]->getHeight(); i++)
		{
			for(j = 0; j < scene_cameras[nombre_cameras]->getWidth(); j++)
			{
				*ray.get_origine_ray() = (add(add(
					add(scene_cameras[nombre_cameras]->getPosition(), multiply(scene_cameras[nombre_cameras]->get_directionnal_vector(), scene_cameras[nombre_cameras]->getFocal())),
					multiply(droite, (float) (j - scene_cameras[nombre_cameras]->getWidth() / 2) / (float)divisor)),
					multiply(height, (float) (i - scene_cameras[nombre_cameras]->getHeight() / 2) / (float)divisor)));

				*ray.get_direction_ray() = (substract(*ray.get_origine_ray(), scene_cameras[nombre_cameras]->getPosition()));

				*ray.get_direction_ray() = (normalize(*ray.get_direction_ray()));

				pixel = (resultRay(ray, MAX_ITERATION));

				//Transformation in RGBQUAD
				color.rgbRed = pixel.getX();
				color.rgbGreen = pixel.getY();
				color.rgbBlue = pixel.getZ();

				FreeImage_SetPixelColor(Image, j, i, &color);
			}
		}
		return Image;
	}
	return NULL;
}
