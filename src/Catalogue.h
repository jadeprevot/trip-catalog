/******************************************************************************
						   Catalogue  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ---------
#ifndef CATALOGUE_H
#define CATALOGUE_H
//-------------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TypeTrajet.h"
#include <fstream>

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

// Rôle de la classe <Catalogue>
//		Recense plusieurs trajets de manière ordonnée.
//-----------------------------------------------------------------------------
class Catalogue {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		void Ajouter(const Trajet* trajet);
		// Mode d'emploi :
		//		Ajoute un trajet dans le catalogue.
		// Contrat :
		//		Aucun.

		void Afficher(ostream& fichier, TypeTrajet type = TypeTrajet::TRAJET) const;
		// Mode d'emploi :
		//		Affiche les trajets du catalogue de type type dans fichier.
		// Contrat :
		//		Aucun.

		void Afficher(ostream& fichier, string depart, string arrivee) const;
		// Mode d'emploi :
		//		Affiche le catalogue dans fichier dont la ville de départ et/ou
		//		la ville d'arrivée correspond.
		// Contrat :
		//		Aucun.

		Catalogue* TrouverTrajetsVersionSimple(const char* depart, const char* arrivee) const;
		// Mode d'emploi :
		//		Recherche de trajets simples ou composés.
		// Contrat :
		//		Aucun.

		Catalogue* TrouverTrajetsVersionAvancee(const char* depart, const char* arrivee) const;
		// Mode d'emploi :
		//		Recherche des trajets simples ou composés, ou des combinaisons
		//		de trajets simples et/ou de trajets composés.
		// Contrat :
		//		Aucun.

		void Vider();
		// Mode d'emploi :
		//		Vide le catalogue de ses trajets.
		// Contrat :
		//		Aucun.

		//----------------------------------------- Constructeurs - destructeur
		Catalogue();
		// Mode d'emploi :
		//		Construit un catalogue vide.
		// Contrat :
		//		Aucun.

		Catalogue(ListeTrajet* listeTrajet);
		// Mode d'emploi :
		//		Construit un catalogue à partir d'une liste de trajets déjà
		// 		existante.
		// Contrat :
		//		Aucun.

		virtual ~Catalogue();
		// Mode d'emploi :
		//		Libère la mémoire associée au catalogue.
		// Contrat :
		// 		Aucun.

	//------------------------------------------------------------------- PRIVE
	private:
		//----------------------------------------------------- Méthodes privées

		//---------------------------------------------------- Attributs privés
		ListeTrajet* liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
