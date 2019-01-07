all: MergeSort InsertSort

MergeSort: MergeSort.o MergeSortHeader.o
	gcc -g -Wall -std=c99 -o MergeSort MergeSort.o MergeSortHeader.o -lm
InsertSort: InsertSort.o InsertSortHeader.o
	gcc -g -Wall -std=c99 -o testda InsertSort.o InsertSortHeader.o
MergeSort.o: MergeSort.c MergeSortHeader.h
	gcc -g -Wall -std=c99 -c MergeSort.c
InsertSort.o: InsertSort.c InsertSortHeader.h
	gcc -g -Wall -std=c99 -c InsertSort.c


clean:
	rm MergeSort.o
	rm InsertSort.o
	rm MergeSort
	rm InsertSort
	rm merge.txt
	rm insert.txt
	