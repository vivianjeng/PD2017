#include <iostream >
#include<iomanip>
using namespace std;
int main()
{
int a = 99;
int b = 75;
float r = static_cast <float >(a) / b;
cout << r << " "<<setprecision(10) << r * b << "\n";
if(r * b != a)
cout << "WOW!\n";
return 0;
}
