#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class User_authentication{
    protected:
        string first_name;
        string last_name;
        long long int phone_number;
        string email;
        string password;
    public:
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
        }
};

int main()
{
    User_authentication u1;
    u1.signup();


return 0;
}