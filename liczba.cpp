
#include "liczba.h"
//
int Liczba::size_=1;

Liczba::Liczba(int liczba):
    //
    tablica_(std::vector<char>(Liczba::size_,'0'))
{

  //for(int i=0; i<Liczba::size_; ++i) tablica_[i]='0';
  int licznik=1;
  while(liczba>0)
    {
    tablica_[Liczba::size_-licznik]=liczba%Liczba::system_+Liczba::asci_;
    liczba/=Liczba::system_;
    ++licznik;
    }
}

std::ostream & operator<<(std::ostream &a, const Liczba &b)
{
  int licznik=0;
  while(b.tablica_[licznik]=='0' && licznik<Liczba::size_-1) ++licznik;
  for( int i=licznik; i<Liczba::size_; ++i) a<<b.tablica_[i];
  a<<"\n";
  return a;
}

int Liczba::length() const
{
  int licznik=0;
  int rozmiar=Liczba::size_;
  while(licznik<Liczba::size_ && tablica_[licznik]=='0') licznik++;
  if(licznik==rozmiar)
  {
    rozmiar=1;
  }
  else
    {
  rozmiar-=licznik;
    }

  return rozmiar;
}


Liczba operator+( const Liczba &a, const Liczba &b)
{
  Liczba wynik;
  int temp;
  int reszta=0;
    int wieksza;
    if(a.length()>b.length())
    {
    wieksza=a.length();
    }
  else
    {
    wieksza=b.length();
    }

  for(int i=Liczba::size_-1; i>wieksza; --i)
    {
    temp=a.get(i)+b.get(i)-2*Liczba::asci_+reszta;
    reszta=temp/Liczba::system_;
    wynik.set(temp%Liczba::system_+Liczba::asci_, i);
    }

  return wynik;
 }



Liczba operator*(const Liczba &a, const Liczba &b)
{
  Liczba wynik;
  int temp;
  int przeniesienie=0;
  int wieksza;
  Liczba temp_wynik;
  if(a.length()>b.length())
    {
    wieksza=a.length();
    }
  else
    {
    wieksza=b.length();
    }

  for(int i=0; i<wieksza; ++i)
    {
    przeniesienie=0;
    temp_wynik=Liczba();
    for(int j=0; j<wieksza; ++j)
    {

      temp=(a.get(Liczba::size_-i-1)-Liczba::asci_)*(b.get(Liczba::size_-j-1)-Liczba::asci_)+przeniesienie;
      przeniesienie=temp/Liczba::system_;
      temp_wynik.set(temp%Liczba::system_+Liczba::asci_, Liczba::size_-i-j-1);

    }

    temp_wynik.set(przeniesienie+Liczba::asci_, Liczba::size_-wieksza-i-1);
    wynik=wynik+temp_wynik;

    }
      return wynik;
}

