/**
 * \file libMath.cpp
 * \brief Librairy of vector operation
 *
 * \author geewy
 */

#include "stdafx.h"
#include "stdlib.h"

#include "libMath.h"
#include "cVecteurHomogene.h"

#include "math.h"
/**
 * \fn cVector matrix_product(cVector vector1, cVector vector2)
 * \brief Compute the matrix product
 *
 * \param cVector vector(1 or 2) : The two vectors to compute
 * \return cVector vector_cross : The new vector
 */
cVector matrix_product(cVector vector1, cVector vector2){
	cVector vector_cross;
	float posX, posY, posZ;

	posX = (vector1.getY() * vector2.getZ()) - vector1.getZ() - vector2.getY();
	posY = (vector1.getZ() * vector2.getX()) - vector1.getX() - vector2.getZ();
	posZ = (vector1.getX() * vector2.getY()) - vector1.getY() - vector2.getX();

	vector_cross.setX(posX);
	vector_cross.setY(posY);
	vector_cross.setZ(posZ);

	return vector_cross;
}

/**
 * \fn double dot_product(cVector vector1, cVector vector2)
 * \brief Compute the cot product
 *
 * \param cVector cVector(1 or 2) : The two vectors to compute
 * \return double dot_res : The result
 */
double dot_product(cVector vector1, cVector vector2){
	double dot_res;

	dot_res = (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY()) + (vector1.getZ() * vector2.getZ());

	return dot_res;
}


/**
 * \fn double norm(cVector vector)
 * \brief Compute the norm of a vector
 *
 * \param cVector(1 or 2) : The two vectors to compute
 * \return double norm
 */
double norm(cVector vector){
	double norm_res;

	norm_res = sqrt((vector.getX()*vector.getX()) + (vector.getY()*vector.getY()) + (vector.getZ()*vector.getZ()));

	return norm_res;
}

/**
 * \fn double distance(cVector vector1, cVector vector2)
 * \brief Compute the norme of the addition of two vectors
 *
 * \param cVector(1 or 2) : The two vectors to compute
 * \return double norme of the addition of two vectors
 */
double normAdd(cVector vector1, cVector vector2){
	double distance_res;

	distance_res = norm(add(vector2,vector1));

	return distance_res;
}

/**
 * \fn cVector normalize(cVector v)
 * \brief Normalize the vector
 *
 * \param cVector vector : The vector to normalize
 * \return cVector normalize_vector 
 */
cVector normalize(cVector vector){
	cVector normalize_vector;

	normalize_vector = multiply(vector, 1/norm(vector));

	return normalize_vector;
}

/**
 * \fn cVector sum(cVector vector1, cVector vector2)
 * \brief Sum two vector
 *
 * \param cVector vector(1 & 2) : The two vector to sum
 * \return cVector sum_vector
 */
cVector add(cVector vector1, cVector vector2){
	cVector sum_vector;
	float sumX, sumY, sumZ;

	sumX = vector1.getX() + vector2.getX();
	sumY = vector1.getY() + vector2.getY();
	sumZ = vector1.getZ() + vector2.getZ();

	sum_vector.setX(sumX);
	sum_vector.setY(sumY);
	sum_vector.setZ(sumZ);

	return sum_vector;
}

/**
 * \fn cVector substract(cVector vector1,cVector vector2)
 * \brief Substract two vector
 *
 * \param cVector vector(1 & 2) : The two vector to sum
 * \return cVector substract_vector
 */
cVector substract(cVector vector1,cVector vector2){
	cVector substract_vector;
	float subX, subY, subZ;

	subX = vector1.getX() - vector2.getX();
	subY = vector1.getY() - vector2.getY();
	subZ = vector1.getZ() - vector2.getZ();

	substract_vector.setX(subX);
	substract_vector.setY(subY);
	substract_vector.setZ(subZ);

	return substract_vector;
}

/**
 * \fn cVector multiply(cVector v, double s)
 * \brief Multiply a vector with a scalar
 *
 * \param cVector vector : The vector
 * \param double scalar
 * \return cVector substract_vector
 */
cVector multiply(cVector vector, double scalar){
	cVector res_vector;
	float multX, multY, multZ;

	multX = vector.getX() * scalar;
	multY = vector.getY() * scalar;
	multZ = vector.getZ() * scalar;

	res_vector.setX(multX);
	res_vector.setY(multY);
	res_vector.setZ(multZ);

	return res_vector;
}


/**
 * \fn cVector reflexion(cVector incident, cVector normal)
 * \brief Compute the reflect vector
 *
 * \param cVector incident
 * \param cVector normal
 * \return cVector reflect_vector
 */
cVector reflexion(cVector incident, cVector normal){
	cVector reflect_vector;

	reflect_vector = add(multiply(normal, -2 * dot_product(normal, incident)), incident); 

	return reflect_vector;
}

/**
 * \fn cVector double::squareVector(cVector vector1)
 * \brief The result of (x²+y²+z²)
 *
 * \param cVector vector1 : The vector
 * \return double square_result
 */
double squareVector(cVector vector1){
	double square_result;

	square_result = pow(vector1.getX(),2) + pow(vector1.getY(), 2) + pow(vector1.getZ(), 2);

	return square_result;
}


cVector saturation(cVector  color)
{
	color.setX((color.getX() >= 1) ? 255 : color.getX() * 255);
	color.setY((color.getY() >= 1) ? 255 : color.getY() * 255);
	color.setZ((color.getZ() >= 1) ? 255 : color.getZ() * 255);

	return color;
}

bool egal_vect(cVector *vector1, cVector *vector2)
{

	if((vector1->getX() - vector2->getX()  < 0.01) && (vector1->getY() - vector2->getY() < 0.01) && (vector1->getZ() - vector2->getZ() < 0.01) )
		return true;
	else
		return false;

}
