#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>
#include <ctime>
#include <array>
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
    string cnic,passport,phone_number;
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
        getline(cin,phone_number);
        if(check_valid_cnic_passport_phonenumber(phone_number)==false){
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
        cout<<"Phone Number="<<phone_number<<endl;
    }
    
};
class user_authentication:public person{  // class have function for signup , login and forgot password
    protected:
    string email;
    string password;
    public:
    bool check_signup=false;
    static vector<user_authentication> user;
    void signup(){   //in this function take details and valide it 
        person::person_input();  // for name and other enteries
        cout<<"Enter email =";
        getline(cin,email);
        cout<<"Enter password=";
        cout<<"Set your password according to criteria\n"
            "Password must have at least 8 characters\n"
            "password must have one upercase,lowercase,digit\n"
            "and special character"<<endl;
            bool overall_check=false;
            do{
                bool uper_case_check=false;
                bool lower_case_check=false;
                bool digit_check=false;
                bool special_char_check=false;
                cout<<endl;
                cout<<"Enter Password=";
                getline(cin,password);
                int len=password.length();
                if(len>=8){
                for(int i=0;i<len;i++){
                    if(isupper(password[i])){
                        uper_case_check=true;
                    }
                    else if(islower(password[i])){
                        lower_case_check=true;
                    }
                    else if(isdigit(password[i])){
                        digit_check=true;
                    }
                    else if(ispunct(password[i])){   // special characters
                        special_char_check=true;
                    }
                }
                    if(uper_case_check==true&&lower_case_check==true&&digit_check==true&&special_char_check==true){
                        overall_check=true;
                        break;
                    }
                    else {
                        cout<<endl;
                        cout<<"password does not match the given criteria Try Again!!"<<endl;
                    }  
            }
            else {
                    cout<<"password atleast 8 character long \n";
                }
            }
            while(!overall_check);  // it turn true into false and loop ends
            cout<<endl;
        cout<<"Account Created Successfully!!"<<endl;
        check_signup=true;
        user.push_back(*this);  
        }
         // it push back the detail in vector when it function is called
        static int login(){     // login again after signup
            string temp_mail,temp_password;
            cout<<"Enter email=";
            getline(cin,temp_mail);
            cout<<"Enter Password=";
            getline(cin,temp_password);
            for(auto &u:user){
                if(u.email==temp_mail&&u.password==temp_password){
                    cout<<"Login Successfully !!"<<endl;
                    return 0;
                }
            }
            cout<<"Email or password does not match with user credentials!"<<endl;
            return -1;
        }
        void static check_details(){    //will check why static??
            string temp_mail, temp_password;
            cout<<"Enter email=";
            getline(cin,temp_mail);
            cout<<"Enter password=";
            getline(cin,temp_password);
            bool find=false;
            for (auto &u:user){
            if(u.email==temp_mail && u.password==temp_password ){
                 cout<<"\nHere are your details:\n"<<endl;
                            cout<<"Your first name = "<<u.first_name<<endl;
                            cout<<"Your last name = "<<u.last_name<<endl;
                            cout<<"Your CNIC = "<<u.cnic<<endl;
                            cout<<"Your phone number = "<<u.phone_number<<endl;
                            cout<<"Your email = "<<u.email<<endl;
                            cout<<"Your Password = "<<u.password<<endl;
                            find=true;
                            break;
            }
            }
             if(!find){             
                cout<<"Email or password does not match with user credentials!"<<endl;
            }
        }
        void edit_details(){
            string temp_mail,temp_password;
            cout<<"Enter email=";
            getline(cin,temp_mail);
            cout<<"Enter Password=";
            getline(cin,temp_password);
            bool find=false;
            for(auto &u:user){
                if(u.email==temp_mail && u.password==password){
                    u.person_input();
                    cout<<endl;
                    cout<<"Details changed successfully!!!"<<endl;
                    find=true;
                    break;
                }
                
            }
            if(!find){
                   cout<<"Email or password does not match with user credentials!"<<endl;
            }
        }
        void forgot_password(){
            string temp_mail,temp_password;
            bool ph_n=false;
            do{
                cout<<"Enter your email=";
                getline(cin,temp_mail);
                string phone_n;
                cout<<"Enter phone number=";
                getline(cin,phone_n);
                bool validate=false;
                do{
                if(check_valid_cnic_passport_phonenumber(phone_n)==true){
                validate=true;
                }
                else {
                    cout<<"Enter valid phone number"<<endl;
                    getline(cin,phone_n);
                }

                }
                while(!validate);
                for(auto &u:user){
                    if(u.phone_number==phone_n && u.email==temp_mail){
                        ph_n=true;
                        break;
                    }
                }
                if(!ph_n){
                    cout<<endl;
                    cout<<"invalid credentials!!"<<endl;
                    return;
                }
                break;  
            }
            while(true);
            do{
                cout<<"Enter 4 digit conde sent to you number=";
                cin>>temp_password;
                if(temp_password.length()==4){
                    break;
                }
                cout<<endl;
                cout<<"password must have 4 digit"<<endl;
            }
            while(true);
            for(auto &u:user){
                if(u.email==temp_mail){
                    cout<<endl;
                    cout<<"Set your password according to criteria\n"
                            "Password must have at least 8 characters\n"
                            "password must have one upercase,lowercase,digit\n"
                            "and special character"<<endl;
                            bool overall_check=false;
                            do
                            {
                                bool upper_case_check=false;
                                bool lower_case_check=false;
                                bool digit_check=false;
                                bool special_char_check=false;
                                cout<<endl;
                                cout<<"Enter New Password = ";
                                getline(cin,u.password);
                                int len=u.password.length();
                                if (len>=8)
                                {
                                    for (int i = 0; i < len; i++)
                                    {
                                        if (isupper(u.password[i]))
                                            {
                                                upper_case_check=true;
                                                
                                            }
                                        else if (islower(u.password[i]))
                                            {
                                                lower_case_check=true;
                                                
                                            }
                                        else if (isdigit(u.password[i]))
                                            {
                                                digit_check=true;
                                                
                                            }
                                        else if (ispunct(u.password[i]))
                                            {
                                                special_char_check=true;
                                                
                                            }
                                    }
                                    if (upper_case_check==true && lower_case_check==true &&
                                            digit_check==true && special_char_check==true)
                                            {
                                                overall_check=true;
                                                cout<<endl;
                                                cout<<"Password Changed Seccessfully!"<<endl;
                                                cout<<endl;
                                                break;
                                            }
                                        else{
                                            cout<<endl;
                                            cout<<"Password does not match with criteria Try Again!"<<endl;
                                        } 
                                }
                                else
                                    {
                                        cout<<"Password must have atleast 8 characters long!\n";
                                    } 
             }
                while (!overall_check);
               }
            }
        }

};
vector<user_authentication> user_authentication::user;

int main(){
    
}