
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
using namespace std;

class Book
{
public:
    int id;
    char bname[100];
    char author[100];
    char publisher[100];
    int stock;
    int price;
    Book(){};
    void getBookData();     // Get Data about book from user
    void DisplayAllBooks(); // Display data of all books
    int NextBookID();
    int NextBookPrice();
    int NextBookStock();
};

void Book::getBookData()
{
    cout << "\n\tBook ID : ";
    cin >> id;
    cout << "\tBook Name : ";
    cin.ignore();
    cin.getline(bname, 100);
    cout << "\tAuthor name : ";
    cin.getline(author, 100);
    cout << "\tPublisher name : ";
    cin.getline(publisher, 100);
    cout << "\tNumber of copies : ";
    cin >> stock;
    cout << "\tBook price : ";
    cin >> price;
}
void Book::DisplayAllBooks()
{
    cout << "\n\n\tBook ID              : " << id;
    cout << "\n\tName Of book         : " << bname;
    cout << "\n\tAuthor of Book       : " << author;
    cout << "\n\tPublisher of Book    : " << publisher;
    cout << "\n\tNumber of copies     : " << stock;
    cout << "\n\tBook price           : " << price;
    cout << "\n";
}
int Book::NextBookID()
{
    return id;
}
int Book::NextBookPrice()
{
    return price;
}
int Book::NextBookStock()
{
    return stock;
}

bool IsBookIdexist(int id)
{
    int ID = id;
    Book b;
    ifstream file;
    file.open("BookData.dat", ios::binary);
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        if (b.NextBookID() == ID)
        {
            return true;
        }
    }
}
void AddNewCopiesInStore(int, int);
int ModifyBook(int);
void DeleteBook(int);
void BookFinder_ID(int);
void BookFinder_Price(int, int);
int order(int, int);

class person
{
protected:
    string name;
    string contact;

public:
    person(){};
    virtual void display_homepage() = 0;

    virtual void login(){};
};

class shopkeeper : public person
{
protected:
    // data
    string password;
    string user_id;

public:
    Book b;
    void getdata()
    {
        cout << "\n\n\t\t\t\tUser ID : ";
        cin >> user_id;
        cout << "\t\t\t\tPassword : ";
        cin >> password;
    }
    void login()
    {
    st:
        system("cls");
        getdata();
        if (user_id == "tamim" && password == "2007009")
        {
            system("cls");
            display_homepage();
        }
        else
        {
            cout << "Invalid user ID and password, try again!" << endl;

            goto st;
        }
    }

    void adddata();
    void DisplayAllBooks();

