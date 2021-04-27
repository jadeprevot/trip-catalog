/******************************************************************************
						   ListeTrajet  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) -------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//----------------------------------------------------------- Include personnel
#include "ListeTrajet.h"
#include "TrajetCompose.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
void ListeTrajet::Ajouter(const Trajet* trajet)
// Algorithme :
//		Aucun.
{
	if (estVide()) {
		derniere = new Cellule(trajet);
		derniere->SetSuivante(derniere);
	}
	else {
		if (!estTrieeAlpha) {
			Cellule* nouvelle = new Cellule(trajet, derniere->GetSuivante());
			derniere->SetSuivante(nouvelle);
			derniere = nouvelle;
		}
		else {
			if (trajet->EstPostAlpha(derniere->GetTrajet())) {
				Cellule* nouvelle = new Cellule(trajet, derniere->GetSuivante());
				derniere->SetSuivante(nouvelle);
				derniere = nouvelle;
			}
			else if (derniere->GetSuivante()->GetTrajet()->EstPostAlpha(trajet)) {
				Cellule* nouvelle = new Cellule(trajet, derniere->GetSuivante());
				derniere->SetSuivante(nouvelle);
			}
			else {
				Cellule* it = derniere->GetSuivante();
				while (!it->GetSuivante()->GetTrajet()->EstPostAlpha(trajet)) {
					it = it->GetSuivante();
				}
				Cellule* nouvelle = new Cellule(trajet, it->GetSuivante());
				it->SetSuivante(nouvelle);
			}
		}
	}
} //----- Fin de Ajouter

void ListeTrajet::Ajouter(const ListeTrajet* listeTrajet)
// Algorithme :
//		Ajoute une copie en profondeur.
{
	if (!listeTrajet->estVide()) {
		TrajetCompose* trajetCompose = new TrajetCompose();
		Cellule* it = listeTrajet->derniere->GetSuivante();
		trajetCompose->Ajouter(it->GetTrajet()->Copier());
		it = it->GetSuivante();
		while (it != listeTrajet->derniere->GetSuivante()) {
			trajetCompose->Ajouter(it->GetTrajet()->Copier());
			it = it->GetSuivante();
		}
		Ajouter(trajetCompose);
	}
} //----- Fin de Ajouter

void ListeTrajet::Afficher(ostream& fichier, TypeTrajet type) const
// Algorithme :
//		Aucun.
{
	if (!estVide()) {
		Cellule* it = derniere->GetSuivante();
		bool aEteAffiche = it->GetTrajet()->Afficher(fichier, type);
		if (estTrieeAlpha && aEteAffiche) {
			if (fichier.rdbuf() == cout.rdbuf()) {
				fichier << " ;" << endl;
			}
			else {
				fichier << ";" << endl;
			}
		}
		it = it->GetSuivante();
		while (it != derniere->GetSuivante()) {
			if (aEteAffiche) {
				if (fichier.rdbuf() == cout.rdbuf()) {
					if (!estTrieeAlpha) {
						fichier << " + ";
					}
				}
				else {
					if (!estTrieeAlpha) {
						fichier << "+" << endl;
					}
				}
			}
			aEteAffiche = it->GetTrajet()->Afficher(fichier, type);
			if (estTrieeAlpha && aEteAffiche) {
				if (fichier.rdbuf() == cout.rdbuf()) {
					fichier << " ;" << endl;
				}
				else {
					fichier << ";" << endl;
				}
			}
			it = it->GetSuivante();
		}
	}
} //----- Fin de Afficher

void ListeTrajet::Afficher(ostream& fichier, string depart, string arrivee) const
// Algorithme :
//		Aucun.
{
	if (depart == "*" && arrivee == "*") {
		Afficher(fichier);
		return;
	}

	if (!estVide()) {
		Cellule* it = derniere->GetSuivante();
		if ((depart == "*" && arrivee == it->GetTrajet()->GetVilleArrivee()) ||
			(arrivee == "*" && depart == it->GetTrajet()->GetVilleDepart()) ||
			(depart == it->GetTrajet()->GetVilleDepart() && arrivee == it->GetTrajet()->GetVilleArrivee())) {
			it->GetTrajet()->Afficher(fichier);
			fichier << ";" << endl;
		}
		it = it->GetSuivante();
		while (it != derniere->GetSuivante()) {
			if ((depart == "*" && arrivee == it->GetTrajet()->GetVilleArrivee()) ||
				(arrivee == "*" && depart == it->GetTrajet()->GetVilleDepart()) ||
				(depart == it->GetTrajet()->GetVilleDepart() && arrivee == it->GetTrajet()->GetVilleArrivee())) {
				it->GetTrajet()->Afficher(fichier);
				fichier << ";" << endl;
			}
			it = it->GetSuivante();
		}
	}
} //----- Fin de Afficher

const Trajet* ListeTrajet::GetPremierTrajet() const
// Algorithme :
//		Aucun.
{
	return derniere->GetSuivante()->GetTrajet();
} //----- Fin de GetPremierTrajet

const Trajet* ListeTrajet::GetDernierTrajet() const
// Algorithme :
//		Aucun.
{
	return derniere->GetTrajet();
} //----- Fin de GetDernierTrajet

ListeTrajet* ListeTrajet::TrouverTrajetsVersionSimple(const char* depart, const char* arrivee) const
// Algorithme :
//		Aucun.
{
	ListeTrajet* resultat = new ListeTrajet(true);
	if (!estVide()) {
		Cellule* it = derniere->GetSuivante();
		if (!strcmp(it->GetTrajet()->GetVilleDepart(), depart) && !strcmp(it->GetTrajet()->GetVilleArrivee(), arrivee)) {
			resultat->Ajouter(it->GetTrajet()->Copier());
		}
		it = it->GetSuivante();
		while (it != derniere->GetSuivante()) {
			if (!strcmp(it->GetTrajet()->GetVilleDepart(), depart) && !strcmp(it->GetTrajet()->GetVilleArrivee(), arrivee)) {
				resultat->Ajouter(it->GetTrajet()->Copier());
			}
			it = it->GetSuivante();
		}
	}
	return resultat;
} //----- Fin de TrouverTrajetsVersionSimple

ListeTrajet* ListeTrajet::TrouverTrajetsVersionAvancee(const char* depart, const char* arrivee) const
// Algorithme :
//		Aucun.
{
	ListeTrajet* resultat = new ListeTrajet(true);
	if (!estVide()) {
		int nbCellules = 1;
		Cellule* it = derniere->GetSuivante();
		while (it != derniere) {
			it = it->GetSuivante();
			++nbCellules;
		}
		int index = 0;
		it = derniere->GetSuivante();
		while (index < nbCellules) {
			if (!strcmp(it->GetTrajet()->GetVilleArrivee(), arrivee)) {
				ListeTrajet* tentative = new ListeTrajet(false);
				bool tmp = trouverTrajetsVersionAvancee(depart, it->GetTrajet()->GetVilleDepart(), nbCellules, tentative);
				tentative->Ajouter(it->GetTrajet()->Copier());
				if (tmp) {
					resultat->Ajouter(tentative);
				}
				delete tentative;
			}
			it = it->GetSuivante();
			++index;
		}
	}
	return resultat;
} //----- Fin de TrouverTrajetsVersionAvancee

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet(bool trieeAlpha) : derniere(nullptr), estTrieeAlpha(trieeAlpha)
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au constructeur de <ListeTrajet>" << endl;
	#endif
} //----- Fin de ListeTrajet

ListeTrajet::ListeTrajet(const ListeTrajet& listeTrajet) : derniere(nullptr), estTrieeAlpha(listeTrajet.estTrieeAlpha)
// Algorithme :
//		Effectue une copie en profondeur.
{
	if (!listeTrajet.estVide()) {
		Cellule* it = listeTrajet.derniere->GetSuivante();
		Ajouter(it->GetTrajet()->Copier());
		it = it->GetSuivante();
		while (it != listeTrajet.derniere->GetSuivante()) {
			Ajouter(it->GetTrajet()->Copier());
			it = it->GetSuivante();
		}
	}
} //----- Fin de ListeTrajet (constructeur de copie)

ListeTrajet::~ListeTrajet()
// Algorithme :
//		Aucun.
{
	#ifdef MAP
		cout << "Appel au destructeur de <ListeTrajet>" << endl;
	#endif

	if (!estVide()) {
		Cellule* it = derniere->GetSuivante();
		while (it != derniere) {
			Cellule* tmp = it->GetSuivante();
			delete it;
			it = tmp;
		}
		delete it;
	}
} //----- Fin de ~ListeTrajet

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
bool ListeTrajet::trouverTrajetsVersionAvancee(const char* depart, const char* arrivee, int nbCellules, ListeTrajet* tentative) const
// Algorithme :
//		Trouve les trajets de manière récursive : cherche les trajets
//		dont la ville d'arrivée d'un trajet est identique à la ville de
//		départ d'un autre trajet. Permet de chaîner les trajets.
{
	if (!strcmp(depart, arrivee)) {
		return true;
	}
	int index = 0;
	Cellule* it = derniere->GetSuivante();
	while (index < nbCellules) {
		if (!strcmp(it->GetTrajet()->GetVilleArrivee(), arrivee)) {
			bool tmp = trouverTrajetsVersionAvancee(depart, it->GetTrajet()->GetVilleDepart(), nbCellules, tentative);
			tentative->Ajouter(it->GetTrajet()->Copier());
			return tmp;
		}
		it = it->GetSuivante();
		++index;
	}
	return false;
} //----- Fin de trouverTrajetsVersionAvancee
