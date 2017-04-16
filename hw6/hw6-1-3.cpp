#include <iostream>
using namespace std;
   
void setTransactions(int** trans , int* itemCnt , int m);
   
int main(){
        
    int objectNum = 0;
    int validCount = 0;
    int iterNum = 0;
    int located = 0 ;
    int transNum = 0;
    float supportThr;
   
    const int n = 20;
    const int m = 500;
        
    int a = 0;
    cin >> objectNum >> transNum >> supportThr;
       
    int** trans = new int*[transNum];
    bool test[n];
    bool transValid[m];
        
    // test & trans init
    for(int j = 0; j < objectNum; j++){
        test[j] = false;
    }
        
   
    // take input transform into matrix form & call setTransactions function
    int* itemCnt = new int[transNum];
    setTransactions(trans , itemCnt , transNum);
     
    cin >> iterNum;
        
    // take testing data
    for(int j = 0; j < iterNum; j++){
        cin >> located;
        test[located - 1] = true;
    }
    
    // compute support set with test data
    for(int i = 0; i < transNum; i++){
        transValid[i] = false;
        bool sign = true;
        for(int j = 0; j < objectNum; j++){
            if(test[j] == 1){
                bool transExist=false;
                for (int k = 0; k < itemCnt[i]; k++)
                {   
                    if(trans[i][k] == j){
                        transExist = true;
                    }
                }
                if(!transExist){
                    sign = false;
                }
            }
        }
        if(sign == true){
            transValid[i] = true;
            validCount++;
        }
    }
        
    // calculate confidence with threshold of suppport
        
    int maxIndex = -1;
    int maxCount = -1;
    for(int i = 0; i < objectNum; i++){
        if(test[i] == 1)
            continue;
        int count = 0;
        for(int j = 0; j < transNum; j++){
            if(transValid[j]){
                for (int k = 0; k < itemCnt[j]; k++)
                {
                    if(trans[j][k] == i){
                        count++;
                    }
                }
            }
        }
            
        if( count > supportThr * transNum && count > maxCount)   
        {
            maxCount = count;
            maxIndex = i;
        }
    }
    if(maxCount != -1){
        cout << (maxIndex + 1) << " " << maxCount << " " << validCount ;
    }
 
    //delete dynamic array
    for(int i=0;i<transNum;i++){
         delete [] trans[i];
    }
    delete [] trans;
    delete [] itemCnt;
    
    return 0;
}
   
void setTransactions(int** trans , int* itemCnt , int m){
    int iterNum = 0;
    int located = 0 ;
       
    for(int i = 0; i < m; i++){
        cin >> iterNum;
        itemCnt[i] = iterNum;
        //allocate "iterNum" space for trans[i]
        trans[i] = new int[iterNum];
        for(int j = 0; j < iterNum; j++){
            cin >> located;
            trans[i][j] = located-1;
                
        }
    }
}