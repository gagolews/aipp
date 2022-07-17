#include <iostream>
#include <cassert>
using namespace std;

// -------------- lista.h ------------------------

struct wezel
{
   double elem;    // element przechowywany w w�le
   wezel* nast; // wska�nik na nast�pny element
};

void dodajpocz(double i, wezel*& pocz); // dodanie elementu na pocz�tek listy
void usunpocz(wezel*& pocz); // usuniecie elementu z pocz�tku listy
void wypisz(wezel* pocz);   // wypisz elementy listy na ekran
bool czypusta(wezel* pocz); // sprawdzenie, czy lista jest pusta
void przesunco2a(wezel* pocz); // przesuni�cie co drugiego w kolejno�ci elementu na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci - wersja a
void przesunco2b(wezel*& pocz); // przesuni�cie co drugiego w kolejno�ci elementu na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci - wersja b
void przesunparz(wezel*& pocz); // przesuni�cie wszystkich element�w o warto�ci parzystej na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci

// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz�tek)

   for (int i=0; i<10; ++i)
      dodajpocz((double)((3*i+17)%13), pocz); // dodaj "jakies" elementy do listy

   wypisz(pocz);

   przesunco2a(pocz);
   wypisz(pocz);

   przesunco2b(pocz);
   wypisz(pocz);

   przesunparz(pocz);
   wypisz(pocz);   

   // skasuj list�
   while (!czypusta(pocz))
      usunpocz(pocz);

   return 0;
}


// ------------ stos.cpp -------------------------

bool czypusta(wezel* pocz)
{
   return (pocz == NULL); // true, je�li lista pusta
}


void wypisz(wezel* pocz)
{
   cout << "(";
   // pocz nie jest przekazany przez referencj� - jego modyfikacja
   // nie b�dzie "widoczna" w main
   while (pocz != NULL)
   {
      cout << pocz->elem << ' ';
      pocz = pocz->nast;
   }
   cout << ")" << endl;
}


void dodajpocz(double i, wezel*& pocz)
{
   wezel* nowy = new wezel;
   nowy->elem = i;

   nowy->nast = pocz; /* wskazuj na to, na co wskazuje pocz, mo�e by� NULL */

   pocz = nowy; /* teraz lista zaczyna si� od nowego w�z�a */
}


void usunpocz(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   wezel* wsk = pocz;    // zapami�taj "stary" pocz
   pocz = pocz->nast;    // zmie� pocz
   delete wsk;           // skasuj "stary" pocz
}


void przesunco2a(wezel* pocz)
{
   // przesuni�cie co drugiego w kolejno�ci elementu na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci
   // umowa: zaczynamy od II elementu
   // pocz zatem nie przekazujemy przez referencj�, bo g�owa si� nie zmieni

   if (pocz == NULL || pocz->nast == NULL || pocz->nast->nast == NULL)
      return; // nie ma nic do roboty
   
   wezel* koniec = pocz; // znajd� ogon listy - tam b�dziemy wstawia�
   while (koniec->nast != NULL)
      koniec = koniec->nast;

   wezel* starykoniec = koniec; // zapami�taj, gdzie by� koniec, by wiedzie�, gdzie sko�czy�
   do // na pewno raz musimy co� przestawi�
   {
      // pocz->nast przenosimy na koniec
      koniec->nast = pocz->nast;

      pocz->nast = pocz->nast->nast; // wska� nie na nast�pny, ale na po-nast�pny
      pocz = pocz->nast; // id� dalej

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
   while (pocz != starykoniec && koniec != starykoniec);
}



void przesunco2b(wezel*& pocz)
{
   // przesuni�cie co drugiego w kolejno�ci elementu na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci
   // umowa: zaczynamy od I elementu
   // pocz zatem przekazujemy przez referencj�, bo g�owa si� mo�e zmieni�

   if (pocz == NULL || pocz->nast == NULL)
      return; // nie ma nic do roboty

   wezel* koniec = pocz; // znajd� ogon listy - tam b�dziemy wstawia�
   while (koniec->nast != NULL)
      koniec = koniec->nast;   

   wezel* starykoniec = koniec; // zapami�taj, gdzie by� koniec, by wiedzie�, gdzie sko�czy�

   // przesuni�cie I elementu oodzielnie (trzeba zmieni� pocz)
   koniec->nast = pocz;

   pocz = pocz->nast; // przesu� g�ow�
   wezel* wsk = pocz; // ustal aktualn� pozycj�

   koniec = koniec->nast; // teraz tu jest koniec
   koniec->nast = NULL;

   while (wsk != starykoniec && koniec != starykoniec)
   {
      // teraz przesuwaj jak w przesunco2a

      // wsk->nast przenosimy na koniec
      koniec->nast = wsk->nast;

      wsk->nast = wsk->nast->nast; // wska� nie na nast�pny, ale na po-nast�pny
      wsk = wsk->nast; // id� dalej

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
}


void przesunparz(wezel*& pocz)
{
   // przesuni�cie wszystkich element�w o warto�ci parzystej na koniec listy, z zachowaniem ich pierwotnej wzgl�dnej kolejno�ci
   // umowa: liczba rzeczywista x jest parzysta, je�li jej cz�� ca�kowita jest parzysta, tzn. gdy ((int)x)%2 == 0.
   // pocz zatem przekazujemy przez referencj�, bo g�owa si� mo�e zmieni�

   if (pocz == NULL || pocz->nast == NULL)
      return; // nie ma nic do roboty

   wezel* koniec = pocz; // znajd� ogon listy - tam b�dziemy wstawia�
   while (koniec->nast != NULL)
      koniec = koniec->nast;

   wezel* starykoniec = koniec; // zapami�taj, gdzie by� koniec, by wiedzie�, gdzie sko�czy�

   // przesuni�cie pocz�tkowych parzystych element�w oodzielnie (trzeba zmieni� pocz)
   while (pocz != starykoniec && ((int)pocz->elem)%2 == 0)
   {
      koniec->nast = pocz;

      pocz = pocz->nast; // przesu� g�ow�

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
   wezel* wsk = pocz; // ustal aktualn� pozycj�


   while (wsk != starykoniec && koniec != starykoniec)
   {
      if (((int)wsk->nast->elem)%2 == 0)
      {
         // wsk->nast przenosimy na koniec
         koniec->nast = wsk->nast;

         wsk->nast = wsk->nast->nast; // wska� nie na nast�pny, ale na po-nast�pny
         wsk = wsk->nast; // id� dalej

         koniec = koniec->nast; // teraz tu jest koniec
         koniec->nast = NULL;
      }
      else
         wsk = wsk->nast; // nast�pny nieparzysty - po prostu id� dalej
   }
}
