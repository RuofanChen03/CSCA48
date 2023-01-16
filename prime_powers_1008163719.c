#include <stdio.h> //Importing standard C library.
#include <stdbool.h> //Importing boolean library.

float power(float x, int p){
    float result = 1;
    for (int i = 1; i <= p; i++){
        result *= x;
    }
    return result;
}

int main()
{
    for (int i = 2; i < 100; i++){
        bool is_prime = true;
        for (int j = 2; j < i; j++){
            if (i%j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            printf("p=%d, 1.4142^%d = %f\n", i, i, power(1.4142, i));
        }
    }
    system("pause");
	return 0;
}