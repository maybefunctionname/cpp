#pragma once
#include<iostream>
using namespace std;

class SortUtil{
public:
	enum SORT_KIND {BUBBLE, SELECT, INSERT, HEAP};
private:
	SORT_KIND kind = SORT_KIND::BUBBLE;
public:
	void setSortKind(SORT_KIND kind) {
		this->kind = kind;
	}
	void traversal(int* arr, int len) {
		for (int i = 0; i < len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void sort(int* arr, int len) {
		if (this->kind == SORT_KIND::BUBBLE){
			this->bubbleSort(arr, len);
		}
	}
private:
	void bubbleSort(int* arr, int len) {
		for (int i = 0; i < len - 1; i++) {
			bool isSwap = 0;
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j] > arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					isSwap = 1;
				}
			}
			if (!isSwap){
				return;
			}
		}
	}	
};
