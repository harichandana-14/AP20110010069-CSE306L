#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int size = 0;

struct symbolTable
{
    char label[10];
    int addr;
    struct symbolTable *next;
} * first, *last;

int search(char lab[])
{
    int i, flag = 0;
    struct symbolTable *temp;
    temp = first;
    for (i = 0; i < size; i++)
    {
        if (strcmp(temp->label, lab) == 0)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    
 
 return flag;
 
}

void insert()
{
    int n;
    char l[10];
    printf("Enter the label: ");
    scanf("%s", l);
    n = search(l);
    if(n!=1)
    {
        struct symbolTable *p;
        p = malloc(sizeof(struct symbolTable));
        strcpy(p->label, l);
        printf("Enter the address: ");
        scanf("%d", &p->addr);
        p->next = NULL;
        if (size == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        size++;
         printf("\nSuccessfully inserted\n");
    }
}

void show()
{
    int i;
    struct symbolTable *p;
    p = first;
    printf("\nLABEL\tADDRESS\n");
    for (i = 0; i < size; i++)
    {
        printf("%s\t%d\n", p->label, p->addr);
        p = p->next;
    }
}

void main()
{
    int choice;
    int y;
    int x=0;
    char label[10];
    while(x==0)
    {
        printf("\n....SYMBOL TABLE....\n");
        printf("1.Insert Label\n");
        printf("2.Display\n");
        printf("3.Search Label\n");
        printf("4.END\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
           
            break;
        case 2:
            show();
            break;
        case 3:
            printf("Enter the label to search: ");
            scanf("%s", label);
            y=search(label);
            if (y== 1)
                printf("The label is Present in the symbol table\n");
            else
                printf("The label is not found in the symbol tablel\n");
            
            break;
        case 4:
            x=1;
            exit(0);
        }
    } ;
}
