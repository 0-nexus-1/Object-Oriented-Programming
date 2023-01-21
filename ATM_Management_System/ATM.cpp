// C++ Program to implement an ATM and it's basic functions
#include <iostream>
#include <fstream>
#include <limits>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Class ATM to get user details
class atm
{
private:
    char username[30];
    int password;
    int balance;

public:
    char *usernames(void)
    {
        // Return username
        return username;
    }

    int passwords(void)
    {
        // Return the password
        return password;
    }

    // Funtion to get the data
    void getData(void)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter username: ";

        cin.getline(username, 30);
        cout << "\nEnter 4-digit "
             << "password: ";
        int pas;
    p:
        cin >> pas;
        if (pas < 10000)
        {
            password = pas;
        }
        else
        {
            cout << "\nPlease Enter password in 4-digit\n\n";
            goto p;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter initial balance: ";

        int bal;
        cin >> bal;
        if (bal > 0)
        {
            balance = bal;
        }
        else
        {
            cout << "\n\t\t\t\tPlease Enter Balance greater than 0!\n\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Function displaying the Data
    void showData(void)
    {
        cout << "\t\tUsername: " << username
             << "\t\tPassword: " << password
             << "\t\tBalance: " << balance << "\n\n";
        // cout << time;
    }

    // Member Functions
    int adduser();
    int veiwAllUsers();
    int deleteUser(char *);
    void updateUserasDeposit(char *);
    void updateUserasWithdraw(char *);
    int searchSpecificUser(char *, int);
    int searchAllUsertoDisplay(char *);
};

// Function to implement
// functionality of ATM User
void atmUser()
{
    atm a;

    char uname[30];
    int pass, ch, ch1, ch2, found = 0;

mainmenu:

    // System("cls");
    cout << "\nLogin as:\n\n1.\4 Admin"
         << "\n2.\4 User"
         << "\n3.\4 Exit"
         << "\n\t\t\t\tEnter your choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    rerun:
        // System("cls");
        cout << "\n\t\t\t\tEnter details to login as Admin\n ";
        cout << "\n\t\t\t\tEnter password: ";
        cin >> pass;
        if (pass == 1234)
        {
            cout << "\n\t\t\t\tWelcome to ";
        admin:
            // System("cls");
            cout << "Admin Menu"
                 << "\n";
            cout << "\n1.\4 Add User "
                 << "\n2.\4 Delete User"
                 << "\n3.\4 View All User"
                 << "\n4.\4 Exit";
            cout << "\n\t\t\t\tEnter your choice :";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                a.adduser();
                goto admin;

            case 2:
                cout << "\n\t\t\t\tEnter the Username to be deleted: ";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.getline(uname, 30);
                a.deleteUser(uname);
                goto admin;

            case 3:
                a.veiwAllUsers();
                // sleep(4);
                goto admin;

            case 4:
                break;
            }
        }
        else
        {
            cout << "\n\t\t\t\tDetails are incorrect! "
                 << "\n\t\t\t\tPlease try again ";
            cin.get();
            goto rerun;
        }
        goto mainmenu;

    case 2:
        // System("cls");
        cout << "\n\t\t\t\tEnter details to login as User\n ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\t\tEnter username: ";
        cin.getline(uname, 30);
        cout << "\n\t\t\t\tEnter password: ";

        cin >> pass;
        found = a.searchSpecificUser(uname, pass);

        if (found)
        {
            cout << "\n\t\t\t\tWelcome to ";
        user:
            // System("cls");
            // cout << "\n\t\t\t\t" << endl;
            cout << "User Menu\n";
            cout << "\n1.\4 Deposit"
                 << "\n2.\4 Withdraw"
                 << "\n3.\4 Veiw Account"
                 << "\n4.\4 Exit"
                 << "\n\t\t\t\tEnter your choice: ";
            cin >> ch2;

            switch (ch2)
            {
            case 1:
                a.updateUserasDeposit(uname);
                goto user;
            case 2:
                a.updateUserasWithdraw(uname);
                goto user;
            case 3:
                a.searchAllUsertoDisplay(uname);
                // sleep(4);
                goto user;
            case 4:
                cout << "\n\t\t\t\t\2 Thank You! \2" << endl;
                break;
            }
        }
        else
        {
            cout << "\n\t\t\t\tNo account found with such username! "
                 << "\n\n\t\t\t\tHit ENTER to continue " << uname;
            cin.get();
        }
        goto mainmenu;

    case 3:
        cout << "\n\t\t\t\t\2 Thanks for visiting our branch \2";
        cin.get();
        break;
    }
}

// Function to Add User
int atm::adduser()
{
    atm a;

    ofstream file;

    // Open file in write mode
    file.open("Save Data.txt", ios::out | ios::app);

    if (!file)
    {
        cout << "\n\t\t\t\tError in creating file..." << endl;
        return 0;
    }

    // Read from user
    a.getData();

    // Write into file
    file.write((char *)&a, sizeof(a));

    // Close the file
    file.close();

    return 0;
}

