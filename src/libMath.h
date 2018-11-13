/**
 * \file libMath.h
 * \brief Header for the librairy of vector operation
 *
 * \author geewy
 */

#ifndef LIB_MATH_H
#define LIB_MATH_H

#include "cVector.h"

cVector matrix_product(cVector vector1, cVector vector2);		// Return v1^v2
double dot_product(cVector vector1, cVector vector2);			// Return v1.v2
double norm(cVector vector);									// Return ||v|| 
double normAdd(cVector vector1, cVector vector2);				// Return ||v2+v1||
cVector normalize(cVector vector);								// Return v/||v||
cVector add(cVector vector1, cVector vector2);					// Return v1 + v2
cVector substract(cVector vector1,cVector vector2);				// Return v1 - v2
cVector multiply(cVector v, double scalar);						// Return v*s
cVector reflexion(cVector i, cVector n);						// Return the reflexion vector
double squareVector(cVector vector1);							// Return (x²+y²+z²)
bool egal_vect(cVector* vector1, cVector* vector2);
cVector saturation(cVector  color);	

#endif
