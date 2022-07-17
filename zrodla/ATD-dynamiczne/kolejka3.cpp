#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w wê¼le
   wezel* nast; // wska¼nik na nastêpny element
};

void enqueue(int i, wezel*& pocz);
int  dequeue(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz±tek)

   for (int i=0; i<10; ++i)
      enqueue(i, pocz);

   while (!empty(pocz))
      cout << dequeue(pocz);

   return 0;
}


// ------------ kolejka.cpp -------------------------

bool empty(wezel* pocz)
{
   return (pocz == NULL); // true, je¶li lista pusta
}


void enqueue(int i, wezel*& pocz)
{
   // wstawianie na koniec listy

   wezel* nowy = new wezel; // stwórz nowy wezel
   nowy->elem = i;
   nowy->nast = NULL;

   if (pocz == NULL)        // gdy lista pusta...
   {
      pocz = nowy;          // zmieniamy pocz
   }
   else                     // gdy lista niepusta...
   {
      wezel* wsk = pocz;    // pocz nie zmieniamy!

      while (wsk->nast != NULL) // przejd¼ do ostatniego elementu
         wsk = wsk->nast;

      wsk->nast = nowy;         // podepnij nowy za ostatnim
   }

   // koszt operacji: O(n) - niestety...
}


int dequeue(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   // usuwanie z pocz±tku listy

   int i = pocz->elem;   // zapamiêtaj przechowywany element

   wezel* wsk = pocz;    // zapamiêtaj "stary" pocz
   pocz = pocz->nast;    // zmieñ pocz
   delete wsk;           // skasuj "stary" pocz

   return i;

   // koszt operacji: O(1)
}
