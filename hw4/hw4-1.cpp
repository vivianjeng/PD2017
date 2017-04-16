#include <iostream > 
using namespace std; 
void printArray(int[][2], int); 
int main() { 
	int num[2][5] = {1, 2, 3, 4, 5}; // five 0s 
	printArray(num,5); 
	return 0; }
void printArray(inta[][2], int len) {
 for(int i = 0; i < len; i++) {
  for(int j = 0; j < 2; j++) cout << a[i][j] << " "; cout << "\n"; } }
