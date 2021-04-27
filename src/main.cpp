using namespace std;
#include <iostream>
#include "Catalogue.h"
#include "InterfaceUtilisateur.h"

int main(int argc, char const *argv[]) {
	Catalogue catalogue;
	string option;

	InterfaceUtilisateur::Bienvenue();
	while (true) {
		InterfaceUtilisateur::EnoncerOptions();

		getline(cin, option);

		if (option == "0") {
			InterfaceUtilisateur::Quitter();
			return 0;
		}
		else if (option == "1") {
			InterfaceUtilisateur::AjouterTrajet(catalogue);
		}
		else if (option == "2") {
			InterfaceUtilisateur::AfficherCatalogue(catalogue);
		}
		else if (option == "3") {
			InterfaceUtilisateur::RechercherTrajet(catalogue);
		}
		else if (option == "4") {
			InterfaceUtilisateur::ChargerCatalogue(catalogue);
		}
		else if (option == "5") {
			InterfaceUtilisateur::SauvegarderCatalogue(catalogue);
		}
		else {
			InterfaceUtilisateur::RepeterOptions();
		}
	}
}
