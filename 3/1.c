#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void addNode(int pos,int value,struct node* arr[])
{
    struct node *point = arr[pos];
    if(point == NULL)
    {
        point = (struct node*)malloc(sizeof(struct node));
        arr[pos] = point;
        point->next = NULL;
        point->value = value;
        return;
    }
    while (point->next != NULL)
    {
        point = point->next;
    }
    point->next = (struct node*)malloc(sizeof(struct node));
    point = point->next;
    point->value = value;
    point->next = NULL;
    return;   
}


void search(char *full,char *sub)
{
    //100003
    int prime = 5;
    struct node* arr[5]={NULL};
    int full_len = strlen(full);
    int sub_len = strlen(sub);
    long long int sum = full[0]-'0';
    long long int sum_check = sub[0]-'0';
    long long int x = 2;
    for(int i = 1;i < sub_len ;i++)
    {
        x = x*2;
        sum = sum*2 + full[i] - '0';
        sum_check = sum_check*2 + sub[i] - '0';
    }
    addNode(sum%prime,0,arr);
    for(int j=1;j<=full_len-sub_len;j++)
    {
        sum = sum*2 - x*(full[j-1]-'0') + (full[j+sub_len-1] - '0');
        addNode(sum%prime,j,arr);
    }
    int hashCheck = sum_check%prime;
    struct node *point = arr[hashCheck%prime];
    if(point == NULL)
    {
        printf("\nNO MATCH\n");
    }
    else
    {
        int flag = 0;
        while(point != NULL)
        {
            int f=0;
            int index = point->value,i=0,j=index;
            for(i=0;i < sub_len ;i++)
            {
                if(sub[i] != full[j+i])
                {
                    f=1;
                    break;
                }
            }

            if(f == 0)
            {
                printf("Match Found At : %d\n",j);
                flag = 1;
            }
            point = point->next;
        }
        
        if(flag == 0)
            printf("\nNO MATCH\n");
    }
    return;
}
int main(void)
{
    FILE *fp = fopen("data","r");
    
    char *full = (char*)malloc(10000000);
    char *sub = (char*)malloc(100000);
    
    fscanf(fp,"%s",full);    
    fscanf(fp,"%s",sub);
    
    search(full,sub);
}