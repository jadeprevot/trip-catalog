/******************************************************************************
						   TrajetSimple  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) -----

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//----------------------------------------------------------- Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
bool TrajetSimple::Afficher(ostream& fichier, TypeTrajet type) const
// Algorithme :
//		Aucun.
{
	if (type != TypeTrajet::TRAJETCOMPOSE) {
		if (fichier.rdbuf() == cout.rdbuf()) { // si la sortie est cout
			fichier << villeDepart << " -> " << villeArrivee << " : " << moyenTransport;
		}
		else {
			fichier << villeDepart << endl << villeArrivee << endl << moyenTransport << endl;
		}
		return true;
	}
	return false;
} //----- Fin de Afficher

bool TrajetSimple::EstPostAlpha(const Trajet* trajet) const
// Algorithme :
//		Aucun.
{
	if (!strcmp(GetVilleDepart(), trajet->GetVilleDepart())) {
		return strcmp(GetVilleArrivee(), trajet->GetVilleArrivee()) >= 0;
	}
	return strcmp(GetVilleDepart(), trajet->GetVilleDepart()) >= 0;
} //----- Fin de EstPostAlpha

char* TrajetSimple::GetVilleDepart() const
// Algorithme :
//		Aucun.
{
	return villeDepart;
} //----- Fin de GetVilleDepart

char* TrajetSimple::GetVilleArrivee() const
// Algorithme :
//		Aucun.
{
	return villeArrivee;
} //----- Fin de GetVilleArrivee

TrajetSimple* TrajetSimple::Copier() const
// Algorithme :
//		Effectue une copie en profondeur.
{
	return new TrajetSimple(*this);
} //----- Fin de Copier

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple& trajetSimple)
// Algorithme :
//		Effectue une copie en profondeur.
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
	#endif

	villeDepart = new char[strlen(trajetSimple.villeDepart) + 1];
	strcpy(villeDepart, trajetSimple.villeDepart);
	villeArrivee = new char[strlen(trajetSimple.villeArrivee) + 1];
	strcpy(villeArrivee, trajetSimple.villeArrivee);
	moyenTransport = new char[strlen(trajetSimple.moyenTransport) + 1];
	strcpy(moyenTransport, trajetSimple.moyenTransport);
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple(const char* depart, const char* arrivee, const char* transport)
// Algorithme :
//		Effectue une copie en profondeur.
{
	#ifdef MAP
		cout << "Appel au constructeur de <TrajetSimple>" << endl;
	#endif

	villeDepart = new char[strlen(depart) + 1];
	strcpy(villeDepart, depart);
	villeArrivee = new char[strlen(arrivee) + 1];
	strcpy(villeArrivee, arrivee);
	moyenTransport = new char[strlen(transport) + 1];
	strcpy(moyenTransport, transport);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au destructeur de <TrajetSimple>" << endl;
	#endif

	delete[] villeDepart;
	delete[] villeArrivee;
	delete[] moyenTransport;
} //----- Fin de ~TrajetSimple

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
