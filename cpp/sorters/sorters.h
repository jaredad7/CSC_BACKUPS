#ifndef SORTERS_H
#define SORTERS_H

#define MAX_SORT_SIZE 300
template<class swap_type>
void swap(int i, int j, swap_type arr[MAX_SORT_SIZE])
{
	swap_type temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template<class sort_type>
void bubble_sort(sort_type arr[MAX_SORT_SIZE])
{
	for(int i = 0; i < MAX_SORT_SIZE; i++)
		for(int j = 0; j < (MAX_SORT_SIZE - i); j++)
			if(arr[j] > arr[(j+1)])
				swap(j, (j+1), arr);
}

template<class sort_type>
void select_sort(sort_type arr[MAX_SORT_SIZE])
{
}

template<class sort_type>
void insert_sort(sort_type arr[MAX_SORT_SIZE])
{
}

template<class sort_type>
void quick_sort(sort_type arr[MAX_SORT_SIZE])
{
}

#endif
