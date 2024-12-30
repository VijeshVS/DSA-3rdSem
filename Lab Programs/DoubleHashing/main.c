#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {-1}; // Initialize all elements to -1

void insert()
{
    int key, index, i, flag = 0, hkey, hash2;
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;
    hash2 = 7 - (key % 7); // Second hash function

    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * hash2) % TABLE_SIZE;
        if (h[index] == -1) // Check for an empty slot
        {
            h[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            flag = 1; // Successfully inserted
            break;
        }
    }

    if (!flag) // If no empty slot is found
        printf("\nElement cannot be inserted (Table is full)\n");
}

void search()
{
    int key, index, i, flag = 0, hash2, hkey;
    printf("\nEnter the value to search: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;
    hash2 = 7 - (key % 7); // Second hash function

    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * hash2) % TABLE_SIZE;
        if (h[index] == key) // Check if the value is found
        {
            printf("Value %d is found at index %d\n", key, index);
            flag = 1;
            break;
        }
        else if (h[index] == -1) // Stop searching if an empty slot is found
        {
            break;
        }
    }

    if (!flag)
        printf("\nValue %d is not found in the hash table\n", key);
}

void display()
{
    int i;
    printf("\nElements in the hash table are:\n");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (h[i] != -1)
            printf("Index %d: %d\n", i, h[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main()
{
    int opt;

    for(int i = 0;i<TABLE_SIZE;i++){
        h[i] = -1;
    }

    while (1)
    {
        printf("\nPress 1. Insert\t 2. Display\t 3. Search\t 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}
