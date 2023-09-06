#pragma once
#include<iostream>
#include"SortUtil.h"
using namespace std;

int main(){
	int arr[10] = {3,4,1,2,3,5,1,7,8,6};
	SortUtil sortUtil;
	int len = sizeof(arr) / sizeof(int);
	sortUtil.setSortKind(sortUtil.SORT_KIND::BUCKET);
	sortUtil.sort(arr, len);
	sortUtil.traversal(arr, len);
	return 1;
}
