#ifndef LICZBA_H_INCLUDED
#define LICZBA_H_INCLUDED

#include<iostream>
#include<vector>
class Liczba
{
public:
  Liczba(int liczba=0);

friend  std::ostream & operator<<(std::ostream &a, const Liczba &b);

  int length() const ;
  int get(int i) const
  {
    return tablica_[i];
  }
  void set(char a, int i )
  {
    tablica_[i]=a;
  }

    static int size_;
    static const int system_=10;
    static const int asci_=48;

private:
    std::vector<char> tablica_;
    //char tablica_[size_];

};

Liczba operator*( const Liczba &a, const Liczba &b);
Liczba operator+(const Liczba &a, const Liczba &b);
Liczba operator-(const Liczba &a, const Liczba &b);


#endif // LICZBA_H_INCLUDED
