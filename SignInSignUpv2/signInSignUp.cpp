#include <iostream>
#include <fstream>
using namespace std;
string userNames[100];
string passwords[100];
int userCount = 0;
bool signIn(string userName, string password);
bool isValidUsername(string userName);
void signUpArray(string userName, string password);
void storeInFile(string userName, string password);
int takeChoice();
void viewUsers();
void readDataFromFile();
main()
{
    readDataFromFile();
    bool decision;
    string userName;
    string password;
    int choice = 4;
    while(choice != 0)
    {
        choice = takeChoice();
        if (choice == 1)
        {
            cout << "Enter your username: " ;
            cin >> userName;
            cout << "Enter your password: " ;
            cin >> password;
            decision = isValidUsername(userName);
            if(decision == true)
            {
                signUpArray(userName,password);
                storeInFile(userName,password);
                cout << "User Created Successfully" << endl;
            }
            else
            {
                cout << "Username already exists" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter your username: " ;
            cin >> userName;
            cout << "Enter your password: " ;
            cin >> password;
            decision = signIn(userName,password);
            if (decision == true)
            {
                cout << "Login Successful" << endl;
            }
            else
            {
                cout << "Invalid Credentials" << endl;
            }
        }
        else if (choice == 3)
        {
            viewUsers();
        }
    }
}
bool signIn(string userName, string password)
{
    bool flag = false;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName && passwords[idx] == password)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool isValidUsername(string userName)
{
    bool flag = true;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void signUpArray(string userName, string password)
{
    userNames[userCount] = userName;
    passwords[userCount] = password;
    userCount++;
}
void storeInFile(string userName, string password)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << userName << endl;
    file << password << endl;
    file.close();
}
int takeChoice()
{
    int choice;
    cout << "01. SignUp User" << endl;
    cout << "02. SignIn User" << endl;
    cout << "03. View Users" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice >  ";
    cin >> choice;
    return choice;
}
void viewUsers()
{
    cout << "Usernames"
         << "\t\t"
         << "Passwords" << endl
         << endl;
    for (int idx = 0; idx < userCount; idx++)
    {
        cout << userNames[idx] << "\t\t" << passwords[idx] << endl;
    }
}
void readDataFromFile()
{
    string username;
    string password;
    fstream file;
    file.open("users.txt",ios::in);
    while(getline(file,username)&&getline(file,password))
    {
        userNames[userCount] =  username;
        passwords[userCount] = password;
        userCount++;
    }
    file.close();
}