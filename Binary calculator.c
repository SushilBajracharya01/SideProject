// A program to add and subtract binary numbers.

#include <stdio.h>
#include <math.h>

int len(int N);
int converter(int,int);

int main(){
	int len1,len2,num1,num2,bicon1,bicon2;
	printf("Enter binary number :");
	scanf("%d",&num1);
	printf("Enter another binary number :");
	scanf("%d",&num2);
	
	len1=len(num1);
	len2=len(num2);
	
	bicon1 = converter(num1,len1);
	bicon2 = converter(num2,len2);
	
	printf("%d\n",bicon1);
	printf("%d",bicon2);
	
	
}

int len(int N){
		int length = 1;
		while(N > 9){
			length++;
			N = N / 10;
		}
		return length;
}

int converter(int n,int len){
	int i,mod=0,p=0,con=0;
	for(i=0;i<len;i++){
		mod=n%10;
		n=n/10;
		p=pow(2,i);
		con=con+mod*p;
	}
	return con;
}
	
