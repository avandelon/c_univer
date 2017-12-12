# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "sin_list.h"



singl_list_t *creat_node(int marks[MAX_EXAM], char name[MAX_LEN])
{
	singl_list_t *node = malloc(sizeof(singl_list_t));
	memmove(node->marks, marks, MAX_EXAM*sizeof(int));
	memmove(node->name, name, MAX_LEN*sizeof(char));
	return node;
}

void insert_list(singl_list_t **head, singl_list_t *node)
{	
	node->next = *head;
	*head = node;
}

int load_from_file(FILE *f, int marks[MAX_EXAM], char name[MAX_LEN])
{
	for (int i = 0; i < MAX_EXAM; i++)
	{
		if (fscanf(f, "%d", &(marks[i])) != 1)
			return -1;
	}
	if (fscanf(f, "%s", name) != 1)
		return -1;
	return 0;	
}

void printf_list(singl_list_t *head)
{
	for(; head; head = head->next)
	{
		for (int i = 0; i < MAX_EXAM; i++)
			printf("%d ",head->marks[i]);
		printf("\n%s\n",head->name);
	}	
}

double sred(singl_list_t *node)
{
	double res = 0; 
	for (int i = 0; i < MAX_EXAM; i++)
	{
		res += node->marks[i];
	}	
	return res/MAX_EXAM;
}

double sred_all(singl_list_t *head)
{
	double all_ball = 0;
	int k = 0;
	for(; head; head = head->next)
	{
		all_ball += sred(head);
		k++;
	}
	return all_ball/k;
}

void remove_ball(singl_list_t **head, int ball)
{
	singl_list_t *node = *head;
	singl_list_t *node_prev = NULL;
	singl_list_t *tmp;
	while(node)
	{
		if (sred(node) < ball)
		{
			tmp = node;
			if (node == *head)
				*head = (*head)->next;
			if (node_prev)
				node_prev->next = node->next;
			node = node->next;
			free(tmp);
		}
		else
		{
			node_prev = node;
			node = node->next;
		}
	}
}

int count_elements(singl_list_t *head)
{
	int res = 0;
	for(; head; head = head->next)
	{
		res++;
	}
	return res;
}

singl_list_t *access_to_element_list(singl_list_t *head, int k)
{
	for (int i = 0; i < k-1; i++)
	{
		head = head->next;
	}
	return head;
}


void bubbel_sort_list(singl_list_t **head)
{
	int kol = count_elements(*head);
	singl_list_t *elem_i;
	singl_list_t *elem_j;
	singl_list_t *tmp1;
	singl_list_t *tmp2;
	singl_list_t *tmp3;
	
	for (int i = 0; i < kol - 1; i++)
	{
		for (int j = i+1; j < kol; j++)
		{
			elem_i = access_to_element_list(*head, i);
			elem_j = access_to_element_list(*head, j);
			if (i == 0)
			{
				if (sred(elem_i) > sred(elem_j->next))
				{
					*head = elem_j->next;
					tmp1 = elem_i;
					tmp2 = elem_j->next;
					elem_j->next = elem_i;
					
					tmp3 = tmp2->next;
					tmp2->next = tmp1->next;
					tmp1->next = tmp3;	
				}
			}
			else
			{
				if (sred(elem_i->next) > sred(elem_j->next))
				{
					tmp1 = elem_i->next;
					tmp2 = elem_j->next;
					elem_i->next = elem_j->next;
					elem_j->next = tmp1;
					
					tmp3 = tmp2->next;
					tmp2->next = tmp1->next;
					tmp1->next = tmp3;	
				}
			}
		}
	}
}

void front_back_split(singl_list_t *head, singl_list_t **back)
{
	int count = count_elements(head);
	if (count % 2 != 0)
		count = count / 2 + 1;
	else
		count = count / 2;
	for(int i = 0; i < count-1; i++)
	{
		head = head->next;
	}
	(*back) = head->next;
	head->next = NULL;
}




