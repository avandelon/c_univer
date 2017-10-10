# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# define SEP "., ?!" 

void foo(char *s)
{
    printf("%c\n", s[1]);
}

const char *strchr1(const char *str, char symbol)
{
    const char *c = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == symbol)
        {
            c = &(str[i]);
            break;
        }
    }
    return c;
}

int count_words(const char *str)
{
    int n = 0;
    int len = strlen(str);
    for (int i = 0;i < len;i++)
    {
        if (!strchr1(SEP, str[i]) && (i == 0 || strchr1(SEP, str[i-1])))
            n++;
    }
    return n;
}

void split_words(char *str, char **words)
{
    int k = 0;
    int len = strlen(str);
    for (int i = 0;i < len;i++)
    {
        if (!strchr1(SEP, str[i])) 
        {
            if (i == 0 || str[i-1] == 0)
            {
                words[k] = &(str[i]);
                k++;
            }
        }
        else
            str[i] = 0;
    }    
} 

int podstroka(char *str,char *podstr) // lololol -- 3
{
    int len1 = strlen(str);
    int len2 = strlen(podstr);
    int k;
    int counter;
    int n = 0;
    if (len2 > len1)
        return -1;
    else
    {
        for (int i = 0; i < len1 - len2+1; i++)
        {
            k = 1;
            counter = 0;
            for (int j = i; j < i + len2; j++)
            {
                if (str[j] != podstr[counter])
                {
                    k = 0;
                    break;
                }
                counter++;
            }
            if (k)
            {
                n++;
            }    
        }
    }
    return n;
}



int podstroka2(char *str,char *podstr) // lololol -- 2
{
    int len1 = strlen(str);
    int len2 = strlen(podstr);
    int k;
    int i;
    int counter;
    int n = 0;
    if (len2 > len1)
        return -1;
    else
    {
        i = 0;
        while(i < len1 - len2 + 1)
        {
            k = 1;
            counter = 0;
            for (int j = i; j < i + len2; j++)
            {
                if (str[j] != podstr[counter])
                {
                    k = 0;
                    break;
                }
                counter++;
            }
            if (k)
            {
                n++;
                i = i + len2;
            }    
            else
            {
                i++;
            }
        }
    }
    return n;
}

void read_line(char **str, FILE *f)
{
    int buf_size = 5;
    int size = 0;
    int count = 0;
    int k = 1;
    char buf[buf_size];
    *str = malloc(sizeof(char));
    while (buf[0] != '\n')
    {
        fgets(buf, buf_size, f);
        printf("@@@  %s\n",buf);
        
        if (buf[0] != '\n')
        {
            printf("@@@");
            //printf("! %s\n",buf);
            count = 0;
            *str = realloc(*str,buf_size * k - (k-1));
            
            for (int i = size; i < size + buf_size; i++)
            {    
                (*str)[i] = buf[count];
                count++;
            }
            k++;
            size += buf_size;    
        }
    } 
    //fgets(buf, buf_size, f);
    //printf("%s\n",buf);
    for (int i = 0; i < buf_size * k- (k-1);i++)
    {
        printf("%c",(*str)[i]);
    }
}


void written (char s[100]) 
{
    int i, c;
 
    i = 0;
    while ((c = getchar()) != '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}
    
    
    
// удаление из одной строки символов которые есть во второй
void squeeze (char s[], char s1[]);
void written (char s[]);
 
main() {
    char str[MAX];
    char str1[DEL];         
 
    written (str);
    written (str1);
    squeeze (str, str1);
    printf("%s\n", str);
}
 
void written (char s[100]) {
    int i, c;
 
    i = 0;
    while ((c = getchar()) != '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}
 
void squeeze (char s[], char s2[]) {
    int k, i, j;
 
    for (k = 0; s2[k] != '\0'; k++) { 
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != s2[k])
                s[j++] = s[i];
        s[j] = '\0';
    }
}    
//////
    
    
int main(void)        
{
    int n;
    char s[] = "Hello mr me,me mlomm!e<mem, eeelolo?";
    n = count_words(s);
    char **words = malloc(n*sizeof(char *));
    split_words(s, words);
    for (int i = 0; i < n ; i++)
    {
        printf("%s\n",words[i]);
    }
    char s1[] = "lollolol";
    //n = podstroka(s1,"lol");
    n = podstroka2(s1,"lol");
    printf("$$$ %d\n",n);
    
    FILE *f;
    char *s2;
    //char *s3;
    f = fopen("text.txt","r");
    /* read_line(&s2,f);   чтение из файла строк неизвестной длины
    printf("\n");
    read_line(&s3,f);
     */
    /* int N = 5;
    int delta = 5;
    int i = 0;
    char* buf = (char*) malloc (sizeof(char)*N);    
    while ((buf[i] = fgetc(f)) != EOF  )  {  
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            s2 = buf;
            puts (s2); 
            free (buf);
            char* buf = (char*) malloc (sizeof(char)*N);
            i = 0;
        }    
        else
        {
            if (++i >= N) {
                N += delta;
                buf = (char*) realloc (buf, sizeof(char)*N);        
            }
        }    
    } 
    fclose(f);
    buf[i] = '\0';  
    free (buf); */
    
    
    
    
    
    
    return 0;
}