#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cout << "��J�@�ӫD�t���:" ; 
	cin >> n; //��J�D�t���
	int rmd = n % 2; //�ŧirmd(remainder)��n���H2���l�� 
	
	if(rmd == 1) //�Yremainder��1�A�h���_�� 
		cout << "��X���Ƭ��G" << 3*n + 1; 
	if(rmd == 0) //�Yremainder��0�A�h������  
		cout << "��X���Ƭ��G" << n / 2;
	return 0;
}
