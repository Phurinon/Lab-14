#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum;
    for(int i=0;i<N;i++){
        sum += A[i];
        B[0] = sum/N;
    }

    double standard;
    for(int i=0;i<N;i++){
        standard += A[i]*A[i];
        B[1] = sqrt(standard/N-pow(sum/N,2));
    }

    double Geo;
    float product = 1;
    for(int i=0;i<N;i++){
        product = product*A[i];
    }
    Geo = pow(product,(float)1/N);
    B[2] = Geo;

    double Har=0;
    for(int i=0;i<N;i++){
        Har += (float)1/A[i];
        B[3] = (float)N/Har;
    }

    double max=A[0],min=A[0];
    for(int i=1;i<N;i++){
        if(A[i]>max) B[4]=A[i];
        if(A[i]<min) B[5]=A[i];
    }
}