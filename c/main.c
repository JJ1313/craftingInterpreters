/*
* ====== TODO ======
* Insert
*
*/

#include <stdio.h>
#include <string.h>
 
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
void showList(doublyLinkedList list){
  node_dl* temp = list.head;
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
int insertDoublyLinkedList(doublyLinkedList* list, char* word, int pos){
  return 0;
}

// Find
int findDoublyLinkedList(doublyLinkedList* list, char* word){
  int i = 0;
  node_dl* temp = list->head;

  while(temp){
    if(strcmp(word, temp->word) == 0){
      printf("Searching...\n");
      printf("'%s' is at position %d\n", word, i);
      return i;
    }
    i += 1;
    temp = temp->next;
  }
  return -1;
}

// Delete
int deleteDoublyLinkedList(doublyLinkedList* list, char* word){
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
  node_dl n1, n2, n3;
  
  strcpy(n1.word, "Many");
  strcpy(n2.word, "is");
  strcpy(n3.word, "fat");
 
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;
  
  n1.prev = NULL;
  n2.prev = &n1;
  n3.prev = &n2;

  l1.head = &n1;
  l1.tail = &n3;

  showList(l1);
  findDoublyLinkedList(&l1, "is");
  deleteDoublyLinkedList(&l1, "is");
  showList(l1);
  insertDoublyLinkedList(&l1, "es", 1);
  showList(l1);
  return 0;
}
