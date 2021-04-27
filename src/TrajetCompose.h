/******************************************************************************
						   TrajetCompose  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//----- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajet.h"
#include "TypeTrajet.h"
#include <fstream>

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//		Permet de gérer une collection de trajets.
//-----------------------------------------------------------------------------

class TrajetCompose : public Trajet {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		void Ajouter(const Trajet* trajet);
		// Mode d'emploi :
		//		Ajouter un trajet au trajet composé.
		// Contrat :
		//		Aucun.

		bool Afficher(ostream& fichier, TypeTrajet type = TypeTrajet::TRAJET) const;
		// Mode d'emploi :
		//		Affiche la ville de départ, la ville d'arrivée et le moyen de
		// 		transport du trajet composé dans fichier si celui ci est de type type.
		//		Retourne vrai si un affichage à eu lieu. Retourne faux sinon.
		// Contrat :
		//		Aucun.

		bool EstPostAlpha(const Trajet* unTrajet) const;
		// Mode d'emploi :
		//		Retourne vrai si la ville de départ du trajet composé arrive
		// 		après la ville de départ de unTrajet dans l'ordre alphabétique.
		// 		Si les villes de départs sont identiques, retourne vrai si la
		// 		ville d'arrivée du trajet composé arrive après la ville
		// 		d'arrivée de unTrajet dans l'ordre alphabétique. Retourne faux
		// 		sinon.
		// Contrat :
		//		Aucun.

		char* GetVilleDepart() const;
		// Mode d'emploi :
		//		Retourne la ville de départ du trajet composé.
		// Contrat :
		//		Aucun.

		char* GetVilleArrivee() const;
		// Mode d'emploi :
		//		Retourne la ville d'arrivée du trajet composé.
		// Contrat :
		//		Aucun.

		TrajetCompose* Copier() const;
		// Mode d'emploi :
		//		Retourne une copie du trajet composé.
		// Contrat :
		//		Aucun.

		//---------------------------------------------- Surcharge d'opérateurs

		//----------------------------------------- Constructeurs - destructeur
		TrajetCompose(const TrajetCompose& unTrajetCompose);
		// Mode d'emploi (constructeur de copie) :
		//		Construit un trajet composé à partir de unTrajetCompose.
		// Contrat :
		//		Aucun.

		TrajetCompose();
		// Mode d'emploi :
		//		Construit un trajet composé.
		// Contrat :
		//		Aucun.

		virtual ~TrajetCompose();
		// Mode d'emploi :
		//		Libère la mémoire associée au trajet composé.
		// Contrat :
		//		Aucun.

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées

		//---------------------------------------------------- Attributs privés
		ListeTrajet* liste;
};

//--------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
