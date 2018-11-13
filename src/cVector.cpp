/**
 * \file cVector.cpp
 * \brief Librairy of vector operation
 *
 * \author geewy
 */

#include "stdafx.h"
#include "stdlib.h"

#include "cVector.h"
#include "cVecteurHomogene.h"

#include <cmath>

/**
 * \fn cVector::cVector()
 * \brief Contructor of a vector(x,y,z)
 */
cVector::cVector(){}

cVector::cVector(float x, float y, float z){
	m_x = x;
	m_y = y;
	m_z = z;
}

/**
 * \fn cVector::~cVector()
 * \brief Destructor of a vector
 */
cVector::~cVector(){}

void cVector::setVecteur(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void cVector::setX(float posX){
	m_x = posX;
}

void cVector::setY(float posY){
	m_y = posY;
}

void cVector::setZ(float posZ){
	m_z = posZ;
}

float cVector::getX(){
    return m_x;
} 

float cVector::getY(){
    return m_y;
} 

float cVector::getZ(){
    return m_z;
}

float cVector::getRedColor(){ return m_red ;}
float cVector::getGreenColor(){ return m_green ;}
float cVector::getBlueColor(){ return m_blue ;}

void cVector::setColor(float red, float green, float blue){
	m_red = red;
	m_green = green;
	m_blue = blue;
}
