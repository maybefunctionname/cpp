#pragma once

class BaseUtil
{
	public:
		static void swap(int& a, int& b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
};
