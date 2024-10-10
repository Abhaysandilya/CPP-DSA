//Search an element in Sorted Rotated Array
#include<iostream>
using namespace std;

int* array;
int size, item;

int sorted_rotated(int beg, int end)
{
	if(beg > end) //base condition
	   return -1;

	int mid = (beg + end)/2;

	if(array[mid] == item) return mid;

	if(array[beg] <= array[mid]) //left subarray is sorted
	{
		if(item >= array[beg] && item <= array[mid]) //item lies in left portion
		   return sorted_rotated(beg, mid-1);

		return sorted_rotated(mid+1, end);
	}
	//right side portion is sorted

	if(item >= array[mid] && item <= array[end])  //item may be there in rights side
	    return sorted_rotated(mid+1, end);
	return sorted_rotated(beg, mid-1);
}

int main()
{
	cout<<"Enter the Size of Array: ";
	cin>>size;

	array = new int[size];

	for(int i = 0; i<size; i++)
	   cin>>array[i];

//	int item;
	cout<<"\nEnter the element to be Searched: ";
	cin>> item;

	int pos = sorted_rotated(0, size-1);
	if(pos == -1) cout<<"\nItem is not Present";
    else cout<<"\nItem found at index "<<pos;
}
