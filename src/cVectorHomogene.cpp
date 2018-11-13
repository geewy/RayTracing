#include "stdafx.h"
#include "cVectorHomogene.h"
#include <math.h>
#include "cVector.h"

//constructeur
cVectorHomogene::cVectorHomogene()
{

}

//destructeur
cVectorHomogene::~cVectorHomogene()
{

}

void cVectorHomogene::setX(float posX){
	this->m_x = posX;
}

void cVectorHomogene::setY(float posY){
	this->m_y = posY;
}

void cVectorHomogene::setZ(float posZ){
	this->m_z = posZ;
}

void cVectorHomogene::setW(float posW){
	this->m_z = posW;
}

float cVectorHomogene::getX(){
    return this->m_x;
} 

float cVectorHomogene::getY(){
    return this->m_y;
} 

float cVectorHomogene::getZ(){
    return this->m_z;
} 

float cVectorHomogene::getW(){
    return this->m_w;
} 
