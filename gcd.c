#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    printf("%d = %d * %d + %d \n",a,b,a/b,a%b);
    return gcd(b, a % b);
}

int main() {
    //write a program to find the gcd of two input integer using Euclidean algo
    int num1 ,num2,temp;
    printf("----------------------------------------------\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("----------------------------------------------\n");
    if(num1<num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int ddd = gcd(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1,num2,ddd);
    if(ddd==1){
        printf("----------------------------------------------\n");
        printf("It is relatively prime.\n");
    }
    else{
        printf("----------------------------------------------\n");
        printf("It is not relatively prime.\n");
    }
    printf("----------------------------------------------");
    return 0;
}

