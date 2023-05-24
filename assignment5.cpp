/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.*/

#include <iostream>
using namespace std;

template <class T>
class sort{
	private:
	int n;
	T arr[20],temp;
	public:
	void input();
	void display();
	void selectionSort();
};
template <class T>
void sort<T> :: input(){
cout<<"How many elements do you want?";
cin>>n;
for(int i=0;i<n;i++){
	cin>>arr[i];
	}
}
template <class T>
void sort<T> :: display(){
cout<<"Given array is :";
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
}

template <class T>
void sort<T> :: selectionSort(){
for (int step=0;step<n;step++){
	int min_i = step;
	for(int i=step+1;i<n;i++){
		if(arr[i]<arr[min_i])
		min_i = i;
		}
		swap(arr[min_i],arr[step]);
		}
cout<<"\nSorted array is :";
for (int step=0;step<n;step++){
cout<<arr[step]<<" ";
		}
}


int main(){
sort<int> int1;
sort<float> float1;
sort<char> char1;
sort<string> s1;
int ch;
cout<<"\n1.Integers\n2.Float\n3.Character\n4.String";
cout<<"\nEnter your choice:";
cin>>ch;

switch (ch){
case 1: 
cout<<"\nFor INTEGERS"<<endl;
int1.input();
int1.display();
int1.selectionSort();
break;

case 2:
cout<<"\n\nFor FLOAT"<<endl;
float1.input();
float1.display();
float1.selectionSort();
break;

case 3:
cout<<"\n\nFor CHARACTERS"<<endl;
char1.input();
char1.display();
char1.selectionSort();
break;

case 4:
cout<<"\n\nFor STRINGS"<<endl;
s1.input();
s1.display();
s1.selectionSort();
break;

default:
cout<<"You entered wrong choice";
break;
}
}
