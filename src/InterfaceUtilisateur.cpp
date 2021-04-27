/******************************************************************************
						   InerfaceUtilisateur  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail	  : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//Réalisation de la classe <InerfaceUtilisateur> (fichier InerfaceUtilisateur.cpp)

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include "InterfaceUtilisateur.h"
#include <iostream>
#include <cstring>
#include <fstream>

//----------------------------------------------------------- Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
void InterfaceUtilisateur::Bienvenue()
// Algorithme :
//		Aucun.
{
	cout << "Bienvenue !" << endl;
} //----- Fin de Bienvenue

void InterfaceUtilisateur::EnoncerOptions()
// Algorithme :
//		Aucun.
{
	cout << "<0> Quitter" << endl;
	cout << "<1> Ajouter un trajet dans le catalogue" << endl;
	cout << "<2> Afficher les trajets du catalogue" << endl;
	cout << "<3> Rechercher un parcours" << endl;
	cout << "<4> Charger un catalogue" << endl;
	cout << "<5> Sauvegarder le catalogue" << endl;
	cout << "-> ";
} //----- Fin de EnoncerOptions

void InterfaceUtilisateur::Quitter()
// Algorithme :
//		Aucun.
{
	cout << "Au revoir !" << endl;
} //----- Fin de Quitter

void InterfaceUtilisateur::AjouterTrajet(Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Veuillez renseigner les villes de départ et d'arrivée, le moyen de transport puis ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
	cout << "Ajout de trajet:" << endl;

	TrajetSimple* simple = lectureTrajetSimple();

	char in[BUFFER_SIZE] = {'\0'};
	cin >> in;
	while (strcmp(in, ";") && strcmp(in, "+")) {
		cout << "Veuillez taper ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
		cin >> in;
	}
	if (!strcmp(in, ";")) {
		catalogue.Ajouter(simple);
		cout << "Trajet ajouté !" << endl;
		return;
	}

	TrajetCompose* compose = new TrajetCompose();
	compose->Ajouter(simple);
	do {
		if (!strcmp(in, "+")) {
			TrajetSimple* suivant = lectureTrajetSimple();
			if (strcmp(simple->GetVilleArrivee(), suivant->GetVilleDepart())) {
				cerr << "Veuillez, svp, renseigner un trajet composé cohérent, à savoir, dont les villes de départ et d'arrivée de deux trajets consécutifs coïncident." << endl;
				delete suivant;
				in[0] = '+', in[1] = '\n';
				continue;
			}
			compose->Ajouter(suivant);
		}
		else {
			cout << "Veuillez taper ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
		}
		cin >> in;
	} while (strcmp(in, ";"));
	catalogue.Ajouter(compose);
	cout << "Trajet ajouté !" << endl;
} //----- Fin de AjouterTrajet

void InterfaceUtilisateur::AjouterTrajet(Catalogue& catalogue, istream& fichier, TypeTrajet type)
// Algorithme :
//		Aucun.
{
	TrajetSimple* simple = lectureTrajetSimple(fichier);
	string in;
	getline(fichier, in);

	if (fichier.eof()) {
		delete simple;
		return;
	}

	switch (type) {
		case 0: {
			if (in == ";") {
				catalogue.Ajouter(simple);
				break;
			}

			TrajetCompose* compose = new TrajetCompose();
			compose->Ajouter(simple);
			do {
				if (in == "+") {
					TrajetSimple* simple = lectureTrajetSimple(fichier);
					compose->Ajouter(simple);
				}
				getline(fichier, in);
			} while (in != ";");
			catalogue.Ajouter(compose);
			break;
		}
		case 1: {
			if (in == ";") {
				catalogue.Ajouter(simple);
			}
			else {
				delete simple;
				while (in != ";") {
					getline(fichier, in);
				}
			}
			break;
		}
		case 2: {
			if (in == "+") {
				TrajetCompose* compose = new TrajetCompose();
				compose->Ajouter(simple);
				do {
					TrajetSimple* simple = lectureTrajetSimple(fichier);
					compose->Ajouter(simple);
					getline(fichier, in);
				} while (in != ";");
				catalogue.Ajouter(compose);
			}
			else {
				delete simple;
			}
			break;
		}
		default: {
			delete simple;
			cerr << "Erreur: type de chargement inconnu" << endl;
			exit(-1);
		}
	}
} //----- Fin de AjouterTrajet

void InterfaceUtilisateur::AjouterTrajet(Catalogue& catalogue, istream& fichier, string depart, string arrivee) {
	TrajetSimple* simple = lectureTrajetSimple(fichier);
	string in;
	getline(fichier, in);

	if (fichier.eof()) {
		delete simple;
		return;
	}

	if (depart != "*" && strcmp(simple->GetVilleDepart(), depart.c_str())) {
		delete simple;
		return;
	}

	if (in == ";") {
		if (arrivee == "*" || !strcmp(simple->GetVilleArrivee(), arrivee.c_str())) {
			catalogue.Ajouter(simple);
		}
		else {
			delete simple;
		}
		return;
	}

	TrajetCompose* compose = new TrajetCompose();
	compose->Ajouter(simple);
	do {
		simple = lectureTrajetSimple(fichier);
		compose->Ajouter(simple);
		getline(fichier, in);
	} while (in != ";");
	if (arrivee == "*" || !strcmp(simple->GetVilleArrivee(), arrivee.c_str())) {
		catalogue.Ajouter(compose);
	}
	else {
		delete compose;
	}
}

void InterfaceUtilisateur::AfficherCatalogue(const Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Affichage catalogue:" << endl << endl;
	catalogue.Afficher(cout);
	cout << endl;
} //----- Fin de AfficherCatalogue

void InterfaceUtilisateur::AfficherCatalogue(const Catalogue& catalogue, ostream& fichier, TypeTrajet type)
// Algorithme :
//		Aucun.
{
	catalogue.Afficher(fichier, type);
} //----- Fin de AfficherCatalogue

void InterfaceUtilisateur::AfficherCatalogue(const Catalogue& catalogue, ostream& fichier, string depart, string arrivee)
// Algorithme :
//		Aucun.
{
	catalogue.Afficher(fichier, depart, arrivee);
} //----- Fin de AfficherCatalogue

void InterfaceUtilisateur::RechercherTrajet(const Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Veuillez renseigner les villes de départ et d'arrivée." << endl;
	cout << "Recherche de parcours:" << endl;
	cout << "	Ville de départ: ";
	char depart[BUFFER_SIZE];
	cin >> depart;
	cout << "	Ville d'arrivée: ";
	char arrivee[BUFFER_SIZE];
	cin >> arrivee;
	cout << "<1> Recherche simple" << endl;
	cout << "<2> Recherche avancée" << endl;
	cout << "-> ";
	char versionRecherche[BUFFER_SIZE];
	cin >> versionRecherche;
	while (strcmp(versionRecherche, "1") && strcmp(versionRecherche, "2")) {
		cout << "Veuillez choisir entre '1' et '2' svp." << endl;
		cout << "-> ";
		cin >> versionRecherche;
	}

	cout << "Affichage catalogue résultat:" << endl << endl;

	Catalogue* resultat = !strcmp(versionRecherche, "1") ? catalogue.TrouverTrajetsVersionSimple(depart, arrivee) : catalogue.TrouverTrajetsVersionAvancee(depart, arrivee);
	resultat->Afficher(cout);
	delete resultat;

	cout << endl << endl;
} //----- Fin de RechercherTrajet

void InterfaceUtilisateur::RepeterOptions()
// Algorithme :
//		Aucun.
{
	cout << "Svp, veuillez choisir une option entre 0, 1, 2, 3, 4, 5." << endl;
} //----- Fin de RepeterOptions

void InterfaceUtilisateur::ChargerCatalogue(Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Souhaitez vous conserver les trajets actuellement dans le catalogue ?" << endl;
	cout << "	<1> Oui" << endl;
	cout << "	<2> Non" << endl;
	cout << "-> ";
	string reponse;
	getline(cin, reponse);
	while (reponse != "1" && reponse != "2") {
		cerr << "Veuillez choisir un chiffre entre 1 et 2 svp." << endl;
		cout << "-> ";
		getline(cin, reponse);
	}
	if (reponse == "2") {
		catalogue.Vider();
	}
	cout << "Veuillez renseigner le nom du fichier svp." << endl;
	cout << "-> ";
	string str;
	getline(cin, str);
	ifstream fichier(str.c_str());
	if (!fichier.is_open()) {
		cerr << "Erreur lors de l'ouverture du fichier. Veuillez réessayer svp." << endl;
		return;
	}
	cout << "Veuillez choisir un critère de sélection svp." << endl;
	cout << "	<1> Sans critère de sélection" << endl;
	cout << "	<2> Selon le type de trajets" << endl;
	cout << "	<3> Selon la ville de départ / arrivée" << endl;
	cout << "-> ";
	string mode;
	getline(cin, mode);
	while (mode != "1" && mode != "2" && mode != "3") {
		cerr << "Veuillez choisir un chiffre entre 1, 2 et 3 svp." << endl;
		cout << "-> ";
		getline(cin, mode);
	}
	if (mode == "1") {
		while (!fichier.eof()) {
			InterfaceUtilisateur::AjouterTrajet(catalogue, fichier);
		}
	}
	else if (mode == "2") {
		cout << "Veuillez choisir le type de trajet svp." << endl;
		cout << "		<1> Trajets simples" << endl;
		cout << "		<2> Trajets composes" << endl;
		cout << "-> ";
		string type;
		getline(cin, type);
		while (type != "1" && type != "2") {
			cerr << "Veuillez choisir un chiffre entre 1 et 2 svp." << endl;
			cout << "-> ";
			getline(cin, type);
		}
		while (!fichier.eof()) {
			InterfaceUtilisateur::AjouterTrajet(catalogue, fichier, stoi(type) == 1 ? TypeTrajet::TRAJETSIMPLE : TypeTrajet::TRAJETCOMPOSE);
		}
	}
	else if (mode == "3") {
		cout << "Veuillez renseigner la ville de départ et d'arrivée svp (* pour ignorer)." << endl;
		cout << "		Ville de départ: ";
		string depart;
		getline(cin, depart);
		cout << "		Ville d'arrivée: ";
		string arrivee;
		getline(cin, arrivee);
		while (!fichier.eof()) {
			InterfaceUtilisateur::AjouterTrajet(catalogue, fichier, depart, arrivee);
		}
	}
	fichier.close();
} //----- Fin de ChargerCatalogue

void InterfaceUtilisateur::SauvegarderCatalogue(const Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Veuillez renseigner le nom du fichier svp." << endl;
	cout << "-> ";
	string str;
	getline(cin, str);
	ofstream fichier(str.c_str(), ios::out | ios::trunc);
	if (!fichier.is_open()) {
		cerr << "Erreur lors de l'ouverture du fichier. Veuillez réessayer svp." << endl;
		return;
	}
	cout << "Veuillez choisir un critère de sélection svp." << endl;
	cout << "	<1> Sans critère de sélection" << endl;
	cout << "	<2> Selon le type de trajets" << endl;
	cout << "	<3> Selon la ville de départ / arrivée" << endl;
	cout << "-> ";
	string mode;
	getline(cin, mode);
	while (mode != "1" && mode != "2" && mode != "3") {
		cerr << "Veuillez choisir un chiffre entre 1, 2 et 3 svp." << endl;
		cout << "-> ";
		getline(cin, mode);
	}
	if (mode == "1") {
		InterfaceUtilisateur::AfficherCatalogue(catalogue, fichier);
	}
	else if (mode == "2") {
		cout << "Veuillez choisir le type de trajet svp." << endl;
		cout << "		<1> Trajets simples" << endl;
		cout << "		<2> Trajets composes" << endl;
		cout << "-> ";
		string type;
		getline(cin, type);
		while (type != "1" && type != "2") {
			cerr << "Veuillez choisir un chiffre entre 1 et 2 svp." << endl;
			cout << "-> ";
			getline(cin, type);
		}
		InterfaceUtilisateur::AfficherCatalogue(catalogue, fichier, stoi(type) == 1 ? TypeTrajet::TRAJETSIMPLE : TypeTrajet::TRAJETCOMPOSE);
	}
	else if (mode == "3") {
		cout << "Veuillez renseigner la ville de départ et d'arrivée svp (* pour ignorer)." << endl;
		cout << "		Ville de départ: ";
		string depart;
		getline(cin, depart);
		cout << "		Ville d'arrivée: ";
		string arrivee;
		getline(cin, arrivee);
		InterfaceUtilisateur::AfficherCatalogue(catalogue, fichier, depart, arrivee);
	}
	fichier.close();
} //----- Fin de SauvegarderCatalogue

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
TrajetSimple* InterfaceUtilisateur::lectureTrajetSimple()
// Algorithme :
//		Aucun.
{
	cout << "	Ville de départ: ";
	char depart[BUFFER_SIZE];
	cin >> depart;

	cout << "	Ville d'arrivée: ";
	char arrivee[BUFFER_SIZE];
	cin >> arrivee;

	cout << "	Moyen de transport: ";
	char transport[BUFFER_SIZE];
	cin >> transport;

	return new TrajetSimple(depart, arrivee, transport);
} //----- Fin de lectureTrajetSimple

TrajetSimple* InterfaceUtilisateur::lectureTrajetSimple(istream& fichier)
// Algorithme :
//		Aucun.
{
	string depart;
	getline(fichier, depart);

	string arrivee;
	getline(fichier, arrivee);

	string transport;
	getline(fichier, transport);


	return new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
} //----- Fin de lectureTrajetSimple
