#pragma once
#include<iostream>
#include"BaseUtil.h"
#include"SortUtil.h"
using namespace std;

void SortUtil::setSortKind(SORT_KIND kind) {
	this->kind = kind;
}
void SortUtil::traversal(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void SortUtil::sort(int* arr, int len) {
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
	else if (this->kind == SORT_KIND::HEAP)
	{
		this->heapSort(arr, len);
	}
	else if (this->kind == SORT_KIND::SHELL)
	{
		this->shellSort(arr, len);
	}
}

void SortUtil::shellSort(int* arr, int len)
{
	for (int gap = len >> 1;  gap >= 1; gap >>= 1)
	{
		for (int i = gap; i <= len - 1; i++)
		{
			if (i > 0 && arr[i] < arr[i-gap])
			{
				int temp = arr[i];
				int j =  i - gap;
				while (j >= 0 && arr[j] > temp)
				{
					arr[j+gap] = arr[j];
					j -= gap;
				}
				arr[j+gap] = temp;
			}
		}	
	}
}

void SortUtil::heapify(int* arr, int parent, int end)
{
	int son = 2 * parent + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son+1])
			++son;
		if (arr[parent] >= arr[son])
			break;
		BaseUtil::swap(arr[parent], arr[son]);
		parent = son;
		son = 2 * parent + 1;
	}
}

void SortUtil::heapSort(int* arr, int len)
{
	// 先构建一个大顶堆
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heapify(arr, i, len-1);
	}
	for (int i = len - 1; i > 0; i--)
	{
		BaseUtil::swap(arr[i], arr[0]);
		heapify(arr, 0, i - 1);
	}
}

void SortUtil::bubbleSort(int* arr, int len) {
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
void SortUtil::selectSort(int* arr, int len)
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
void SortUtil::insertSort(int* arr, int len)
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
