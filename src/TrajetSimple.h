/******************************************************************************
						   TrajetSimple  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//------ Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -------
#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TypeTrajet.h"
#include <fstream>

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//		Permet de gérer un trajet simple.
//-----------------------------------------------------------------------------

class TrajetSimple : public Trajet {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		bool Afficher(ostream& fichier, TypeTrajet type = TypeTrajet::TRAJET) const;
		// Mode d'emploi :
		//		Affiche la ville de départ, la ville d'arrivée et le moyen de
		// 		transport du trajet simple dans fichier si celui ci est de type type.
		//		Retourne vrai si un affichage à eu lieu. Retourne faux sinon.
		// Contrat :
		//		Aucun.

		bool EstPostAlpha(const Trajet* unTrajet) const;
		// Mode d'emploi :
		//		Retourne vrai si la ville de départ du trajet simple arrive après la
		// 		ville de départ de unTrajet dans l'ordre alphabétique. Si les villes de
		// 		départs sont identiques, retourne vrai si la ville d'arrivée du trajet
		// 		simple arrive après la ville d'arrivée de unTrajet dans l'ordre
		// 		alphabétique. Retourne faux sinon.
		// Contrat :
		//		Aucun.

		char* GetVilleDepart() const;
		// Mode d'emploi :
		//		Retourne la ville de départ du trajet simple.
		// Contrat :
		//		Aucun.

		char* GetVilleArrivee() const;
		// Mode d'emploi :
		//		Retourne la ville d'arrivée du trajet simple.
		// Contrat :
		//		Aucun.

		TrajetSimple* Copier() const;
		// Mode d'emploi :
		//		Retourne l'adresse d'une copie du trajet simple.
		// Contrat :
		//		Aucun.

		//---------------------------------------------- Surcharge d'opérateurs

		//----------------------------------------- Constructeurs - destructeur
		TrajetSimple (const TrajetSimple& unTrajetSimple);
		// Mode d'emploi (constructeur de copie) :
		//		Construit un trajet simple à partir de unTrajetSimple.
		// Contrat :
		//		Aucun.

		TrajetSimple(const char* depart, const char* arrivee, const char* transport);
		// Mode d'emploi :
		//		Construit un trajet simple à partir de depart, arrivee et transport,
		//		représentant respectivement la ville de départ, la ville d'arrivée
		//		et le moyen de transport.
		// Contrat :
		//		Aucun.

		virtual ~TrajetSimple();
		// Mode d'emploi :
		//		Libère la mémoire associée au trajet simple.
		// Contrat :
		//		Aucun.

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées

		//---------------------------------------------------- Attributs privés
		char* villeDepart;
		char* villeArrivee;
		char* moyenTransport;
};

//---------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
