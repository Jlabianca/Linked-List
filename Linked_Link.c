//Linked Lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char data[255];
	struct Node* next;
};

//"deleteNode" has to deal with the del command.
//If the list contains a node whose index is equal 
//to the number specified in the command, then the 
//node must be DELETED from the list
void deleteNode(int index , struct Node** Head)
{
    if(*Head == NULL)
    {
        printf("No such index\n");
        return;
    }
    if(index == 1)
    {
        struct Node* temp = *Head;
        (*Head) = (*Head)->next;
        free(temp);
        printf("Deleted\n");
        return;
    }
    struct Node* temp = *Head;
    struct Node* prev = temp;
    temp = temp->next;
    int current = 2;
    while(temp != NULL)
    {
        if(index == current)
        {
            prev->next = temp->next;
            free(temp);
            printf("Deleted\n");
            return;
        }
        current++;
        temp= temp->next;
        prev = prev->next;
    }
    printf("No such index\n");
    
}
//"insertAfter" has to deal with the ina command which
//inserts a new node into the list AFTER a node whose 
//index is equal to the number specified in the command 
void insertAfter(char data[], int index, struct Node** Head)
{
	struct Node* temp = *Head;
	if (*Head == NULL)
	{
		*Head = (struct Node*)malloc(sizeof(struct Node));
		strcpy((*Head)->data, data);
		(*Head)->next = NULL;
		printf("Text inserted at the end.\n");
		return;
	}
	int current = 1;
	while (temp != NULL)
	{
		if (!strcmp(temp->data, data))
		{
			printf("Such text exists already.\n");
			return;
		}
		temp = temp->next;
	}
	temp = *Head;
	while (temp != NULL)
	{
		if (current == index)
		{
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->next = temp->next;
			temp->next = new_node;
			strcpy(new_node->data, data);
			printf("Ok\n");
			return;
		}
		if (temp->next == NULL)
		{
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->next = temp->next;
			strcpy(new_node->data, data);
			printf("Text inserted at the end\n");
			return;
		}
		current++;
		temp = temp->next;
	}
}
//this prints the Node
void print(struct Node* Head)
{
    struct Node* temp = Head;
    int index = 1;
    while(temp != NULL)
    {
        printf("%d %s\n", index, temp->data);
        index++;
        temp = temp->next;
    }
}
//"insertBefore" has to deal with the inb command which
//inserts a new node into the list BEFORE a node whose 
//index is equal to the number specified in the command
void insertBefore(char data[], int index, struct Node** Head)
{
	struct Node* temp = *Head;
	if (*Head == NULL)
	{
		*Head = (struct Node*)malloc(sizeof(struct Node));
		strcpy((*Head)->data, data);
		(*Head)->next = NULL;
		printf("Text inserted at the beginning.\n");
		return;
	}
	while (temp != NULL)
	{
		if (!strcmp(temp->data, data))
		{
			printf("Such text exists already.\n");
			return;
		}
		temp = temp->next;
	}
	if (index == 1)
	{
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->next = *Head;
		strcpy(new_node->data, data);
		*Head = new_node;
		printf("Ok\n");
		return;
	}
	int current = 2;
	temp = *Head;
	while (temp != NULL)
	{
		if (current == index && temp->next != NULL)
		{
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->next = temp->next;
			temp->next = new_node;
			strcpy(new_node->data, data);
			printf("Ok\n");
			return;
		}
		if (temp->next == NULL)
		{
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		    new_node->next = *Head;
		    strcpy(new_node->data, data);
		    *Head = new_node;
			printf("Text inserted at the beginning.\n");
		}
		current++;
		temp = temp->next;
	}
}

//"replace" has to deal with the rep command.
//If the list contains a node whose index 
//is equal to the number specified in the command, 
//then the node text must be REPLACED with the text specified in the command
void replace(char data[], int index, struct Node** Head)
{
	struct Node* temp = *Head;
	while (temp != NULL)
	{
		if (!strcmp(temp->data, data))
		{
			printf("Such text exists already.\n");
			return;
		}
		temp = temp->next;
	}
	int current = 1;
	temp = *Head;
	while (temp != NULL)
	{
		if (current == index)
		{
			strcpy(temp->data, data);
			printf("Replaced\n");
			return;
		}
		current++;
		temp = temp->next;
	}
	printf("No such index\n");
}

int main()
{
	char command[4];
	struct Node* Head = NULL;
	while (1)
	{
	    printf("Command? ");
		scanf("%s", command);
		if (!strcmp(command, "ina"))//inserts after
		{
			int num;
			scanf("%d", &num);
			char data[255];
			scanf("%s", data);
			insertAfter(data, num, &Head);
		}
		else if (!strcmp(command, "inb"))//inserts before
		{
			int num;
			scanf("%d", &num);
			char data[255];
			scanf("%s", data);
			insertBefore(data, num, &Head);
		}
		else if (!strcmp(command, "del"))//deletes a node
		{
			int num;
			scanf("%d", &num);
			deleteNode(num, &Head);
		}
		else if (!strcmp(command, "rep"))//replaces a node
		{
		    int num;
			scanf("%d", &num);
			char data[255];
			scanf("%s", data);
		    replace(data, num, &Head);
		}
		else if (!strcmp(command, "prn"))//prints the list
		{
		    print(Head);
		}
		else if (!strcmp(command, "end"))//stops the program
		{
		    break;
		}
	}
}
