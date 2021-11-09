#include <stdio.h>
#include <math.h>

int main(){

    int p = 5;
    int q = 7;
    int n = p*q;
    int z=(p-1)*(q-1);
    int e = 5;
    int d=29;
    int v = 22;//m
    int num=e*d-1;
    printf("l:%d\n",v);
    printf("p:%2d\n q:%2d\n n:%2d\n z:%2d\n e:%2d\n d:%2d\n e*d-1:%2d\n",p,q,n,z,e,d,num);

    int c =  pow(v,e);
    int cipher = c % n ; 
    //I was only able to solve the cipher for the letter "v" 
    //based from the table in your video Sir
    printf("m^e:%d\n",c);
    printf("cipher:%d\n",cipher);

    return 0;
}