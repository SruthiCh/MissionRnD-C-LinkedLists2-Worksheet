/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node*temp1, *temp2;
	if (head == NULL)
		return -1;
	temp1 = head;
	temp2 = head;
	while (temp1->next != NULL && temp1->next->next != NULL)
	{
		temp1 = temp1->next->next;
		temp2 = temp2->next;
	}
	if (temp1->next == NULL)
		return temp2->num;
	else
		return ((temp2->num) + (temp2->next->num)) / 2;
}
