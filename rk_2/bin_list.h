#ifndef BIN
#define BIN
typedef struct bin_list
{
	int value;
	struct bin_list *next;
	struct bin_list *prev; 
} bin_list_t;

typedef struct head_tail
{
	bin_list_t *head;
	bin_list_t *tail;
} head_tail_t;

bin_list_t *create_node(int value);
void insert_front(head_tail_t *h_t, bin_list_t *node);
void insert_back(head_tail_t *h_t, bin_list_t *node);
void del_bin(head_tail_t *h_t, int value);
void printf_front(const head_tail_t *h_t);
void printf_back(const head_tail_t *h_t);
void flavel(int kol, int num);

#endif // BIN