#include <iostream>

struct node {
	int data;
	struct node* next;
};

void addBegin(struct node** head, int val) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = *head;
	*head = newNode;
}

void addLast(struct node** head, int val) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;

	if (NULL == *head) {
		*head = newNode;
		return;
	}

	struct node* trav = *head;
	while(trav->next != NULL) trav = trav->next;

	trav->next = newNode;
}

void delBegin(struct node** head) {
	if (*head == NULL) {
		std::cout << "Emplty list\n";
	}

	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}

	struct node* tmp = *head;
	*head = tmp->next;
	free(tmp);
}

void delEnd(struct node** head) {
	if (*head == NULL) {
		std::cout << "Empty list\n";
	}

	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}

	struct node* trav = *head;
	while(trav->next->next != NULL) trav = trav->next;
	free(trav->next);
	trav->next = NULL;
}

void display(struct node* head) {
	if (head == NULL) {
		std::cout << "Empty list\n";
		return;
	}

	struct node* trav = head;

	while(trav->next != NULL) {
		std::cout << trav->data << "\t";
		trav = trav->next;
	}
	printf("%d\t",trav->data);
	std::cout << std::endl;
}

void reverse(struct node** head) {
	struct node* prev = NULL;
	struct node* current = *head;
	struct node* next;
	
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main() {
	struct node* head = NULL;
	addBegin(&head, 30);
	addLast(&head, 10);
	addLast(&head, 20);
	addLast(&head, 30);
	addLast(&head, 40);
	addBegin(&head, 50);
	addBegin(&head, 60);
	display(head);
	reverse(&head);
	/*delBegin(&head);
	delEnd(&head);
	display(head);
	delBegin(&head);
	delEnd(&head);
	display(head);
	delBegin(&head);
	delEnd(&head);*/
	display(head);
	return 0;
}