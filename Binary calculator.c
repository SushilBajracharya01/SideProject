// A program to add and subtract binary numbers.

#include <stdio.h>
#include <math.h>

int len(int N);
int decon(int N);
int bicon(int,int);
int check(int,int);
int add(int n1,int n2);
int sub(int n1,int n2);

int mod,i,div;

int main(){
	int len1,ch,chk,len2,num1,check1,check2,num2,bicon1,bicon2;
	printf("This is a program to add or subtract 2 binary numbers\n\t To add press 1, To subtract press 2 :");
	scanf("%d",&chk);
	printf("\n****Enter two numbers****\n"); 
	printf("Enter binary number 1 :");
	scanf("%d",&num1);
	printf("Enter binary number 2 :");
	scanf("%d",&num2);
	
	
	//functions to calculate length of number.
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
	bicon1 = bicon(num1,len1);
	bicon2 = bicon(num2,len2);
	
	//printf("%d\n",bicon1);
	//printf("%d\n",bicon2);
	
	switch(chk){
		case 1:
			printf("Sum : %d",decon(add(bicon1,bicon2)));
			break;
		case 2: 
			printf("Difference : %d",decon(sub(bicon1,bicon2)));
			break;
		default:
			printf("\n\t\tINVALID INPUT\n");
			printf("\tTo Try Again Press 1 : ");
			scanf("%d",&ch);
			if(ch == 1){
				main();
			}
	}
}
}

//a function to calculate length of number.
int len(int N){
		int length = 1;
		while(N > 9){
			length++;
			N = N / 10;
		}
		return length;
}

//a Function to check whether the numbers are in binary.
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

//a function to convert binary to decimal number.
int bicon(int n,int len){
	int mod=0,p=0,con=0;
	for(i=0;i<len;i++){
		mod=n%10;
		n=n/10;
		p=pow(2,i);
		con=con+mod*p;
	}
	return con;
}

int add(int n1,int n2){
	return n1+n2;
}
	
int sub(int n1,int n2){
	return n1-n2;
}	

int decon(int N){
	
	div=N;
	int sum=0;
	int mul = 1;
	mod=0;
	do{
		mod=div%2;
		div=div/2;
		sum=sum+mod*mul;
		mul=mul*10;
	}while(div>0);
	return sum;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
