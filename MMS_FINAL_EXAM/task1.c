#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ITEMS_COUNT 3

typedef struct BankAccount{
    unsigned short number;
    char ownerName[101];
    double availability;
    char currency[5];
}BankAccount;

typedef struct node{
    BankAccount account;
    struct node *next;
}node_t;

char* currencies[]={"EUR","BGN","USD","GBR"};

void randomOwnerName(char *str, size_t len){
    const char alphabet[] = "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(size_t i=0; i<len; i++){
        str[i] = alphabet[rand() % (sizeof(alphabet)-1)];
    }
    str[len] = 0;
    str[0] = toupper(str[0]);
}

void randomize(BankAccount *account, unsigned short number){
    account->number = number;
    int wCount = 2 + rand() % 4;
    char word[21];
    account->ownerName[0] = '\0';

    for(int i=0; i<wCount; i++){
        randomOwnerName(word, 1 + rand() % 20);
        strcat(account->ownerName,word);

        if(i < wCount - 1){
            strcat(account->ownerName, " ");
        }
    }
    account->availability = ((double)rand() / RAND_MAX)*100000;
    strcpy(account->currency,currencies[rand() % (sizeof(currencies)/sizeof(currencies[0]))]);
}

node_t *accCreatelist(){
    node_t *head = NULL;
    node_t *current = NULL;

    for(int i=0; i<ITEMS_COUNT; i++){
        node_t *newNode = (node_t*)malloc(sizeof(node_t));
        randomize(&newNode->account, i+1);

        newNode->next = NULL;

        if(!head){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

double totalBalance(node_t *head){
    if(!head){
        return -1;
    }

    double sum = 0.0;
    while(head){
        sum += head->account.availability;
        head = head->next;
    }
    return sum;
}

node_t *maxBalance(node_t *head){
    if(!head){
        return NULL;
    }
    node_t *maxNode = head;
    double maxAv= head->account.availability;

    while(head){
        if(head->account.availability > maxAv){
            maxAv = head ->account.availability;
            maxNode = head;
        }
        head = head->next;
    }
    return maxNode;
}

void printAccList(node_t *head){
    while(head){
        printf("Account number: %u\n",head->account.number);
        printf("Owner name: %s\n",head->account.ownerName);
        printf("Availability of this cutomer(owner): %.2f %s\n",head->account.availability,head->account.currency);
        printf("\n");

        head = head->next;
    }
}

int main(void){
    srand(time(NULL));
    node_t *accountList = accCreatelist();
    printAccList(accountList);
    printf("\nTotal balance: %.2f\n",totalBalance(accountList));

    node_t *maxAccount = maxBalance(accountList);

    if(maxAccount){
        printf("\nHighest bank account balance is: \n");
        printf("\nOwner name: %s\n",maxAccount->account.ownerName);
        printf("\nAccount NO: %u\n",maxAccount->account.number);
        printf("\nAvailability: %.2f %s\n",maxAccount->account.availability, maxAccount->account.currency);
    }

    return 0;
}