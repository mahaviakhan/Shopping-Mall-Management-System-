//shopping mall cep project (group E)
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

class admin
{
protected:
    int code;
    float price, discount;
    string name;

public:
    void menu();
    void add();
    void search();
    void edit();
    void show();
    void del();
    void zaqat();
    void dailyprofit();
};

class customer : public admin
{
public:
    void customermenu()
    {
        system("cls");
    p:
        int choise;
        cout << "\n\n\t\t -customer menu-";
        cout << "\n\n 1. sale product";
        cout << "\n 2. go back";
        cout << "\n\n enter your choise: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            purchase();
            break;
        default:
            cout << "\n\n invalid value";
        }
        getch();
        goto p;
    }
    list()
    {
        fstream file;
        file.open("product.txt", ios::in);
        cout << "\n\n====================================================\n";
        cout << "P.NO.\t\tNAME\t\tPRICE\n";
        cout << "====================================================\n";
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            cout << code << "\t\t" << name << "\t\t" << price << "\n";
            file >> code >> name >> price >> discount;
        }
        file.close();
    }
    purchase()
    {
        system("cls");
        fstream file;
        char choice;
        int o_c[50], o_q[50], c = 0;
        float amt = 0, dis = 0, total = 0;
        cout << "\n\n\t\t\t purchase product:";
        file.open("product.txt", ios::in);
        if (!file)
        {
            cout << "\n\n Data Base is Empty...";
        }
        else
        {
            file.close();
            list();
            cout << "\n****************************";
            cout << "\n    PLACE YOUR ORDER";
            cout << "\n****************************\n";
            do
            {
            p:
                cout << "\n\n Product Code : ";
                cin >> o_c[c];
                cout << "\n Product Quantity : ";
                cin >> o_q[c];
                for (int i = 0; i < c; i++)
                {
                    if (o_c[c] == o_c[i])
                    {
                        cout << "\n\n Duplicate Product Code...";
                        goto p;
                    }
                }
                c++;
                cout << "\n\n Do You Want Add Another Product (Y,N) : ";
                cin >> choice;
            } while (choice == 'Y' || choice == 'y');
            system("cls");
            cout << "\n\n********************************BILL************************\n";
            cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
            for (int i = 0; i < c; i++)
            {
                file.open("product.txt", ios::in);
                file >> code >> name >> price >> discount;
                while (!file.eof())
                {
                    if (code == o_c[i])
                    {
                        amt = price * o_q[i];
                        dis = amt - (amt / 100 * discount);
                        total += dis;
                        cout << "\n" << code << "\t" << name << "\t" << o_q[i] << "\t\t" << price << "\t" << amt << "\t\t" << dis;
                    }
                    file >> code >> name >> price >> discount;
                }
                file.close();
            }
            cout << "\n\n======================================";
            cout << "\n Total Amount : " << total;
        }
    }
};

class product
{
private:
    int code;
    float price, discount;
    string name;

public:
    void promenu()
    {
        system("cls");
    p:
        int choise;
        cout << "\n\n 1. Avaliable product list";
        cout << "\n\n 2. go back";
        cin >> choise;
        switch (choise)
        {
        case 1:
            prolist();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "\n\n invalid value..";
            goto p;
            getch;
        }
    }

    void prolist()
    {
        system("cls");
        fstream file;
        cout << "\n\n\t\t show product :";
        file.open("product.txt", ios::in);
        if (!file)
        {
            cout << "\n\n file opening error..";
        }
        else
        {
            cout << "\n\n code\tname\tprice\tdiscount ";
            file >> code >> name >> price >> discount;
            while (!file.eof())
            {
                cout << "\n " << code << "\t " << name << "\t   " << price << "\t  " << discount;
                file >> code >> name >> price >> discount;
            }
            file.close();
        }
    }
};

