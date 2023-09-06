#pragma once
#include<iostream>
#include"BaseUtil.h"
#include"SortUtil.h"
#include<vector>
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
	else if (this->kind == SORT_KIND::MERGE)
	{
		this->mergeSort(arr, 0, len-1);
	}
	else if (this->kind == SORT_KIND::QUICK)
	{
		this->quickSort(arr, 0, len-1);
	}
	else if (this->kind == SORT_KIND::COUNT) 
	{
		this->countSort(arr, len);
	}
	else if (this->kind == SORT_KIND::BUCKET)
	{
		this->bucketSort(arr, len);
	}
}

void SortUtil::bucketSortImpl(vector<int>& arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; i++) {
		bool isSwap = 0;
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				BaseUtil::swap(arr[j], arr[j+1]);
				isSwap = 1;
			}
		}
		if (!isSwap)
			break;
	}
}

void SortUtil::bucketSort(int* arr, int len){
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int size = (max - min) / len + 1;
	int n = (max - min) / size + 1;
	vector<vector<int>> buckets(n);
	for (int i = 0; i < len; i++) {
		int j =  arr[i] / size;
		if (j >= n)
			j = n - 1;
		buckets[j].push_back(arr[i]); 
	}
	int index = 0;
	for (int i = 0; i < buckets.size(); i++) {
		bucketSortImpl(buckets[i]);
		for (int j = 0; j < buckets[i].size(); j++) {
			arr[index++] = buckets[i][j]; 
		}
	}
}

void SortUtil::countSort(int* arr, int len)
{
	int max = arr[len-1];
	int min = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
		   	max = arr[i];
	}
	vector<int> b(max - min + 1, 0);
	vector<int> c(max - min + 1, 0);
	for (int i = 0; i < len; i++) {
		b[arr[i] - min]++; 
	}
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			c[i] = b[i];
			continue;
		}
		c[i] = c[i-1] + b[i];
	}
	// 需要新创建一个和元数组等长的数组来存放排序后的结果
	vector<int> res(len, 0);
	for (int i = len - 1; i >= 0; i--) {
		res[c[arr[i] - min] - 1] = arr[i];
	  	c[arr[i] - min]--;	
	}
   	for (int i = 0; i < len; i++) {
		arr[i] = res[i];
	}	
}

void SortUtil::quickSort(int* arr, int left, int right)
{	
	if (left >= right)
		return;
	int temp = arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && arr[j] >= temp)
			j--;
		while (i < j && arr[i] <= temp)
			i++;
		if (i < j)
		{
			BaseUtil::swap(arr[i], arr[j]);		
		}
	}
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort(arr, left, i-1);
	quickSort(arr, i+1, right);	
}

void SortUtil::mergeSort(int* arr, int left, int right)
{
	if (left >= right) 
		return;
	int mid = ((right - left) >> 1) + left;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

void SortUtil::merge(int* arr, int left, int mid, int right)
{
	int tempArr[10];
	int p_left = left;
	int p_right = mid + 1;
	int index = 0;
	while(p_left <= mid && p_right <= right)
	{
		if (arr[p_left] > arr[p_right]) 
			tempArr[index++] = arr[p_right++];
		else
			tempArr[index++] = arr[p_left++];
	}
	while(p_left <= mid)
	{
		tempArr[index++] = arr[p_left++];
	}
	while(p_right <= right)
	{
		tempArr[index++] = arr[p_right++];
	}
	for (int i = 0; i <= index - 1; i++)
	{
		arr[left+i] = tempArr[i]; 
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
