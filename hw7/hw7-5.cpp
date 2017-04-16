#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

#define MAX_ARRAY_LENGTH 20
#define MIN_PRICE_LIMIT (-99999999)
#define MAX_PRICE_LIMIT 99999999

void compute_sum(char*, char*, int&, int&, bool);

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
        int length = 0;
        bool finish_compare = false;
         
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
      //no string edit
      for(int j=0;j<n;j++){
          if(strcmp(fruit,fruit_type[j]) == 0){
              compute_sum(adjust_price,floating_number,fruit_price[j],fruit_price_float[j],price_negative);
              finish_compare = true;
          }
          if(finish_compare)
              break;
      }
        length = strlen(fruit);
      // a = 97, z = 122
      
      //insert
      for (int k = 0; k < length + 1; k++)
      {
        char temp[length+1];
        strcpy(temp,fruit);

        for (int l = length; l >=k ; l--)
        {
          temp[l+1] = temp[l]; //characters shift right
        }
        for (int m = 97; m < 123; m++)
        {
          temp[k] = (char)m;
          for(int j=0;j<n;j++){
            if(strcmp(temp,fruit_type[j]) == 0){
               compute_sum(adjust_price,floating_number,fruit_price[j],fruit_price_float[j],price_negative);
               finish_compare = true;
            }
            if(finish_compare)
              break;
          }
          if(finish_compare)
              break;
        }
        if(finish_compare)
              break;
      }

      //delete
      for (int k = 0; k < length; k++)
      {
        char temp[length+1];
        strcpy(temp,fruit);

        for (int l = k; l < length-1 ; l++)
        {
          temp[l] = temp[l+1]; //characters shift left
        }
        temp[length-1] = '\0';
        for(int j=0;j<n;j++){
            if(strcmp(temp,fruit_type[j]) == 0){
               compute_sum(adjust_price,floating_number,fruit_price[j],fruit_price_float[j],price_negative);
               finish_compare = true;
            }
            if(finish_compare)
              break;
          }
          if(finish_compare)
              break;
      }

      //substitute
      for (int k = 0; k < length; k++)
      {
        char temp[length+1];
        strcpy(temp,fruit);

        for (int m = 97; m < 123; m++)
        {
          temp[k] = (char)m;
          for(int j=0;j<n;j++){
            if(strcmp(temp,fruit_type[j]) == 0){
               compute_sum(adjust_price,floating_number,fruit_price[j],fruit_price_float[j],price_negative);
               finish_compare = true;
            }
            if(finish_compare)
              break;
          }
          if(finish_compare)
              break;
        }
      }
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

void compute_sum(char* adjust_price, char* floating_number, int& sum,int& sum_float,bool price_negative){

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
        } else{
            //if the price to be add is positive and the original sum is positive
            if(atoi(adjust_price) > 0 && sum > 0){
               sum_float += atoi(floating_number);
               if(sum_float >= 100){
                    sum += 1;
                    sum_float -= 100;
                }
            }
            //if the price to be add is negative and the original sum is positive 
            else if(atoi(adjust_price) < 0 && sum > 0){
                //if the sum_float part is zero
                if(sum_float == 0){
                  if(sum + atoi(adjust_price) > 0){
                        sum_float = 100 - atoi(floating_number);
                        sum -= 1;
                  }
                  else{
                     sum_float = atoi(floating_number);
                  }   
                }
                //if the sum_float part is not zero
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
             } 
             //if the price to be add is positive and original sum is negative
             else if(atoi(adjust_price) > 0 && sum < 0){
                   //if the sum_float part is zero
                   if(sum_float == 0){
                        if(sum + atoi(adjust_price) < 0){
                             sum_float = 100 - atoi(floating_number);
                             sum += 1;
                         }
                        else{
                            sum_float = atoi(floating_number);
                        }
                    }
                    //if the sum_float part is not zero
                    else {
                        sum_float -= atoi(floating_number);
                        if(sum_float < 0){
                              if((sum + atoi(adjust_price)) > 0){
                                    sum_float *= (-1);
                              }
                              else{
                                    sum_float = 100 + sum_float;
                                    sum += 1;
                              }
                        }
                        else if(sum_float > 0){
                              if((sum+atoi(adjust_price)) > 0){
                                    sum -= 1;
                                    sum_float = 100 - sum_float;
                              }
                        }
                    }
            }
            //if the price to be add is negative and original sum is negative
             else if(atoi(adjust_price) < 0 && sum < 0){
                    sum_float += atoi(floating_number);
                    if(sum_float >= 100){
                        sum -= 1;
                        sum_float -= 100;
                   }
            }
            // if the price to be add is zero or original sum is zero
            else{
            sum_float += atoi(floating_number);
            }
            
            // add the interger part of the price
            sum += atoi(adjust_price);
        }
}
