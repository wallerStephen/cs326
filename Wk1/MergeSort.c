#include "MergeSortHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pass file pointer to file to read and return an Array of numbers 
int *Array(FILE* fp, int loopVar){
	
	int arr[100000];

	for(int i = 0; i < loopVar; i++){

		fscanf(fp, "%d", &arr[i]);		
	}	
	arr[loopVar] = '\0';

	return arr; 
}
//Takes a pointer to an array and writes to a file 
void WriteFile(FILE* fp, int array[]){

	int i = 0; 

	while(array[i] != NULL){

		fprintf(fp, "%d ", array[i]);

		i++; 
	}
	fprintf(fp, "\n");
}
//pointer to array.  Merges the array 
void Merge(int array[], int p, int q, int r){

	int n1 = q - p + 1;
	int n2 = r - q; 
	int left[n1];
	int right[n2];

	for(int i = 0; i < n1; i++){

		left[i] = array[p + i];
	}
	for(int j = 0; j < n2; j++){

		right[j] = array[q + 1 + j]; 
	}
	int i = 0; 

	int j = 0; 

	int k = p; 

	while((i < n1) && (j < n2)){

		
		if(left[i] <= right[j]){

			array[k] = left[i];
			i++;
		}
		else{

			array[k] = right[j];
			j++;
		}	
		k++;		
	}
	while(i < n1){

		array[k] = left[i];		
		i++;
		k++;
	}	
	while(j < n2){

		array[k] = right[j];
		j++;
		k++;
	}	
}
void MergeSort(int array[], int p, int r){

	if(p < r){

		int q = p + (r - p)  / 2;

		MergeSort(array, p, q);

		MergeSort(array, q + 1, r); 

		Merge(array, p, q, r);

	}	
}
int main(int argc, char* argv[]){

	char* textfile = "data.txt"; 

	FILE *fp;
	
	fp = fopen(textfile, "r");
	
	char* writefile = "merge.txt";
	
	FILE *fpOpen;
	
	fpOpen = fopen(writefile, "ab+");
	//chech file was open
	do{
		int size; 

		fscanf(fp, "%d", &size);

		int* sort = Array(fp, size);

		MergeSort(sort, 0, size - 1); 

		WriteFile(fpOpen, sort);


		if(feof(fp)){

			break; 
		}

	}while(1);
}











