/**
 * \file cMaterial.cpp
 * \brief Librairy of a material
 *
 * \author geewy
 */
#include "stdafx.h"
#include "cMaterial.h"

/**
 * \fn cMaterial::cMaterial()
 * \brief Contructor of a material
 */
cMaterial::cMaterial(){}

/**
 * \fn cMaterial(float ka, float kd, float ke, float ks, cVector Ia)
 * \brief Contructor of a material
 */
cMaterial::cMaterial(float ka, float kd, float ke, float ks){
	m_ka = ka;
	m_kd = kd;
	m_ke = ke;
	m_ks = ks;
}

/**
 * \fn cMaterial::~cMaterial()
 * \brief Destructor of a material
 */
cMaterial::~cMaterial(){}

/**
 * \fn float getKa()
 * \brief Get the ka coefficient of the material
 */
float cMaterial::getKa(){return m_ka;}

/**
 * \fn float getKd()
 * \brief Get the kd coefficient of the material
 */
float cMaterial::getKd(){return m_kd;}

/**
 * \fn float getKe()
 * \brief Get the ke coefficient of the material
 */
float cMaterial::getKe(){return m_ke;}

/**
 * \fn float getKs()
 * \brief Get the ks coefficient of the material
 */
float cMaterial::getKs(){return m_ks;}

cVector cMaterial::getColor(){ return m_color; }

void cMaterial::setColor(float red, float green, float blue){
	m_color.setColor(red, green, blue);
}

void cMaterial::setCoefficient(float ka, float kd, float ke, float ks){
	m_ka = ka;
	m_kd = kd;
	m_ke = ke;
	m_ks = ks;
}
