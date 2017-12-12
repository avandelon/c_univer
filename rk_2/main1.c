# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "sin_list.h"

int main(void)
{
	singl_list_t *head = NULL;
	int marks[MAX_EXAM];
	char name[MAX_LEN];
	FILE *f = fopen("in.txt","r");
	while (load_from_file(f, marks, name) == 0)
	{
		singl_list_t *node = creat_node(marks, name);
		insert_list(&head, node);
	}
	printf_list(head);
	
	double sred_ball = sred_all(head);
	printf("\n\n%f\n", sred_ball);
	
	bubbel_sort_list(&head);
	//remove_ball(&head, 0);
	printf_list(head);

}
