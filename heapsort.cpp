#include <iostream>
#include <cmath>

/*				1
			2		3
		4	5		6	7
*/

int parent(int index)
{
	if(index == 1)
		return 1;
	if(index%2 == 0)
	{
		return index/2;
	}
	else
	{
		return index/2 - 1;
	}
}

inline int left(int index)
{
	return 2*index;
}

inline int right(int index)
{
	return 2*index+1;
}


//We will index this array from 1 for heapsort, we have to!
void heapsort(int* array, int heapsize, int index)
{
	int pos = index;
	if(left(index) < heapsize and array[left(index)] < array[pos])
	{
		pos = left(index);
	}
	if(right(index) < heapsize and array[right(index)] < array[pos])
	{
		pos = right(index);
	}
	if(pos != index)
	{
		std::swap(array[index],array[pos]);
		heapsort(array, heapsize, pos);
	}
}

void extractMax(int* array, int heapsize)
{
	std::cout << heapsize << "\n";
	array[heapsize] = 0;
}
	

int main()
{
	int num[7];
	num[1] = 1;
	num[2] = 2;
	num[3] = 3;
	num[4] = 4;
	num[5] = 5;
	num[6] = 8;
	heapsort(num, 6, 1);
	for(int i(1); i < 7; ++i)
	{
		std::cout << "Pos" << i << " :" << num[i] << "\n";
	}
	extractMax(num, 6);
	for(int i(1); i < 7; ++i)
	{
		std::cout << "Pos" << i << " :" << num[i] << "\n";
	}
}

