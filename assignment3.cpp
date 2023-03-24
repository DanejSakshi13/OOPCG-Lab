/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price 
(type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the
data member values*/

#include <iostream>
using namespace std;
class publication {                                             //base class
protected:
	char name[30];
	float price;
public:
	virtual void getdata()=0;
	virtual void display()=0;
};

class book: public publication {                              //first derived class
private:
	int page_c;
public:
	void getdata();
	void display();
};

class cassette : public publication {                        //second derived class
private:
	float play_time;
public:
	void getdata();
	void display();
};

void book :: getdata() {                                      //input details
cout<<"Enter the name of book  :";
cin>>name;
cout<<"Enter the price of the book :";
cin>>price;
cout<<"Enter the number of pages :";
cin>>page_c;
}

void book :: display() {                                      //output details
cout<<endl;
cout<<"\t\tDETAILS OF BOOK"<<endl;
cout<<"\t\tName of the book :"<<name<<endl;
cout<<"\t\tPrice of the book :"<<"Rs."<<price<<endl;
cout<<"\t\tNumber of pages :"<<page_c<<endl;
}

void cassette :: getdata() {                                  //input details
cout<<endl;
cout<<"Enter the name of cassette :";
cin>>name;
cout<<"Enter the price of the cassette :";
cin>>price;
cout<<"Enter the play time of cassette :";
cin>>play_time;
}

void cassette :: display() {                                 //output details
cout<<endl;
cout<<"\t\tDETAILS OF CASSETTE"<<endl;
cout<<"\t\tName of the cassette :"<<name<<endl;
cout<<"\t\tPrice of the cassette :"<<"Rs."<<price<<endl;
cout<<"\t\tPlay time of cassette :"<<play_time<<" mins"<<endl;
}

int main() {
int i, ch, n;
publication *P[50];			                                  	//array of pointers
i = 0;
do {
cout<<"Choice : 1 = Book \nChoice : 2 = Cassette\nChoice : 3 = Display \nChoice : 4 = Exit";
cout<<"\nEnter your choice:"<<endl;
cin>>ch;
switch (ch)
	{
	case 1 :
	cout<<"Book"<<endl;
		P[i] = new book();		                               	//memory allocation operator new
		P[i]->getdata() ;
		i++;
		break;

	case 2 :
	cout<<"Cassette"<<endl;
		P[i] = new cassette();		                         	//memory allocation operator new
 		P[i]->getdata(); 
		i++;
		break;

	case 3 :
	cout<<"Display details:"<<endl;
		cout << "\t\tDETAILS : " << endl;
            	n = i;
            	for (i = 0; i < n; i++)
            	{
                cout <<"\t\t---------------------------------"<<endl;
                P[i]->display();
                cout <<"\t\t---------------------------------"<<endl;
            	}
            	break;

	case 4 : 
            	cout <<"Finish"<<endl;
            	break;
	}

} 
while (ch< 4);
   
return 0;
}
