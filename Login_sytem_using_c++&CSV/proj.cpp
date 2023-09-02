#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<ctime>

using namespace std;

int PId=1;

class Emp{
    int Id;
    string fname;
    string mname;
    string lname;
    int d,m,y;
    int age[3];
    string email;
    string altemail={0};
    long long int phnum;
    long long int phnum2=0;
    int aadhar;

    public:
    void getdata(){
        string name;
        cout<<"Enter the name of the Employee-";
        getline(cin,name);
        istringstream iss(name);
        iss>>this->fname>>this->mname>>this->lname;
        cout<<"Enter Details for Date Of Birth(should be in DD/MM/YYYY format)"<<endl<<"Date-";
        string dob;
        getline(cin,dob);
        d=stoi(dob.substr(0,2));
        m=stoi(dob.substr(3,2));
        y=stoi(dob.substr(6,4));
        get_age(d,m,y);
        cout<<"Enter Email address:";
        cin>>email;
        //cout<<
        cout<<"Enter Phone Number:";
        cin>>phnum;
        //cout<<
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
        cout<<"Name-"<<fname<<" "<<mname<<" "<<lname<<endl;
        cout<<"Age-"<<age[2]<<"year "<<age[1]<<"month "<<age[0]<<"days";
        
    }
};

int main(){
    Emp E;
    E.getdata();
    E.showdata();
    return 0;
}