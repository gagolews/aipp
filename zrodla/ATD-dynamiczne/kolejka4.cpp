#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w wê¼le
   wezel* nast; // wska¼nik na nastêpny element
};

void enqueue(int i, wezel*& pocz, wezel*& ost);
int  dequeue(wezel*& pocz, wezel*& ost);
bool empty(wezel* pocz, wezel* ost);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz±tek)
   wezel* ost = NULL;  // wska¿nik na ostatni element - te¿ NULL

   for (int i=0; i<10; ++i)
      enqueue(i, pocz, ost);

   while (!empty(pocz, ost))
      cout << dequeue(pocz, ost);

   return 0;
}


// ------------ kolejka.cpp -------------------------

bool empty(wezel* pocz, wezel* ost)
{
   return (pocz == NULL); // true, je¶li lista pusta
}


void enqueue(int i, wezel*& pocz, wezel*& ost)
{
   // wstawianie na koniec listy

   wezel* nowy = new wezel; // stwórz nowy wezel
   nowy->elem = i;
   nowy->nast = NULL;

   if (pocz == NULL)        // gdy lista pusta...
   {
      pocz = ost = nowy;    // zmieniamy pocz i ost
   }
   else                     // gdy lista niepusta...
   {
      ost->nast = nowy;     // po ostatnim - nowy
      ost = nowy;           // teraz ostatni to nowy
   }

   // koszt operacji: O(1)
}


int dequeue(wezel*& pocz, wezel*& ost)
{
   assert(pocz != NULL); // na wszelki wypadek...

   // usuwanie z pocz±tku listy

   int i = pocz->elem;   // zapamiêtaj przechowywany element

   wezel* wsk = pocz;    // zapamiêtaj "stary" pocz
   pocz = pocz->nast;    // zmieñ pocz
   delete wsk;           // skasuj "stary" pocz

   if (pocz == NULL) ost = NULL;

   return i;

   // koszt operacji: O(1)
}
