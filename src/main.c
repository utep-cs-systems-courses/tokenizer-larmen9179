#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

main(){

  char option[3];
  char stringUser[100];
    
  List *history = init_history();

  while(1){

    printf("Welcome to the tokenizer...");
    putchar('\n');

    printf("Here is the options menu, please input your selection...");
    putchar('\n');

    printf("w: Enter a string\n");
    printf("!h: See history\n");
    printf("!i: Use the '!' symbol and a number instead of i to see a specific history\n");

    putchar('>');

    fgets(option, 3, stdin);
    
    if(*option == 'w'){
      
      printf("Enter in your string: \n");
      putchar('>');
      fgets(stringUser, 100, stdin);

      char **tokenizer = tokenize(stringUser);

      print_tokens(tokenizer);

      add_history(history, stringUser);
    }

    else if(option[0] == '!'){
      if(option[1] == 'h'){

	print_history(history);
	
      }
    }
    else{
      printf("Your selection was invalid, goodbye!!\n");
      break;
    }
  }
  free_history(history);
  return 0;
}
