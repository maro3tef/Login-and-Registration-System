#include <bits/stdc++.h>
using namespace std;

struct User
{
    string username;
    string password;
};

void Register()
{
    User u;
    cout<<" Enter your username please: ";
    getline(cin,u.username);
    cout<<" Enter your password please: ";
    getline(cin,u.password);
    ifstream check("users.txt");
    string ur,pass;
    while (check>>ur>>pass)
    {
       if(ur==u.username){
       cout<<"Problem, This username already exist"<<endl;
       return;
       }
    }
    ofstream add("users.txt");
    add<<u.username<<"  " <<u.password<<endl;
    cout<<"Registration successful "<<endl;

}

void Login()
{
    string username ,password;
    cout<<" Enter your username please: ";
    getline(cin,username);
    cout<<" Enter your password please: ";
    getline(cin,password);
    ifstream check("users.txt");
    string ur,pass;
    while (check>>ur>>pass)
    {
        if (ur==username && pass==password)
        {
           cout<<"Login successful, Welcome "<<username<<endl;
           return;
        }
    }
    
    cout<<"Problem in username or password "<<endl;
}


    int main()
{
    int choice;
    while (true)
    {
        cout<<" Menu "<<endl;
        cout<<"For Registertion => Enter 1 "<<endl;
        cout<<"For Login => Enter 2 "<<endl;
        cout<<"For Exit => Enter 0 "<<endl;
        cin>>choice;
      
        cin.ignore();
        if (choice==0)
        {
            cout<<" Thank You ! "<<endl;
            break;
        }
        else if (choice==1)
        Register();
        else if (choice==2) 
        Login();
        else  
        cout<<" Invalid choice ,Try again "<<endl ;
        

    }
    
   
       
   return 0;
}