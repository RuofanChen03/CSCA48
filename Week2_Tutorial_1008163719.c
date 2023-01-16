#include <stdio.h> //Importing standard C library.
#include <math.h> //Importing the math library.

int main()
{
    for(float i = 0; i < 2*M_PI; i += 0.25){
		int WIDTH = 15;
		float sinx = sin(i);
// 		if (fabs(sinx) < 0.75 && fabs(sinx) > 0.5){
// 			printf("%.3f\n", sinx);
// 		}
		for(int j = 0; j < 2 * WIDTH; j += 1){
			if (j == (int)(sinx * WIDTH) + WIDTH){
				printf("*");
			}
			else if (j == WIDTH){
				printf("|");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
    // system("pause");
	return 0;
}