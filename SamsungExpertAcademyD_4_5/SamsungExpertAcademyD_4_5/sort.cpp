#include <iostream>

using namespace std;

void selection_sort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min= arr[i];
		int idx = i;
		for (int j = i; j < len; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				idx = j;
			}
		}
		//switch
		int temp = arr[i];
		arr[i] = min;
		arr[idx] = temp;

		//print
		for (int j = 0; j < len; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
}
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i-1; j++)
		{
			//swap
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		//print
		for (int j = 0; j < len; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
}

int main(void)
{

	int arr[8] = { 4, 7, 1, 3, 2, 8, 6, 5 };

	int arr2[8] = { 4, 7, 1, 3, 2, 8, 6, 5 };

	int len = 8;


	selection_sort(arr, len);

	bubble_sort(arr2, len);

}	