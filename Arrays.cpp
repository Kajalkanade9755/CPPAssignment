// Online C++ compiler to run C++ program on
#include<iostream>

using namespace std;
class Ary{
public:
int size;
int *arr=new int[size];
 void Add(){
    cout<<"enter size"<<endl;
    cin>>size;
    cout<<"Enter elements of array"<<endl;
for(int i=0;i<size;i++){
    cout<<"Enter : ";
    cin>>arr[i];
}
for(int i=0;i<size;i++){
    cout<<arr[i]<<"\n";
}
   
}

void del(){
    delete []arr; 
}

void display(){
    for(int i=0;i<size;i++){
    cout<<arr[i]<<"\n";
}
}
void Adele(){
    int n,i;
    int tobemoved=size-1;
    cout<<"enter location"<<endl;
    cin>>i;
    cout<<"Enter Element to be inserted"<<endl;
    cin>>n;
    while(tobemoved>=i){
        arr[tobemoved+1]=arr[tobemoved];
        --tobemoved;
    }
  arr[i]=n;
  ++size;
}
void Delele(){
    int i,found=0;
     cout<<"enter value to be deleted"<<endl;
    cin>>i;
    for(int j=0;j<size;j++){
        if(arr[j]==i){
            for(int k=j;k<size-1;k++)
            arr[k]=arr[k+1];
            found++;
            j--;
            size--;
        }
    }
    if(found==0){
        cout<<"Elent doesn't found"<<endl;
    }
    else{
        cout<<"Deleted"<<endl;
    }
}
void Manager()

{
    l:
int ch,s;
cout<<"Welcome to the world of array \n";
cout<<"\n Choose your option:";
cout<<"1.Initialize The Size of An Array and add values\n";
cout<<"2.Delete the Array \n";
cout<<"3.Delete value from Array \n";
cout<<"4.Add Value to a specific position an array \n";
cout<<"5. Display the Array \n";
cout<<"6. Exit \n";
cin>>ch;

switch(ch){
    case 1:
    Add();
     goto l;
    break;
    case 2:
    del();
     goto l;
    break;
    case 3:
    Delele();
    goto l;
    break;
    case 4:
    Adele();
    goto l;
    break;
    case 5:
    display();
     goto l;
     break;
    case 6:
    exit(0);
    break;
    default:
    cout<<"invalid input";
    goto l;
}
}

};
int main(){
 
    Ary a;
    a.Manager();
}
