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

// Flights And Airport Data Class

class Flights{
    protected:
        void pakistan_airports(){
            cout<<"1.Allama Iqbal International Airport\tLahore"<<endl;
            cout<<"2.Faisalabad International Airport\tFaisalabad"<<endl;
            cout<<"3.Islamabad International Airport\tIslamabad"<<endl;
        }
        void uae(){
            cout<<"1.Dubai International Airport\tDubai"<<endl;
            cout<<"2.Sharjah International Airport\tSharjah"<<endl;
            cout<<"3.Abu Dhabi International Airport\tAbu Dhabi"<<endl;
        }
        void saudi_arabia(){
            cout<<"1.King Khalid International Airport\tRiyadh"<<endl;
            cout<<"2.King Fahd International Airport\tDammam"<<endl;
            cout<<"3.King Abdulaziz International Airport\tJeddah"<<endl;
        }

        // List of Airport Flights
        void Allama_Iqbal(int d,int m,int y,string country,bool return_type=false,string arrival_airport){
            string lower_case;
            string lower_case_ai;
                // for converting into lower case
                for (size_t i = 0; i < country.size(); i++)
                {
                    lower_case.push_back(tolower(country[i]));
                }
                for (size_t i = 0; i < arrival_airport.size(); i++)
                {
                    lower_case_ai.push_back(tolower(arrival_airport[i]));
                }
            if (return_type)
            {
                if (lower_case=="uae")
                {
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : LHE-DXB-301R"<<endl<<
                        "flight_name : PIA Gulf1"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 95000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 110000<<endl;
                    }else{
                        cout<<"flight_id : LHE-AIA-101A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 85000<<endl;
                    }
                    
                    
                }else if (lower_case=="saudi arabia")
                {
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : LHE-KIA-409F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 110000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 150000<<endl;
                    }else{
                        cout<<"flight_id : LHE-AIA-301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 90000<<endl;
                    }   
                }
            }else{
                if (lower_case=="uae"){
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : LHE-DXB-301R"<<endl<<
                        "flight_name : PIA Express"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 70000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 110000<<endl;
                    }else{
                        cout<<"flight_id : LHE-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 115000<<endl;
                    }
                }else if(lower_case=="saudi arabia"){
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : LHE-KIA-1209F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 70000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : LHE-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 75000<<endl;
                    }else{
                        cout<<"flight_id : LHE-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 80000<<endl;
                    }
                }
                    
            }
            
        }
        void faisalabad(int d,int m,int y,string country,bool return_type=false,string arrival_airport){
            string lower_case;
            string lower_case_ai;
                // for converting into lower case
                for (size_t i = 0; i < country.size(); i++)
                {
                    lower_case.push_back(tolower(country[i]));
                }
                for (size_t i = 0; i < arrival_airport.size(); i++)
                {
                    lower_case_ai.push_back(tolower(arrival_airport[i]));
                }
            if (return_type)
            {
                if (lower_case=="uae")
                {
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : FIA-DXB-3501R"<<endl<<
                        "flight_name : PIA Gulf1"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 95000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : FIA-SIA-2041F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 110000<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-1011A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 85000<<endl;
                    }    
                }else if (lower_case=="saudi arabia")
                {
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : FIA-KIA-2409F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 110000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : FIA-SIA-3201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 150000<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-3301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 90000<<endl;
                    }   
                }     
            }else{
                if (lower_case=="uae"){
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : FIA-DXB-6301R"<<endl<<
                        "flight_name : PIA Express"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 70000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : FIA-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 75000<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 65000<<endl;
                    }
                }
                else if (lower_case=="saudi arabia")
                {
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : FIA-KIA-1209F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 80000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : FIA-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 85000<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 90000<<endl;
                    }
                }       
            }      
        }
        void islamabad(int d,int m,int y,string country,bool return_type=false,string arrival_airport){
            string lower_case;
            string lower_case_ai;
                // for converting into lower case
                for (size_t i = 0; i < country.size(); i++)
                {
                    lower_case.push_back(tolower(country[i]));
                }
                for (size_t i = 0; i < arrival_airport.size(); i++)
                {
                    lower_case_ai.push_back(tolower(arrival_airport[i]));
                }
            if (return_type)
            {
                if (lower_case=="uae")
                {
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : ISB-DXB-3501R"<<endl<<
                        "flight_name : PIA Gulf1"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 95000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : ISB-SIA-2041F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 110000<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-1011A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 85000<<endl;
                    }
                    
                    
                }else if (lower_case=="saudi arabia")
                {
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : ISB-KIA-2409F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price"<< 110000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : ISB-SIA-3201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price"<< 150000<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-3301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "return_date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price"<< 90000<<endl;
                    }
                    
                }
                
                
            }else{
                if (lower_case=="uae"){
                    if (lower_case_ai=="dia")
                    {
                        cout<<"flight_id : ISB-DXB-6301R"<<endl<<
                        "flight_name : PIA Express"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 70000<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : ISB-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 75000<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 65000<<endl;
                    }
                }
                else if (lower_case=="saudi arabia")
                {
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : ISB-KIA-1209F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 80000<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : ISB-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 85000<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date"<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price"<< 90000<<endl;
                    }
                }   
            }
        }
};



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