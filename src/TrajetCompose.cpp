/******************************************************************************
						   TrajetCompose  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//--- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ----

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//----------------------------------------------------------- Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
void TrajetCompose::Ajouter(const Trajet* trajet)
// Algorithme :
//		Aucun.
{
	liste->Ajouter(trajet);
} //----- Fin de Ajouter

bool TrajetCompose::Afficher(ostream& fichier, TypeTrajet type) const
// Algorithme :
//		Aucun.
{
	if (type != 1) {
		liste->Afficher(fichier);
		return true;
	}
	return false;
} //----- Fin de Afficher

bool TrajetCompose::EstPostAlpha(const Trajet* trajet) const
// Algorithme :
//		Aucun.
{
	if (!strcmp(GetVilleDepart(), trajet->GetVilleDepart())) {
		return strcmp(GetVilleArrivee(), trajet->GetVilleArrivee()) >= 0;
	}
	return strcmp(GetVilleDepart(), trajet->GetVilleDepart()) >= 0;
} //----- Fin de EstPostAlpha

char* TrajetCompose::GetVilleDepart() const
// Algorithme :
//		Aucun.
{
	return liste->GetPremierTrajet()->GetVilleDepart();
} //----- Fin de GetVilleDepart

char* TrajetCompose::GetVilleArrivee() const
// Algorithme :
//		Aucun.
{
	return liste->GetDernierTrajet()->GetVilleArrivee();
} //----- Fin de GetVilleArrivee

TrajetCompose* TrajetCompose::Copier() const
// Algorithme :
//		Effectue une copie en profondeur.
{
	return new TrajetCompose(*this);
} //----- Fin de Copier

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose& trajetCompose)
// Algorithme :
//		Effectue une copie en profondeur.
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
	#endif

	liste = new ListeTrajet(*trajetCompose.liste);
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose()
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur de <TrajetCompose>" << endl;
	#endif

	liste = new ListeTrajet(false);
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au destructeur de <TrajetCompose>" << endl;
	#endif

	delete liste;
} //----- Fin de ~TrajetCompose

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
