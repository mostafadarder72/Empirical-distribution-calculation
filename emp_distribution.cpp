#include "stdio.h"

#define NUM_OF_VALS 50
void main()
{
	FILE *fp;
	int services[NUM_OF_VALS];
	
	int ST[NUM_OF_VALS];
	int frequency[NUM_OF_VALS]={0};
	float probability[NUM_OF_VALS];
	float cum_prob[NUM_OF_VALS];

	fp=fopen("d:\\maclunch.txt", "r");
	int i;
	int min=1000,max=0;
	for(i=0;i<NUM_OF_VALS;i++)
	{
		fscanf(fp,"%d",&services[i]);
		if(services[i]%60<30)
			services[i]=services[i]/60;
		else
			services[i]=services[i]/60+1;
		if(services[i]<min) min=services[i];
		if(services[i]>max) max=services[i];
	}

	int range=max-min+1;

	//first column
	for(i=0;i<range;i++)
		ST[i]=i+min;

	//second column
	for(i=0;i<NUM_OF_VALS;i++)
		frequency[services[i]-min]++;

	//third and fourth columns
	float cum=0;
	for(i=0;i<range;i++)
	{
		probability[i]=(float)frequency[i]/NUM_OF_VALS;
		cum+=probability[i];
		cum_prob[i]=cum;
	}

	fclose(fp);

	for(i=0;i<range;i++)
		printf("%d\t%d\t\%.2f\t%.2f\n",ST[i],frequency[i],probability[i],cum_prob[i]);

}
