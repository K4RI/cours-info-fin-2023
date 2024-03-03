#include <math.h>
#include <stdio.h>

double somme(double x, int N){
    double sum = 0;
    for (int n = 0; n < N; n++){
        sum += log(x+n)/(x + pow(n, 2));
    }
    return sum;
}

int main(){
    printf("%f\n", somme(1e13, 1e0));
}