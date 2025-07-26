#include "in2post.h"
#include "postcal.h"
#include <string.h>
#include <stdio.h>

#define MAX_LEN 100
int main(void){
    char input[MAX_LEN];
    char result[MAX_LEN];
    memset(result, 0, MAX_LEN);
    fgets(input, MAX_LEN, stdin);
    input[strlen(input)-1] = 0;

    printf("1. test converting\n");
    conv2post(result, input);
    printf("input: %s\n", input);
    printf("result: %s\n", result);

    printf("2. test calculation\n");
    int val = postcal(result);
    printf("result: %d\n", val);
    
    return 0;
}