#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[]) {
  string line;
  while(cin >> line){
    for(int i = 0; i < line.length();i++){
      cout << (char)(line[i]-7);
    }
    cout << endl;
  }

  return 0;
}