void admin::menu()
{
    system("cls");
p:
    int choise;
    cout << "\n\n\t\tadmin menu";
    cout << "\n 1. add product";
    cout << "\n 2. search product";
    cout << "\n 3. edit product";
    cout << "\n 4. delete product";
    cout << "\n 5. show products";
    cout << "\n 6. daily sales and profit:";
    cout << "\n 7. go back:";
    cout << "\n\n enter your choise: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        edit();
        break;
    case 4:
        del();
        break;
    case 5:
        show();
        break;
    case 6:
        dailyprofit();
        break;
    case 7:
        exit(0);
        break;
    default:
        cout << "\n\n invalid value..";
    }
    getch();
    goto p;
}
void admin::add()
{
    system("cls");
p:
    fstream file;
    int c, found = 0;
    float p, d;
    string n;
    cout << "\n\n\t\t add product";
    cout << "\n\n product code: ";
    cin >> code;
    cout << "\n\n name: ";
    cin >> name;
    cout << "\n\n price: ";
    cin >> price;
    cout << "\n\n discount in % : ";
    cin >> discount;
    file.open("product.txt", ios::in);
    if (!file)
    {
        file.open("product.txt", ios::app | ios::out);
        file << " " << code << " " << name << " " << price << " " << discount << " \n";
        file.close();
    }
    else
    {
        file >> c >> n >> p >> d;
        while (!file.eof())
        {
            if (c == code)
            {
                found++;
            }
            file >> c >> n >> p >> d;
        }
        file.close();
        if (found == 1)
            goto p;
        else
        {
            file.open("product.txt", ios::app | ios::out);
            file << " " << code << " " << name << " " << price << " " << discount << " \n";
            file.close();
        }
    }
    cout << "\n\n\t\t record inserted successfully...";
}
void admin::edit()
{
    system("cls");
    int p_c, found = 0, c;
    float p, d;
    string n;
    fstream file, file1;
    cout << "\n\n\t\t edit  ";
    cout << "\n\n product code";
    cin >> p_c;
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\n file openning error...";
    }
    else
    {
        file1.open("product1.txt", ios::app | ios::out);
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (p_c == code)
            {
                cout << "\n\n product new code: ";
                cin >> c;
                cout << "\n\n name: ";
                cin >> n;
                cout << "\n\n price: ";
                cin >> p;
                cout << "\n\n discount in %: ";
                cin >> d;
                file1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\trecord edit successfully...";
                found++;
            }
            else
            {
                file1 << " " << code << " " << name << " " << price << " " << discount << "\n";
            }
            file >> code >> name >> price >> discount;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product1.txt", "product.txt");
        if (found == 0)
            cout << "\n\n record cannot found";
    }
}
void admin::search()
{
    system("cls");
    int p_c, found = 0;
    fstream file;
    cout << "\n\n\t\tsearch ";
    cout << "\n\n product code";
    cin >> p_c;
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\n file openning error...";
    }
    else
    {
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (p_c == code)
            {
                cout << "\n\n\t\t search  record";
                cout << "\n\n product code: " << code;
                cout << "\n\n name: " << name;
                cout << "\n\n price: " << price;
                cout << "\n\n discount: " << discount << "%";
                found++;
            }
            file >> code >> name >> price >> discount;
        }
        file.close();
        if (found == 0)
            cout << "\n\n record cannot found";
    }
}

void admin::zaqat()
{
    system("cls");
    float money, zqt, prof;
    cout << "\n\n\t\tZAQAT CALCULATOR";
    cout << "\n enter profit money(yearly):";
    cin >> money;
    zqt = money / 100 * 2.5;
    cout << "\n your payable zaqat is :" << zqt;
}

void admin::dailyprofit()
{
    system("cls");
    fstream file4;
    float prof;

    cout << "\n\n\t\t SOLD ITEMS/PRODUCT AND DAILY PROFIT.... ";
    file4.open("profite.txt", ios::in);
    if (!file4)
    {
        cout << "\n\n\t\t record not available right now...";
    }
    else
    {
        file4.open("profite.txt", ios::app | ios::out);
        file4 << " " << prof << " \n";
        file4.close();
    }
    cout << "\n\t your daily profit is :" << prof;
}
void admin::del()
{
    system("cls");
    fstream file, file1;
    int p_c, found = 0;
    cout << "\n\n\t\t\tDelete Product";
    cout << "\n\n Product Code : ";
    cin >> p_c;
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File opening error...";
    }
    else
    {
        file1.open("product1.txt", ios::app | ios::out);
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            if (code == p_c)
            {
                cout << "\n\n Product Deleted Successfully...";
                found++;
            }
            else
            {
                file1 << " " << code << " " << name << " " << price << " " << discount << "\n";
            }
            file >> code >> name >> price >> discount;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product1.txt", "product.txt");
        if (found == 0)
            cout << "\n\n Record Can't Found...";
    }
}

void admin::show()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t show product :";
    file.open("product.txt", ios::in);
    if (!file)
    {
        cout << "\n\n file opening error..";
    }
    else
    {
        cout << "\n\n code\tname\tprice\tdiscount ";
        file >> code >> name >> price >> discount;
        while (!file.eof())
        {
            cout << "\n " << code << "\t " << name << "\t   " << price << "\t  " << discount;
            file >> code >> name >> price >> discount;
        }
        file.close();
    }
}

int main()
{
    admin A, Z;
    product P;
    customer C;

p:
    int choise;
    cout << "\n\n\n\n\t\t\t\t -MAIN MENU-";
    cout << "\n\t\t\t\t*************";
    cout << "\n 1. Admin";
    cout << "\n 2. Product/items list";
    cout << "\n 3. Customer";
    cout << "\n 4. Zaqat calculator";
    cout << "\n 5. Exit";
    cout << "\n enter your choice: ";
    cin >> choise;
    switch (choise)
    {
    case 1:
        A.menu();
        break;
    case 2:
        P.promenu();
        break;
    case 3:
        C.customermenu();
        break;
    case 4:
        Z.zaqat();
        break;
    case 5:
        exit(0);
        break;
    default:
    	cout<<"\n\n invalid value...";
	 }
	  getch();
	  goto p;
 }

