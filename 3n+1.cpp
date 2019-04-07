#include <iostream>
using namespace std;

long long int cycles(long long int number){
  long long int cont = 1;
  long long int numero = number;
  while(numero != 1){
    if(numero % 2 != 0){
      numero = (numero*3)+1;
      cont ++;
    }
    else if(numero % 2 == 0){
      numero /= 2;
      cont ++;
    }
  }
  return cont;
}


int main(){
  long long int lower,upper;
  long long int mayor = 0;
  while(cin >> lower >> upper){
    mayor = 0;
    if(lower > upper){swap(lower,upper);}
    for(int i = lower; i <= upper; i++){
      if(cycles(i)>mayor){mayor = cycles(i);}
    }
    cout << lower << " " << upper <<" " << mayor<<"\n";
  }
  return 0;
}
