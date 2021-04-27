/******************************************************************************
						   Trajet  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//--------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//----------------------------------------------------------- Include personnel
#include "Trajet.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur
Trajet::Trajet()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur de <Trajet>" << endl;
	#endif
}

Trajet::~Trajet()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
}

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
