// Library Management Program

#include <iostream>
#include <string>
using namespace std;

// book structure
struct library {
    string book_name;
    string author;
    int pages;
    float price;
};

int main()
{
    library lib[100];

    string ar_nm;
    int input = 0, count = 0, i;

    while (input != 5) {

        cout << "\n\n***** WELCOME TO E-LIBRARY *****\n";
        cout << "1. Add book\n";
        cout << "2. Display books\n";
        cout << "3. Search by author\n";
        cout << "4. Total books\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> input;

        switch (input) {

        case 1:
            cout << "Enter book name: ";
            cin >> lib[count].book_name;

            cout << "Enter author name: ";
            cin >> lib[count].author;

            cout << "Enter pages: ";
            cin >> lib[count].pages;

            cout << "Enter price: ";
            cin >> lib[count].price;

            count++;
            break;

        case 2:
            cout << "\nBook Details:\n";
            for (i = 0; i < count; i++) {
                cout << lib[i].book_name << "\t"
                     << lib[i].author << "\t"
                     << lib[i].pages << "\t"
                     << lib[i].price << endl;
            }
            break;

        case 3:
            cout << "Enter author name: ";
            cin >> ar_nm;

            for (i = 0; i < count; i++) {
                if (ar_nm == lib[i].author) {
                    cout << lib[i].book_name << " "
                         << lib[i].author << " "
                         << lib[i].pages << " "
                         << lib[i].price << endl;
                }
            }
            break;

        case 4:
            cout << "Total books: " << count << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Wrong choice";
        }
    }

    return 0;
}
