/**
 * \file cObject.cpp
 * \brief Librairy of an object
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cObject.h"

/**
 * \fn cObject::cObject()
 * \brief Contructor of an object
 */
cObject::cObject(){}

void cObject::setPosition(cVector v)
{
	m_position = v;
}
cVector cObject::getPosition()
{
	return m_position;
}


/**
 * \fn cObject::~cObject()
 * \brief Destructor of an object
 */
cObject::~cObject(){}


void cObject::setColorMaterial(float red, float green, float blue){
	m_material.setColor(red,green,blue);
}

void cObject::setCoefficientMaterial(float ka, float kd, float ke, float ks){
	m_material.setCoefficient(ka, kd, ke, ks);
}

int cObject::getType(){
	return m_type;
}

float cObject::getKaMaterial(){
	return m_material.getKa();
}

float cObject::getKdMaterial(){
	return m_material.getKd();
}

float cObject::getKeMaterial(){
	return m_material.getKe();
}

float cObject::getKsMaterial(){
	return m_material.getKs();
}

cMaterial cObject::getMaterial(){
	return m_material;
}
