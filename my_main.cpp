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
                        "price : "<< 95000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 85000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 150000<<endl<<
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
                        "price : "<< 90000<<endl<<
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
                        "price : "<< 70000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 115000<<endl<<
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
                        "price : "<< 70000<<endl<<
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
                        "price : "<< 75000<<endl<<
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
                        "price : "<< 80000<<endl<<
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
                        "price : "<< 95000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 85000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 150000<<endl<<
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
                        "price : "<< 90000<<endl<<
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
                        "price : "<< 70000<<endl<<
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
                        "price : "<< 75000<<endl<<
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
                        "price : "<< 65000<<endl<<
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
                        "price : "<< 80000<<endl<<
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
                        "price : "<< 85000<<endl<<
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
                        "price : "<< 90000<<endl<<
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
                        "price : "<< 95000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 85000<<endl<<
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
                        "price : "<< 110000<<endl<<
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
                        "price : "<< 150000<<endl<<
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
                        "price : "<< 90000<<endl<<
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
                        "price : "<< 70000<<endl<<
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
                        "price : "<< 75000<<endl<<
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
                        "price : "<< 65000<<endl<<
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
                        "price : "<< 80000<<endl<<
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
                        "price : "<< 85000<<endl<<
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
                        "price : "<< 90000<<endl<<
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