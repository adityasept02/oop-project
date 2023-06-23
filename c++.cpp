#include <bits/stdc++.h>
using namespace std;
#define ll int long long
class shop
{
private:
    int code;
    float discount;
    float price;
    string name;

public:
    void menu();
    void admin();
    void customer();
    void add();
    void edit();
    void r();
    void list();
    void bill();
};
void shop::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "modern market" << endl;
    cout << "1) admin" << endl;
    cout << "2) customer" << endl;
    cout << "3) exit" << endl;
    cout << "please select" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {

        cout << "please login" << endl;
        cout << "enter email" << endl;
        cin >> email;
        cout << "password" << endl;
        cin >> password;
        if (email == "adityasept02@gmail.com" and password == "aditya@123")
        {
            admin();
        }
        else
        {
            cout << "invalid" << endl;
        }

        break;
    }

    case 2:
    {
        customer();
    }
    case 3:
    {
        exit(0);
    }
    default:
        cout << "enter valid option" << endl;
    }
    goto m;
}
void shop::admin()
{
m:
    int c;
    cout << "admin menu" << endl;
    cout << "1) add" << endl;
    cout << "2) edit" << endl;
    cout << "3) remove" << endl;
    cout << "4) menu" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        r();
        break;
    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice" << endl;
    }
    goto m;
}
void shop::customer()
{
m:
    int c;
    cout << "buyer" << endl;
    cout << "1) buy" << endl;
    cout << "2) go back" << endl;
    cout << "enter your choice" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        bill();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "invalid choice" << endl;
    }
    goto m;
}
void shop::add()
{
m:
    fstream data;
    int c;
    int t = 0;
    float p;
    float d;
    string s;
    cout << "add new items" << endl;
    cout << "product code" << endl;
    cin >> code;
    cout << "name of product" << endl;
    cin >> name;
    cout << "price of items" << endl;
    cin >> price;
    cout << "discount on product" << endl;
    cin >> discount;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << code << " " << price << " " << discount << endl;
        data.close();
    }
    else
    {
        data >> c >> s >> p >> d;
        while (!data.eof())
        {
            if (c == code)
            {
                t++;
            }

            data >> c >> s >> p >> d;
        }
        data.close();

        if (t == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << code << " " << price << " " << discount << endl;
            data.close();
        }
    }
    cout << "recorded inserted" << endl;
}
void shop::edit()
{
    fstream data, data1;
    int key;
    int t = 0;
    int c;
    float p;
    float d;
    string s;
    cout << "edit int items" << endl;
    cout << "product code" << endl;
    cin >> key;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "no such file exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> code >> name >> price >> discount;
        while (!data.eof())
        {
            if (key == code)
            {
                cout << "new product code" << endl;
                cin >> c;
                cout << "name of product" << endl;
                cin >> s;
                cout << "price" << endl;
                cin >> p;
                cout << "discount" << endl;
                cin >> d;
                data1 << " " << code << " " << price << " " << name << " " << discount << endl;
                cout << "record edited" << endl;
                t++;
            }
            else
            {
                data1 << " " << price << " " << code << " " << name << " " << discount << endl;
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}
void shop::r()
{
    fstream data, data1;
    int key;
    int t = 0;
    cout << "remove an items" << endl;
    cout << "product code" << endl;
    cin >> key;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "no such file exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> code >> name >> price >> discount;
        while (!data.eof())
        {
            if (key == code)
            {
                cout << "product removed successfully" << endl;
                t++;
            }
            else
            {
                data1 << " " << price << " " << code << " " << name << " " << discount << endl;
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (t == 0)
        {
            cout << "no item found" << endl;
        }
    }
}
void shop::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "pro.code\tname\tprice" << endl;
    data >> code >> name >> price;
    while (!data.eof())
    {
        cout << price << " " << name << " " << price << " " << endl;
        data >> code >> name >> price >> discount;
    }
    data.close();
}
void shop::bill()
{
m:
    fstream data;
    int ac[100];
    int ar[100];
    char c;
    int t = 0;
    float amount = 0;
    float d = 0;
    float total = 0;

    cout << "\t\tbill" << endl;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "empty" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "place the order" << endl;
        do
        {
            cout << "enter product code" << endl;
            cin >> ac[c];
            cout << "enter product code" << endl;
            cin >> ar[c];
            for (int i = 0; i < c; i++)
            {
                /* code */
                if (ac[c] == ar[c])
                {
                    cout << "duplicate product code" << endl;
                    goto m;
                }
            }
            c++;
            cout << "do not want to buy another product? if yes then please y else no";
            cin >> c;

        } while (c == 'y');
        {
            /* code */
            cout << "bill" << endl;
            cout << "pro.no \t quantity \t price \t amount \t amount with discount" << endl;
        }
        for (ll i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> code >> name >> price >> discount;
            while (!data.eof())
            {
                if (code == ac[i])
                {
                    amount = price * ar[i];
                    discount = amount * ((amount * discount) / 100);
                    total = total + discount;
                    cout << code << "\t" << name << "\t" << ac[i] << "\t" << price << "\t" << amount << "\t" << discount;
                }
                data >> code >> name >> price >> discount;
            }
        }
        data.close();
    }
    cout << endl;
    cout << "total amount" << total;
}

int main()
{
    shop s;
    s.menu();
    return 0;
}