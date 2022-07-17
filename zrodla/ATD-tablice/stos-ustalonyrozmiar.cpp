#include <iostream>
#include <cassert>
using namespace std;


/* Tablicowa implementacja stosu
 * Stos o ustalonej maksymalnej liczbie element�w
 */


// -------------- stos.h ------------------------

struct Stos {
   int* e;  // tablica element�w
   int n;   // rozmiar tablicy (prealokacja!)
   int t;   // indeks elementu na wierzcho�ku stosu
};


Stos* tworzStos(int n=100);
void kasujStos(Stos* s);
bool empty(Stos* s);
int pop(Stos* s);
void push(Stos* s, int w);


// -------------- main.cpp ----------------------


int main()
{
   Stos* stos = tworzStos();

   push(stos, 7);
   push(stos, 5);
   push(stos, 3);

   while (!empty(stos))
      cout << pop(stos) << endl;
   // wypisze na ekran 357

   kasujStos(stos);

   return 0;
}


// ------------ stos.cpp -------------------------


// tworzy nowy, pusty stos, w kt�rym mo�na przechowa� max. n element�w
Stos* tworzStos(int n)
{
   Stos* s = new Stos;
   s->e = new int[n];
   s->n = n;
   s->t = -1; // pocz�tkowo pusty
   return s;
}

void kasujStos(Stos* s)
{
   delete [] s->e;
   delete s;
}

bool empty(Stos* s)
{
   return s->t < 0; // true, je�li stos jest pusty
}


int pop(Stos* s)
{
   assert(s->t >= 0);       // zak�adamy, �e mamy co zdejmowa�
   return s->e[s->t--];  // zwr�� s->e[s->t], a "potem" zmniejsz s->t o 1
}


void push(Stos* s, int w)
{
   assert(s->t < s->n-1); // zak�adamy, �e mamy gdzie umie�ci� element
   s->e[++s->t] = w;      // najpierw zwi�ksz s->t o 1, potem s->e[s->t] = w;
}


