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
  
  cin>>n>>m;
    char** fruit_type = new char*[n];
    for(int i=0;i<n;i++){
      fruit_type[i] = new char[MAX_ARRAY_LENGTH];
    }
    int* fruit_price = new int[n];
    int* fruit_price_float = new int[n];
    for(int i=0;i<n;i++){
      cin>>fruit_type[i];
      fruit_price[i] = 0;
      fruit_price_float[i] = 0;
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
        
        for(int j=0;j<strlen(fruit);j++){
        if(isupper(fruit[j]))
          fruit[j] = tolower(fruit[j]);
      }
         
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

      for(int j=0;j<n;j++){
        if(strcmp(fruit,fruit_type[j]) == 0){
          if((atoi(adjust_price) == 0) && price_negative){
            if(fruit_price[j] > 0){
                fruit_price_float[j] -= atoi(floating_number);
                if(fruit_price_float[j] < 0){
                    fruit_price[j] -= 1;
                    fruit_price_float[j] = 100 + fruit_price_float[j];
                }
            }
            else {
                fruit_price_float[j] += atoi(floating_number);
                if(fruit_price_float[j] > 100){
                    fruit_price[j] -= 1;
                    fruit_price_float[j] -= 100;
                }
            }
          } else{
            //if the price to be add is positive and the original fruit_price[j] is positive
            if(atoi(adjust_price) > 0 && fruit_price[j] > 0){
               fruit_price_float[j] += atoi(floating_number);
               if(fruit_price_float[j] >= 100){
                    fruit_price[j] += 1;
                    fruit_price_float[j] -= 100;
                }
            }
            //if the price to be add is negative and the original fruit_price[j] is positive 
            else if(atoi(adjust_price) < 0 && fruit_price[j] > 0){
                //if the fruit_price_float[j] part is zero
                if(fruit_price_float[j] == 0){
                  if(fruit_price[j] + atoi(adjust_price) > 0){
                        fruit_price_float[j] = 100 - atoi(floating_number);
                        fruit_price[j] -= 1;
                  }
                  else{
                     fruit_price_float[j] = atoi(floating_number);
                  }   
                }
                //if the fruit_price_float[j] part is not zero
                else{
                    fruit_price_float[j] -= atoi(floating_number);
                    if(fruit_price_float[j] < 0){
                        if((fruit_price[j]+atoi(adjust_price)) > 0){
                         fruit_price_float[j] = 100 + fruit_price_float[j];
                         fruit_price[j] -= 1;
                         }
                        else{
                          fruit_price_float[j] *= (-1);
                        }
                    }
                    else if(fruit_price_float[j] > 0){
                         if((fruit_price[j]+atoi(adjust_price)) < 0){
                            fruit_price[j] += 1;
                            fruit_price_float[j] = 100 - fruit_price_float[j];
                        }
                    }
                }
             } 
             //if the price to be add is positive and original fruit_price[j] is negative
             else if(atoi(adjust_price) > 0 && fruit_price[j] < 0){
                   //if the fruit_price_float[j] part is zero
                   if(fruit_price_float[j] == 0){
                        if(fruit_price[j] + atoi(adjust_price) < 0){
                             fruit_price_float[j] = 100 - atoi(floating_number);
                             fruit_price[j] += 1;
                         }
                        else{
                            fruit_price_float[j] = atoi(floating_number);
                        }
                    }
                    //if the fruit_price_float[j] part is not zero
                    else {
                        fruit_price_float[j] -= atoi(floating_number);
                        if(fruit_price_float[j] < 0){
                              if((fruit_price[j] + atoi(adjust_price)) > 0){
                                    fruit_price_float[j] *= (-1);
                              }
                              else{
                                    fruit_price_float[j] = 100 + fruit_price_float[j];
                                    fruit_price[j] += 1;
                              }
                        }
                        else if(fruit_price_float[j] > 0){
                              if((fruit_price[j]+atoi(adjust_price)) > 0){
                                    fruit_price[j] -= 1;
                                    fruit_price_float[j] = 100 - fruit_price_float[j];
                              }
                        }
                    }
            }
            //if the price to be add is negative and original fruit_price[j] is negative
             else if(atoi(adjust_price) < 0 && fruit_price[j] < 0){
                    fruit_price_float[j] += atoi(floating_number);
                    if(fruit_price_float[j] >= 100){
                        fruit_price[j] -= 1;
                        fruit_price_float[j] -= 100;
                   }
            }
            // if the price to be add is zero or original fruit_price[j] is zero
            else{
            fruit_price_float[j] += atoi(floating_number);
            }
            
            // add the interger part of the price
            fruit_price[j] += atoi(adjust_price);
        
       
          }
        }
      }
      delete [] fruit;
      delete [] price;
      
    }

    for (int i = 0; i < n; i++)
    {
      cout<<fruit_price[i]<<'.';
    if((fruit_price_float[i] /10) == 0)
        cout<<'0'<<fruit_price_float[i];
    else
        cout<<fruit_price_float[i];
      if(i<n-1){
        cout<<" ";
      }
    }
    
  
    
  return 0;
}

