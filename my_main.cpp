#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define UAE_PRICE 100000
#define SA_PRICE 150000
using namespace std;
class Person{
    protected:
        string first_name;
        string last_name;
        long long int phone_number,passport,cnic;
    public:
        void person_input(){
            cout<<"Enter First name = ";
            getline(cin,first_name);
            cout<<"Enter Last name = ";
            getline(cin,last_name);
            cout<<"Enter CNIC = ";
            cin>>cnic;
            cin.ignore();
            cout<<"Enter Passport = ";
            cin>>passport;
            cin.ignore();
            cout<<"Enter Phone Number = ";
            cin>>phone_number;
            cin.ignore();
        }
        void show(){
            cout<<"First name = "<<first_name<<endl;
            cout<<"Last name = "<<last_name<<endl;
            cout<<"CNIC = "<<cnic<<endl;
            cout<<"Passport = "<<passport<<endl;
            cout<<"Phone Number = "<<phone_number<<endl;
        }
};
class User_authentication:public Person{
    protected:
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
        int login(){
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
                            return 0;
                        }
                }
                if (!find)
                {
                   cout<<"Email or password does not match with user credentials!"<<endl;
                   return -1;
                }
                
            }else
                {
                    cout<<"Please sign up first!"<<endl;
                    return 1;
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
            cout<<"1.Dubai International Airport(DIA)\tDubai"<<endl;
            cout<<"2.Sharjah International Airport(SIA)\tSharjah"<<endl;
            cout<<"3.Abu Dhabi International Airport(AIA)\tAbu Dhabi"<<endl;
        }
        void saudi_arabia(){
            cout<<"1.King Khalid International Airport(KIA)\tRiyadh"<<endl;
            cout<<"2.King Fahd International Airport(FIA)\tDammam"<<endl;
            cout<<"3.King Abdulaziz International Airport(AIA)\tJeddah"<<endl;
        }

        // List of Airport Flights
        void Allama_Iqbal(int d,int m,int y,string country,string arrival_airport,bool return_type=false){
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else if (lower_case_ai=="aia"){
                        cout<<"flight_id : LHE-AIA-101A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else{
                        cout<<"You Entered wrong Details!"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else {
                        cout<<"flight_id : LHE-AIA-301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

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
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : LHE-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else{
                        cout<<"flight_id : LHE-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }
                }else if(lower_case=="saudi arabia"){
                    if (lower_case_ai=="kia")
                    {
                        cout<<"flight_id : LHE-KIA-1209F"<<endl<<
                        "flight_name : PIA Gulf11"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : LHE-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }else{
                        cout<<"flight_id : LHE-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Lahore"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;

                    }
                }
                    
            }
            
        }
        void faisalabad(int d,int m,int y,string country,string arrival_airport,bool return_type=false){
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : FIA-SIA-2041F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-1011A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : FIA-SIA-3201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-3301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : FIA-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : FIA-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : FIA-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Faisalabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }
                }       
            }      
        }
        void islamabad(int d,int m,int y,string country,string arrival_airport,bool return_type=false){
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : ISB-SIA-2041F"<<endl<<
                        "flight_name : PIA Gulf2"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-1011A"<<endl<<
                        "flight_name : PIA Gulf3"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+4"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+2<10?"0":"")<<d+2<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : ISB-SIA-3201F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+1<10?"0":"")<<d+1<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-3301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : Return"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "Return Date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d+3<10?"0":"")<<d+3<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Return Time : 11:30:00 GMT+3"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="sia")
                    {
                       cout<<"flight_id : ISB-SIA-201F"<<endl<<
                        "flight_name : AirBlue Sky"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-301R"<<endl<<
                        "flight_name : New PIA"<<endl<<
                        "type : One-Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Dubai"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< UAE_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
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
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else if (lower_case_ai=="fia")
                    {
                       cout<<"flight_id : ISB-SIA-2701F"<<endl<<
                        "flight_name : PIA Gulf12"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }else{
                        cout<<"flight_id : ISB-AIA-F301R"<<endl<<
                        "flight_name : PIA Gulf13"<<endl<<
                        "type : One Way"<<endl<<
                        "from : Islamabad"<<endl<<
                        "to : Saudi Arabia"<<endl<<
                        "date : "<<y<<"-"<<(m<10?"0":"")<<m<<"-"<<(d<10?"0":"")<<d<<endl<<
                        "price : "<< SA_PRICE<<endl<<
                        "Bagage Allownce: "<<"10KG\t10000Rs"<<endl<<
                        "\t\t "<<"20KG\t20000Rs"<<endl<<
                        "Departure Time : 08:30:00 GMT+5"<<endl<<
                        "Arrival Time : 10:00:00 GMT+5"<<endl<<
                        "Refund : Available"<<endl<<
                        "Upgrade : Available"<<endl;
                    }
                }   
            }
        }
};

// Flight Searching
struct Date
{
    int date,month,year;
};

