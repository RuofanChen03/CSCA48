/*
GDP Walkthrough - https://www.cs.umd.edu/~srhuang/teaching/cmsc212/gdb-tutorial-handout.pdf
Extra - https://www.cs.toronto.edu/~krueger/csc209h/tut/gdb_tutorial.html
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BankReserveStruct
{
    float USD;
    float CAD;
    float AUD;
    float RUBLE;
} BankReserve;

typedef struct BankNodeStruct
{
    BankReserve reserves;
    char name[1024];
    struct BankNodeStruct *next;
} BankNode;

BankNode *new_bank(BankNode *head, char *name, float USD, float CAD, float AUD, float RUBLE)
{
    BankNode *new_node = (BankNode *)calloc(1, sizeof(BankNode));
    strcpy(new_node->name, name);
    new_node->reserves.USD = USD;
    new_node->reserves.CAD = CAD;
    new_node->reserves.AUD = AUD;
    new_node->reserves.RUBLE = RUBLE;
	new_node->next = head;
    /* new_node->next = ;*/
    return new_node;
}

int main()
{
    BankNode *head = NULL;
    head = new_bank(head, "TD BANK", 10, 10, 10, 0.01);
    head = new_bank(head, "RBC BANK", 50, 0, 0, 1);
    free(head->next);
    free(head);
	return 0;
}