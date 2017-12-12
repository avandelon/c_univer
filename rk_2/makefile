CC := gcc
CFLAGS := -std=c99 -Wall -Werror

app.exe : main1.o sin_list.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	RM *.o *.exe