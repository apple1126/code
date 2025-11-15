#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool verifyPostorder(int* postorder,int start,int end){
	if(start >= end){
		return true;
	}
	int root = postorder[end];
	
	int i = start;
	while(i < end&&postorder[i]<root){
		i++;
	}
	int j = i;
	while (j < end){
		if(postorder[j] < root){
			return false;
		}
		j++;
	}
	//检查左子树和右子树 
	bool leftValid = verifyPostorder(postorder,start,i-1);
	bool rightValid = verifyPostorder(postorder,i,end - 1);
	
	return leftValid && rightValid;
}

int main(){
	int capacity = 10;
	int size = 0;
	//动态数组用于存储输入 
	int* postorder = (int*)malloc(capacity* sizeof(int));
	
	int num;
	while (scanf("%d",&num) == 1){
		if(size >= capacity){
			capacity *= 2;
			postorder = (int*)realloc(postorder,capacity * sizeof(int));
			
		}
		postorder[size++] = num;
		
	}
	if(verifyPostorder(postorder,0,size - 1)){
		printf("true\n");
	}else{
		printf("false\n");
	}
	free(postorder);
	return 0;
}
