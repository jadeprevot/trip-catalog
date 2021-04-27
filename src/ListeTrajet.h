/******************************************************************************
						   ListeTrajet  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//------ Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ---------
#ifndef LISTETRAJET_H
#define LISTETRAJET_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Cellule.h"
//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
//		Permet de gérer une liste chaînée de trajets.
//-----------------------------------------------------------------------------

class ListeTrajet {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		void Ajouter(const Trajet* trajet);
		// Mode d'emploi :
		//		Ajouter un trajet à la liste.
		// Contrat :
		//		Aucun.

		void Ajouter(const ListeTrajet* uneListeTrajet);
		// Mode d'emploi :
		//		Ajouter les trajets de uneListeTrajet à la liste.
		// Contrat :
		//		Aucun.

		void Afficher(ostream& fichier, TypeTrajet type = TypeTrajet::TRAJET) const;
		// Mode d'emploi :
		//		Affiche les villes de départ, les villes d'arrivée et les
		// 		moyens de transport des trajets de la liste dans fichier si les
		//		trajets sont de type type.
		// Contrat :
		//		Aucun.

		void Afficher(ostream& fichier, string depart, string arrivee) const;

		ListeTrajet* TrouverTrajetsVersionSimple(const char* depart, const char* arrivee) const;
		// Mode d'emploi :
		//		Renvoie une liste contenant une copie des trajets de la liste avec
		//		des villes de départ et d'arrivée similaires.
		// Contrat :
		//		Aucun.

		ListeTrajet* TrouverTrajetsVersionAvancee(const char* depart, const char* arrivee) const;
		// Mode d'emploi :
		//		Renvoie une liste contenant une copie des trajets de la liste avec
		//		des villes de départ et d'arrivée similaires. Des combinaisons de
		// 		trajets sont possibles.
		// Contrat :
		//		Aucun.

		const Trajet* GetPremierTrajet() const;
		// Mode d'emploi :
		//		Retourne l'adresse du premier trajet de la liste.
		// Contrat :
		//		Aucun.

		const Trajet* GetDernierTrajet() const;
		// Mode d'emploi :
		//		Retourne l'adresse du dernier trajet de la liste.
		// Contrat :
		//		Aucun.

		//---------------------------------------------- Surcharge d'opérateurs

		//----------------------------------------- Constructeurs - destructeur
		ListeTrajet(const ListeTrajet& uneListeTrajet);
		// Mode d'emploi (constructeur de copie) :
		//		Construit une liste de trajets à partir de uneListeTrajet
		// Contrat :
		//		Aucun.

		ListeTrajet(bool trieeAlpha);
		// Mode d'emploi :
		//		Construit une liste de trajets triée si trieeAlpha est vrai,
		//		non triée sinon.
		// Contrat :
		//		Aucun.

		virtual ~ListeTrajet();
		// Mode d'emploi :
		//		Libère la mémoire associée à la liste de trajets.
		// Contrat :
		//		Aucun.

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées
		bool estVide() const
		// Algorithme :
		//		Aucun.
		{
			return !derniere;
		} //----- Fin de estVide
		// Mode d'emploi :
		//		Renvoie vrai si la liste est vide.
		// Contrat :
		//		Aucun.

		bool trouverTrajetsVersionAvancee(const char* depart, const char* arrivee, int nbCellules, ListeTrajet* tentative) const;
		// Mode d'emploi :
		//		Ajoute dans resultat les trajets avec des villes de départ et
		//		d'arrivée similaires à depart et arrivee.
		//		Retourne vrai si depart égale arrivee. Retourne faux sinon.
		// Contrat :
		//		Aucun.

		//--------------------------------------------------- Attributs privées
		Cellule* derniere;
		const bool estTrieeAlpha;
};

//----------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // LISTETRAJET_H

