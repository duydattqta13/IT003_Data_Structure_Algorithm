#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *next;
};

struct node *even = NULL;
struct node *odd = NULL;
struct node *list = NULL;

void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   struct node *current;

   link->data = data;
   link->next = NULL;

   if(list == NULL) {
      list = link;
      return;
   }
   current = list;

   while(current->next!=NULL)
      current = current->next;
   current->next = link; 
}

void display(struct node *head) {
   struct node *ptr = head;

   cout<<"[head] =>";
   while(ptr != NULL) {        
      cout<<" %d =>"<<ptr->data;
      ptr = ptr->next;
   }

   cout<<" [null]\n";
}

void split_list() {
   struct node *link;
   struct node *current;

   while(list != NULL) {
      struct node *link = (struct node*) malloc(sizeof(struct node));

      link->data = list->data;
      link->next = NULL;

      if(list->data%2 == 0) {
         if(even == NULL) {
            even = link;
            list = list->next;
            continue;
         } else {
            current = even;

            while(current->next != NULL)
            current = current->next;

            current->next = link; 
         }
         list = list->next;
      
      } else {
         if(odd == NULL) {
            odd = link;
            list = list->next;
            continue;
         } else {
            current = odd;
            while(current->next!=NULL)
            current = current->next;

            current->next = link; 

         }
         list = list->next;
      }
   }
}
    
int main() {
   int i;

   for(i = 1; i <= 10; i++)
      insert(i);

   cout<<"Complete list: \n";
   display(list);

   split_list();

   cout<<"\nOdd  : ";
   display(odd);

   cout<<"Even : ";
   display(even);

   return 0;
}