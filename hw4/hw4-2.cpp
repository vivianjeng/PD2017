#include <iostream >
using namespace std;

int sum = 0;
void setScore (int cnt,int score[]);
float getAvg (int cnt, int score[]);

int main()
{
const int cnt = 5;
int score[cnt] = {0};
setScore (cnt,score);
cout << getAvg (cnt,score) << "\n";
cout << getAvg (cnt,score) << "\n";
return 0;
}

void setScore (int cnt,int score[])
{
for(int i = 0; i < cnt; i++)
cin >> score[i];
}
float getAvg (int cnt, int score[])
{
for(int i = 0; i < cnt; i++)
sum += score[i];
return static_cast <float >(sum) / cnt;
}
