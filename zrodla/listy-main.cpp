#include "listy.h"


int main() {

	wezel* imiona = NULL; // tworzymy pusta liste

	dodajPocz(imiona, "Karolina", true);
	dodajPocz(imiona, "Olga", true);
	dodajPocz(imiona, "Pawel", false);
	dodajPocz(imiona, "Paulina", true);
	dodajPocz(imiona, "Dominik", false);
	dodajPocz(imiona, "Michal", false);
	dodajPocz(imiona, "Milena", true);
	dodajPocz(imiona, "Paula", true);
	dodajPocz(imiona, "Sylwia", true);
	dodajPocz(imiona, "Iza", true);
	dodajPocz(imiona, "Marcin", false);

	cout << "WSZYSCY" << endl;
	wypisz(imiona);

	wezel *imionaK = NULL, *imionaM = NULL;
	podzielMK(imiona, imionaM, imionaK);

	cout << "PANOWIE" << endl;
	wypisz(imionaM);

	cout << "PANIE" << endl;
	wypisz(imionaK);

	usunWszystko(imiona);
	usunWszystko(imionaK);
	usunWszystko(imionaM);

	return 0;
}
