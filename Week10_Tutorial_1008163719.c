
// Week 10 Tutorial Notes
// - Recursion
	// - functions calls itself
	// - base case (stopping condition) & recursive cases (function calls itself)
	// - every iterative program can be written in recursion style
	// - sometimes doing recursion is easier
		// - e.g., tree traversal
	
// - Questions to solve
	int factorial(int i){
		int product = 1;
		while (i != 0){
			product *= i;
			i--;
		}
		return product;
	}
	int factRec(int i){
		if (i==1){
			return 1;
		}
		return i*factRec(i-1);
	}
	
	int maxArray(int array[], int length){
		int max = array[0];
		for(int i = 1; i < length; i++){
			if (max < array[i]){
				max = array[i];
			}
		}
		return max;
	}
	int maxArrayRec(int array[], int length){
		if (length == 1){
			return array[0];
		}
		// My solution through online research of max program/command in c
		// return (array[length-1] > maxArrayRec[array, length-1] ) ? array[length-1] : maxArrayRec[array, length-1];
		int maxRest = maxArray(array, length-1);
		if (array[length-1] > maxRest){
			return array[length-1];
		}
		return maxRest;
	}
	
	int isPalindrome(char *str, int count){
		// start with count = 0
		int len = strlen(s);
		
		if (count >= (len/2)){
			return 1;
		}
		if (*(str+count) != *(str+len-1-count)){
			return 0;
		}
		isPalindrome(str, count+1);
	}