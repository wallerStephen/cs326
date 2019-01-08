
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pass file pointer to file to read and return an Array of numbers 
int *Array(FILE* fp){
	 
	int loopVar;
	//Reads the First number for loop init
	fscanf(fp, "%d", &loopVar);
	
	int* arr = malloc (sizeof (int) * loopVar);

	for(int i = 0; i < loopVar; i++){

		fscanf(fp, "%d", &arr[i]);		
	}	
	
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
int main(int argc, char* argv[]){

	char* textfile = "data.txt"; 

	FILE *fp;
	
	fp = fopen(textfile, "r");
	
	char* writefile = "merge.txt";
	
	FILE *fpOpen;
	
	fpOpen = fopen(writefile, "ab+");
	//chech file was open
	do{
		int* sort = Array(fp);

		WriteFile(fpOpen, sort);

		if(feof(fp)){

			break; 
		}

	}while(1);


}