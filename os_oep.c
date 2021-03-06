#include<stdio.h>
int main()
{
	int bsize[10], psize[10],flags[10], allocation[10];
	int i, j, bno, pno;
	
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
	
	printf("Enter no. of Memory blocks: ");
	scanf("%d", &bno);
	
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
 
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	
	printf("\nEnter size of each process: ");
	
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	
	for(i = 0; i < pno; i++)       
		for(j = 0; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	
	printf("\n Block no.\t size \t\t process no. \t\t size");
	for(i = 0; i < bno; i++)
	{
		printf("\n %d \t\t %d \t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d \t\t\t %d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
}
