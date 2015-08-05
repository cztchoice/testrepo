#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
We assume that tokens has enough columns and rows to store the result
and we donot allocate any space in this function
Directly use this function on the input string make us cannot deal with the
for, while, until, if, and others, because we donot use 
*/
/*int getTokens(char *line, char **tokens, int *arg_count){
    if (NULL == line || NULL == tokens)
    {
        return -1;
    }
    *arg_count = 0;
    int k = 0;
    bool token_begin = false;
    while(line && *line != '\0'){
        if(!isspace(*line)){
            if(!token_begin){
                k = 0;
                token_begin = true;
            }
            tokens[*arg_count][k] = *line;
            k++;
            line++;
        }
        else{
            if(token_begin){
                tokens[*arg_count][k] = '\0';
                (*arg_count)++;
                if(NULL == tokens[*arg_count]){
                    return -1;
                }
                token_begin = false;
            }
            line++;
        }
    }
    // tokens[argc_count] = NULL;
    return 0;
}*/

/*int getTokens(char *line, char **tokens){
    if (NULL == line || NULL == tokens)
    {
        return -1;
    }
    char **it = tokens;
    int num = 0;
    //Like QuickSort's double while loop, this is not a good way to think
    //A single while loop use State Machine is a good idea.
    while(*line != '\0'){
        // while(*line == ' ' || *line == '\t' || *line == '\n'){
        while(*line != '\0' && isspace(*line)){
            *line = '\0';
            line++;
        }
        //This if is to ensure there will not be  empty string in the end of tokens
        if(*line != '\0'){
            *tokens = line;
            tokens++;
        }
        else{
            break;
        }
        //Attention: Here we must check *line not equal to '\0', so we cannot visit out of the string
        // while(*line != '\0' && *line != ' ' &&  *line != '\t' && *line != '\n'){
        while(*line != '\0' && !isspace(*line)){
            line++;
        }
        for(int i = 0;i < num; i++){
            printf("%s\n", it[i]);
        }
    }
    //printf("%s", *(tokens - 1));
    //This place we solve the problem, that the tokens we generate is end with an empty string "",
    //And in Mac OS X, send an empty string to "ls" command will get an error like this:
    //ls: fts_open: No such file or directory
    //So we delete the empty string. 
    // if(strcmp(*(tokens - 1), "") == 0){
    //     tokens--;
    // }

    *tokens = NULL;
    return 0;
}*/

int getTokens1(char *line, char **tokens){
    if (NULL == line || NULL == tokens)
    {
        return -1;
    }
    char **it = tokens;
    int num = 0;
    //Like QuickSort's double while loop, this is not a good way to think
    //A single while loop use State Machine is a good idea.
    while(*line != '\0'){
        // while(*line == ' ' || *line == '\t' || *line == '\n'){
        while(*line != '\0' && isspace(*line)){
            *line = '\0';
            line++;
        }
        //This if is to ensure there will not be  empty string in the end of tokens
        if(*line != '\0'){
            *tokens = line;
            tokens++;
        }
        else{
            break;
        }
        //Attention: Here we must check *line not equal to '\0', so we cannot visit out of the string
        // while(*line != '\0' && *line != ' ' &&  *line != '\t' && *line != '\n'){
        while(*line != '\0' && !isspace(*line)){
            line++;
        }
        for(int i = 0;i < num; i++){
            printf("%s\n", it[i]);
        }
    }
    //printf("%s", *(tokens - 1));
    //This place we solve the problem, that the tokens we generate is end with an empty string "",
    //And in Mac OS X, send an empty string to "ls" command will get an error like this:
    //ls: fts_open: No such file or directory
    //So we delete the empty string. 
    // if(strcmp(*(tokens - 1), "") == 0){
    //     tokens--;
    // }

    *tokens = NULL;
    return 0;
}

//A good example, easy to read and to understand.
//The more important, it's easy to write and debug without many annoying (*line != '\0') like upper one
int getTokens2(char *line, char **tokens){
    if(NULL == line || NULL == tokens){
        return -1;
    }
    bool word_begin = false;
    while(*line != '\0'){
        if(isspace(*line)){
            *line = '\0';
            line++;
            if(word_begin){
                word_begin = false;
            }
        }
        else{
            if(!word_begin){
                word_begin = true;
                *tokens = line;
                tokens++;
            }
            line++;
        }
    }
    tokens = NULL;
    return 0;
}


int main(int argc, char const *argv[])
{
    char * s = "ls /home  \n";
    char * str = (char * )malloc(50 * sizeof(char));
    strcpy(str, s);
    char **tokens = (char **)malloc(20 * sizeof(char *));
    getTokens(str, tokens);
    char **it = tokens;
    while(*it){
        printf("%s\n", *it);
        it++;
    }
    return 0;
}