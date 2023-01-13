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
void stat(const double A[], int N, double B[]) {
    double sum = 0, sumSq = 0, product = 1, harmonicSum = 0;
    double max = A[0], min = A[0];
    for (int i = 0; i < N; i++) {
        sum += A[i];
        sumSq += pow(A[i], 2);
        product *= A[i];
        harmonicSum += 1/A[i];
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    double mean = sum/N;
    double variance = (sumSq/N) - pow(mean, 2);
    double stdDev = sqrt(variance);
    double geoMean = pow(product, 1.0/N);
    double harmMean = N / harmonicSum;
    B[0] = mean;
    B[1] = stdDev;
    B[2] = geoMean;
    B[3] = harmMean;
    B[4] = max;
    B[5] = min;
}