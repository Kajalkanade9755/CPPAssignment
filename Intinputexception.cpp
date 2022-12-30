// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
int main() {
    int opc;
    bool aux = true;
    cin.exceptions(istream::failbit);
    do {
        try {
            cout << "PLEASE INSERT VALUE:" << endl;
            cin >> opc;
            aux = true;
        }
        catch (ios_base::failure & fail) {
            aux = false;
            cout << "PLEASE INSERT A VALID OPTION." << endl;
            cin.clear();
            string tmp;
            getline(cin, tmp);
            //cin>>tmp;
           // cout<<tmp;
        }
    } while (aux == false);
    //system("PAUSE");
  cout<<opc;  
}
