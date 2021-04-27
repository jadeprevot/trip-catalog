/******************************************************************************
						   Catalogue  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//----------------------------------------------------------- Include personnel
#include "Catalogue.h"

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

void Catalogue::Ajouter(const Trajet* trajet)
//Algorithme :
//		Aucun.
{
	liste->Ajouter(trajet);
}//----- Fin de Ajouter

void Catalogue::Afficher(ostream& fichier, TypeTrajet type) const
//Algorithme :
//		Aucun.
{
	liste->Afficher(fichier, type);
} //----- Fin de Afficher

void Catalogue::Afficher(ostream& fichier, string depart, string arrivee) const
//Algorithme :
//		Aucun.
{
	liste->Afficher(fichier, depart, arrivee);
} //----- Fin de Afficher

Catalogue* Catalogue::TrouverTrajetsVersionSimple(const char* depart, const char* arrivee) const
//Algorithme :
//		Aucun.
{
	return new Catalogue(liste->TrouverTrajetsVersionSimple(depart, arrivee));
} //----- Fin de TrouverTrajetsVersionSimple

Catalogue* Catalogue::TrouverTrajetsVersionAvancee(const char* depart, const char* arrivee) const
//Algorithme :
//		Aucun.
{
	return new Catalogue(liste->TrouverTrajetsVersionAvancee(depart, arrivee));
} //----- Fin de TrouverTrajetsVersionAvancee

void Catalogue::Vider()
//Algorithme :
//		Aucun.
{
	delete liste;
	liste = new ListeTrajet(true);
} //----- Fin de Vider

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
//Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur 1 de <Catalogue>" << endl;
	#endif

	liste = new ListeTrajet(true);
} //----- Fin de Catalogue

Catalogue::Catalogue(ListeTrajet* listeTrajet) : liste(listeTrajet)
//Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur 2 de <Catalogue>" << endl;
	#endif
} //----- Fin de Catalogue 2

Catalogue::~Catalogue()
//Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au destructeur de <Catalogue>" << endl;
	#endif

	delete liste;
} //----- Fin de ~Catalogue

//----------------------------------------------------------------------- PRIVE

//---------------------------------------------------------- Méthodes protégées
