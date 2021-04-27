/******************************************************************************
						   Cellule  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//--------- Réalisation de la classe <Cellule> (fichier Cellule.cpp) ----------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//----------------------------------------------------------- Include personnel
#include "Cellule.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

const Trajet* Cellule::GetTrajet() const
// Algorithme :
//		Aucun.
{
	return trajet;
} //----- Fin de GetTrajet

Cellule* Cellule::GetSuivante() const
// Algorithme :
//		Aucun.
{
	return suivante;
} //----- Fin de GetSuivante

void Cellule::SetTrajet(const Trajet* unTrajet)
// Algorithme :
//		Aucun.
{
	trajet = unTrajet;
} //----- Fin de SetTrajet

void Cellule::SetSuivante(Cellule* uneSuivante)
// Algorithme :
//		Aucun.
{
	suivante = uneSuivante;
} //----- Fin de SetSuivante

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

Cellule::Cellule()
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur de <Cellule>" << endl;
	#endif
} //----- Fin de Cellule

Cellule::Cellule(const Trajet* unTrajet, Cellule* uneSuivante) : trajet(unTrajet), suivante(uneSuivante)
// Algorithme :
// 		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur de <Cellule>" << endl;
	#endif
} //----- Fin de Cellule

Cellule::~Cellule()
// Algorithme :
// 		Aucun.
{
	#ifdef MAP
		cout << "Appel au destructeur de <Cellule>" << endl;
	#endif

	delete trajet;
} //----- Fin de ~Cellule

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
