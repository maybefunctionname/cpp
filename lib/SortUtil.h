#pragma once

class SortUtil{
public:
	enum SORT_KIND {BUBBLE, SELECT, INSERT, HEAP};
private:
	SORT_KIND kind = SORT_KIND::BUBBLE;
public:
	void setSortKind(SORT_KIND kind);
	void traversal(int* arr, int len);
	void sort(int* arr, int len);
private:
	void heapify(int* arr, int parent, int end);
	void heapSort(int* arr, int len);
	void bubbleSort(int* arr, int len);	
	void selectSort(int* arr, int len);
	void insertSort(int* arr, int len);
};
