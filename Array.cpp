
#include<iostream>

using namespace std;
int size;
int* arr;  //pointer to store the address

int main()
{

cout<<"enter the size of Array: ";
cin>>size;

//create the Array of given size.
arr= new int[size];   //Create Array


//print the values of Array.

cout<<"\nEnter the values of Array\n";
int x=1;
while(x<=size){

cin>>arr[x-1];
x++;

}

for(int i=0;i<=size-1;i++){
cout<<arr[i]<<endl;
}

return 0;
}
