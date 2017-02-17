// A program to add and subtract binary numbers.

#include <stdio.h>
#include <math.h>

int len(int N);
int converter(int,int);
int check(int,int);

int mod,i;

int main(){
	int len1,ch,len2,num1,check1,check2,num2,bicon1,bicon2,swt;
	printf("Enter binary number :");
	scanf("%d",&num1);
	printf("Enter another binary number :");
	scanf("%d",&num2);
	
	//a function to calculate length of number.
	len1=len(num1);
	len2=len(num2);
	
	//Functions to check whether the numbers are in binary.
	check1=check(num1,len1);
	check2=check(num2,len2);
	
	if(0==(check1 && check2)){
		printf("\n\t\tINVALID INPUT\n");
		printf("\tTo Try Again Press 1 : ");
		scanf("%d",&ch);
		if(ch == 1){
			main();
		}
	}
	
	else{
	//a function to convert binary to decimal number.
	bicon1 = converter(num1,len1);
	bicon2 = converter(num2,len2);
	
	printf("%d\n",bicon1);
	printf("%d\n",bicon2);
	}
}

int len(int N){
		int length = 1;
		while(N > 9){
			length++;
			N = N / 10;
		}
		return length;
}

int check(int N,int len){
	mod=0;
	for(i=0;i<len;i++){
		mod=N%10;
		N=N/10;
		if(mod>1){
			return 0;
		}
	}
	return 1;
}	

int converter(int n,int len){
	int mod=0,p=0,con=0;
	for(i=0;i<len;i++){
		mod=n%10;
		n=n/10;
		p=pow(2,i);
		con=con+mod*p;
	}
	return con;
}
