#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cstdio>
#include<regex>
using namespace std;
#define LEN 50
int inputnum();
string inputstr();
class ManageProject{
  public :
 int PId;//Project ID number(4) auto increment
int EId;//Created By number(4) = Employee ID of login Employee
string Description;//Project Description string(50)
char date[80];//Create Date date (DD/MM/YYYY format) = today’s date
int duration;//Project Duration int(2) = number of months
string Depat;//Department string(50)
string Group;//Group string(50)
ManageProject(){
 PId=100;
}
int c=100;
int get_id();
void getdata();
void showdata();
 void Add();
 void Modify();
 void Delete();
 void option();
};
int ManageProject::get_id(){
const string filename = "projects.txt";
 string l;
  ifstream fs(filename);
  if(fs.is_open()){
    while(!fs.eof()){
        getline(fs,l);
        c++;
    }
    fs.close();
  //  cout<<"number of count"<<c<<endl;
  }
  else{
    cout<<"cant open\n";
  }

return c;
}
void ManageProject:: getdata(){
       cout<<"Project id is created"<<endl;
      PId=get_id();
      cout<<PId<<endl;
      cout<<"Your Employee id is taken from login"<<endl;
      cout<<EId<<endl;;
      cout<<"Enter Description"<<endl;
      cin.ignore();
      Description=inputstr();
      cout<<"Current date is taken"<<endl;
      time_t tmNow = time(0);
      strftime(date, 80, "%d/%m/%Y", localtime(&tmNow));
       cout<<"Enter duration"<<endl;
duration= inputnum();
        cout<<"Enter Department"<<endl;
        cin.ignore();
    Depat=inputstr();
         cout<<"Enter Group"<<endl;
     Group=inputstr();
                  ofstream outfile("projects.txt",ios::out|ios::app);
       cout<<"Project id is created"<<endl;
          outfile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
 cout<<"\n"<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
outfile.close();
}
void ManageProject:: showdata(){
    string str;
   ifstream infile("projects.txt",ios::in);
   cout<<"enter id\n";
   int id=inputnum();
   //cin>>id;
    int PId;//Project ID number(4) auto increment
int EId;//Created By number(4) = Employee ID of login Employee
string Description;//Project Description string(50)
//string date;//Create Date date (DD/MM/YYYY format) = today’s date
int duration;//Project Duration int(2) = number of months
string Depat;//Department string(50)
string Group;
   cout<<"\n data from file"<<endl;
 /* while(!infile.eof()){

         if(str.length()>0){
            getline(infile,str);
            PId=stoi(str);
             getline(infile,str);
             EId=stoi(str);
              getline(infile,str);
              Description=str;
             // getline(infile,str);
              //date=str;
              //getline(infile,str);
              //duration=stoi(str);
              //getline(infile,str);
              //Depat=str;
              //getline(infile,str);
              //Group=str;

         }

        if(infile.eof()){
          break;
        }}*/
     // cout<<"\n"<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
while(!infile.eof()){
        getline(infile,str);
cout<<""<<str<<"\n";
    }

}

 void ManageProject::Add(){
    getdata();
    showdata();
  }
void ManageProject::Modify(){

  }
void ManageProject::Delete(){


int id;
cout<<"enter: \n";
cin>>id;
ifstream read;
read.open("ticketts.txt");
string ch;
//getline(read,ch);
//cout<<ch;
while(!read.eof())
{
  getline(read,ch);  //cout<<"infile"<<endl;
while(sscanf(ch.c_str(), "%d,%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],*[\n]",&PId,&EId,Description,date,&duration,Depat,Group)==7) {
       //cout<<"infile"<<endl;
        if (duration == id) {
                cout<<id<<"Id "<<endl;
                //read<<89;
        break;
}
}
}

  }
 void ManageProject::option(){
box:
cout<<"  -------------------------- Projects Menu---------------------------"<<endl;
 cout<<"1. Add Project"<<endl;
 cout<<"2. Modify Project"<<endl;
 cout<<"3. Delete Project"<<endl;
 cout<<"0. Quit"<<endl;
int ch;
cout<<"Enter your choice\n";
cin>>ch;
switch(ch){
    case 1:
    Add();
    break;
    case 2:
    Modify();
    break;
    case 3:
    Delete();
    break;
    case 0:
    exit(0);
    break;
    default:
    cout<<"Invalid choice"<<endl;
    goto box;
    break;
}
   }

   int inputnum(){
string str;
regex regex_int("[0-9]+");
do{
    cout<<"Input a integer only: ";
    cin>>str;
}
while(!regex_match(str,regex_int));
return stoi(str);
}

 string inputstr(){
string str;
regex regex_int("^.{1,50}$");
do{
    cout<<"Input length must be between 1 to 50 only: ";
    getline(cin,str);
}
while(!regex_match(str,regex_int));
return str;
}

int main(){
    ManageProject p;
   p.option();
    return 0;
}
