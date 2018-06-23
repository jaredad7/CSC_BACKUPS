

#ifndef ARRAY_SEARCH_H
#define ARRAY_SEARCH_H

#define ARRAY_SIZE 500

//Will use a binary search to return the index of the sought data or -1
//assumes a min-to-max sorted array
template <class search_type>
int bin_search(search_type arr[ARRAY_SIZE], search_type data)
{
	int first = 0;
	int last = (ARRAY_SIZE -1);
	int mid = ((first + last) / 2);

	while((arr[mid] != data) && (last >= first))
	{
		if(arr[mid] < data)
			first = (mid + 1);
		else
			last = (mid - 1);

		mid = ((first + last) / 2);
	}

	if(arr[mid] == data)
		return mid;
	else
		return -1;
}

//Will use a sequential search to return the index of the sought data or -1
//assumes a min-to-max sorted array
template <class search_type>
int seq_search(search_type arr[ARRAY_SIZE], search_type data)
{
	int point = 0;
	
	while((point < ARRAY_SIZE) && (arr[point] < data))
		point++;

	if(arr[point] == data)
		return point;
	else
		return -1;
}

//Will use a sequential search to return the index of the sought data or -1
//assumes no sorted array
template <class search_type>
int unsort_search(search_type arr[ARRAY_SIZE], search_type data)
{
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(arr[i] == data)
			return i;
	}

	return -1;
}

#endif
