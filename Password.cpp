// Online C++ compiler to run C++ program online
#include <iostream>
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class Bank{
    string pw , chkpw;
  public:void chk(){
    bool upper_case = false; //saves the result if upper-casecharacters were found.
    bool lower_case = false; //same for lower-case
    bool number_case = false; //...
    bool special_char = false;

    regex upper{ "[A-Z]+" }; //here is the very simple expression for upper_case search
    regex lower{ "[a-z]+" }; //for lower-case
    regex number_exp{ "[0-9]+" }; //...
    regex special{ "[@!?]+"};
    


    bool done = false; //let's assume we're not done
    do{ //do ask-for-password as long were not done
cout<<"-=========WELCOME CREATE A PASSWORD=============-\n"<<endl;
 cout<<"Password length must be 8 or more than it \n Should Contain one special character \n Should contain one upper case and lower case letter and one digit"<<endl;
        cout << "Type in a valid password: ";
        //get input
        cin>>pw;
        if (pw.length() <= 8){ //too short!
        cout <<"Invalid password length ! Try again . . .\n\n";
        }
        else{

            upper_case=regex_search(pw, upper); //save the result, if the expression was found.
            lower_case=regex_search(pw, lower); //....
            number_case=regex_search(pw, number_exp);
        special_char=regex_search(pw,special);

            //like: sum_of_positive_results = 1 + 1 + 1 + 1 (true/false as an integer)
            int sum_of_positive_results = upper_case + lower_case + number_case + special_char; 

            if (sum_of_positive_results < 4){
            cout << "Invalid password! Try again . . .\n\n";
            }
            else{ //otherwise it's valid!
            cout << "That's a valid Password!" <<endl;
                done =true;
            }
        }

    } while (!done);
}
 public: void login(){
     int c=0;
     
    for(int i=0;i<5;i++){
        cout<<" \n Enter password"<<endl;
     cin>>chkpw;
        if(pw==chkpw){
            cout<<"Login successfull";
        break;
        }
        if(c==3){
            cout<<"It's your last chance \n";
        }
        if(c==4){
            cout<<"Sorry Your have tried multiple times your account is blocked on temporarily basis\n";
            
        }
        else{
            cout<<"try again Invalid password"<<endl;
            c++;
        }
        
    }
option();
}
   public: void option(){
       
       g:
    cout<<"\n 1. Create Password \n2. Login \n3. Exit\n";
    int choice;
    cout<<"Enter choice\n";
    cin>>choice;
    switch(choice){
        case 1:
        chk();
        goto g;
        break;
        case 2:
     login();
        break;
        goto g;
        case 3:
         exit(0);
        default:
        cout<<"Invalid choice"<<endl;
      goto g;  
    } 
    }
};
int main(){
    Bank b;
    b.option();
    return 0;
}

 
