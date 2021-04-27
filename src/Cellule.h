/******************************************************************************
						   Cellule  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---------- Interface de la classe <Cellule> (fichier Cellule.h) -------------
#ifndef CELLULE_H
#define CELLULE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <Cellule>
//		Permet de gérer un élément de ListeTrajet, à savoir le trajet et
//		l'élément suivant.
//-----------------------------------------------------------------------------

class Cellule {
	//------------------------------------------------------------------ PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques
		const Trajet* GetTrajet() const;
		// Mode d'emploi :
		// 		Retourne l'adresse du trajet de la cellule.
		// Contrat :
		// 		Aucun.

		Cellule* GetSuivante() const;
		// Mode d'emploi :
		//		Retourne l'adresse de la cellule suivante de la cellule.
		// Contrat :
		//		Aucun.

		void SetTrajet(const Trajet* trajet);
		// Mode d'emploi :
		//		Met à jour l'adresse du trajet de la cellule.
		// Contrat :
		//		Aucun.

		void SetSuivante(Cellule* suivante);
		// Mode d'emploi :
		//		Met à jour l'adresse de la cellule suivante de la cellule.
		// Contrat :
		//		Aucun.

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		Cellule();
		// Mode d'emploi :
		//		Construit une cellule vide.
		// Contrat :
		//		Aucun.

		Cellule(const Trajet* trajet, Cellule* suivante = nullptr);
		// Mode d'emploi :
		//		Construit une cellule à partir de l'adresse d'un trajet
		//		et de l'adresse de la cellule suivante.
		// Contrat :
		//		Aucun.

		virtual ~Cellule();
		// Mode d'emploi :
		//		Libère la mémoire associée à la cellule.
		// Contrat :
		//		Aucun.

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées

		//---------------------------------------------------- Attributs privés
		const Trajet* trajet;
		Cellule* suivante;
};

//-------------------------------- Autres définitions dépendantes de <Cellule>

#endif // CELLULE_H