// View Users
int atm::veiwAllUsers()
{
    atm a;

    ifstream file1;

    // Open file in read mode
    file1.open("Save Data.txt", ios::in);

    if (!file1)
    {
        cout << "\n\t\t\t\tError in opening in file...";
        return 0;
    }

    // Read data from file
    file1.read((char *)&a, sizeof(a));

    while (!file1.eof())
    {
        // Display data on monitor
        a.showData();
        file1.read((char *)&a, sizeof(a));
    }

    // Close the file
    file1.close();
    return 0;
}

// Function to Delete the User
int atm::deleteUser(char *uname)
{
    atm a;

    fstream original, temp;
    original.open("Save Data.txt", ios::in);

    if (!original)
    {
        cout << "\n\t\t\t\tfile not found ";
        return 0;
    }
    else
    {
        temp.open("temp.txt", ios::out | ios::app);
        original.read((char *)&a, sizeof(a));

        // Till end of file is reached
        while (!original.eof())
        {
            if (!strcmp(a.usernames(), uname))
            {
                cout << "\n\t\t\t\tData found and Deleted\n "
                     << a.username
                     << "\n";
            }
            else
            {
                temp.write((char *)&a, sizeof(a));
            }
            original.read((char *)&a, sizeof(a));
        }

        original.close();
        temp.close();
        remove("Save Data.txt");
        rename("temp.txt", "Save Data.txt");
        a.veiwAllUsers();
    }
    return 0;
}

// Function to Update User
// by depositing money
void atm::updateUserasDeposit(char *uname)
{
    atm a;

    fstream file, temp;
    file.open("Save Data.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);

    file.seekg(0);
    file.read((char *)&a, sizeof(a));

    // Till end of the file
    while (!file.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            int b;

            cout << "\n\t\t\t\tEnter amount to deposit: ";
            cin >> b;

            a.balance = a.balance + b;
            cout << "\n\t\t\t\tNew Balance: "
                 << "Rs." << a.balance << endl;
            temp.write((char *)&a, sizeof(a));
        }
        else
        {
            temp.write((char *)&a, sizeof(a));
        }
        file.read((char *)&a, sizeof(a));
    }
    file.close();
    temp.close();
    remove("Save Data.txt");
    rename("temp.txt", "Save Data.txt");
}

// Function to Update User
// by withdrawing money
void atm::updateUserasWithdraw(char *uname)
{
    atm a;

    fstream file, temp;
    file.open("Save Data.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);

    file.seekg(0);
    file.read((char *)&a, sizeof(a));

    // Till end of file is reached
    while (!file.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            int b;

            cout << "\n\t\t\t\tEnter amount to withdraw: ";
            cin >> b;

            if (a.balance < b)
            {
                cout << "\n\t\t\t\tInsufficient balance to withdraw! ";
            }
            else
            {
                a.balance = a.balance - b;
                temp.write((char *)&a, sizeof(a));
                cout << "\n\t\t\t\tRemainig Balance: "
                     << "Rs." << a.balance << endl;
            }
        }
        else
        {
            temp.write((char *)&a, sizeof(a));
        }
        file.read((char *)&a, sizeof(a));
    }

    // Close the file
    file.close();
    temp.close();
    remove("Save Data.txt");
    rename("temp.txt", "Save Data.txt");
}

// Search User
int atm::searchSpecificUser(char *uname, int pass)
{
    atm a;
    fstream f;

    // Open the file
    f.open("Save Data.txt", ios::in);
    if (!f)
    {
        cout << "\n\t\t\t\tError in opening file...";
        return 0;
    }

    // Read data from file
    f.read((char *)&a, sizeof(a));
    while (!f.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            if (a.passwords() == pass)

                return 1;
        }
        f.read((char *)&a, sizeof(a));
    }

    // Close the file
    f.close();
    return 0;
}

// Search Specific User
int atm::searchAllUsertoDisplay(char *uname)
{
    atm a;
    fstream file1;

    // Open the file
    file1.open("Save Data.txt", ios::in);
    if (!file1)
    {
        cout << "\n\t\t\t\tError in oprning file...";
        return 0;
    }

    // Read data from file
    file1.read((char *)&a, sizeof(a));
    while (!file1.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            a.showData();
            return 0;
        }
        file1.read((char *)&a, sizeof(a));
    }
    // Close the file
    file1.close();
    return 0;
}

// Driver Code
int main()
{
    cout << "\t\t\tTime: " << __TIME__ << "\t\t\t\t\t" << __DATE__ << endl;
    cout << "\n\t\t\t\t--------Welcome to ATM--------";

    // Function Call
    atmUser();

    return 0;
}
