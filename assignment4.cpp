/*Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.*/

#include <iostream>
#include<fstream>         //i/p and o/p op on files
using namespace std;

int main(){
//class  obj
ofstream outf("studentInfo.txt");    //to o/p file
char name[30];
int roll_no;
char address[50];

cout<<"Enter your name:";
cin>>name;
outf<<name<<endl;                     //to o/p file
cout<<"Enter your roll.no:";
cin>>roll_no;
outf<<roll_no<<endl;             //to o/p file
cout<<"Enter your address:";
cin>>address;
outf<<address<<endl;                  //to o/p file
outf.close();

//class  obj
ifstream inf;
inf.open("studentInfo.txt");
inf>>name;
inf>>roll_no;
inf>>address;
cout<<"\n"<<name<<"\n"<<roll_no<<"\n"<<address<<endl;
inf.close();

//to append something in txt file
outf.open("studentInfo.txt", ios::app);   
char bloodGrp[5];
cout<<"Enter blood group:";
cin>>bloodGrp;
outf << bloodGrp;
outf.close();

inf.open("studentInfo.txt", ios::app);
inf>>bloodGrp;
cout<<bloodGrp<<" ";
inf.close();

return 0;
}
