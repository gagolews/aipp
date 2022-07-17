#include <iostream>
#include <cassert>
using namespace std;

// -------------- stos.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w wê¼le
   wezel* nast; // wska¼nik na nastêpny element
};

void push(int i, wezel*& pocz);
int  pop(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz±tek)

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
   return (pocz == NULL); // true, je¶li lista pusta
}


void push(int i, wezel*& pocz)
{
   wezel* nowy = new wezel;
   nowy->elem = i;

   nowy->nast = pocz; /* wskazuj na to, na co wskazuje pocz, mo¿e byæ NULL */

   pocz = nowy; /* teraz lista zaczyna siê od nowego wêz³a */
}


int pop(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   int i = pocz->elem;   // zapamiêtaj przechowywany element

   wezel* wsk = pocz;    // zapamiêtaj "stary" pocz
   pocz = pocz->nast;    // zmieñ pocz
   delete wsk;           // skasuj "stary" pocz

   return i;
}