    void display_homepage()
    {
        cout << "\n\n\t\tPress any key for continue.......\n";
        cin.ignore();
        cin.ignore();
        system("cls");
        cout << "\n\n\t\t\t\t\t\tADMIN MENU DRIVE" << endl;
        cout << "\t\t\t\t******************************************" << endl;
        cout << "\t\t\t\t*       Show list        : PRESS 1       *" << endl;
        cout << "\t\t\t\t*       Add book         : PRESS 2       *" << endl;
        cout << "\t\t\t\t*       Add more copies  : PRESS 3       *" << endl;
        cout << "\t\t\t\t*       Edit Book        : PRESS 4       *" << endl;
        cout << "\t\t\t\t*       Delete Book      : PRESS 5       *" << endl;
        // cout<<"Search book      : press 6"<<endl;
        cout << "\t\t\t\t*       Exit             : PRESS 0       *" << endl;
        cout << "\t\t\t\t******************************************" << endl;

        cout << "\n\nEnter your choice : ";
        char c;
        cin >> c;
        if (c == '1')
        {
            system("cls");
            DisplayAllBooks();
            display_homepage();
        }
        else if (c == '2')
        {
            system("cls");
            DisplayAllBooks();
            adddata();
            display_homepage();
        }
        else if (c == '3') // copies
        {
            system("cls");
            int ID;
            int co;
            DisplayAllBooks();
            cout << "\n\nEnter Book ID                   : ";
            cin >> ID;
            cout << "Number of copies to add         : ";
            cin >> co;
            AddNewCopiesInStore(co, ID);
            display_homepage();
        }
      
        else if (c == '4') // modify book details
        {

            int bid;
            DisplayAllBooks();
            cout << "Enter the Book ID number :";
            cin >> bid;
            ModifyBook(bid);
            display_homepage();
        }

        else if (c == '5') // delete
        {
            system("cls");
            int id;
            DisplayAllBooks();
            cout << "Enter the ID number of the book : ";
            cin >> id;
            DeleteBook(id);
            display_homepage();
        }
        else if (c == '0') // invalid;
        {

            exit(0);
        }
        else
        {
            system("cls");
            cout << "Invalid Input!!!!!";
            display_homepage();
        }
    }
    
};
void shopkeeper::adddata()
{

    ofstream file;
    file.open("BookData.dat", ios::binary | ios::app);
    b.getBookData();
    if (IsBookIdexist(b.id) == false)
    {
        file.write(reinterpret_cast<char *>(&b), sizeof(Book));
    }
    else
    {
        cout << "Book ID is already taken for another!";
    }
}
void shopkeeper::DisplayAllBooks()
{
    ifstream file;
    system("cls");
    file.open("BookData.dat", ios::binary);
    cout << "\n\n";
    cout << "\t+-----------------------------------------------------------------------------------------------------+\n";
    cout << "\t|                                             BOOK  DITAILS                                           |\n";
    cout << "\t|-----------------------------------------------------------------------------------------------------|\n";
    cout << "\t| " << left << setw(9) << "Book ID"
         << "|  " << left << setw(20) << "Book Name"
         << "| " << left << setw(20) << "Book Author "
         << "| " << left << setw(20) << "Book Publisher "
         << "| " << left << setw(10) << "Copies"
         << "| " << left << setw(10) << "Price"
         << "|\n";
    cout << "\t|----------+------------------------------------------------------------------------------------------|\n";
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        cout << "\t| " << left << setw(9) << b.id << "| "
             << left << setw(21) << b.bname << "| "
             << left << setw(20) << b.author << "| "
             << left << setw(20) << b.publisher << "|"
             << left << setw(11) << b.stock << "| "
             << left << setw(10) << b.price << "|\n";
        ;
    }
    cout << "\t+-----------------------------------------------------------------------------------------------------+\n\n";
    file.close();
}
void AddNewCopiesInStore(int Co, int ID)
{
    Book b;
    ifstream file;
    file.open("BookData.dat", ios::binary);
    ofstream file1;
    file.seekg(0, ios::beg);
    file1.open("Temp.dat", ios::binary | ios::app);
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        if (b.NextBookID() != ID)
        {
            file1.write(reinterpret_cast<char *>(&b), sizeof(Book));
        }
        if (b.NextBookID() == ID)
        {
            b.stock += Co;
            file1.write(reinterpret_cast<char *>(&b), sizeof(Book));
        }
    }
    file.close();
    file1.close();
    remove("BookData.dat");
    rename("Temp.dat", "BookData.dat");
}

int ModifyBook(int BookID)
{
    string Confirmation;
    Book b;
    ifstream file;
    file.open("BookData.dat");
    bool found = false;
    if (!file)
    {
        cout << "\n Data File is missing from  System !";
    }
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        if (b.NextBookID() == BookID)
        {
            cout << "\tCurrent Information about Book ID '" << BookID << "'\n";
            b.DisplayAllBooks();
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << " No such type of Book exists in  database !";
    }

    cout << "Are you sure want to modify data of '" << BookID << "'[y/n]: ";
    cin >> Confirmation;
    if (Confirmation == "Y" || Confirmation == "y")
    {
        Sleep(2);
        ifstream inFile;
        inFile.open("BookData.dat", ios::binary);
        if (!inFile)
        {
            cout << "\nFile Error[10011]   : Data File 'BookDataBase.dat' is missing from your System !";
        }
        ofstream outFile;
        outFile.open("Temp.dat");
        inFile.seekg(0, ios::beg);
        while (inFile.read(reinterpret_cast<char *>(&b), sizeof(Book)))
        {
            if (b.NextBookID() != BookID)
            {
                outFile.write(reinterpret_cast<char *>(&b), sizeof(Book));
            }
            else
            {
                b.getBookData();
                outFile.write(reinterpret_cast<char *>(&b), sizeof(Book));
            }
        }
        inFile.close();
        outFile.close();
        remove("BookData.dat");
        rename("Temp.dat", "BookData.dat");
        cout << "\nData Updated Successfully of BookID '" << BookID << "'\n";
    }
    else
    {
        cout << "\nConfirmation Canceled ...\n";

        system("cls");
    }
}

