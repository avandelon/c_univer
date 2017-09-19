#include <stdio.h>

#define COl 4
#define STR 4
#define OK 0
#define FILE_EMPTY -1

void sum_str(int *ppb,int *ppe,int col,int str,int *sum)
{
    int *pe = ppb;
    int k = 0;
    while (pe<ppe)
    {
        sum[k]+=*pe;
        pe += 1;
        if ((pe-ppb)%col == 0)
        {
            k+=1;
        }
    }
}

void sum_col(int *ppb,int *ppe,int col,int str,int *sum)
{
    int *pe = ppb;
    int k = 0;
    while (pe<ppe)
    {
        sum[k]+=*pe;    
        k+=1;
        pe += 1;
        if ((pe-ppb)%str == 0)
        {
            k = 0;    
        }
    }
}


void bubble_sort(int *pb,int *pe,int k)
{
    int *pb1 = pb;
    
    int tmp;
    while(pb1<pe-k)
    {
        int *pb2 = pb1+k;
        while(pb2<pe)
        {
            if(*pb2<*pb1)
            {
                tmp = *pb2;
                *pb2 = *pb1;
                *pb1 = tmp;
            }
            pb2 += k;
        }
        pb1 += k;
    }
}

void sort_str(int *ppb,int *ppe,int col,int str)
{
    int *pe = ppb;
    while (pe<ppe)
    {
        pe += 1;
        if ((pe-ppb)%col == 0)
        {
            bubble_sort(pe-col,pe,1);
        }
    }
}


void sort_col(int *ppb,int *ppe,int col)
{
    for (int i=0;i<col;i++)
    {    
        bubble_sort(ppb+i,ppe+i,col);
    }
}

int read_array(FILE *f, int **pb, int **pe, int k)
{
    int err = OK;
    while((fscanf(f,"%d",*pe) == 1) && (*pe-*pb < k))
    {
        *pe = *pe + 1;  
    }
    
    if (*pe == *pb)
    {
        err = FILE_EMPTY;
    }
    return err;        
}

void inversia_diags(int *ppb,int *ppe,int col,int str)
{
    int tmp;
    int *ppb1 = ppb;
    int *ppe1 = ppe;
    
    while(ppe1>ppb1)
    {
        tmp = *(ppe1-1);
        *(ppe1-1) = *ppb1;
        *ppb1 = tmp;
        ppb1 += (col+1);
        ppe1 -= (col+1);
    }
    ppb1 = ppb+(col-1);
    ppe1 = ppe-(col-1);
    while(ppe1>ppb1)
    {
        tmp = *(ppe1-1);
        *(ppe1-1) = *ppb1;
        *ppb1 = tmp;
        ppb1 += (col-1);
        ppe1 -= (col-1);
    }
    
}

int main(void)
{
    FILE *f1;
    int *ppe;
    int *ppb;
    int a[COl][STR];
    int k = 0;
    ppb = a[0];
    ppe = a[0];
    int sum_s[STR] = {0};
    int sum_r[COl] = {0};
    
    /* while (ppe-ppb<col*STR)
    {
        scanf("%d",ppe);
        ppe += 1;
    } */
    f1 = fopen("text.txt","r");
    read_array(f1,&ppb,&ppe,COl*STR);
    
    printf("\n");
    
    printf("Sum str\n");
    sum_str(ppb,ppe,COl,STR,sum_s);
    for(int i=0;i<STR;i++)
    {
        printf("%d ",*(sum_s+i));
    }
    
    printf("\nSum col\n");
    sum_col(ppb,ppe,COl,STR,sum_r);
    for(int i=0;i<COl;i++)
    {
        printf("%d ",*(sum_r+i));
    }
    
    printf("\nСортировка по строкам\n");
    
    
    sort_str(ppb,ppe,COl,STR);
    
    int *ppb2 = ppb;
    while(ppb2<ppe)
    {
        
        printf("%d ",*ppb2);
        k++;
        ppb2 += 1;
        if (k % COl == 0)
        {
            printf("\n");
        }
    }
    
    printf("Сортировка по столбцам\n");
    
    sort_col(ppb,ppe,COl);
    
    int *ppb3 = ppb;
    while(ppb3<ppe)
    {
        
        printf("%d ",*ppb3);
        k++;
        ppb3 += 1;
        if (k % COl == 0)
        {
            printf("\n");
        }
    }
    
    inversia_diags(ppb,ppe,COl,STR);
    printf("Инверсия диагонлей\n");
    int *ppb4 = ppb;
    while(ppb4<ppe)
    {    
        
        printf("%d ",*ppb4);
        k++;
        ppb4 += 1;
        if (k % COl == 0)
        {
            printf("\n");
        }
    }
    
    
}