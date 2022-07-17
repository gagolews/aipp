#include "listy.h"

bool czyPusta(wezel* glowa)
{
	return glowa==NULL;
}

void wypisz(wezel* glowa)
{
	while (glowa != NULL) {
		cout << "wsk: "  << glowa << ", ";
		cout << "elem: " << glowa->elem << ",\t";
		cout << "czyK: " << glowa->czyK << ", ";
		cout << "nast: " << glowa->nast << endl;
		glowa = glowa->nast;
	}
}

void dodajPocz(wezel*& glowa, const char* co, bool czyK)
{
	wezel* z = new wezel;
	z->elem = co;
	z->czyK = czyK;
	z->nast = glowa;
	glowa = z;
}

void usunWszystko(wezel*& glowa)
{
	while (glowa != NULL) {
		wezel* z = glowa;
		glowa = glowa->nast;
		delete z;
	}
}


void podzielMK(wezel*& glowa, wezel*& glowaM, wezel*& glowaK)
{
	while (glowa != NULL)
	{
		wezel* w = glowa;
		glowa = glowa->nast;

		// wstaw w na poczatek glowaM ALBO glowaK
		if (w->czyK == true) {
			//glowaK
			w->nast = glowaK;
			glowaK = w;
		}
		else {
			//glowaM
			w->nast = glowaM;
			glowaM = w;
		}
	}
}