class Search_flight:public Flights{
    protected:
        int dept_airport;
        string arrival_airport;
        string arrival_country;
        bool flight_type_return;
        Date d;
    public:
        string toLower(string s) {
        for (auto &c : s) c = tolower(c);
        return s;
        }
        void input_flight_search_details(){
            cout<<"\nThese Airports are available:\n";
            Flights::pakistan_airports();
            cout<<"\n";
            do
            {
                cout<<"Select Departure Airport(1,2,3) = ";
                cin>>dept_airport;
                cin.ignore();
                if (dept_airport==1 || dept_airport==2 || dept_airport==3)
                {
                    break;
                }else{
                    cout<<"You Entered Wrong Details!"<<endl;
                }
                
            } while (true);

            bool check=false;
            do
            {
                string temp_country;
                cout<<"Enter Arrival Country (UAE,Saudi Arabia)= ";
                getline(cin,arrival_country);
                temp_country=toLower(arrival_country);
                
                if (temp_country=="uae")
                {
                    cout<<"\nThese Airports are available:\n";
                    Flights::uae();
                    check=true;
                }else if (temp_country=="saudi arabia")
                {
                    cout<<"\nThese Airports are available:\n";
                    Flights::saudi_arabia();
                    check=true;
                }else{
                    cout<<endl<<"You Entered Wrong Details!"<<endl;
                }
            } while (!check);
            cout<<"\nEnter Arrival Airport(XYZ) = ";
            string temp_airport;
            getline(cin,temp_airport);
            arrival_airport=toLower(temp_airport);
            int choice;
            do
            {
                cout<<"\nSelect Flight Type:\n1.OneWay\n2.Return"<<endl;
                cin>>choice;
                cin.ignore();
                if (choice==1)
                {
                    flight_type_return=false;
                    break;
                }else if (choice==2)
                {
                    flight_type_return=true;
                    break;
                }else{
                    cout<<endl<<"You Entered Wrong Details!"<<endl;
                }
            } while (true);
            cout<<"Enter Departure Date (x/y/z) = ";
            char ch;
            cin>>d.date>>ch>>d.month>>ch>>d.year;
        }
        void show_flights(){
            if (dept_airport==1)
            {
                Flights::Allama_Iqbal(d.date,d.month,d.year,arrival_country,
                arrival_airport,flight_type_return);
            }else if (dept_airport==2)
            {
                Flights::faisalabad(d.date,d.month,d.year,arrival_country,
                arrival_airport,flight_type_return);
            }else{
                Flights::islamabad(d.date,d.month,d.year,arrival_country,
                arrival_airport,flight_type_return);
            }
        }
};

// Seat Management Class
class Seat_management{
    protected:
        int seat_no;
        public:
        static int seats[50];
        static void show_economy_free_seats(){
            cout<<endl<<"Here are the seats available in your selected class:\n"<<endl;
            for (size_t i = 0; i < 30; i++)
            {
                if(seats[i]==0){
                    cout<<i+1<<"\t";
                }
            }
            cout<<endl;
        }
        static void show_buisness_free_seats(){
            cout<<endl<<"Here are the seats available in your selected class:\n"<<endl;
            for (size_t i = 30; i < 40; i++)
            {
                if(seats[i]==0){
                    cout<<i+1<<"\t";
                }
            }
            cout<<endl;
        }
        static void show_first_free_seats(){
            cout<<endl<<"Here are the seats available in your selected class:\n"<<endl;
            for (size_t i = 40; i < 50; i++)
            {
                if(seats[i]==0){
                    cout<<i+1<<"\t";
                }
            }
            cout<<endl;
        }
        void book_seat(int n){
            do
            {
                int start,end;
                if(n==1){start=1,end=30;}
                else if(n==2){start=31,end=40;}
                else if(n==3){start=41,end=50;}
                cout<<"Enter seat number you want to book = ";
                int seat_choice;
                cin>>seat_choice;
                if (seat_choice<start || seat_choice>end)
                {
                    cout<<"Invalid seat number for this class!"<<endl;
                }else{
                
                    if (seats[seat_choice-1]==0)
                    {
                    seats[seat_choice-1]=1; // 1 for seat booked
                    seat_no=seat_choice;
                    cout<<endl<<"Seat selected successfully!"<<endl;
                    break;
                    }else{
                        cout<<endl<<"Seat already Booked!"<<endl;
                    }
                }
            } while (true);
        }
         void cancel_seat(){
            int temp_seat;
            do
            {
                cout<<"Enter your seat number = ";
                cin>>temp_seat;
                cin.ignore();
                if (temp_seat==0 ||temp_seat<0 || temp_seat>50)
                    {
                        cout<<endl<<"Please Sealect a valid seat!"<<endl;
                        continue;
                    }
                if (seats[temp_seat-1]==0)
                    {
                        // To avoid double cancellation
                        cout<<endl<<"Seat is already Freed!"<<endl;
                        continue;
                    }
                if (temp_seat!=seat_no)
                    {
                        cout<<endl<<"This is not your seat!"<<endl;
                        continue;
                    }
               
                   seats[temp_seat-1]=0; // 1 for seat booked
                   seat_no=0;
                   cout<<endl<<"Seat Cancelled successfully!"<<endl;
                   break;
                
            } while (true);
        }
};

