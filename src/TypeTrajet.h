/******************************************************************************
						   TypeTrajet  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//-------- Interface de la classe <TypeTrajet> (fichier TypeTrajet.h) ---------
#ifndef TYPE_TRAJET
#define TYPE_TRAJET

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeTrajet>
//		Permet de distinguer ou non les trajets simples et composés.
//------------------------------------------------------------------------

enum TypeTrajet {
	TRAJET,
	TRAJETSIMPLE,
	TRAJETCOMPOSE
};

//-------------------------------- Autres définitions dépendantes de <TypeTrajet>

#endif // TYPETRAJET_H
