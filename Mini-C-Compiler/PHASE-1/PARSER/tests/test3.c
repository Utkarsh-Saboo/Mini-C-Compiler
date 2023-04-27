// test case to check function decleration ,struct and union decleration
// with error 
#include<stdio.h>
struct student{
	int a;
	char c;
};
union teacher{
	int q;
	int p;
}                 //semicolon missing
void abc(){
	printf("\nHello World");
}
void main(){
	student *S;
	teacher *T;	
	abc();
}
