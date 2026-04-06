#include <iostream>
#include <cstdint>
using namespace std;
uint32_t reverseBits(uint32_t n) {
 uint32_t result = 0;
 for (int i = 0; i < 32; i++) {
 uint32_t bit = n & 1;
 result = (result << 1) | bit;
 n = n >> 1;
 }
 return result;
}
int main() {
 uint32_t n = 43261596;
 cout << reverseBits(n) << endl;
 return 0;
}
