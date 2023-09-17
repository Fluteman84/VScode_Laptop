#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<ctime>
#include<conio.h>

using namespace std;

int PId=1;

class Emp{
    int Id,d,m,y;
    string fname,mname,lname,email;
    int age[3];
    string altemail={0};
    long long int phnum,phnum2=0,aadhar;

    public:
    void enter_name(){
        string name;
        getline(cin,name);
        istringstream iss(name);
        iss>>this->fname>>this->mname>>this->lname;
    }
    void enter_dob(){
        string dob;
        getline(cin,dob);
        d=stoi(dob.substr(0,2));
        m=stoi(dob.substr(3,2));
        y=stoi(dob.substr(6,4));
        get_age(d,m,y);
    }
    void getdata(){
        cout<<"Enter the name of the Employee-";
        enter_name();
        cout<<"Enter Details for Date Of Birth(should be in DD/MM/YYYY format)"<<endl<<"Date-";
        enter_dob();
        cout<<"Enter Email address:";
        cin>>email;
        cout<<"Enter Phone Number:";
        cin>>phnum;
        cout<<"Do you want to add another Phone Number? (If yes press any key, else press 0)";
        if(getch()!='0')
            cin>>phnum2;
        else
            cout<<endl;
        cout<<"Enter Aadhar Number:";
        cin>>aadhar;
    }
    void get_age(int d,int m ,int y){
        time_t t=time(nullptr);
        tm* local_t=localtime(&t);
        int local_d=local_t->tm_mday;
        int local_m=local_t->tm_mon+1;
        int local_yr=local_t->tm_year+1900;
        age[0]=local_d-d;
        age[1]=local_m-m;
        age[2]=local_yr-y;
    }
    void showdata(){
        cout<<"Name-"<<fname<<" "<<mname<<" "<<lname;
        cout<<"\nAge- "<<age[2]<<"year "<<age[1]<<"month "<<age[0]<<"days";
        cout<<"\nEmail Address:"<<email;
        cout<<"\nPhone Number:"<<phnum;
        if(phnum2!=0)
            cout<<","<<phnum2;
        cout<<"\nAadhar Number:"<<aadhar;
    }
};
void initiate_file(){
    
}
int main(){
    Emp E;
    E.getdata();
    E.showdata();
    return 0;
}