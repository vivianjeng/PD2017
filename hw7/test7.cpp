#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
 
#define MAX_ARRAY_LENGTH 20
#define MIN_PRICE_LIMIT (-99999999)
#define MAX_PRICE_LIMIT 99999999
 
int main() {
     
    int n,m;
    int max_price = MIN_PRICE_LIMIT;
    int max_price_float = 0;
    int min_price = MAX_PRICE_LIMIT;
    int min_price_float = 0;
    int sum = 0;
    int sum_float = 0;
    
     
    cin>>n>>m;
    char** fruit_type = new char*[n];
    for(int i=0;i<n;i++){
        fruit_type[i] = new char[MAX_ARRAY_LENGTH];
    }
    for(int i=0;i<n;i++){
        cin>>fruit_type[i];
    }
     
    for(int i=0;i<m;i++){
        char* fruit;
        char* price;
        char* adjust_price;
        char floating_number[3] = "00";
        fruit = new char[MAX_ARRAY_LENGTH];
        price = new char[MAX_ARRAY_LENGTH];
        adjust_price = new char[MAX_ARRAY_LENGTH];
        int adjust_position = 0;
        bool price_negative = false;
         
        cin>>fruit;
        cin>>price;
         
        for(int j=0;j<=strlen(price);j++){
            if(j == 0){
                if(price[j] == 40){ // if "(" is in the first place
                    adjust_price[adjust_position] = 45; //mark the "negative sign"
                    adjust_position++;
                    price_negative = true;
                }
            }
            if(isdigit(price[j]) || price[j] == 45){ //input "isdigit" character
                adjust_price[adjust_position] = price[j];
                adjust_position++;
                if(price[j] == 45){
                    price_negative = true;
                }
            } else if( price[j] == 46 ){ //if input "."
                floating_number[0] = price[j+1];
                if((j+2) == strlen(price)-1 ||
                    (j+2) == strlen(price)-2){
                    if(price[j+2] != 41){   
                        floating_number[1] = price[j+2];
                    }
                    else{
                        floating_number[1] = '0';
                    }
                }
                else
                    floating_number[1] = '0';
                break;
            }
        }

        delete [] fruit;
        delete [] price;


        if(atoi(adjust_price) > max_price){
            max_price = atoi(adjust_price);
            max_price_float = atoi(floating_number);
        } else if (atoi(adjust_price) == max_price &&
                   atoi(floating_number) > max_price_float){
            max_price = atoi(adjust_price);
            max_price_float = atoi(floating_number);
        }
        
        if(atoi(adjust_price) < min_price){
            min_price = atoi(adjust_price);
            min_price_float = atoi(floating_number);
        } else if (atoi(adjust_price) == min_price &&
                   atoi(floating_number) > min_price_float){
            min_price = atoi(adjust_price);
            min_price_float = atoi(floating_number);
        }

        if((atoi(adjust_price) == 0) && price_negative){
            if(sum > 0){
                sum_float -= atoi(floating_number);
                if(sum_float < 0){
                    sum -= 1;
                    sum_float = 100 + sum_float;
                }
            }
            else {
                sum_float += atoi(floating_number);
                if(sum_float > 100){
                    sum -= 1;
                    sum_float -= 100;
                }
            }
        }
        
        if(atoi(adjust_price) > 0 && sum > 0){
            sum_float += atoi(floating_number);
            if(sum_float >= 100){
                sum += 1;
                sum_float -= 100;
            }
        } else if(atoi(adjust_price) < 0 && sum > 0){
            if(sum_float == 0){
                sum_float = 100 - atoi(floating_number);
                sum -= 1;
            }
            else{
                sum_float -= atoi(floating_number);
                if(sum_float < 0){
                    if((sum+atoi(adjust_price)) > 0){
                        sum_float = 100 + sum_float;
                        sum -= 1;
                    }
                    else{
                        sum_float *= (-1);
                    }
                }
                else if(sum_float > 0){
                    if((sum+atoi(adjust_price)) < 0){
                        sum += 1;
                        sum_float = 100 - sum_float;
                    }
                }
            }
        } else if(atoi(adjust_price) > 0 && sum < 0){
            if(sum_float == 0){
                sum_float = 100 - atoi(floating_number);
                sum += 1;
            }
            else {
                sum_float -= atoi(floating_number);
                if(sum_float < 0){
                    if((sum+atoi(adjust_price)) > 0){
                        sum_float = 100 + sum_float;
                        sum -= 1;
                    }
                    else{
                        sum_float *= (-1);
                    }
                }
                else if(sum_float > 0){
                    if((sum+atoi(adjust_price)) > 0){
                        sum -= 1;
                        sum_float = 100 - sum_float;
                    }
                }
            }
        } else if(atoi(adjust_price) < 0 && sum < 0){
            sum_float += atoi(floating_number);
            if(sum_float >= 100){
                sum -= 1;
                sum_float -= 100;
            }
        } else{
            sum_float += atoi(floating_number);
        }
        
        sum += atoi(adjust_price);
       
    }
    
    cout<<max_price<<'.';
    if((max_price_float /10) == 0)
        cout<<'0'<<max_price_float<<" ";
    else
        cout<<max_price_float<<" ";

    cout<<min_price<<'.';
    if((min_price_float /10) == 0)
        cout<<'0'<<min_price_float<<" ";
    else
        cout<<min_price_float<<" ";

    cout<<sum<<'.';
    if((sum_float /10) == 0)
        cout<<'0'<<sum_float;
    else
        cout<<sum_float;
    
    return 0;
}
