#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w w�le
   wezel* nast; // wska�nik na nast�pny element
};

void enqueue(int i, wezel*& pocz);
int  dequeue(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz�tek)

   for (int i=0; i<10; ++i)
      enqueue(i, pocz);

   while (!empty(pocz))
      cout << dequeue(pocz);

   return 0;
}


// ------------ kolejka.cpp -------------------------

bool empty(wezel* pocz)
{
   return (pocz == NULL); // true, je�li lista pusta
}


void enqueue(int i, wezel*& pocz)
{
   // wstawianie na koniec listy

   wezel* nowy = new wezel; // stw�rz nowy wezel
   nowy->elem = i;
   nowy->nast = NULL;

   if (pocz == NULL)        // gdy lista pusta...
   {
      pocz = nowy;          // zmieniamy pocz
   }
   else                     // gdy lista niepusta...
   {
      wezel* wsk = pocz;    // pocz nie zmieniamy!

      while (wsk->nast != NULL) // przejd� do ostatniego elementu
         wsk = wsk->nast;

      wsk->nast = nowy;         // podepnij nowy za ostatnim
   }

   // koszt operacji: O(n) - niestety...
}


int dequeue(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   // usuwanie z pocz�tku listy

   int i = pocz->elem;   // zapami�taj przechowywany element

   wezel* wsk = pocz;    // zapami�taj "stary" pocz
   pocz = pocz->nast;    // zmie� pocz
   delete wsk;           // skasuj "stary" pocz

   return i;

   // koszt operacji: O(1)
}
