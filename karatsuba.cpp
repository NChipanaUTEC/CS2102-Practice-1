#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int grade_school(string& x,string& y){
  long long int result = 0;
  long long int power1 = 0;
  long long int power2 = 0;
  int value1;
  int value2;
  for(int i = y.size()-1; i >= 0; i--){
    for(int j = x.size()-1; j >= 0; j--){
      value1 = y[i] - '0';
      value2 = x[j] - '0';
      result += (value1*value2)*pow(10,power1+power2);
      power1 ++;
    }
    power2 ++;
    power1 = 0;
  }
  return result;
}

long long int karatsuba(string x,string y){
  if(x.size()==1 && y.size()==1){
    return stoi(x)*stoi(y);
  }
  string a,b,c,d,sum1,sum2;
  long long int valueAC;
  long long int valueBD;
  long long int valuesum;
  a = x.substr(0,x.size()/2);
  b = x.substr(x.size()/2,x.size()/2);
  c = y.substr(0,y.size()/2);
  d = y.substr(y.size()/2,y.size()/2);
  valueAC = karatsuba(a,c);
  valueBD = karatsuba(b,d);
  sum1 = to_string(stoi(a)+stoi(b));
  sum2 = to_string(stoi(c)+stoi(d));
  valuesum = karatsuba(sum1,sum2);
  return pow(10,x.size())*valueAC+pow(10,x.size()/2)*(valuesum-valueAC-valueBD)+valueBD;
}


int main(){
  string x;
  string y;
  cin >> x >> y;
  long long int result1 = grade_school(x,y);
  long long int result2 = karatsuba(x,y);
  cout << result1 <<"\n";
  cout << result2 <<"\n";
}
