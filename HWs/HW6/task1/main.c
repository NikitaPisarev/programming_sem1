#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sortableList.h"

void printActions()
{
    printf(" ------------------------------------\n");
    printf(" 0 - Exit\n");
    printf(" 1 - Add a value to the sorted list\n");
    printf(" 2 - Remove a value from the list\n");
    printf(" 3 - Print the sorted list\n");
    printf(" 4 - View the list of commands\n");
    printf(" ------------------------------------\n");
}

int main()
{
    List *list = listCreate();
    if (list == NULL)
    {
        printf("Memory allocation error.\n");
        return 0;
    }

    printf("Hi, that's what i can do:\n");
    printActions();

    int errorCode = 0;
    int action = -1;
    bool isContinue = true;
    while (isContinue)
    {
        printf("Enter the command number: ");
        scanf("%d", &action);

        switch (action)
        {
        case 0:
            printf("Good luck!\n");
            isContinue = false;
            break;
        
        case 1:
            Value addValue = 0;
            printf("Enter the value you want to add to the list: ");
            scanf("%d", &addValue);
            if ((errorCode = addElement(list, addValue)) != 0)
            {
                printf("The addElement function failed with error %d.\n", errorCode);
                isContinue = false;
            }
            printf("The value %d was successfully added.\n", addValue);
            break;
        
        case 2:
            Value popValue = 0;
            printf("Enter the value you want to remove from the list: ");
            scanf("%d", &popValue);
            if ((errorCode = pop(list, popValue)) == -3)
            {
                printf("There is no such value in the list.\n");
                continue;
            }
            else if (errorCode != 0)
            {
                printf("The pop function failed with error %d.\n", errorCode);
                isContinue = false;
            }
            printf("Value %d has been successfully deleted.\n", popValue);
            break;
        
        case 3:
            printf("List:\n");
            printList(list);
            break;

        case 4:
            printActions();
            break;

        default:
            printf("There is no such command :(\n");
            break;
        }
    }
    
    freeList(list);
    return 0;
}