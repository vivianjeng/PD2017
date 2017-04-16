#include <iostream>
using namespace std;

int combiRec(int n, int m, int** com)
{
if(n < m)
return -1;
else if(n == m)
return 1;
else if(m == 1)
return n;
else
{
if(com[n - 1][m - 1] == -1)
{
int res = combiRec(n - 1, m, com) + combiRec(n - 1, m - 1, com);
com[n - 1][m - 1] = res;
return res;
}
else
return com[n - 1][m - 1];
}
}


int main()
{
int n = 0, m = 0;
cin >> n >> m;
int** com = new int*[n];
for(int i = 0; i < n; i++)
{
com[i] = new int[m];
for(int j=0;j<m;j++){
	com[i][j] = -1;
}
}
// declare an n by m dynamic array
// and initialize all elements in it to -1
cout << combiRec(n, m, com);
return 0;
}

