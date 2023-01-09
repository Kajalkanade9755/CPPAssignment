#include<iostream>
#include<string.h>
#include<ctime>
#include<fstream>
using namespace std;
class ManageProject{
  public : 
  int PId;//Project ID number(4) auto increment
int EId;//Created By number(4) = Employee ID of login Employee
string Description;//Project Description string(50)
char *date;//Create Date date (DD/MM/YYYY format) = today’s date
int duration;//Project Duration int(2) = number of months
string Depat;//Department string(50)
string Group;//Group string(50)
ManageProject(){
    PId=0;
}
int get_id();
void getdata();  
void showdata();
 void Add();
 void Modify();
 void Delete();
 void option();
};
int ManageProject::get_id(){
    ifstream infile("project.txt",ios::in);
    int number;
    while(!infile.eof()){
        infile>>PId;
        infile>>EId;
        infile>>Description;
        infile>>date;
        infile>>duration;
        infile>>Depat;
        infile>>Group;
        if(infile.eof()){
            break;
        }
    }
        number=PId;
        number=number+1;//autoincrement
        infile.close();
        return number;
}

void ManageProject:: showdata(){
   ifstream infile("projects.txt",ios::in);
   cout<<"\n data from file"<<endl;
    while(!infile.eof()){
        infile>>PId;
        infile>>EId;
        infile>>Description;
        infile>>date;
        infile>>duration;
        infile>>Depat;
        infile>>Group;
        if(infile.eof()){
            break;
        }
        cout<<"\n"<<PId<<EId<<Description<<date<<duration<<Depat<<Group<<endl;
    }
   
}
void ManageProject:: getdata(){
      ofstream outfile("projects.txt",ios::out|ios::app);
       cout<<"Project id is created"<<endl;
      PId=get_id();
      cout<<PId<<endl;
      cout<<"Your Employee id is taken from login"<<endl;
      cout<<EId<<endl;;
      cout<<"Enter Description"<<endl;
      cin>>Description;
      cout<<"Current date is taken"<<endl;
      time_t tmNow = time(0);
      date = ctime(&tmNow);
       cout<<"Enter duration"<<endl;
       cin>>duration;
        cout<<"Enter Department"<<endl;
         cin>>Depat;
         cout<<"Enter Group"<<endl;
          cin>>Group;
          outfile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
 cout<<"\n"<<PId<<EId<<Description<<date<<duration<<Depat<<Group<<endl;
    
}
 void ManageProject::Add(){
    getdata();  
  }
void ManageProject::Modify(){
      
  }
void ManageProject::Delete(){
      
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
    
int main(){
    ManageProject p;
//    p.showdata();
   // p.getdata();
   p.option();
    return 0;
}
