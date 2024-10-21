#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<"enter two prime numbers:"<<endl;
    int p,q;
    cin>>p;
    cin>>q;
    double n=p*q;
    float fn= (p-1)*(q-1);
    int e=3;
    int d;
    for(int i=0; i<3;i++)
    {
        int num=(1+(i*fn));
        if (num%e==0){
            d=num/e;
            cout<<"d = "<<d<<endl;
        }
    }
    cout<<"enter number to be encrypted:"<<endl;

    int enc;
    cin>>enc;
    cout<<"Number to be encrypted="<<enc<<endl;
    if(enc<n)
    {
    int power=pow(enc,e);
    int encrypted=fmod(power,n);
    cout<<"Encrypted text:"<<encrypted<<endl;
    long double dpow=pow(encrypted,d);
    int decrypted=fmod(dpow,n);
    cout<<"Decrypted text:"<<decrypted<<endl;
    }
    else{
        cout<<"number cant be encrypted"<<endl;
    }
}
