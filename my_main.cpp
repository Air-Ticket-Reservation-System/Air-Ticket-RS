#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class User_authentication{
    protected:
        string first_name;
        string last_name;
        long long int phone_number;
        string email;
        string password;
    public:
        bool check_signup=false;
        static vector<User_authentication> user;
        void signup(){
            cout<<"Enter your first name = ";
            getline(cin,first_name);
            cout<<"Enter your last name = ";
            getline(cin,last_name);
            cout<<"Enter your phone number = ";
            cin>>phone_number;
            cin.ignore();
            cout<<"Enter your email = ";
            getline(cin,email);
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
                cout<<"Enter your password = ";
                getline(cin,password);
                int len=password.length();
                if (len>=8)
                {
                    for (size_t i = 0; i < len; i++)
                    {
                        if (isupper(password[i]))
                        {
                            upper_case_check=true;
                            
                        }
                        else if (islower(password[i]))
                        {
                            lower_case_check=true;
                            
                        }
                        else if (isdigit(password[i]))
                        {
                            digit_check=true;
                            
                        }
                        else if (ispunct(password[i]))
                        {
                            special_char_check=true;
                            
                        }
                    }
                    if (upper_case_check==true && lower_case_check==true &&
                            digit_check==true && special_char_check==true)
                            {
                                overall_check=true;
                                break;
                            }
                        else{
                            cout<<endl;
                            cout<<"Password does not match with criteria Try Again!"<<endl;
                        } 
                }else{
                    cout<<"Password must have atleast 8 characters long!\n";
                } 
            } while (!overall_check);
            cout<<endl;
            cout<<"Account Created successfully!"<<endl;
            check_signup=true;
            user.push_back(*this);
        }
        void login(){
            string temp_mail,temp_password;
            cout<<"Enter your email = ";
            getline(cin,temp_mail);
            cout<<"Enter your Password = ";
            getline(cin,temp_password);
            if (check_signup)
            {
                bool find=false;
                for (auto &u:user)
                {
                    if (u.email==temp_mail && u.password==temp_password)
                        {
                            cout<<"Login successful"<<endl;
                            find=true;
                            break;
                        }
                }
                if (!find)
                {
                   cout<<"Email or password does not match with user credentials!"<<endl;
                }
                
            }else
                {
                    cout<<"Please sign up first!"<<endl;
                }
            }
        void check_details(){
            string temp_mail,temp_password;
            cout<<"Enter your email = ";
            getline(cin,temp_mail);
            cout<<"Enter your Password = ";
            getline(cin,temp_password);
            if (check_signup)
            {
                bool find=false;
                for (auto &u:user)
                {
                    if (u.email==temp_mail && u.password==temp_password)
                        {
                            cout<<"\nHere are your details:\n"<<endl;
                            cout<<"Your first name = "<<u.first_name<<endl;
                            cout<<"Your last name = "<<u.last_name<<endl;
                            cout<<"Your phone number = "<<u.phone_number<<endl;
                            cout<<"Your email = "<<u.email<<endl;
                            cout<<"Your Password = "<<u.password<<endl;
                            find=true;
                            break;
                        }
                }
                if (!find)
                {
                   cout<<"Email or password does not match with user credentials!"<<endl;
                }
            }else{
                cout<<"You do not have any account yet!"<<endl;
            }
        }
        void edit_details(){
            string temp_mail,temp_password;
            cout<<"Enter your email = ";
            getline(cin,temp_mail);
            cout<<"Enter your Password = ";
            getline(cin,temp_password);
            if (check_signup)
            {
                bool find=false;
                for (auto &u:user)
                {
                    if (u.email==temp_mail && u.password==temp_password)
                        {
                            cout<<"Enter your first name = ";
                            getline(cin,u.first_name);
                            cout<<"Enter your last name = ";
                            getline(cin,u.last_name);
                            cout<<"Enter your phone number = ";
                            cin>>u.phone_number;
                            cin.ignore();
                            cout<<"Enter your email = ";
                            getline(cin,email);
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
                                cout<<"Enter your password = ";
                                getline(cin,password);
                                int len=password.length();
                                if (len>=8)
                                {
                                    for (size_t i = 0; i < len; i++)
                                    {
                                        if (isupper(password[i]))
                                            {
                                                upper_case_check=true;
                                                
                                            }
                                        else if (islower(password[i]))
                                            {
                                                lower_case_check=true;
                                                
                                            }
                                        else if (isdigit(password[i]))
                                            {
                                                digit_check=true;
                                                
                                            }
                                        else if (ispunct(password[i]))
                                            {
                                                special_char_check=true;
                                                
                                            }
                                    }
                                    if (upper_case_check==true && lower_case_check==true &&
                                            digit_check==true && special_char_check==true)
                                            {
                                                overall_check=true;
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
                            } while (!overall_check);
                            cout<<endl;
                            cout<<"Details changed successfully!"<<endl;
                                            find=true;
                                            break;
                            }
                        }
                if (!find)
                {
                   cout<<"Email or password does not match with user credentials!"<<endl;
                }
            }else{
                cout<<"You do not have any account yet!"<<endl;
            }
        }
};
vector<User_authentication> User_authentication::user;
int main()
{
    User_authentication u1,u2;
    u1.signup();
    // u1.login();
    // u1.check_details();
    u1.edit_details();
    // u2.signup();
    // u2.login();
   
    


return 0;
}