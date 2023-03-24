#include <stdio.h>
#define N 8

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

int main(){
    int x[N];

    fill_up(&x[0]);
    print_x(&x[0]);
    permute(&x[0]);
    print_x(&x[0]);

    return 0;
}