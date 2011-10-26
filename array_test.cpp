//Take 2 arrays, return 2 new arrays with uniques and non uniques

#include <iostream>

int ascend[100];
int descend[100];

bool sort(int* array1, int* array2, int index1, int index2)
{
	if(index1 > 5 or index2 > 3) //Hardcoded indexes in for my example... All I'd need to do is swap with length...
		return 0;
	if(array1[index1] == array2[index2])
	{
		descend[index2] = array1[index1];
		++index1;
		++index2;
		sort(array1, array2, index1, index2);
	}

	if(array1[index1] > array2[index2])
	{
		for(; array2[index2] < array1[index1]; ++index2)
		{
		ascend[index2] = array2[index2];
		}
		if(array2[index2] == array1[index1])
			descend[index2] = array2[index2];
		sort(array1, array2, index1, index2);
	}

	else
	{
		for(; array1[index1] < array2[index2]; ++index1)
		{
		ascend[index1] = array1[index1];
		}
		if(array2[index2] == array1[index1])
			descend[index2] = array2[index2];
		sort(array1, array2, index1, index2);
	}
}
	
	
int main()
{
	int a[5];
	int b[3];
	a[0] = 4;
	a[1] = 5;
	a[2] = 34;
	a[3] = 89;
	a[4] = 101;
	a[5] = 110;
	b[0] = 1;
	b[1] = 4;
	b[2] = 34;
	b[3] = 101;
	int worked = sort(a, b, 0, 0);
	for(int i(0); i <= 5; ++i)
	{
	std::cout << ascend[i] << "\n";
	std::cout << descend[i] << "\n";
	}
}