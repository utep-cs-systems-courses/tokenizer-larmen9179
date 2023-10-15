#ifndef _HISTORY_
#define _HISTORY_

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){

  List *tokenHist = malloc(sizeof(List));

  tokenHist->root = NULL;

  return tokenHist;
  
}
/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){

  /*Finding the length by iterating*/
  int tokenLen;
  
  for(tokenLen = 0;str[i] != '\0';i += 1){
    ;
  }

  char *newItemPtr = copy_str(str, tokenLen);

  int nodeId = 0;

  Item *currentItem = list -> root;

  /*Checking if the root is empty*/
  if(currentItem == NULL){

    currentItem = malloc(sizeof(Item));
    
    currentItem->id = 0;
    
    currentItem->str = newItemPtr;

    currentItem->next = NULL;

    list->root = currentItem;

    return;
  }

  /*Iterating if the root isn't empty*/
  while(currentItem->next != '\0'){
    
    nodeId += 1;

    /*??????????*/
    currentItem = currentItem->next;
  }

  /*Allocating a new node once we've reached the end*/

  currentItem->next = malloc(sizeof(Item));

  currentItem->next->id = nodeId;

  currentItem->next->str = newItemPtr;

  currentItem->next->next = '\0';
  
}
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){

  Item *currentItem = list->root;

  while(currentItem != '\0'){
    
    if(currentItem->id == id){
      
      return currentItem->str;
    }

    currentItem = currentItem->next;
  }
  /*Returning an empty string if id is not found*/
  printf("String is not in the history");
  return "";
}
/*Print the entire contents of the list. */
void print_history(List *list){

  Item *currentItem = list->root;

  while(currentItem != '\0'){

    printf("Node %d - %s\t", currentItem->id, currentItem->str);
    currentItem = currentItem->next;
  
  
  }
  
}
/*Free the history list and the strings it references. */
void free_history(List *list){

  Item *currentItem = list->root;
  Item *itemToDelete;

  while(currentItem != '\0'){
  
    itemToDelete = currentItem;

    free(itemToDelete);

    currentItem = currentItem->next;
  }

  free(list);

}
#endif
