#ifndef sin_list
#define sin_list

#define MAX_EXAM 3
#define MAX_LEN 80

typedef struct singl_list
{
	int marks[MAX_EXAM];
	char name[MAX_LEN];
	struct singl_list *next;
} singl_list_t;	


singl_list_t *creat_node(int marks[MAX_EXAM], char name[MAX_LEN]);
void insert_list(singl_list_t **head, singl_list_t *node);
int load_from_file(FILE *f, int marks[MAX_EXAM], char name[MAX_LEN]);
void printf_list(singl_list_t *head);
double sred(singl_list_t *node);
double sred_all(singl_list_t *head);
void remove_ball(singl_list_t **head, int ball);
int count_elements(singl_list_t *head);
singl_list_t *access_to_element_list(singl_list_t *head, int k);
void bubbel_sort_list(singl_list_t **head);


#endif // sin_list