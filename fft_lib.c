#include <stdio.h>
#include "fft_lib.h"

#define N 16

void danielson_lanczos(int *x, int *W){
    int M = 1;                                  //1st stage
    int j,Temp;

    while(M < N){                               //for each stage 
        int stride = M << 1;                    //fix the stride at eaxh stage 

        for(int m = 0; m < M ; m++){            //step through the butterflies 
            for(int i = m; i < N; i+=stride ){  
                j = i + M;                      //j difference & i sum 'wing'
                Temp = *(x + j) * *(W + m);       //twiddle factor multiplication
                *(x + i) = *(x + i) + Temp;
                *(x + j) = *(x + j) - Temp;
            }
        }
        M = stride;                             //update invariant 
    }
        
}

void swap(int *x,int *y){                      
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void fill_up(int *x){
   for(int i=0; i<N; i++){
        *(x + i) = i;
   }
}

void print_x(int *x){
    for(int i=0; i<N; i++){
        printf("%d\n",*(x + i));
    }
}

void permute(int *x){
    int n,m,i = 0;

    for(n = 0; n < N; n++){ 
        if(n > i){
            swap(&x[i],&x[n]);
        }
        m = (N)/2 ;

        while( m >= 2 && i >= m){
            i = i - m;
            m = (m)/2;
        }
        i = i + m;
    }
}


