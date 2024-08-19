/*
* ====== TODO ======
* Insert
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ======= DOUBLY LINK LIST ======
// Node
struct DoublyLinkedNode {
  char word[30];
  struct DoublyLinkedNode* prev;
  struct DoublyLinkedNode* next;
}; 
typedef struct DoublyLinkedNode node_dl;
// List 
struct DoublyLinkedList {
  node_dl* head;
  node_dl* tail;
};
typedef struct DoublyLinkedList doublyLinkedList;

// Mostrar 
void showList(doublyLinkedList* list){
  node_dl* temp = list->head;
  if(temp == NULL){
    printf("Empty list\n");
    return;
  }
  while(temp){
    if(temp->next){
      printf("%s ", temp->word);
    }
    else{
      printf("%s", temp->word);
    }
    temp = temp->next;
  }
  printf("\n");
}

// Insert
int insert(doublyLinkedList* list, char* word, int pos){
  node_dl* temp = list->head;
  int i = 0;
  node_dl* node = (node_dl*) malloc(sizeof(node_dl));
  if (node == NULL){
    printf("Error: Memory allocation failure");
    return -1;
  }
  strcpy(node->word, word);
  // Handle empty list
  node->prev = NULL;
  node->next = NULL;
  if(temp == NULL){
    list->tail = node;
    list->head = node;
    return 0;
  }
  while(temp){
    if(i == pos){
      // Inserting at the start of the list
      if(temp->prev == NULL){
        list->head = node;

        node->next = temp;

        temp->prev = node;
      }
      // Inserting inside the list
      else{
        node->prev = temp->prev;
        node->next = temp;

        temp->prev->next = node;
        temp->prev = node;
      }
      return 0;
    }
    i += 1 ;
    temp = temp->next;
  }
  // Inserting at the end of the list, doesn't matter if it's out of bound
  if(temp == NULL){
    node->prev = list->tail;

    list->tail->next = node;
    list->tail = node;
  }
  return 0;
}

// Find
int find(doublyLinkedList* list, char* word){
  int i = 0;
  node_dl* temp = list->head;

  printf("Searching...\n");
  while(temp){
    if(strcmp(word, temp->word) == 0){
      printf("'%s' is at position %d\n", word, i);
      return i;
    }
    i += 1;
    temp = temp->next;
  }
  printf("'%s' is not in the list\n", word);
  return -1;
}

// Delete
int delete(doublyLinkedList* list, char* word){
  node_dl* temp = list->head;
  while(temp){
    if(strcmp(word, temp->word) == 0){
      printf("Deleting...\n");
      if(temp->prev == NULL){
        list->head = temp->next;  
      }
      else{
        temp->prev->next = temp->next;
      }
      if(temp->next == NULL){
        list->tail = temp->prev;
      }
      else{
        temp->next->prev = temp->prev;
      }
      return 0;
    }
    temp = temp->next;
  }
  return -1;
}

// ====== END DOUBLY LINK LIST ======

// ====== MAIN ======
int main(){
  doublyLinkedList l1;
  
  showList(&l1);
  // find(&l1, "is");
  // delete(&l1, "is");
  // showList(&l1);
  insert(&l1, "Many", -1);
  insert(&l1, "is", -1);
  insert(&l1, "fat", -1);
  showList(&l1);
  return 0;
}
