/*Develop a program in C++ to create a database of student’s information system containing the following information: name, roll number, class, division, date of birth,
blood group, contact address, telephone number, driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default
constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as
well as exception handling.*/

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#define max_len 25
using namespace std;
class student 
{
	public:
	int rollno;
	unsigned long int contact_no;
	char name[30];
	char blood_grp[10];
	char clas[3];
	char div[3];
	char DOB[20];
	int srno;
	unsigned long int tel_ph;
	static int count;
	void getdata();
	friend void display(student & object);


student()      //constructor
{
	int rollno=0;
	cout<<"\nConstructor";
	rollno=count;    
	count++;
}



static void getcount() 
{
	cout<<"count"<<count;
}
student (int rollno)
{
	this->rollno=rollno;
}


student(student & obj)
{
	rollno=obj.rollno;
	strcpy(div,obj.div);
	strcpy(clas,obj.clas);
	contact_no=obj.contact_no;
	strcpy(name,obj.name);
	strcpy(blood_grp,obj.blood_grp);
	tel_ph=obj.tel_ph;
	srno = count;
	count++;
}

~student() {
	cout<<"\nDestructor";
	count++;
	}

};

int student::count=0;
void student::getdata()
{

	cout<<"\nName:"<<endl;
	cin.getline(name,30);

	cout<<"\nRoll number:";
	cin>>rollno;

	cout<<"\nClass:";
	cin>>clas;

	cout<<"\nDivision:";
	cin>>div;

	cout<<"Contact number:";
	cin>>contact_no;

	cout<<"\nTelephone number:";
	cin>>tel_ph;

	cout<<"\nBlood group:";
	cin>>blood_grp;

	cout<<"\nDate of birth:";
	cin>>DOB;
}

void display(student & obj)
{
	cout<<"\n\t"<<obj.name;
	cout<<"\t"<<obj.rollno;
	cout<<"\t"<<obj.clas;
	cout<<"\t"<<obj.div;
	cout<<"\t\t"<<obj.contact_no;
	cout<<"\t"<<obj.tel_ph;
	cout<<"\t\t"<<obj.blood_grp;
	cout<<"\t\t"<<obj.DOB;
}

int main()
{
	student s1;
	student s2(s1);
	s1.getdata();
	cout<<"\tName\tRoll No\tClass\tDivision\tContact No,\tTel Ph.No\tBlood group\tDOB";
	display(s1);
	student*s[10];   //array of object
	int i ,n;
	cout<<"\nHow many student objects?";
	cin>>n;
	
	for(i=0;i<n;i++)
	s[i]=new student();   //dynamic memory allocate
	
	for(i=0;i<n;i++)
	s[i]->getdata();
	
	cout<<"\tName\tRoll No\tClass\tDivision\tContact No,\tTel Ph.No\tBlood group\tDOB";
	for(i=0;i<n;i++)
	display(*s[i]);
	
	for(i=0;i<n;i++)
	delete(s[i]);  //dynamic memory deallocate
	return 0;
}
