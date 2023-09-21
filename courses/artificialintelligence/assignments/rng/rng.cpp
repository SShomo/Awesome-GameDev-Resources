#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

int main(){
  unsigned int seed, num;
  signed int min, max, value;
  cin >> seed >> num >> min >> max;

  for(int x =0; x < num; x++)
  {
    seed ^= seed << 13;
    //cout << bitset<32>(seed) << endl;
    seed ^= seed >> 17;
    //cout << bitset<32>(seed) << endl;
    seed ^= seed << 5;
    //cout << bitset<32>(seed) << endl;


    value = min + (seed  % (max - min + 1));
    cout <<  value << endl;
  }
  return 0;
}