int Seat_management::seats[50]={0};



// Booking Class

class Booking:public User_authentication{
    protected:
        int no_of_passengers; //5 passenger allowed at one time
        int adult,infant,child;
        string flight_class;
        float fare;
        vector<Person> person_vector;
        vector<Seat_management> seat_vector;
    public:
        static vector<Booking> book;
        void fare_calculation(string c,float weight){
            do
            {
                if (weight>=0 && weight<=20)
                {
                    if (c=="uae")
                    {
                        fare=UAE_PRICE+(weight*1000);
                        cout<<"Your Total Bill is = "<<fare<<endl;
                        break;
                    }else{
                        fare=SA_PRICE+(weight*1000);
                        cout<<"Your Total Bill is = "<<fare<<endl;
                        break;
                    }
                    
                }else{
                    cout<<"Enter a valid weight = ";
                    cin>>weight;
                }
                
            } while (true);  
        }
        void start_Booking(){
            cout<<"Login if you have an account.\nSignUp if you are new user\n"<<endl;
            int choice;
            bool checking_account=false;
            do
            {
                cout<<"Select one option Below\n1.Login\n2.SignUP\n"<<endl;
                cin>>choice;
                cin.ignore();
                if (choice==1)
                {
                    int n=User_authentication::login();
                    if (n==0)
                    {
                        checking_account=true;
                        break;
                    }  
                }else if (choice==2)
                {
                    User_authentication::signup();
                    checking_account=true;
                    break;
                }else{
                    cout<<"Please give a valid input"<<endl;
                }
            } while (true);
            if (checking_account)
            {
               cout<<"Fill Details Below:\n"<<endl;
               do
               {
                cout<<"Enter number of Passengers (at one time maximum limit 5) = ";
                cin>>no_of_passengers;
                cin.ignore();
                if (no_of_passengers>0 &&no_of_passengers<=5)
                {
                    do
                    {
                        int sum=0;
                        cout<<"How many Adults = ";
                        cin>>adult;
                        cin.ignore();
                        if (sum+adult<=no_of_passengers)
                        {
                            sum+=adult;
                        }else{
                            cout<<"Your selected number of passeger limit reached!\n"<<endl;
                            continue;
                        }
                        cout<<"How many childs = ";
                        cin>>child;
                        cin.ignore();
                        if(sum+child<=no_of_passengers){
                                if (adult>0)
                                {
                                    sum+=child;
                                }else{
                                    cout<<"Child cant travel without An Adult!"<<endl;
                                    continue;
                                } 
                        }else{
                            cout<<"Maximum Limit Reached!"<<endl;
                            break;
                        }
                        cout<<"How many infants = ";
                        cin>>infant;
                        cin.ignore();
                        if(sum+infant<=no_of_passengers){
                                if (adult>0)
                                {
                                    sum+=infant;
                                    break;
                                }else{
                                    cout<<"Infants cant travel without An Adult!"<<endl;
                                    continue;
                                } 
                        }else{
                            cout<<"Maximum Limit Reached!"<<endl;
                            break;
                        }
                    } while (true);
                    for (size_t i = 0; i < no_of_passengers; i++)
                    {
                        cout<<"Enter Passenger "<<i+1<<"details:\n"<<endl;
                        Person p;
                        p.person_input();
                        person_vector.push_back(p);
                        do
                        {
                            cout<<"Enter Class You want to Book:\n1.Economy\n"
                            "2.Business\n3.First Class"<<endl;
                            int class_choice;
                            cin>>class_choice;
                            cin.ignore();
                            if (class_choice<0 || class_choice>3)
                            {
                                cout<<"Please enter a Valid number!\n"<<endl;
                                continue;
                            } 
                            else if (class_choice==1)
                                {
                                    cout<<"Select Seat From selected class!\n"<<endl;
                                    Seat_management s;
                                    s.show_economy_free_seats();
                                    s.book_seat(class_choice);
                                    seat_vector.push_back(s);
                                    break;
                                }
                            else if(class_choice==2)
                                {
                                    cout<<"Select Seat From selected class!\n"<<endl;
                                    Seat_management s;
                                    s.show_buisness_free_seats();
                                    s.book_seat(class_choice);
                                    seat_vector.push_back(s);
                                    break;
                                }
                            else
                                {
                                    cout<<"Select Seat From selected class!\n"<<endl;
                                    Seat_management s;
                                    s.show_first_free_seats();
                                    s.book_seat(class_choice);
                                    seat_vector.push_back(s);
                                    break;
                                }
                        } while (true);
                        //Free Memory
                    }
                }else{
                    cout<<"PLease give valid input!"<<endl;
                }
               } while (true);
            }
        }
};




int main()
{
    // User_authentication u1,u2;
    // u1.signup();
    // // u1.login();
    // // u1.check_details();
    // u1.edit_details();
    // // u2.signup();
    // // u2.login();
    Search_flight s1;
    s1.input_flight_search_details();
    cout<<"\nHere are the Available Flights for date you Entered\n"<<endl;
    s1.show_flights();
   
    


return 0;
}