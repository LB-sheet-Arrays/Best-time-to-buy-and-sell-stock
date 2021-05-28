#include<stdio.h>

//some utility functions
int minimum(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int maximum(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//ACTUAL function

void trading(int price[],int size)
{
	int max_profit=0,i,min_price=0,buy_day,sell_day,cost; //initialize yahi kiya to avoid garbage values.

	for(i=0;i<size;i++)
	{
		//Getting the smallest element(price) in the price array directly by coparing with each element without sorting.
		if(price[i]<price[0])
		{
			min_price=price[i];
			buy_day=i; //getting that day when stock should be purchase
		}
		
	//	min_price=minimum(price[i],price[0]);
	//	buy_day=i; //getting that day when stock should be purchased
	}
	
	for(i=0;i<size;i++)
	{
		//subtracting this minimum cost with every other price of the price array to get maximum cost!
		cost=price[i]-min_price;
		
		//ab upar se jo cost nikli vo ab max hai ki nhi check karo
		max_profit=maximum(max_profit,cost);
		sell_day=i; //getting that day when stock should be sold
	}
	
	//return the max profit thus obtained,  Bole to paisa hi paisa
	printf("\n\n The maximum profit will be Rs.%d\nDay to make purchase is %d.\nDay to sell should be %d",max_profit,buy_day+1,sell_day+1);
}

int main()
{
	int i;
	int price[100],size;  //price array!

	printf("\nHow many days do you want in your price array? => ");
	scanf("%d",&size);
	printf("\t\nPlz start filling your day-wise prices one by one.");
	for(i=0;i<size;i++)
	{
		printf("\n\nPrice at day no %d => ",i+1);
		scanf("%d",&price[i]);
	}
	
	if(size==0)
	{
		printf("\n\nSize of array is zero.Algo won't work");  //corner case
	}
	else
	{
		trading(price,size);
	}

	
}
