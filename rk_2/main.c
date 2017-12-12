# include <stdio.h>
# include <stdlib.h>
# include "bin_list.h"


int main(void)
{
	head_tail_t *h_t = malloc(sizeof(head_tail_t));
	h_t->head = NULL;
	h_t->tail = NULL;
	flavel(10, 1);
	//for (int i = 30; i < 45; i++)
	//{
		//insert_front(h_t, create_node(i));
		//insert_back(h_t, create_node(i));
	//}

	//printf_back(h_t);
}
