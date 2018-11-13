/**
 * \file cPonctual.h
 * \brief Header for the librairy of the ponctual light source
 *
 * \author geewy
 */

#ifndef PONCTUAL_H
#define PONCTUAL_H

#include "cLightSource.h"

/** 
 * \class cPonctual
 * \brief class which represents an ponctual light source - Heritage from cLightSource
 */
class cPonctual : public cLightSource
{
	public:
		cPonctual();	//constructor
		~cPonctual();	//destructor
};

#endif
