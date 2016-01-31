/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1,*temp2;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL && head2 != NULL)
		return head2;
	else if(head2 == NULL && head1 != NULL)
		return head1;
	if (head1->num <= head2->num)
	{
		temp1 = head1;
		temp2 = head2;
	}
	else
	{
		temp1 = head2;
		temp2 = head1;
		head2 = temp2;
		head1 = temp1;
	}
	while (temp1->next!= NULL)
	{
		if (temp2->num < temp1->next->num)
		{
			head2 = head2->next;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp2 = head2;
		}
		temp1 = temp1->next;
	}
	if (temp2!=NULL)
		temp1->next = temp2;
	return head1;
}
