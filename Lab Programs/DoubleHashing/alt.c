#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 10;
int HASH_TABLE[100];

void hashTableInit(){
    for(int i = 0;i<MAX_SIZE;i++){
        HASH_TABLE[i] = -1;
    }
}

int hashFunction1(int key){
    // 2k+7
    return (2*key+7) % MAX_SIZE;
}

int hashFunction2(int key){
    // k+2
    return (key+2) % MAX_SIZE;
}

int hash(int key,int prob){
    return (hashFunction1(key) + hashFunction2(key)*prob) % MAX_SIZE;
}

void insert(int data){
    int i = 0;

    for(i = 0;i<=MAX_SIZE-1;i++){
        int hashed = hash(data,i);
        if(HASH_TABLE[hashed] == -1){
            HASH_TABLE[hashed] = data;
            printf("\nData %d was inserted at key %d",data,hashed);
            break;
        }
    }

    if(i == MAX_SIZE){
        printf("\nData %d could not be inserted",data);
    }
}

void search(int data){
    int i = 0;

    for(i = 0;i<=MAX_SIZE-1;i++){
        int hashed = hash(data,i);
        if(HASH_TABLE[hashed] == data){
            printf("\nData %d was found at key %d",data,hashed);
            break;
        }
    }

    if(i == MAX_SIZE){
        printf("\nData was not found in the hash table");
    }
}

void display(){
    printf("\nHash table is displayed as below");
    for(int i = 0;i<MAX_SIZE;i++){
        printf("\nKey %d: ",i);
        HASH_TABLE[i] == -1 ? printf("EMPTY") : printf("%d",HASH_TABLE[i]);
    }
    printf("\n");
}

int main(){
    hashTableInit();
    insert(30);
    insert(40);
    insert(20);

    display();
}