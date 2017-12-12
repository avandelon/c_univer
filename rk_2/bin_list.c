# include <stdio.h>
# include <stdlib.h>
# include "bin_list.h"

bin_list_t *create_node(int value)
{
	bin_list_t *node = malloc(sizeof(bin_list_t));
	if (node)
	{
		node->value = value;
		node->next = NULL;
		node->prev = NULL;
	}
	else
		return NULL;
	return node;
}

void insert_front(head_tail_t *h_t, bin_list_t *node)
{
	if (!h_t->head && !h_t->tail)
	{
		h_t->head = node;
		h_t->tail = node;
	}
	else
	{
		node->next = h_t->head;
		h_t->head->prev = node;
		h_t->head = node;
	}
}	

void insert_back(head_tail_t *h_t, bin_list_t *node)
{
	if (!h_t->head && !h_t->tail)
	{
		h_t->head = node;
		h_t->tail = node;
	}
	else
	{
		node->prev = h_t->tail;
		h_t->tail->next = node;
		h_t->tail = node;
	}
}	

void del_bin(head_tail_t *h_t, int value)
{
	bin_list_t *node = h_t->head;
	bin_list_t *tmp;
	while (node)
	{
		if (node->value == value)
		{
			tmp = node;
			if (!node->prev && !node->next)
			{
				free(node);
				h_t->head = NULL;
				h_t->tail = NULL;
			}
			else if (!node->prev)
			{
				node->next->prev = NULL;
				h_t->head = node->next;
				free(tmp);
			}
			else if (!node->next)
			{
				node->prev->next = NULL;
				h_t->tail = node->prev;
				free(tmp);
			}
			else
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
				//node = node->next;
				free(tmp);
			}
			break;
		}
		node = node->next;
	}
}


void printf_front(const head_tail_t *h_t)
{
	bin_list_t *node = h_t->head;
	while (node)
	{
		printf("%d->",node->value);
		node = node->next;
		
		//printf("%d->",h_t->head->value);
	}
}

void printf_back(const head_tail_t *h_t)
{
	bin_list_t *node = h_t->tail;
	while (node)
	{
		printf("%d->",node->value);
		node = node->prev;
	}
}



void flavel(int kol, int num)
{
	head_tail_t *h_t = malloc(sizeof(head_tail_t));
	h_t->head = NULL;
	h_t->tail = NULL;
	for (int i = 1; i <= kol; i++)
	{
		insert_back(h_t, create_node(i));
	}
	h_t->tail->next = h_t->head;
	h_t->head->prev = h_t->tail;
	
	bin_list_t *node = h_t->head;
	while (h_t->head->next->next != h_t->head)
	{
		for (int i = 1; i < num; i++)
		{
			node = node->next;
		}
		printf("%d ", node->value);
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (node == h_t->head)
		{
			h_t->head = h_t->head->next;
		}
		bin_list_t *tmp = node;
		node = node->next;
		//free(tmp);	
	}	
	printf("\n%d - %d\n", h_t->head->value, h_t->head->next->value);
}