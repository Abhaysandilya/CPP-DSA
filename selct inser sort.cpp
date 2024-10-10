void selection_sort(int arr[], int n)
{
	for(int i=0; i< n-1; i++)
	{
		int min = i;
		for(int j= i+1; j<n; j++)
		   {
		   	 if(arr[j] < arr[min]) min = j;
		   }
		if(i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void insertion_sort(int A[], int n)
{
	for(int i=1; i<n; i++)
	{
		int key = A[i];
		int j = i-1;
		while(j>=0)
		{
			if(A[j] > key)
			   A[j+1] = A[j];
			   j--;
			else break;
		}
		A[j+1] = key;
	}
}
