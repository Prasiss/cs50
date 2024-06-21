#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node *node;

} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->node = NULL;
    }
    if (list == NULL)
    {
        list =n;
    }
    else if (n->number < list->number)
    {
        n->node =list;
        list=n;
    }
    else
    {
        for (node *ptr =list; ptr!= NULL; ptr= ptr->node)
        {
            //if at the end of list
            if (ptr->node == NULL)
            {
                ptr->node=n;
                break;
            }
            // if at the middle of the list
            if (n->number < ptr->node->number)
            {
                n->node=ptr->node;
                ptr->node =n;
                break;
            }
        }
    }
}
