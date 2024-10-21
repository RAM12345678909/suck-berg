#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int g,p,a,b,A,B,X,Y;
    cout<<"Diffie Helman Key Exchange"<<endl;
    cout<<"Enter the value of generator (g)"<<endl;
    cin>>g;

    cout<<"Enter the prime number (p)"<<endl;
    cin>>p;

    cout<<"Enter the private key for Alice (a)"<<endl;
    cin>>a;

    A=(long long int)pow(g,a)%p;

    cout<<"A="<<A<<endl;

    cout<<"Enter the private key for Bob (b)"<<endl;
    cin>>b;

    B=(long long int)pow(g,b)%p;

    cout<<"B="<<B<<endl;

    cout<<"Now Alice and Bob exchange keys"<<endl;
    cout<<"Now Alice has "<<"a="<<a<<" A="<<A<<" B="<<B<<endl;
    cout<<"Now Bob has "<<"b="<<b<<" B="<<B<<" A="<<A<<endl;

    X = (long long int)pow(B,a)%p;

    cout<<"The value of X="<<X<<endl;
    Y = (long long int)pow(A,b)%p;

    cout<<"The value of Y="<<Y<<endl;

    if(X==Y)
    {
        cout<<"Diffie Helman key exchange is verified"<<endl;
    }
    else
    {
        cout<<"not verified";

    }

}
