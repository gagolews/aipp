#include <iostream>
#include <cassert>
using namespace std;


struct Data {
   int dzien;
   int miesiac;
};


void wypiszDate(Data d)
{
   cout << d.dzien << "." << d.miesiac << endl;
}


Data tworzDate(int dzien, int miesiac)
{
   Data d;
   d.dzien = dzien;
   d.miesiac = miesiac;
   return d;
}


bool czyWieksze(Data d1, Data d2) // czy d1 > d2???
{
   if (d1.miesiac > d2.miesiac) return true;
   else if (d1.miesiac < d2.miesiac) return false;
   else {
      if (d1.dzien > d2.dzien) return true;
      else return false;
   }
}






struct KolejkaPriorytetowa
{
   Data* elem; // tablica elementow
   int n;     // rozmiar tablicy (niekoniecznie wszystkie beda uzywane)
   int k;     // ile uzywamy
   int ep;    // indeks pierwszego elementu
};


KolejkaPriorytetowa* tworzKolejkePriorytowa()
{
   KolejkaPriorytetowa* kolejka = new KolejkaPriorytetowa;

   kolejka->k = 0;
   kolejka->n = 1000; // na poczatek
   kolejka->elem = new Data[kolejka->n];
   kolejka->ep = 0;

   return kolejka;
}


void kasujKolejkePriorytetowa(KolejkaPriorytetowa* kolejka)
{
   delete [] kolejka->elem;
   delete kolejka;
}


bool empty(KolejkaPriorytetowa* kolejka)
{
   return (kolejka->k == 0);

   /*
      rownowaznie:

      if (kolejka->k == 0)
         return true;
      else
         return false;
   */
}


Data pull(KolejkaPriorytetowa* kol)
{
   assert(kol->k > 0);
   Data w = kol->elem[kol->ep];

   kol->k--;
   kol->ep = (kol->ep + 1) % kol->n;

   return w;
}



void insert(KolejkaPriorytetowa* kol, Data dm)
{
   assert(kol->k < kol->n);  //// W DOMU ---- PRZEROBIC KOD TAK, BY TABLICA MOGLA SIE POWIEKSZAC

   if (czyWieksze(kol->elem[kol->ep], dm))
   {
      if (kol->ep == 0) kol->ep = kol->n-1;
      else kol->ep--;

      kol->elem[kol->ep] = dm;
   }
   else
   {
      int i;
      for (i=0; i<kol->k; i++)
      {
         if (czyWieksze(kol->elem[(kol->ep + i)%kol->n], dm))
            break;
      }
      // tutaj i - miejsce {(kol->ep + i)%kol->n}, na ktore mamy wstawic przemek
      for (int j=kol->k; j>i; j--)
         kol->elem[(kol->ep + j)%kol->n] = kol->elem[(kol->ep + j-1)%kol->n];
      kol->elem[(kol->ep + i)%kol->n] = dm;
   }

   kol->k++;
}

int main()
{
   KolejkaPriorytetowa* k = tworzKolejkePriorytowa();

   insert(k, tworzDate(1,1));
   insert(k, tworzDate(11,11));
   insert(k, tworzDate(31,12));
   insert(k, tworzDate(4,10));
   insert(k, tworzDate(18,11));
   insert(k, tworzDate(30,6));

   while (!empty(k))
       wypiszDate(pull(k));

   kasujKolejkePriorytetowa(k);

   return 0;
}

