#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* foo(char *string) {
    char* tmp = strdup(string);
    char shift = tmp[1]-tmp[0];
    
    for(int i=0; i<strlen(tmp); i++) {
        tmp[i] += shift;
    }
    
    return tmp;
}

int main() {
    char* input = "qsncpigleq";
    char* result;

    printf("Input string: %s\n", input);
    
    result = foo(input);
    
    printf("Output string: %s\n", result);
    
    free(result);  // Don't forget to free the memory allocated by strdup
    
    return 0;
}