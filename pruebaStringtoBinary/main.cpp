#include <string>
#include <bitset>
#include <iostream>
using namespace std;
int main(){
  string myString = "Hello World";
  for (size_t i = 0; i < myString.size(); ++i)
  {
      bitset<8>(myString[i]);
  }
  cout<<myString<< endl;
}
