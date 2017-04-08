void rreverse(struct Node** head)
{
	if(*head==NULL)
		return;

	struct Node* first = *head;
	struct Node* rest = (*head)->next;

	if(rest==NULL)
		return;

	rreverse(&rest);

	first->next->next = first;
	first->next = NULL;

	*head = rest;
}