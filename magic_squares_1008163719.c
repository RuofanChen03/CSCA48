////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>


void fillCol(int square[6][6], int sum, int colNum, int lineSum){
	// Fills the column using the given sums.
	for(int j = 0; j<6; j++){
		if (square[j][colNum] == -1){
			square[j][colNum] = sum-lineSum;
		}
	}
}

void fillRow(int square[6][6], int sum, int rowNum, int lineSum){
	// Fills the row using the given sums.
	for(int j = 0; j<6; j++){
		if (square[rowNum][j] == -1){
			square[rowNum][j] = sum-lineSum;
		}
	}
}

int findNumOfBlank(int square[6][6]){
	// Finds & returns the number of blanks in the square.
	int counter = 0;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j<6; j++){
			if (square[i][j] == -1){
				counter++;
			}
		}
	}
	return counter;
}

int findSum(int square[6][6]){
	// Finds & returns the sum of the row/col/diagonal.
	// Assumption: there is at least 1 col/row/diagonal which is full
	// (because there are "no guessing element involved").
	// Also, the magic square should only have 1 unique solution.
	int hasCompleteRow, hasCompleteCol,hasCompleteDiag1, hasCompleteDiag2;
	int	sum, sum2;
	
	// Check if matrix has complete row
	for(int i = 0; i < 6; i++){
		hasCompleteRow = 1;
		sum = 0;
		for(int j = 0; j<6; j++){
			if (square[i][j] == -1){
				hasCompleteRow = 0;
			}
			else{
				sum += square[i][j];
			}
		}
		if(hasCompleteRow){
			return sum;
		}
	}
	
	// Check if matrix has complete column
	for(int j = 0; j < 6; j++){
		hasCompleteCol = 1;
		sum = 0;
		for(int i = 0; i < 6; i++){
			if (square[i][j] == -1){
				hasCompleteCol = 0;
			}
			else{
				sum += square[i][j];
			}
		}
		if(hasCompleteCol){
			return sum;
		}
	}
	
	// Check if matrix has complete diagonal
	hasCompleteDiag1 = 1;
	hasCompleteDiag2 = 1;
	sum = 0;
	sum2 = 0;
	for(int i = 0; i < 6; i++){
		if (square[i][i] == -1){
			hasCompleteDiag1 = 0;
		}
		else{
			sum += square[i][i];
		}
		if (square[i][5-i] == -1){
			hasCompleteDiag2 = 0;
		}
		else{
			sum2 += square[i][5-i];
		}
	}
	if(hasCompleteDiag1){
		return sum;
	}
	else if(hasCompleteDiag2){
		return sum2;
	}
	return -1;
}

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////
	int sum = findSum(square);
	int counter = findNumOfBlank(square);
	int blankCount, lineSum;
	while ((counter > 0) && (sum != -1)){
		for(int i = 0; i < 6; i++){
			blankCount = 0;
			lineSum = 0;
			for(int j = 0; j<6; j++){
				if (square[i][j] == -1){
					blankCount++;
				}
				else{
					lineSum += square[i][j];
				}
			}
			if (blankCount == 1){
				fillRow(square, sum, i, lineSum);
				counter--;
			}
		}
		for(int j = 0; j < 6; j++){
			blankCount = 0;
			lineSum = 0;
			for(int i = 0; i<6; i++){
				if (square[i][j] == -1){
					blankCount++;
				}
				else{
					lineSum += square[i][j];
				}
			}
			if (blankCount == 1){
				fillCol(square, sum, j, lineSum);
				counter--;
			}
		}
	}
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
