// A program to display the string is palindrome or not.
#include <stdio.h>
#include <string.h>

int main(){
	char str[100],str1[100];
	printf("Enter a string : ");
	gets(str);
	
	strcpy(str1,str);
	
	if(strcmp(strlwr(str),strrev(strlwr(str1)))==0){
		printf("It is palendrome");
	}
	else 
		printf("It is not palendrome");
	return 0;
}
