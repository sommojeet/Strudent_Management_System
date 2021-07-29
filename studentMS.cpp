// Student Management System using file handling

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;
class student
{
private:
    string name, fname, lname, roll_no, course, address, email_id, contact_no;
    char x;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student::menu()
{
    do
    {
// menustart:
    int choice;
    system("cls");
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|  STUDENT MANAGEMENT SYSTEM  |" << endl;
    cout << "\t\t\t-------------------------------" << endl
         << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl
         << endl;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t  Choose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << "\n\t\t\t Thank You For Using This Portal.. Have A Nice Day!";
        exit(0);
    default:
        cout << "\n\t\t\t Invalid Choice!! Plese Try Again. ";
        break;
    }
        cout << "\n\t\t\t New Choice ? (Y/N): ";
        cin >> x;
    } while (x == 'y' || x == 'Y');
    cout << "\n\t\t\t Thank You For Using This Portal.. Have A Nice Day!";
    exit(0);
}
void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n-----------------------------------------------------------------------ADD STUDENT DETAILS---------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\tEnter First Name: ";
    cin >> fname;
    cout << "\n\t\t\tEnter Last Name: ";
    cin >> lname;
    cout << "\n\t\t\tEnter Roll No: ";
    cin >> roll_no;
    cout << "\n\t\t\tEnter Cource: ";
    cin >> course;
    cout << "\n\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\n\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\n\t\t\tEnter Address: ";
    cin >> address;
    file.open("StudentRecord.txt", ios::app | ios::out);
    file << " " << fname << " " << lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n-----------------------------------------------------------------------------------------STUDENT RECORD TABLE--------------------------------------------------------------------------------------------" << endl;
    file.open("StudentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present";
        file.close();
    }
    else
    {
        file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\t\t\t Student No.: " << ++total << endl;
            cout << "\t\t\t Student Name: " << fname << " " << lname << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t Student Course: " << course << endl;
            cout << "\t\t\t Student Email Id: " << email_id << endl;
            cout << "\t\t\t Student Contact No.: " << contact_no << endl;
            cout << "\t\t\t Student Address: " << address << endl;
            file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t===== No Data Is Present! =====";
        }
    }
    file.close();
}
void student::modify()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n----------------------------------------------------------------------------------------STUDENT MODIFY DETAILS-------------------------------------------------------------------------------------------" << endl;
    file.open("StudentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present";
        file.close();
    }
    else
    {
        cout << "\n Enter Roll No. Of Student Who's Data You Want To Modify: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << fname << " " << lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                cout << "\n\t\t\t===== Enter Modified Data =====" << endl;
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\n\t\t\tEnter Roll No: ";
                cin >> roll_no;
                cout << "\n\t\t\tEnter Cource: ";
                cin >> course;
                cout << "\n\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\n\t\t\tEnter Contact No: ";
                cin >> contact_no;
                cout << "\n\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << fname << " " << lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found += 1;
            }
            file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t===== Student Roll No. Not Found! =====";
        }
        file1.close();
        file.close();
        remove("StudentRecord.txt");
        rename("Record.txt", "StudentRecord.txt");
    }
}
void student::search()
{
    system("cls");
    fstream file;
    int found=0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n-----------------------------------------------------------------------------------------STUDENT SEARCH DATA---------------------------------------------------------------------------------------------" << endl;
    file.open("StudentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data Is Present!";
    }
    else
    {
        string rollno;
        cout << "\n Enter Roll No. Of Student You Want To Search: ";
        cin >> rollno;
        file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout<<"\n\t\t\t ===== Record Found ====="<<endl;
                cout << "\n\t\t\t Student Name: " << fname << " " << lname << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student Course: " << course << endl;
                cout << "\t\t\t Student Email Id: " << email_id << endl;
                cout << "\t\t\t Student Contact No.: " << contact_no << endl;
                cout << "\t\t\t Student Address: " << address << endl;
                found+=1;
            }
            file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t===== Student Roll No. Not Found! =====";
        }
        file.close();
    }
}
void student::deleted(){
    system("cls");
    fstream file,file1;
    string rollno;
    int found=0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n----------------------------------------------------------------------------------------DELETE STUDENT RECORD--------------------------------------------------------------------------------------------" << endl;
    file.open("StudentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data Is Present!";
    }
    else{
        cout<<"\n\t\t\t Enter Roll No. Of Student You Want To Delete: ";
        cin>>rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << fname << " " << lname << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else{
                cout<<"\n\t\t\t===== Record Deleted! =====";
                found+=1;
            }
            file >> fname >> lname >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout<<"\n\t\t\t===== Student Roll No. Not Found! =====";
        }
        file1.close();
        file.close();
        remove("StudentRecord.txt");
        rename("Record.txt", "StudentRecord.txt");
    }
}
main()
{
    student project;
    project.menu();
    return 0;
}