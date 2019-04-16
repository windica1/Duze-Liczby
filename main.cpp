#include <iostream>
#include "Liczba.h"


int main()
{
    int a,b;
    //
    Liczba::size_=100000;
    Liczba A(1);
    Liczba B(1);
    std::cout<<"podaj silnie ";
    std::cin >> a;
    for (int i = 1; i < a+1; i++)
    {
        A = A * i;
    }
    std::cout<<"= "<<A<<std::endl;

    std::cout<<"podaj silnie ";
    std::cin >> b;
    for (int i = 1; i < b+1; i++)
    {
        B = B * i;
    }
    std::cout <<"= "<< B<<std::endl;
    std::cout<<"Suma = ";
    std::cout<<A+B<<std::endl;
    std::cout<<"Iloczyn = ";
    std::cout<<A*B<<std::endl;

    return 0;
}
