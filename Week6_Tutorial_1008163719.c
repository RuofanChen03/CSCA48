#include <stdio.h>
#include <stdlib.h>

/* Define StringList CDT with the following entries
//  character:  char type
//  new:        pointer to the next StringList node
*/
typedef struct StringList {
	char character;
	struct StringList* next;
} StringList;

// Return a new StringList node with the char c inside
StringList *newNode(char c) {
    StringList *node = (StringList*)calloc(1, sizeof(StringList));
	node -> character = c;
	node -> next = NULL;
	return node;
}

// Create a new StringList node and insert at the end of the linked list
void insertAtTail(StringList *head, char c) {
    StringList *traverse = head;
	while(traverse->next != NULL){
		traverse = traverse -> next;
	}
	// traverse is at the last node of the linked list
	
	StringList *newNode = newNode(c);
	traverse->next = newNode;
	// return head;
}

// Covert the string to a linked list
// "abc" becomes a->b->c
StringList *toStringList(char *input) {

}

// Traverse through the linked list and print
void printList(StringList *head) {
    while (head != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

// Delete the first occurence of c from the linked list
StringList *deleteChar(StringList *head, char c) {
	if (head->character == c){
		StringList *newHead = head->next;
		free(head);
		return newHead;
	}
	StringList *traverse = head->next;
	StringList *previous = head;
	while(traverse != NULL){
		if (traverse->character == c){
			previous->next = traverse->next;
			free(traverse);
			return head;
		}
		traverse = traverse -> next;
		previous = previous -> next;
	}
	return head;
}

/*  EXERCISE 
//  Given the head of a linked list, 
//  return a new list where the order is reversed.
*/
StringList *reverse(StringList *head) {
    // Not done
	// insert at head
}

int main() {
    // Add tests here
	
}