#include <bits/stdc++.h>
using namespace std;

void Insert();
void Read();
void Search();
void Update();
void Delete();

char id[50];
char productname[50];
char productiondate[50];
char expdate[50];
char exportedcountry[50];
char importedcountry[50];
char quality[50];

// **************************** Main Loop of Project *********************************

int main()
{

    int mainChoice = 1;

    cout << "Welcome to our company ^_^ \n\n"
         << "***************************\n\n";

    while (mainChoice == 1)
    {
        int choice;
        cout << "Enter 1 to INSERT  \n";
        cout << "Enter 2 to READ \n";
        cout << "Enter 3 to SEARCH \n";
        cout << "Enter 4 to UPDATE \n";
        cout << "Enter 5 to DELETE \n";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
            Insert();

        else if (choice == 2)
            Read();

        else if (choice == 3)
            Search();

        else if (choice == 4)
            Update();

        else if (choice == 5)
            Delete();
        else
            cout << "\nPlease enter correct value ( 1-6 )\n";

        // ************************ Ask to Leave loop or continue ************************

        cout << "\n\nEnter 1 to Continue\n";
        cout << "Enter 2 to Close \n\n";
        cout << "**********************************************************\n";
        cin >> mainChoice;

    } // end of mainChoice loop
    return 0;

} //   end of main function

// **************************** Insert Function *********************************

void Insert()
{

    fstream file;
    file.open("data.txt", ios::in | ios::out | ios::app);

    if (file)
        // file<<endl;
        cout << "Enter the id           :";
    cin.getline(id, 50);
    cout << "Enter product name     :";
    cin.getline(productname, 50);
    cout << "Enter production date  :";
    cin.getline(productiondate, 50);
    cout << "Enter exp date         :";
    cin.getline(expdate, 50);
    cout << "Enter exported country :";
    cin.getline(exportedcountry, 50);
    cout << "enter imported country :";
    cin.getline(importedcountry, 50);
    cout << "Enter The Quality Of Product ( low - Normal - high ) ";
    cin.getline(quality, 50);

    file << id << "|" << productname << "|" << productiondate << "|" << expdate << "|" << exportedcountry << "|" << importedcountry << "|" << quality << "\n";

    cout << "**********************************************************\n";

} // <-- end of Function

// **************************** Read Function *********************************

void Read()
{
    fstream file;
    file.open("data.txt", ios::in);

    while (!file.eof())
    {
        file.getline(id, 50, '|');
        file.getline(productname, 50, '|');
        file.getline(productiondate, 50, '|');
        file.getline(expdate, 50, '|');
        file.getline(exportedcountry, 50, '|');
        file.getline(importedcountry, 50, '|');
        file.getline(quality, 50, '\n');
        cout << "\n\nID number        : " << id << "\n"
             << "Name of Product  : " << productname << "\n"
             << "production date  : " << productiondate << "\n"
             << "Exp date         : " << expdate << "\n"
             << "Exported country : " << exportedcountry << "\n"
             << "Imported country : " << importedcountry << "\n"
             << "Quality          : " << quality << "\n";

    } // end of while loop

    cout << "\n\nYour read had been finished !\n\n******************************\n";

    file.close();

} //  end of Function

// **************************** Search Function *********************************

void Search()
{
    char searchKey[50];

    int found = 0;
    cout << "Enter id to Search On :\n";
    cin.getline(searchKey, 50);

    fstream file;
    file.open("data.txt", ios::in | ios::app | ios::out);

    while (!file.eof())
    {
        file.getline(id, 50, '|');
        file.getline(productname, 50, '|');
        file.getline(productiondate, 50, '|');
        file.getline(expdate, 50, '|');
        file.getline(exportedcountry, 50, '|');
        file.getline(importedcountry, 50, '|');
        file.getline(quality, 50, '\n');

        if (strcmp(id, searchKey) == 0)
        {
            cout << "Found ^_^ \n\n";
            cout << "\n\nID number        : " << id << "\n"
                 << "Name of Product  : " << productname << "\n"
                 << "production date  : " << productiondate << "\n"
                 << "Exp date         : " << expdate << "\n"
                 << "Exported country : " << exportedcountry << "\n"
                 << "Imported country : " << importedcountry << "\n"
                 << "Quality          : " << quality << "\n";
            found = 1;
        } // end if

    } // end while loop
    if (found == 0)
        cout << "Not Found ): \n";
    file.close();
} //   end of Function

// ************************** Update Function *********************************

void Update()
{
    char searchKey1[50];
    int found = 0;
    cout << "Enter id of Product to Update :\n";
    cin.getline(searchKey1, 50);
    fstream file;
    fstream newfile;
    file.open("data.txt", ios::in);
    newfile.open("data_2.txt", ios::in | ios::out | ios::app);

    while (!file.eof())
    {
        file.getline(id, 50, '|');
        file.getline(productname, 50, '|');
        file.getline(productiondate, 50, '|');
        file.getline(expdate, 50, '|');
        file.getline(exportedcountry, 50, '|');
        file.getline(importedcountry, 50, '|');
        file.getline(quality, 50, '\n');

        if (strcmp(id, searchKey1) == 0)
        {
            found = 1;
            cout << "Found ! .. Enter New Product Data ! \n\n";
            cout << "Enter product name     :\n";
            cin.getline(productname, 50);
            cout << "Enter production date  :\n";
            cin.getline(productiondate, 50);
            cout << "Enter exp date         :\n";
            cin.getline(expdate, 50);
            cout << "Enter exported country :\n";
            cin.getline(exportedcountry, 50);
            cout << "Enter imported country :\n";
            cin.getline(importedcountry, 50);
            cout << "Enter The Quality Of Product ( low - Normal - high ) \n";
            cin.getline(quality, 50);
        } // end if
        newfile << id << "|" << productname << "|" << productiondate << "|" << expdate << "|" << exportedcountry << "|" << importedcountry << "|" << quality;

    } // end of while loop
    if (found == 0)
        cout << "Not Found ): \n";

    file.close();
    newfile.close();

    remove("data.txt");
    rename("data_2.txt", "date.txt");
} //  end of Function

// **************************** Delete Function *********************************

void Delete()
{
    char searchKey2[50];
    int found = 0;
    cout << "Enter number of id to Delete :\n";
    cin.getline(searchKey2, 50);
    fstream file;
    fstream newfile;
    file.open("date.txt", ios::in | ios::out | ios::app);
    newfile.open("date2.txt", ios::out | ios::in | ios::app);

    while (!file.eof())
    {
        file.getline(id, 50, '|');
        file.getline(productname, 50, '|');
        file.getline(productiondate, 50, '|');
        file.getline(expdate, 50, '|');
        file.getline(exportedcountry, 50, '|');
        file.getline(importedcountry, 50, '|');
        file.getline(quality, 50, '\n');

        if (strcmp(id, searchKey2) == 0)
        {
            found = 1;
            cout << "Found ! .. Product data has been deleted successfully ^_^ \n";
        } // end if
        else
            newfile << id << "|" << productname << "|" << productiondate << "|" << expdate << "|" << exportedcountry << "|" << importedcountry << "|" << quality << endl;

    } // <-- While
    if (found == 0)
        cout << "Not Found ): \n";
    file.close();
    newfile.close();
    remove("data.txt");
    rename("data2.txt", "data.txt");

} //  end of Function
