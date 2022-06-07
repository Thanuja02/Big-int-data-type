#include <stdio.h>
#define SIZE 10000

void bigIntAdd(char strnum1[SIZE],char strnum2[SIZE],int res[SIZE+10],int max,int i,int j);//function to add big integers
void bigIntSub(char strnum1[SIZE],char strnum2[SIZE],int res[SIZE],int max,int i,int j);//function to substract big integers
void bigIntMul(char strnum1[SIZE],char strnum2[SIZE],int res[2*SIZE],int max,int i,int j);//function to multiply big integers
//driver program
void main()
{
	char strnum1[SIZE],strnum2[SIZE];
	int i=0,j=0;
	int res[2*SIZE],d[SIZE];
	int max,k;
	printf("enter two numbers\n");
	scanf("%s",&strnum1);
	scanf("%s",&strnum2);
	//counting length of strnum1
	while(strnum1[i]!='\0')
	{
		i++;
	}
	//counting length of strnum2
	while(strnum2[j]!='\0')
	{
		j++;
	}
	i--;
	j--;
	//initializing max to greater size among strnum1 and strnum2
	if(i>j)
	{
		max=i;
	}
	else
	{
		max=j;
	}
	//initializing elements of array res to 0
	for(k=0;k<=i+j+1;k++)
	{
		res[k]=0;
	}
	printf("\naddition of two numbers is\n");
	bigIntAdd(strnum1,strnum2,d,max,i,j);
	printf("\nsubstraction of two numbers is \n");
	bigIntSub(strnum1,strnum2,d,max,i,j);
	printf("\nmultiplication of two numbers is\n");
	bigIntMul(strnum1,strnum2,res,i+j+1,i,j);
	
}


void bigIntAdd(char strnum1[SIZE],char strnum2[SIZE],int res[SIZE+10],int max,int i,int j)
{
	int carry=0;
	int sum,a,x,y;
	max=max+1;
	a=max;
	for(x=0;x<=max+1;x++)
	{
		res[x]=0;
	}
	while(max>0)
	{
		x=(int)strnum1[i]-48;//converting char to int
		y=(int)strnum2[j]-48;
		if(i<0)
		{
			x=0;
		}
		if(j<0)
		{
			y=0;
		}
		sum=x+y+carry;
		if(sum>9)
		{
			res[max]=sum-10;//storing last place digit of sum if sum>9
		}
		else
		{
			res[max]=sum;
		}
		carry=sum/10;//taking carry to add to next place digit
		i--;//decrementing i,j,max to store next digit in next position of array
		j--;
		max--;
	} 
	res[max]=carry;//at the end of addition taking the final obtained carry and storing it
	
	for(i=0;i<=a;i++)
	{
		printf("%d",res[i]); //printing tthe obtained addition of two numbers
		
	}
	
}
void bigIntSub(char strnum1[SIZE],char strnum2[SIZE],int res[SIZE],int max,int i,int j)
{
	int carry=0;
	int sum,a,x,y;
	a=max;
	for(x=0;x<=max;x++)
	{
		res[x]=0;
	}
	while(max>=0)
	{
		x=(int)strnum1[i]-48;//converting char to int
		y=(int)strnum2[j]-48;//converting char to int
		if(j<0)
		{
			y=0;
		}
		sum=x-y;//subtarcting y from x
		res[max]=sum-carry;
		if(res[max]<0)
		{
			res[max]=10+res[max];
			carry=1;
		} 
	
		i--;
		j--;
		max--;
	} 
	for(i=0;i<=a;i++)
	{
	    printf("%d",res[i]); //printing tthe obtained substraction of two numbers	
	}
	
}
void bigIntMul(char strnum1[SIZE],char strnum2[SIZE],int res[2*SIZE],int max,int i,int j)
{
	int carry1=0,carry2=0;
	int p=i,q=j;
	int a=max;
	int count=0;
    int sum,n1,n2;
	for(p=i;p>=0;p--)
	{
		n1=(int)strnum1[p]-48;//converting char to int
		max=a-count;
		for(q=j;q>=0;q--)
		{
			n2=(int)strnum2[q]-48;
			
			sum=n1*n2 + carry1;
			carry1=sum/10;
			if(sum>9)
			{
				sum=sum%10;//storing ones place digit of sum
			}
			res[max]=res[max]+sum+carry2;
			if(res[max]>9)
			{
				carry2=res[max]/10;//storing tens place digit of res[max]
				res[max]=res[max]%10;//storing ones place digit of res[max]
				
			}
		
			max--;
		}
		res[max]=carry1 +carry2;//after decrementing max storing carry1+carry2 in res[max-1]
		carry1=0;
		carry2=0;
		count++; 
	}


	for(i=0;i<=a;i++)
	{
		printf("%d",res[i]);////printing tthe obtained multiplication of two numbers
	}
	
}