void DeleteBook(int BID)
{
    char c;
    Book b;
    ifstream file;
    file.open("BookData.dat", ios::binary);
    if (!file)
    {
        cout << " File is missing !!!";
    }
    ofstream file1;
    file1.open("Temp.dat", ios::out);
    file.seekg(0, ios::beg);
    cout << "Are you sure want to modify data of '" << BID << "'[y/n]: ";
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
        {
            if (b.NextBookID() != BID)
            {
                file1.write(reinterpret_cast<char *>(&b), sizeof(Book));
            }
        }
        cout << "Data of Book (ID=" << BID << ") is deleted successfully from DataBase .";

        cin.get();
        file1.close();
        file.close();
        remove("BookData.dat");
        rename("Temp.dat", "BookData.dat");
    }
    else
    {
        cout << "\nConfirmation Canceled ...\n";
    }
}

class customer : public person
{
private:
    string n;

public:
    Book b;
    customer(){};
    void showlist();
    void searchBook();
    void display_homepage()
    {
        cout << "\n\n\t\t\t\t\t\tPress any key for continue.......\n";
        cin.ignore();
        cin.ignore();
        system("cls");
        cout << "\n\n";
        cout << "\n\n\t\t\t\t\t\tCUSTOMER MENU DRIVE" << endl;
        cout << "\t\t\t\t******************************************" << endl;
        cout << "\t\t\t\t*       Show list        : PRESS 1       *" << endl;
        cout << "\t\t\t\t*       Search Book      : PRESS 2       *" << endl;
        cout << "\t\t\t\t*       Buy Book         : PRESS 3       *" << endl;
        cout << "\t\t\t\t*       Exit             : PRESS 0       *" << endl;
        cout << "\t\t\t\t******************************************" << endl;

        int c;
        cout << "\n\nEnter Your Choice : ";
        cin >> c;
        if (c == 1)
        {
            showlist();
            display_homepage();
        }
        else if (c == 2)
        {
            system("cls");
            showlist();
            searchBook();
            display_homepage();
        }
        if (c == 3) // order_item();
        {
            int tprice = 0;
            char c;
        st:
            system("cls");
            showlist();
            int id, cn;
            cout << "Enter the ID number of the Book :";
            cin >> id;
            cout << "Enter the number of the copies :";
            cin >> cn;
            int p = order(id, cn);
            tprice += p;
            cout << "Are you want more ??(Y/N)";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                goto st;
            }
            system("cls");
            cout << "\t\t\t\t****************************************" << endl;
            cout << "\t\t\t\t|                                      |" << endl;
            cout << "\t\t\t\t|       Your total price : " << tprice << "        |" << endl;
            cout << "\t\t\t\t|                                      |" << endl;
            cout << "\t\t\t\t****************************************" << endl;
            display_homepage();
        }
        else
        {
            exit(0);
        }
    }
    //
};

void customer::showlist()
{
    ifstream file;
    system("cls");
    file.open("BookData.dat", ios::binary);
    cout << "\n\n";
    cout << "\t+-----------------------------------------------------------------------------------------------------+\n";
    cout << "\t|                                             BOOK  DITAILS                                           |\n";
    cout << "\t|-----------------------------------------------------------------------------------------------------|\n";
    cout << "\t| " << left << setw(9) << "Book ID"
         << "|  " << left << setw(20) << "Book Name"
         << "| " << left << setw(20) << "Book Author "
         << "| " << left << setw(20) << "Book Publisher "
         << "| " << left << setw(10) << "Copies"
         << "| " << left << setw(10) << "Price"
         << "|\n";
    cout << "\t|----------+------------------------------------------------------------------------------------------|\n";
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        cout << "\t| " << left << setw(9) << b.id << "| "
             << left << setw(21) << b.bname << "| "
             << left << setw(20) << b.author << "| "
             << left << setw(20) << b.publisher << "|"
             << left << setw(11) << b.stock << "| "
             << left << setw(10) << b.price << "|\n";
        ;
    }
    cout << "\t+-----------------------------------------------------------------------------------------------------+\n\n";
    file.close();
}

