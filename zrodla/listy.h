#pragma once
#include <iostream>
using namespace std;
#include <cstdlib>


struct wezel {
	const char* elem;  // wezel przechowuje napis
	bool czyK;
	wezel* nast; // nastepnik
};

bool czyPusta(wezel* glowa);
void wypisz(wezel* glowa);
void dodajPocz(wezel*& glowa, const char* co, bool czyK);
void usunWszystko(wezel*& glowa);

void podzielMK(wezel*& glowa, wezel*& glowaM, wezel*& glowaK);
