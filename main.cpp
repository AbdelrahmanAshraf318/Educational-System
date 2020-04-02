#include <iostream>
#include <vector>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
//vector <string>teaching_course;
//vector <string>code;
//vector <string>assignment;
//vector <string>doctorsname;
int k=0;
int n=0;
const int size1=6;
string arr_assignment[size1];
string arr_doctorsname[size1];
//vector <string>doctorsusername;
string arr_doctorsusername[size1];
//vector <string>doctorspassword;
string arr_doctorspassword[size1];
string arr_course[size1];
string arr_code[size1];
string coursename1;
string username1 , password1 , name1;
/*The previous for doctors but the following for student*/
string coursename2 , code2;
string username2 , password2 , name2;
struct doctor
{

    string uesr_name;
    string name;
    string password;
    bool take_data(string user_name,string password);
    string data(string name , string user_name , string password);//sign up
    bool showmenu();
    void list_course(string arr_course[size1],string arr_code1[size1]);
    void create_assignment(string arr_assignment[size1]);
    bool check();
    void list_assignment(string arr_assignment[size1]);
    string create_course(string arr_course[size1],string arr_code[size1]);
    void create_anothercourse(string arr_course[size1],string arr_code[size1]);
};
bool doctor::take_data(string user_name,string password)//login
{
    cout<<"Please,Enter username & password:-"<<"\n";
    cout<<"username: ";
    cin.sync();
    cin.clear();
    getline(cin,user_name);
    cout<<"Password: ";
    cin>>password;
    for(int i=0 ; i<size1 ; i++)
    {
        if(user_name==arr_doctorsusername[i]&&password==arr_doctorspassword[i])
        {
            cout<<"Your Data is true"<<endl;
            break;
        }
    }
}
string doctor::data(string name , string user_name , string password)
{
            cout<<"Fill the following data:- ";
            cout<<"Name: ";
            cin.sync();
            cin.clear();
            getline(cin,name);
            arr_doctorsname[k]=name;
            cout<<"UserName: ";
             cin>>user_name;
             arr_doctorsusername[k]=user_name;
            cout<<"Password: ";
           cin>>password;
           arr_doctorspassword[k]=password;
           k++;
    return name;
}
void doctor::list_course(string arr_course[size1],string arr_code1[size1])
{
    cout<<"Courses:\t\tCodes"<<"\n";
    int i=1;
    for(int j=0 ; j<size1 ;j++)
    {
        if(arr_course[j]!=" ")
        {
            cout<<i<<" "<<arr_course[j]<<" "<<arr_code[j]<<"\t";
        }
        else
        {
            cout<<"_____"<<"\t\t\t\t"<<"_____"<<endl;
        }
    }
    cout<<"\n";
}
bool doctor::check()
{
    cout<<"Enter The name of the course: ";
    cin.sync();
    cin.clear();
    getline(cin,coursename1);
    for(int i=0 ; i<size1 ; i++)
    {
        if(coursename1==arr_course[i])
        {
            cout<<"You really teach this course"<<"\n";
        }
    }
}
void doctor::list_assignment(string arr_assignment[size1])
{
    cout<<"Courses\t\t\t"<<"Assignments"<<"\n";
    for(int i=0 ; i<size1 ;i++)
    {
        if(arr_assignment[i]!=" ")
        {
            cout<<arr_course[i]<<" "<<arr_assignment[i]<<"\n";
        }
        else
        {
            cout<<arr_course[i]<<"-"<<"\n";
        }
    }
}
void doctor::create_assignment(string arr_assignment[size1])
{
    bool passed=true;
    passed=passed&check();
    for(int i=0 ; i<size1;i++)
    {
        if(coursename1==arr_course[i])
        {
            cout<<"Create Your Assignment"<<"\n";
            cin.sync();
            cin.clear();
            getline(cin,arr_assignment[i]);
        }
    }
}
string doctor::create_course(string arr_course[size1],string arr_code[size1])//when he sign up
{
           cout<<"Enter the data of the course(Name&&Code):-"<<endl;
            cout<<"Name: ";
           cin.sync();
           cin.clear();
           getline(cin,arr_course[n]);
           cout<<"Code: ";
           cin>>arr_code[n];
           n++;
   return arr_course[n];
}
void doctor::create_anothercourse(string arr_course[size1],string arr_code[size1])
{
    for(int i=0 ; i<size1 ; i++)
    {
        if(arr_course[i]==" ")
        {
             cout<<"Enter the data of the course(Name&&Code):-"<<endl;
             cin.sync();
             cin.clear();
             cout<<"Name: ";
            getline(cin,arr_course[i]);
            cout<<"Code: ";
            cin>>arr_code[i];
            break;
        }
    }
}
int q=0;
string arr_studentusername[size1];
string arr_assignmentsubmission[size1];
string arr_studentpassword[size1];
string arr_studentname[size1];
string arr_studentid[size1];
string student_assignment[size1];
struct student
{
    string name_student;
    string password_student;
    string username_student;
    string id;
    string student_course[size1];
    string studentcourse_code[size1];
    string data(string name_student,string password_student,string username_student,string id);
    bool take_data(string username_student,string password_student);
    bool registerincourse(string arr_course[size1],string arr_code[size1],string student_course[size1],string studentcourse_code[size1]);
    void studentregistercourse(string arr_course[size1],string arr_code[size1]);
    string student_listassignment(string student_course[size1],string arr_assignment[size1],string arr_course[size1],string studentcourse_code[size1]);
    void submit_solution(string arr_assignmentsubmission[size1],string student_course[size1],string student_assignment[size1]);
    string list_submission(string arr_assignmentsubmission[size1],string student_course[size1],string student_assignment[size1]);
    void showmenu();
};
string student::data(string name_student,string password_student,string username_student , string id)
{
    cout<<"Fill the following data:- \n";
    cout<<"Name: ";
    cin.sync();
    cin.clear();
    getline(cin,name_student);
    arr_studentname[q]=name_student;
    cout<<"UserName: ";
    cin>>username_student;
    arr_studentusername[q]=username_student;
    cout<<"Password: ";
    cin>>password_student;
    arr_studentpassword[q]=password_student;
    cout<<"ID: ";
    cin>>id;
    arr_studentid[q]=id;
}
bool student::take_data(string username_student,string password_student)
{
     cout<<"Please,Enter username & password:-"<<"\n";
     cout<<"UserName: ";
     cin>>username_student;
     cout<<"Password: ";
     cin>>password_student;
     for(int i=0 ; i<10 ; i++)
     {
         if(username_student==arr_studentusername[i]&&password_student==arr_studentpassword[i])
         {
             cout<<"Your data is true\n";
             break;
         }
     }
}
bool student::registerincourse(string arr_course[size1],string arr_code[size1],string student_course[size1],string studentcourse_code[size1])
{
    cout<<"To Register in any course,Please Fill the following data:- ";
    cout<<"Name Of Course: ";
    //cin>>coursename2;
    cin.sync();
    cin.clear();
    getline(cin,coursename2);
    cout<<"Code: ";
    cin>>code2;
    string agree;
    for(int i=0 ; i<size1 ; i++)
    {
        if(coursename2==arr_course[i]&&code2==arr_code[i])
        {
            cout<<"The Data of the course is true"<<endl;
            cout<<"Write Agree to register: ";
            cin>>agree;
            if(agree=="agree"||agree=="Agree")
            {
                for(int j=0 ; j<size1 ; j++)
                {
                    if(student_course[j]==" ")
                    {
                        student_course[j]=coursename2;
                        studentcourse_code[j]=code2;
                        cout<<"Register Completed"<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
void student::studentregistercourse(string arr_course[size1],string arr_code[size1])
{
    cout<<"Courses\t\t"<<"Codes";
    for(int i=0 ; i<size1 ; i++)
    {
        if(student_course[i]!=" ")
        {
            cout<<student_course[i]<<"\t\t"<<studentcourse_code[i]<<endl;
        }
    }
}
string student::student_listassignment(string student_course[size1],string arr_assignment[size1],string arr_course[size1],string studentcourse_code[size1])
{
    cout<<"Courses\t\t"<<"Codes\t\t"<<"Assignment"<<endl;
    for(int i=0 ; i<size1 ; i++)
    {
        cout<<student_course[i]<<"\t\t"<<studentcourse_code[i]<<"\t\t";
        if(student_course[i]==arr_course[i])
        {
            if(arr_assignment[i]!=" ")
            {
                cout<<arr_assignment[i]<<endl;
                student_assignment[i]=arr_assignment[i];
            }
            else
                cout<<"-----"<<endl;
        }
    }
}
void student::submit_solution(string arr_assignmentsubmission[size1],string student_course[size1],string student_assignment[size1])
{
    for(int i=0 ; i<size1 ; i++)
    {
        if(coursename2==student_course[i])
        {
            if(student_assignment[i]!=" ")
            {
                cout<<"Submit Your Solutions"<<endl;
                cin.sync();
                cin.clear();
                getline(cin,arr_assignmentsubmission[i]);
            }
        }
    }
}
string student::list_submission(string arr_assignmentsubmission[size1],string student_course[size1],string student_assignment[size1])
{
    for(int i=0 ; i<size1 ; i++)
    {
        if(student_assignment[i]!=" ")
        {
        if(arr_assignmentsubmission[i]!=" ")
        {
            cout<<"Course: "<<student_course[i]<<" is Submitted"<<endl;
            cout<<"The Solution is: "<<arr_assignmentsubmission[i]<<endl;
        }
        else
        {
            cout<<"Course: "<<student_course[i]<<" Not Submitted"<<endl;
        }
        }
    }
}
void show()
{
    doctor d;
    student s;
    mainmenu:
        int h , y;
    cout<<"1)Login as a doctor"<<endl;
    cout<<"2)Login as a student"<<endl;
    cout<<"3)Sign UP as a doctor"<<endl;
    cout<<"4)Sign Up as a student"<<endl;
    cout<<"Choose one of the previous: ";
    cin>>h;
    if(h==1)
    {
        bool pass=true;
        pass=pass&d.take_data(username1,password1);
        cout<<d.showmenu();
    }
    else if(h==2)
    {
        bool pass=true;
        pass=pass&s.take_data(username2,password2);
        s.showmenu();
    }
    else if(h==3)
    {
         d.data(name1 , username1 , password1);
        cout<<"What is the course which you will teach?"<<endl;
        cout<<d.create_course(arr_course,arr_code)<<endl;
        cout<<"To See Your Menu , Please Enter 1"<<endl;
        cin>>y;
        if(y==1)
        {
            goto mainmenu;
        }
        else
        {
            cout<<"Bye Bye"<<endl;
        }
    }
    else if(h==4)
    {
        s.data(name2,username2,password2,s.id);
        cout<<"To See Your Menu , Please Enter 1"<<endl;
        cin>>y;
        if(y==1)
        {
            goto mainmenu;
        }
        else
        {
            cout<<"Bye Bye"<<endl;
        }
    }
}
bool doctor::showmenu()
{
    menu:
        cout<<"Hello! you are logged in,Here is your menu"<<"\n";
    cout<<"1)List Courses"<<"\n";
    cout<<"2)View Courses"<<"\n";
    cout<<"3)Create Course"<<"\n";
    cout<<"4)LogOut"<<"\n";
    cout<<"5)EndSystem"<<"\n";
    int choice;
    cout<<"Choose a choice from the above: ";
    cin>>choice;
    string answer;
    if(choice==1)
    {
        list_course(arr_course,arr_code);
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="Yes"||answer=="yes")
        {
            goto menu;
        }
        else
            cout<<"Bye"<<endl;
    }
    else if(choice==2)
    {
        smallmenu:
            cout<<"Menu:"<<"\n";
        cout<<"1)List Assignment"<<"\n";
        cout<<"2)Create Assignment"<<"\n";
        cout<<"3)View Assignment"<<"\n";
        cout<<"4)Back"<<"\n";
        int n;
        cout<<"Choose one of the previous: ";
        cin>>n;
        string ans;
        switch(n)
        {
        case 1:
            list_assignment(arr_assignment);
            cout<<"Do you want to still in viewing course?"<<endl;
            cin>>ans;
            if(ans=="Yes"||ans=="yes")
            {
                goto smallmenu;
            }
            else
            {
                break;
            }
        case 2:
            create_assignment(arr_assignment);
            cout<<"Do you want to still in viewing course?"<<endl;
            cin>>ans;
            if(ans=="Yes"||ans=="yes")
            {
                goto smallmenu;
            }
            else
            {
                break;
            }
        case 4:
            goto menu;
            cout<<"Do you want to still in viewing course?"<<endl;
            cin>>ans;
            if(ans=="Yes"||ans=="yes")
            {
                goto smallmenu;
            }
            else
            {
                break;
            }
        }
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="Yes"||answer=="yes")
        {
            goto menu;
        }
        else
         cout<<"BYE"<<endl;
    }
    else if(choice==3)
    {
        create_anothercourse(arr_course,arr_code);
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="Yes"||answer=="yes")
        {
            goto menu;
        }
        else
         cout<<"BYE"<<endl;
    }
    else if(choice==4)
    {
        show();
    }
    else if(choice==5)
    {
        cout<<"Thank You\n";
    }
    return 0;
}
void student::showmenu()
{
    menu:
        cout<<"Hello! you are logged in,Here is your menu"<<"\n";
    cout<<"1)Register In Course"<<endl;
    cout<<"2)List My Course"<<endl;
    cout<<"3)View Course"<<endl;
    cout<<"4)Log Out"<<endl;
    cout<<"5)End System"<<endl;
    cout<<"Choose one of the previous: ";
    int j;
    cin>>j;
    string answer;
    if(j==1)
    {
        registerincourse(arr_course,arr_code,student_course,studentcourse_code);
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="Yes"||answer=="yes")
        {
            goto menu;
        }
        else
        {
            cout<<"Bye,Bye"<<endl;
        }
    }
    else if(j==2)
    {
        studentregistercourse(arr_course,arr_code);
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="Yes"||answer=="yes")
        {
            goto menu;
        }
        else
        {
            cout<<"Bye,Bye"<<endl;
        }
    }
    else if(j==3)
    {
        smallmenu:
            cout<<"1)List Assignment\n";
        cout<<"2)List of submission \n";
        cout<<"3)Back"<<endl;
        cout<<"Choose one of the previous: ";
        int g;
        cin>>g;
        string k;
        if(g==1)
        {
            cout<<student_listassignment(student_course,arr_assignment,arr_course,studentcourse_code);
            cout<<"Do you want to still in viewing course?"<<endl;
            cin>>k;
            if(k=="Yes"||k=="yes")
            {
                goto smallmenu;
            }
        }
        else if(g==2)
        {
            cout<<list_submission(arr_assignmentsubmission,student_course,student_assignment);
            cout<<"Do you want to still in viewing course?"<<endl;
            cin>>k;
            if(k=="Yes"||k=="yes")
            {
                goto smallmenu;
            }
        }
        else if(g==3)
        {
            goto menu;
        }
        cout<<"Do you want to do another thing?"<<endl;
        cin>>answer;
        if(answer=="yes"||answer=="Yes")
        {
            goto menu;
        }
        else
            cout<<"Bye\n";
    }
    else if(j==4)
    {
        show();
    }
    else if(j==5)
    {
        cout<<"Thank You\n";
    }
}
int main()
{
    show();
    return 0;
}
