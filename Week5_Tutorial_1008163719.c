#include <stdio.h>

void makeItLoud(char *src){
    char *counter = src;
    char *end;
    // Finding the pointer to the end of the string
    while(*counter != '\0'){
        counter++;
    }
    end = counter;
    counter = src;
    
    while(*counter != '\0'){
        // Not excluding tabs & new lines yet
        if ((*(counter-1) != ' ') && (*(counter) == ' ') && (counter != src)){
            end++;
            for(char *i = end; i > counter; i--){
    	       	*i = *(i-1); 
            }
            *counter = '!';
            counter+=2;
        }
        else{
            counter++;
        }
        
    }
}

int main()
{
    char source[1024]="    silence! .is a looking bird:the turning; edge, of life. e. e. cummings   ";
    printf("The original string is: \n%s\n",source);
    makeItLoud(&source[0]);
    printf("Loud version of the string: \n%s\n",source); 
    return 0;
}