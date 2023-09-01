#pragma once
#include<iostream>
#include"BaseUtil.h"
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
		else if (this->kind == SORT_KIND::SELECT)
		{
			this->selectSort(arr, len);
		}
		else if (this->kind == SORT_KIND::INSERT)
		{
			this->insertSort(arr, len);
		}
	}
private:
	void bubbleSort(int* arr, int len) {
		for (int i = 0; i < len - 1; i++) {
			bool isSwap = 0;
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j] > arr[j+1]){
					BaseUtil::swap(arr[j], arr[j+1]);
					isSwap = 1;
				}
			}
			if (!isSwap){
				return;
			}
		}
	}	
	void selectSort(int* arr, int len)
	{
		int left = 0;
		int right = len - 1;
		while (left < right)
		{
			int minIndex = left;
			int maxIndex = right;
			for (int i = left; i <= right; i++)
			{
				if (arr[minIndex] > arr[i])
					minIndex = i;
				if (arr[maxIndex] < arr[i])
					maxIndex = i;
			}
			if (minIndex != left)
				BaseUtil::swap(arr[minIndex], arr[left]);
			if (maxIndex == left)
				maxIndex = minIndex;
			if (maxIndex != right)
				BaseUtil::swap(arr[maxIndex], arr[right]);
			left++;
			right--;
		}	
	}
	void insertSort(int* arr, int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (i > 0 && arr[i-1] > arr[i])
			{
				int j = i - 1;
				int temp = arr[i];
				while (j >= 0 && arr[j] > temp)
				{
					arr[j+1] = arr[j];
				   	j--;
				}
				arr[j+1] = temp;
			}
		}
	}

};
