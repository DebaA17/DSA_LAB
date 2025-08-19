#include<stdio.h>
#include<stdlib.h>
 struct node
 {
   int info;
   struct node *next;
   };
   struct node *start = NULL;
   
   
   void createlist()
   {
    if(start == NULL)
    { 
    int n,j,i,data;
    printf("Entr no.of element:");
    scanf("%d",&n);
    struct node *newnode;
    struct node *temp;
    newnode = malloc(sizeof(struct node));
    start = newnode;
    temp = start;
    printf("Enter data for first node");
    scanf("%d",&data);
    newnode -> info = data;
     for(i=2;i<=n;i++)
     {
      newnode = malloc(sizeof(struct node));
      temp -> next = newnode;
      printf("Enter data for next node");
      scanf("%d",&data);
      newnode -> info = data;
      temp = temp -> next;
      temp -> next = NULL;
      }
     }
     }
     
      
      void display()
      {
       struct node *temp;
       temp = start;
       while(temp!=NULL)
       {
        printf("%d ",temp->info);
        temp = temp -> next;
       }
       }
       
       void insfirst()
       {
        struct node *new;
        int data ;
        new = malloc (sizeof(struct node));
        printf("Enter the data from new node");
        scanf("%d", &data);
        new -> info = data;
        new -> next = start;
        start = new;
        }
        
        void inslast()
        {
         struct node *new, *temp;
        int data;
        new = malloc(sizeof(struct node));
        printf("Enter the data from new node");
        scanf("%d",&data);
        new -> info = data;
        temp = start;
        while (temp->next != NULL)
        {
         temp=temp -> next;
        }
         temp-> next = new;
         new-> next = NULL;
        }
        
        void insmid()
        {
         struct node *new,*temp;
         int data, pos, i=1;
         new =  malloc(sizeof(struct node));
        printf("Enter the data from new node");
        scanf("%d",&data);
        printf("Enter the position to insert new node");
        scanf("%d",&pos);
        new -> info = data;
        temp = start;
        while (i<pos)
        {
         temp= temp -> next;
         i++;
         }
         new -> next = temp -> next;
         temp -> next = new;
         }
         
       void deletefirst()
       {
        struct node *temp;
        if (start == NULL)
        printf("The list is empty");
        else 
         {
         temp = start;
         start = start -> next;
         free(temp);
         }
         }
 
      void deletend()
      {
       struct node *temp, *last;
        if (start == NULL)
        printf("The list is empty");
        else 
        {
          temp = start;
          while (temp -> next != NULL)
          {
           last = temp;
           temp = temp -> next;
           }
           free (temp);
           last -> next = NULL;
           }
           }
        
        void deleteany()
        { 
         struct node *temp,*ptr;
         int i=1,pos;
        if (start == NULL)
        printf("The list is empty");
        else 
        {
         printf("Enter Position ");
         scanf ("%d",&pos);
         temp = start;
         while (i<pos-1)
         {
           temp = temp -> next;
           i++;
          }
          ptr = temp -> next;
          temp -> next = ptr -> next;
          free (ptr);
          }
         }
        
        
        
       int main()
       {
       int choice;
       while(1){
       printf("\n MENU...............................................");
       printf("\n Enter 1 to creat the list");
       printf("\n Enter 2 to insert first position");
       printf("\n Enter 3 to insert last position");
       printf("\n Enter 4 to insert any(mid) position");
       printf("\n Enter 5 to delete first position");
       printf("\n Enter 6 to delete last position");
       printf("\n Enter 7 to delete any(mid) position");
       printf("\n Enter 8 display list");
       printf("\n Enter 9 exit");
       
       
       
       
       printf("\n Enter your choice");
       scanf("%d",&choice);
       switch (choice)
        {
          case 1: createlist();
                 break;
          case 2: insfirst();
                 break;
          case 3: inslast();
                 break;  
          case 4: insmid();
                 break;
          case 5: deletefirst();
                 break; 
          case 6: deletend();
                 break;               
          case 7: deleteany();
                 break;                     
          case 8: display();
                  break;
           case 9:exit(1);
           default : printf("Invalid choice");
           }
     }
  }       
               
                  
        
        
         
         
      
   
