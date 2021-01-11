#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct Node{
  char word;
  Node *next;
}*head,*tail;
Node *createNode(char word) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->word=word;
  newNode->next = NULL;
  return newNode;
}
void pushTail(char name) {
  Node *temp = createNode(name);

  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}
void popTail() {
  if(!head) {
    return;
  } else if(head == tail) {
    free(head);
    head = tail = NULL;
  } else {
    Node *temp = head;
    while(temp->next != tail) {
      temp = temp->next;
    }
    temp->next = NULL;
    free(tail);
    tail = temp;
  }
}
void printLinkedList() {
  Node *curr = head;

  while(curr) {
    printf("%c", curr->word);
    curr = curr->next;
  }
}
int main()
{
  printf("==============================\n");
  printf("     Welcome To TextEditor    \n");
  printf("==============================\n");
  printf("To delete just press BackSpace\n");
  printf("To exit just press ESC\n");
  printf("==============================\n\n");
  printf("start typing\n\n");
  system("pause");
  char word;
  while(true)
  {
    printLinkedList();
    word=getch();
    if(word>31&&word<127)
    {
      if(word<59||word>68)
        if(word<69||word>83)
          pushTail(word);
    }

    else if(word=='\r')
      pushTail('\n');

    else if(word==8)
      popTail();

    else if(word==1)
      break;
    system("cls");
  }

}
