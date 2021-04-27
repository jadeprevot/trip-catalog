/******************************************************************************
						   InterfaceUtilisateur  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//Interface de la classe <InterfaceUtilisateur> (fichier InterfaceUtilisateur.h)
#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

//-------------------------------------------------------- Interfaces utilisées

#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TypeTrajet.h"
#include <fstream>

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <InterfaceUtilisateur>
//		Permet de gérer l'interface utilisateur.
//-----------------------------------------------------------------------------

class InterfaceUtilisateur {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		static void Bienvenue();
		// Mode d'emploi :
		//		Affiche un message souhaitant la bienvenue.
		// Contrat :
		//		Aucun.

		static void EnoncerOptions();
		// Mode d'emploi :
		//		Affiche un message énonçant les options.
		// Contrat :
		//		Aucun.

		static void Quitter();
		// Mode d'emploi :
		//		Affiche un message signifiant à l'utilisateur
		//		qu'il a quitté l'interface.
		// Contrat :
		//		Aucun.

		static void AjouterTrajet(Catalogue& catalogue);
		// Mode d'emploi :
		//		Affiche un message pour signifier à l'utilisateur
		//		comment renseigner un trajet. Ajoute un trajet.
		// Contrat :
		//		Aucun.

		static void AjouterTrajet(Catalogue& catalogue, istream& fichier, TypeTrajet type = TypeTrajet::TRAJET);
		// Mode d'emploi :
		//		Ajoute un trajet depuis fichier dont le type est type
		// Contrat :
		//		Aucun.

		static void AjouterTrajet(Catalogue& catalogue, istream& fichier, string depart, string arrivee);
		// Mode d'emploi :
		//		Ajoute un trajet depuis fichier dont la ville de départ et/ou
		//		arrivée correspond.
		// Contrat :
		//		Aucun.

		static void AfficherCatalogue(const Catalogue& catalogue);
		// Mode d'emploi :
		//		Affiche un message signifiant à l'utilisateur que
		//		le catalogue s'affiche et affiche le catalogue.
		// 		Affiche le catalogue sur la sortie standart.
		// Contrat :
		//		Aucun.

		static void AfficherCatalogue(const Catalogue& catalogue, ostream& fichier, TypeTrajet type = TypeTrajet::TRAJET);
		// Mode d'emploi :
		//		Affiche les trajets de catalogue dans fichier dont le type est type.
		// Contrat :
		//		Aucun.

		static void AfficherCatalogue(const Catalogue& catalogue, ostream& fichier, string depart, string arrivee);
		// Mode d'emploi :
		//		Affiche les trajets de catalogue dans fichier dont la ville de départ
		//		et/ou arrivée correspond.
		// Contrat :
		//		Aucun.

		static void RechercherTrajet(const Catalogue& catalogue);
		// Mode d'emploi :
		//		Affiche un message signifiant à l'utilisateur
		//		comment rechercher un trajet dans le catalogue et
		//		permet de rechercher un trajet dans le catalogue.
		// Contrat :
		//		Aucun.

		static void RepeterOptions();
		// Mode d'emploi :
		//		Affiche un message signifiant à l'utilisateur
		//		qu'il doit choisir une option.
		// Contrat :
		//		Aucun.

		static void ChargerCatalogue(Catalogue& catalogue);
		// Mode d'emploi :
		//
		// Contrat :
		//

		static void SauvegarderCatalogue(const Catalogue& catalogue);
		// Mode d'emploi :
		//
		// Contrat :
		//

	//-------------------------------------------------- Surcharge d'opérateurs

	//--------------------------------------------- Constructeurs - destructeur

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées
		static TrajetSimple* lectureTrajetSimple();
		// Mode d'emploi :
		//		Affiche un message demandant à l'utilisateur de renseigner
		//		un trajet simple et retourne l'adresse correspondante au
		//		trajet simple créé.
		//		Lit le trajet depuis cin..
		// Contrat :
		//		Aucun.

		static TrajetSimple* lectureTrajetSimple(istream& fichier);
		// Mode d'emploi :
		//		Lit le trajet contenu dans fichier.
		// Contrat :
		//		Aucun.

		//---------------------------------------------------- Attributs privés
		static const int BUFFER_SIZE = 256;
};

//-------------------- Autres définitions dépendantes de <InterfaceUtilisateur>

#endif
