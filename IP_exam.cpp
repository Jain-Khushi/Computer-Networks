//Name : KHUSHI JAIN
//Roll no. : 204024

#include<iostream>
using namespace std;

class ip{
    string IP; //Taking ip address in string format 
    public:
    void input();
    void checkClass(string c);
};

void ip::input(){
    cout<<endl;
    cout<<"Enter the IP address: "<<endl;
    cin>>IP;
    string c="";
    for(int i =0;i<IP.length();i++){
        if(IP[i]!='.')
        c+=IP[i];
        else break;
    }
    checkClass(c);

}

// Function to find out the Class
void ip::checkClass(string c){
    int num= stoi(c);
    cout<<"\n";
    if(num>=0 && num<=127)
    cout<<"Given IP address belongs to CLASS A";
    else if(num>=128 && num<=191)
    cout<<"Given IP address belongs to CLASS B";
    else if(num>=192 && num<=223)
    cout<<"Given IP address belongs to CLASS C";
    else if(num>=224 && num<=239)
    cout<<"Given IP address belongs to CLASS D";
    else if(num>=240 && num<=255)
    cout<<"Given IP address belongs to CLASS E";
    else cout<<"INVALID.";
}

// Driver code
int main(){
    ip a;
    a.input();
    return 0;
}