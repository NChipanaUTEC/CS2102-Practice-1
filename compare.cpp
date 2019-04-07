#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
using namespace std;

void merge(int array[],int left, int middle, int right){
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int tempL[n1];
  int tempR[n2];
  for(int i = 0; i < n1; i++){tempL[i] = array[left+i-1];}
  for(int j = 0; j < n2; j++){tempR[j] = array[middle+j];}
  int v1 = 0;
  int v2 = 0;
  int key;
  for(int key = left; key<right;key++){
    if(tempL[v1]<=tempR[v2]){
      array[key] = tempL[v1];
      v1+=1;
    }
    else{
      array[key] = tempR[v2];
      v2+=1;
    }
  }
  while (v1 < n1){
      array[key] = tempL[v1];
      v1++;
      key++;
    }
    while (v2 < n2){
      array[key] = tempR[v2];
      v2++;
      key++;
    }
}

void mergeSort(int array[],int left,int right){
  int middle;
  if(left < right){
    middle = (left + right) / 2;
    mergeSort(array,left,middle);
    mergeSort(array,middle+1,right);
    merge(array,left,middle,right);
  }
}

void insertSort(int array[],int size){
  int value,key;
  for(int i = 1; i<=size; i++){
    key = array[i];
    value = i-1;
    while((key<array[value]) && value>=0){
      array[value+1]=array[value];
      value=value-1;
   }
    array[value+1] = key;
  }
}

void create_array(int cant){
  int array[cant];
  int cont = 1;
  string file = "datos2.txt";
  ofstream onFile;
  onFile.open(file, ios::app);
  clock_t execution_time;
  for(int i = cant; i > 0; i--){
    array[i] = cont;
    cont ++;
  }
  execution_time = clock();
  //insertSort(array,cant);
  mergeSort(array,0,cant);
  string num = to_string(cant);
  string time = to_string(((float)(clock()-execution_time))/CLOCKS_PER_SEC);
  cout << num << " "<< time<<"\n";
  onFile << (num+" "+time+"\n");
  onFile.close();
}

int main(){
  for(int i = 10; i < 100000; i++){
    if(i%1000 == 0){
      create_array(i);
    }
  }
  return 0;
}