void customer::searchBook()
{
    int n;
    int i;
    int Max, Min;
    cout << "\t\t+-------------------------Options -----------------------------+\n";
    cout << "\t\t|                                                              |\n";
    cout << "\t\t|            1.  Find Book Information with Book ID            |\n";
    cout << "\t\t|            2.  Find Books between  price range               |\n";
    cout << "\t\t|                                                              |\n";
    cout << "\t\t+--------------------------------------------------------------+\n";
    cout << "\n\n\t\tEnter your choice : ";
    cin >> n;

    switch (n)
    {
    case 1:
        system("cls");
        cout << "\n\n\t\t\tFIND BOOK USING BOOK ID\n";
        cout << "Enter Book ID              :";
        cin >> i;

        BookFinder_ID(i);
        break;
    case 2:
        system("cls");
        cout << "\n\n\t\t\tFIND BOOK USING BOOK PRICE\n";
        cout << "\n\n\t\t\tMinimum price of book should be :";
        cin >> Min;
        cout << "\n\t\t\tMaximum price of book should be :";
        cin >> Max;
        cout << "\n--------------------------------------------------------------------\n";
        BookFinder_Price(Min, Max);
        break;
    default:
        cout << "\n\nError!!! '" << n << "' is not a option !" << endl;
        searchBook();
    }
}

void BookFinder_ID(int BookID)
{
    Book b;
    ifstream file;
    file.open("BookData.dat");
    bool found = false;
    if (!file)
    {
        cout << "\nFile Error[10011]   : Data File is missing from your System !";
    }
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        if (b.NextBookID() == BookID)
        {
            b.DisplayAllBooks();
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << " No such type of Book exists in database !!!!";
    }
    if (file.is_open())
    {
        file.close();
    }
}

void BookFinder_Price(int MinPrice, int MaxPrice)
{
    Book b;
    ifstream file;
    file.open("BookData.dat");
    bool found = false;
    if (!file)
    {
        cout << "\n\n\t\tError : File named as 'BookData.dat' is missing from system!!!!";
    }
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
    {
        if (b.NextBookPrice() >= MinPrice && b.NextBookPrice() <= MaxPrice)
        {
            b.DisplayAllBooks();
            found = true;
            cout << "\n----------------------------------------------------------------------\n";
        }
        if (file.eof())
        {
            exit(0);
        }
        else
        {
            continue;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\n\n\t\tNo book is between range of " << MinPrice << " and " << MaxPrice << "!!!!!";
    }
}

int order(int id, int cn)
{
    Book b;
    ifstream file;
    file.open("BookData.dat", ios::binary);

    if (!file)
    {
        cout << "File is missing!!!";
        return 0;
    }
    int p;
    ofstream outfile;
    outfile.open("Temp.dat", ios::out);
    if (IsBookIdexist(id) == true)
    {
        file.seekg(0, ios::beg);
        while (file.read(reinterpret_cast<char *>(&b), sizeof(Book)))
        {
            if (b.NextBookID() == id)
            {
                if (cn <= b.NextBookStock())
                {

                    p = cn * (b.NextBookPrice());
                    b.stock -= cn;
                }
                if (b.stock != 0)
                {
                    outfile.write(reinterpret_cast<char *>(&b), sizeof(Book));
                }
            }
            else
            {
                outfile.write(reinterpret_cast<char *>(&b), sizeof(Book));
            }
        }
        file.close();
        outfile.close();
        remove("BookData.dat");
        rename("Temp.dat", "BookData.dat");
        return p;
    }
}

void homepage()
{
    cout << "\t\t\t\t*************************************"
         << "\n";
    cout << "\t\t\t\t*           WELCOME                 *"
         << "\n";
    cout << "\t\t\t\t*             TO            *"
         << "\n";
    cout << "\t\t\t\t*          BOOK SHOP                *"
         << "\n";
    cout << "\t\t\t\t*                                   *"
         << "\n";
    cout << "\t\t\t\t*************************************"
         << "\n";
    
    cout << "\n\t\tIf you are Shopkeeper     : Press 1" << endl;
    cout << "\t\tIf you are Customer       : Press 2" << endl;
    cout << "\t\tEnter your choice : ";
}
void loadingbar()
{
    for (int i = 15; i <= 100; i += 5)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\t\t\t";
        cout << i << " %% loadding...\n\n\t\t";
        cout << " ";
        for (int j = 0; j < i; j += 2)
        {
            cout << " ";
        }
        Sleep(40);
        if (i == 90 || i == 50 || i == 96 || i == 83)
        {
            Sleep(40);
        }
    }
    system("cls"); //
}
int main()
{
    Book b;
    person *p;
    loadingbar();
    homepage();
    int c;
    cin >> c;
    if (c == 1) // Dynamic Binding
    {
        p = new shopkeeper();
        p->login();
    }
    else
    {
        p = new customer();
        p->display_homepage();
    }
}
