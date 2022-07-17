#include <iostream>
#include <cassert>
using namespace std;

// -------------- lista.h ------------------------

struct wezel
{
   double elem;    // element przechowywany w wê¼le
   wezel* nast; // wska¼nik na nastêpny element
};

void dodajpocz(double i, wezel*& pocz); // dodanie elementu na pocz±tek listy
void usunpocz(wezel*& pocz); // usuniecie elementu z pocz±tku listy
void wypisz(wezel* pocz);   // wypisz elementy listy na ekran
bool czypusta(wezel* pocz); // sprawdzenie, czy lista jest pusta
void przesunco2a(wezel* pocz); // przesuniêcie co drugiego w kolejno¶ci elementu na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci - wersja a
void przesunco2b(wezel*& pocz); // przesuniêcie co drugiego w kolejno¶ci elementu na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci - wersja b
void przesunparz(wezel*& pocz); // przesuniêcie wszystkich elementów o warto¶ci parzystej na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci

// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz±tek)

   for (int i=0; i<10; ++i)
      dodajpocz((double)((3*i+17)%13), pocz); // dodaj "jakies" elementy do listy

   wypisz(pocz);

   przesunco2a(pocz);
   wypisz(pocz);

   przesunco2b(pocz);
   wypisz(pocz);

   przesunparz(pocz);
   wypisz(pocz);   

   // skasuj listê
   while (!czypusta(pocz))
      usunpocz(pocz);

   return 0;
}


// ------------ stos.cpp -------------------------

bool czypusta(wezel* pocz)
{
   return (pocz == NULL); // true, je¶li lista pusta
}


void wypisz(wezel* pocz)
{
   cout << "(";
   // pocz nie jest przekazany przez referencjê - jego modyfikacja
   // nie bêdzie "widoczna" w main
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

   nowy->nast = pocz; /* wskazuj na to, na co wskazuje pocz, mo¿e byæ NULL */

   pocz = nowy; /* teraz lista zaczyna siê od nowego wêz³a */
}


void usunpocz(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   wezel* wsk = pocz;    // zapamiêtaj "stary" pocz
   pocz = pocz->nast;    // zmieñ pocz
   delete wsk;           // skasuj "stary" pocz
}


void przesunco2a(wezel* pocz)
{
   // przesuniêcie co drugiego w kolejno¶ci elementu na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci
   // umowa: zaczynamy od II elementu
   // pocz zatem nie przekazujemy przez referencjê, bo g³owa siê nie zmieni

   if (pocz == NULL || pocz->nast == NULL || pocz->nast->nast == NULL)
      return; // nie ma nic do roboty
   
   wezel* koniec = pocz; // znajd¼ ogon listy - tam bêdziemy wstawiaæ
   while (koniec->nast != NULL)
      koniec = koniec->nast;

   wezel* starykoniec = koniec; // zapamiêtaj, gdzie by³ koniec, by wiedzieæ, gdzie skoñczyæ
   do // na pewno raz musimy co¶ przestawiæ
   {
      // pocz->nast przenosimy na koniec
      koniec->nast = pocz->nast;

      pocz->nast = pocz->nast->nast; // wska¿ nie na nastêpny, ale na po-nastêpny
      pocz = pocz->nast; // id¼ dalej

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
   while (pocz != starykoniec && koniec != starykoniec);
}



void przesunco2b(wezel*& pocz)
{
   // przesuniêcie co drugiego w kolejno¶ci elementu na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci
   // umowa: zaczynamy od I elementu
   // pocz zatem przekazujemy przez referencjê, bo g³owa siê mo¿e zmieniæ

   if (pocz == NULL || pocz->nast == NULL)
      return; // nie ma nic do roboty

   wezel* koniec = pocz; // znajd¼ ogon listy - tam bêdziemy wstawiaæ
   while (koniec->nast != NULL)
      koniec = koniec->nast;   

   wezel* starykoniec = koniec; // zapamiêtaj, gdzie by³ koniec, by wiedzieæ, gdzie skoñczyæ

   // przesuniêcie I elementu oodzielnie (trzeba zmieniæ pocz)
   koniec->nast = pocz;

   pocz = pocz->nast; // przesuñ g³owê
   wezel* wsk = pocz; // ustal aktualn± pozycjê

   koniec = koniec->nast; // teraz tu jest koniec
   koniec->nast = NULL;

   while (wsk != starykoniec && koniec != starykoniec)
   {
      // teraz przesuwaj jak w przesunco2a

      // wsk->nast przenosimy na koniec
      koniec->nast = wsk->nast;

      wsk->nast = wsk->nast->nast; // wska¿ nie na nastêpny, ale na po-nastêpny
      wsk = wsk->nast; // id¼ dalej

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
}


void przesunparz(wezel*& pocz)
{
   // przesuniêcie wszystkich elementów o warto¶ci parzystej na koniec listy, z zachowaniem ich pierwotnej wzglêdnej kolejno¶ci
   // umowa: liczba rzeczywista x jest parzysta, je¶li jej czê¶æ ca³kowita jest parzysta, tzn. gdy ((int)x)%2 == 0.
   // pocz zatem przekazujemy przez referencjê, bo g³owa siê mo¿e zmieniæ

   if (pocz == NULL || pocz->nast == NULL)
      return; // nie ma nic do roboty

   wezel* koniec = pocz; // znajd¼ ogon listy - tam bêdziemy wstawiaæ
   while (koniec->nast != NULL)
      koniec = koniec->nast;

   wezel* starykoniec = koniec; // zapamiêtaj, gdzie by³ koniec, by wiedzieæ, gdzie skoñczyæ

   // przesuniêcie pocz±tkowych parzystych elementów oodzielnie (trzeba zmieniæ pocz)
   while (pocz != starykoniec && ((int)pocz->elem)%2 == 0)
   {
      koniec->nast = pocz;

      pocz = pocz->nast; // przesuñ g³owê

      koniec = koniec->nast; // teraz tu jest koniec
      koniec->nast = NULL;
   }
   wezel* wsk = pocz; // ustal aktualn± pozycjê


   while (wsk != starykoniec && koniec != starykoniec)
   {
      if (((int)wsk->nast->elem)%2 == 0)
      {
         // wsk->nast przenosimy na koniec
         koniec->nast = wsk->nast;

         wsk->nast = wsk->nast->nast; // wska¿ nie na nastêpny, ale na po-nastêpny
         wsk = wsk->nast; // id¼ dalej

         koniec = koniec->nast; // teraz tu jest koniec
         koniec->nast = NULL;
      }
      else
         wsk = wsk->nast; // nastêpny nieparzysty - po prostu id¼ dalej
   }
}
