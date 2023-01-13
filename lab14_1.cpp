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
void stat(const double A[],int N,double B[])
{
    double sum=0;
    double sumSq=0;
    double hsum=0;
    double product=1;
    double max=A[0];
    double min=A[0];
    for(int i=0; i<N; i++)
    {
        sum+=A[i];
        sumSq+=pow(A[i],2);
        hsum+=1/A[i];
        product*=A[i];
        if(max<A[i])max=A[i];
        if(min>A[i])min=A[i];
    }
    double mean=sum/N;
    double xsd=0;
    for(int j=0; j<N; j++)
    {
        xsd += pow((A[j]-mean),2);
    }
    double sd=sqrt(xsd/N);
    double hm=N/hsum;
    double gm=pow(product,1.0/N);
    B[0]=mean;
    B[1]=sd;
    B[2]=gm;
    B[3]=hm;
    B[4]=max;
    B[5]=min;

}