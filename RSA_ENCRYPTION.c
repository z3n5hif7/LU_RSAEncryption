#include <stdio.h>

/*RESULTS: (98% accurate)
ENCRYPTION -> 'ì' instead of 'a' (should be "lNYECaHS(N") 
WORD: ENCRYPTION 
ENCRYPTION: lNYECìHS(N
DECRYPTION: ENCRYPTION

RASTAMAN -> no BACKSPACE CHARACTER (should be "E(BACKSPACE CHARACTER)HAMAN")
WORD: RASTAMAN 
ENCRYPTION: EHAMAN
DECRYPTION: RASTAMAN
*/

void simulate();//Simulates both Encryption & Decryption, and displays the results.
void encrypt(int p, int q);
void decrypt(int p, int q);

typedef unsigned char String[25];//You can change 25

//Defaults: p=11, q=13, e=7, d=223 
//Test out any word here:
// String string = "RASTAMAN";
String string = "ENCRYPTION";

int main(){
    int p=11,q=13;

    simulate(p,q);
    return 0;
}

void simulate(int p, int q){
    printf("WORD: %s\n",string);
    encrypt(p,q);
    printf("ENCRYPTION: %s\n",string);
    decrypt(p,q);
    printf("DECRYPTION: %s\n",string);
}

void encrypt(int p, int q){

    int n=p*q, z=(p-1)*(q-1), e=7, d=223, c=1,i,m, exp, base;

    for(i=0,m=string[i],c=1,exp=e,base=m;string[i]!='\0';i++,c=1,m=string[i],base=m,exp=e){
        while(exp){
            if(exp%2){
                c=(base*c)%n;
            }
            base=(base*base)%n;
            exp/=2;
        }
        string[i]=c;
    }
}

void decrypt(int p, int q){

    int n=p*q, z=(p-1)*(q-1), e=7, d=223, c=1,i,m, base, exp;

    for(i=0,m=1,c=string[i],base=c,exp=d;string[i]!='\0';i++,m=1,c=string[i],base=c,exp=d){
        while(exp){
            if(exp%2){
                m=(base*m)%n;
            }
            base=(base*base)%n;
            exp/=2;
        }
        string[i]=m;
    }
}
