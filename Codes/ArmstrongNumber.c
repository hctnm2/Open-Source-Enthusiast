#include <stdio.h>
int main() {
    int num, n1, remainder, result = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    n1 = num;

    while (n1 != 0) {
      
        remainder = n1 % 10;
        
       result += remainder * remainder * remainder;
        
      
       n1/= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}
