#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define MAX 100

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == ' ' || c == '\t');
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (!space_char(c) );
}
/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){

  while(*str != '\0'){
    if(non_space_char(*str)){
      return str;
    }
    else{
      str += 1;
    }
  }
  
  str = 0;
  return (str);
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){

  while(non_space_char(*token)){
    /*This print statement is for testing output*/
    printf("%c\n", *token);
    token++;
  }
  
  return token;
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){

  int count = 0;
  char *check; 

  check = str;
  
  while((check = token_start(check)) != NULL){
    check = token_terminator(check);
    count += 1;
  }

  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){

  /*Allocates memory for the character and returns it as a pointer, malloc usually returns void*/
  /* (len + 1) is to include the zero terminator with string allocation */
  char *permPointer = (char * ) malloc((len + 1) * sizeof(char));

  for(int i = 0;i < len;i += 1){
    permPointer[i] = inStr[i];
  }

  permPointer[len] = '\0';

  return permPointer;
  
  
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){

  /*Initilizing length to use for iterating over the character*/
  int wordCount, currLen;

  wordCount = count_tokens(str);

  char **tokens = malloc((wordCount + 1) * sizeof(char * ));

  char *tokenTemp = str;

  for(int i = 0;i < wordCount;i += 1){
    tokenTemp = token_start(tokenTemp);

    currLen = token_terminator(tokenTemp) - tokenTemp;

    tokens[i] = copy_str(tokenTemp, currLen);

    tokenTemp += currLen;
  
  }
  tokens[wordCount] = '\0';
  
  return tokens;
  
}
/* Prints all tokens. */
void print_tokens(char **tokens){
  
  for(int i = 0;tokens[i] != NULL;i += 1){
    printf(tokens[i]);

    putchar('\n');
  }
}
 
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){

  for(int i = 0;tokens[i] != NULL;i += 1){
    free(tokens[i]);
  }
  free(tokens);
}
