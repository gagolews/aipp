#include <iostream>
#include <cassert>
using namespace std;

// -------------- kolejka_prior.h ------------------------

struct wezel
{
   int elem;    // element przechowywany w w�le
   wezel* nast; // wska�nik na nast�pny element
};

void insert(int i, wezel*& pocz);
int  pull(wezel*& pocz);
bool empty(wezel* pocz);


// -------------- main.cpp ----------------------


int main()
{
   wezel* pocz = NULL; // pusta lista (na pocz�tek)

   for (int i=0; i<20; ++i)
      insert((i*7+9)%17, pocz); // jakie� r�ne warto�ci

   while (!empty(pocz))
      cout << pull(pocz) << ' ';

   return 0;
}


// ------------ kolejka_prior.cpp -------------------------

bool empty(wezel* pocz)
{
   return (pocz == NULL); // true, je�li lista pusta
}


void insert(int i, wezel*& pocz)
{
   // wstawianie na odpowiednie miejsce listy (bez zaburzenia porz�dku)
   // pesymistyczny i �redni koszt operacji: O(n)


   // wersja rekurencyjna
   if (pocz == NULL || i > pocz->elem) // >, bo FIFO, gdy ==
   {     // wstawiamy tutaj
      wezel* starypocz = pocz; // mo�e by� NULL

      pocz = new wezel; // stw�rz nowy wezel
      pocz->elem = i;
      pocz->nast = starypocz;
   }
   else // idziemy dalej
      insert(i, pocz->nast);


//    // wersja iteracyjna (dla por�wnania)
//    wezel* nowy = new wezel; // stw�rz nowy wezel
//    nowy->elem = i;
//    nowy->nast = NULL;
//
//    if (pocz == NULL)        // gdy lista pusta...
//    {
//       pocz = nowy;
//    }
//    else if (i > pocz->elem) // gdy mamy wstawi� na pocz�tek...
//    {
//       nowy->nast = pocz;
//       pocz = nowy;
//    }
//    else
//    {
//       wezel* wsk = pocz;
//       while (wsk->nast != NULL && i <= wsk->nast->elem) // <=, bo FIFO, gdy ==
//          wsk = wsk->nast;
//
//       // wstaw nowy mi�dzy wsk a wsk->nast (ten ostatni mo�e by� NULL)
//       nowy->nast = wsk->nast;
//       wsk->nast = nowy;
//    }
}


int pull(wezel*& pocz)
{
   assert(pocz != NULL); // na wszelki wypadek...

   // usuwanie z pocz�tku listy (bo tam najwi�kszy element jest)

   int i = pocz->elem;   // zapami�taj przechowywany element

   wezel* wsk = pocz;    // zapami�taj "stary" pocz
   pocz = pocz->nast;    // zmie� pocz
   delete wsk;           // skasuj "stary" pocz

   return i;

   // koszt operacji: O(1)
}
