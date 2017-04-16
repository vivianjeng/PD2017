#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
 int n,p,d;
 n=(rand()%50)+2;
 p=(rand()%n)+2;
 d=(rand()%300);
 cout<<n<<" "<<p<<" "<<d<<endl;
 for(int i=1;i<=n;i++){
 	cout<<(rand()%200)-100<<" "<<(rand()%200)-100<<" "<<(rand()%100)+1<<endl;
 }
 
}
