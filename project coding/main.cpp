#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
#define UAE_PRICE 100000
#define SA_PRICE  150000
using namespace std;
// this function will check that the name only contain alphabets 
bool check_valid_name(string name){
    string special_character="`~!@#$%^&*)(-_=+][}{\";:'|?/.,<>";
    int i=0;
    for (auto &ch:name){  // auto will detect the datatype of the name
        if(isdigit(ch)){
            return false;
        }
        for(auto &j:special_character){  //everyspecial character will be compared with every charater of name
            if(ch==j){
                return false;
            }
        }
    }
    return true;
}
bool check_valid_cnic_passport_phonenumber(string checker){  // global function to validate the cnic ,passport,phone
    string Scharacter_alphabets="`~!@#$%^&*)(-_=+][}{\";:'|?/.,<>abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVQXYZ";
    for (auto &dig:checker){
        for (auto &ch:Scharacter_alphabets ){
            if(dig==ch){
                return false;
            }
        }
    }
    return true;
}
class person{
    protected:
    string first_name,last_name;
    string cnic,passport,phone;
    //int int long cnic,passport,phone;
    public:
    
    void person_input(){ // this function take input and validate all the inputs
        do{
        cout<<"Enter First Name=";
        getline(cin,first_name);
        if(check_valid_name(first_name)==false){
             cout<<endl;
             cout<<"charcter and numbers are not allowed \n "<<endl;
             continue;
        }
        break;
    }
    while(true);
    do{
        cout<<"Enter Last Name= ";
        getline(cin,last_name);
        if(check_valid_name(last_name)==false){
            cout<<endl;
            cout<<"characters and numbers are allowed \n"<<endl;
            continue;
        }
        break;
    }
    while(true);
    // do
    //         {
    //             cout<<"Enter CNIC = ";
    //             cin>>cnic;
    //             if (!cin)
    //                 {
    //                     cin.clear();
    //                     cin.ignore(1000,'\n');
    //                     cout<<"Enter valid CNIC!"<<endl;
    //                     continue;
    //                 }
    //             cout<<"Enter Passport = ";
    //             cin>>passport;
    //             if (!cin)
    //                 {
    //                     cin.clear();
    //                     cin.ignore(1000,'\n');
    //                     cout<<"Enter valid Passport!"<<endl;
    //                     continue;
    //                 }
    //             cout<<"Enter Phone Number = ";
    //             cin>>phone_number;
    //             if (!cin)
    //                 {
    //                     cin.clear();
    //                     cin.ignore(1000,'\n');
    //                     cout<<"Enter valid Phone Number!"<<endl;
    //                     continue;
    //                 }
    //             break;
    //         } while (true);
    do{
        cout<<"Enter CNIC=";
        getline(cin,cnic);
        if(check_valid_cnic_passport_phonenumber(cnic)==false){
            cout<<endl;
            cout<<"Enter Valid CNIC \n"<<endl;
            continue;
        }
        break;
    }
    while(true);
    do{
        cout<<"Enter Passport=";
        getline(cin,passport);
        if(check_valid_cnic_passport_phonenumber(passport)==false){
            cout<<endl;
            cout<<"Enter Valid Passport \n"<<endl;
            continue;
        }
        break;
    }
    while(true);
    do{
        cout<<"Enter Phone number=";
        getline(cin,phone);
        if(check_valid_cnic_passport_phonenumber(phone)==false){
            cout<<endl;
            cout<<"Enter Valid Phone number \n"<<endl;
            continue;
        }
        break;
    }
     while(true);
    }
    void show(){
        cout<<"First Name="<<first_name<<endl;
        cout<<"Last Name="<<last_name<<endl;
        cout<<"CNIC="<<cnic<<endl;
        cout<<"Passport="<<passport<<endl;
        cout<<"Phone Number="<<phone<<endl;
    }
    
};
class user_authentication:public person{  // class have function for signup , login and forgot password
    protected:
    string email;
    string password;
    public:
    bool check_signup=false;
    static vector<user_authentication> user;
    void signup(){
        person::person_input();
        cout<<"Enter email =";
        getline(cin,email);
        cout<<"Enter password=";
        cout<<"Set your password according to criteria\n"
            "Password must have at least 8 characters\n"
            "password must have one upercase,lowercase,digit\n"
            "and special character"<<endl;
       }
};

int main(){
    person p1;
    p1.person_input();
    p1.show();
}