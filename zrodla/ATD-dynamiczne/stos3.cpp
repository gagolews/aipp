#include <iostream>
#include <cassert>
using namespace std;

// -------------- stos.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w w�le
   wezel* nast; // wska�nik na nast�pny element
};

void push(int i, wezel*& pocz);
int  pop(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz�tek)

   push(7, pocz);
   push(5, pocz);
   push(3, pocz);

   while (!empty(pocz))
      cout << pop(pocz);

   // 357

   return 0;
}


// ------------ stos.cpp -------------------------

bool empty(wezel* pocz)
{
   return (pocz == NULL); // true, je�li lista pusta
}


void push(int i, wezel*& pocz)
{
   wezel* nowy = new wezel;
   nowy->elem = i;

   nowy->nast = pocz; /* wskazuj na to, na co wskazuje pocz, mo�e by� NULL */

   pocz = nowy; /* teraz lista zaczyna si� od nowego w�z�a */
}


int pop(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   int i = pocz->elem;   // zapami�taj przechowywany element

   wezel* wsk = pocz;    // zapami�taj "stary" pocz
   pocz = pocz->nast;    // zmie� pocz
   delete wsk;           // skasuj "stary" pocz

   return i;
}
