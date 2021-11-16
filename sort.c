#include "swap.h"

void sort_arr(int arr[], int low, int hi)
{
	int s;
	int e;
	int temp;

	if (low > hi)
		return ;
	s = low;
	e = hi;
	while (s <= e)
	{
		while (arr[s] < arr[s + (e - s) / 2])
			s++;
		while (arr[e] > arr[s + (e - s) / 2])
			e--;
		if (s <= e)
		{
			temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;
			e--;
		}
		sort_arr(arr, low, e);
		sort_arr(arr, s, hi);
	}
}
