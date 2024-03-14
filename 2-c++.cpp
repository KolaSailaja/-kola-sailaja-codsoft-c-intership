#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**************LIBRARY MANAGEMENT SYSTEM****************/
struct student {
    int bookID;
    char title[30];
    char authorOfBook[30];
    float costofBook; 
};

const int books = 5;
int arr = 0;
student classstudentobj[books];

void prompt_cost(int index) {
    cout << "Enter the cost of the book:" << endl;
    cin >> classstudentobj[index].costofBook;
}

void add_book() {
    if (arr < books) {
        cout << "****-----Enter details of the books----****" << endl;
        cout << "Enter a bookID:" << endl;
        cin >> classstudentobj[arr].bookID;
        cout << "Enter the title of the book:" << endl;
        cin >> classstudentobj[arr].title;
        cout << "Enter the author name of the book:" << endl;
        cin >> classstudentobj[arr].authorOfBook;
        prompt_cost(arr); 
        arr++;
    } else {
        cout << "No more space for books in the library" << endl;
    }
}

void display_books() {
    for (int i = 0; i < arr; i++) {
        cout << "****----Details of the book are:----****" << endl;
        cout << "BookID id:" << classstudentobj[i].bookID << endl;
        cout << "Book title is:" << classstudentobj[i].title << endl;
        cout << "Author of the book is:" << classstudentobj[i].authorOfBook << endl;
        cout << "Cost of the book is:" << classstudentobj[i].costofBook << endl;
    }
}

void book_author() {
    char search_book[30];
    cout << "Enter the name of the author:" << endl;
    cin >> search_book;
    int i = 0;
    while (i < arr) {
        if (strcmp(search_book, classstudentobj[i].authorOfBook) == 0) {
            cout << "BookID:" << classstudentobj[i].bookID << endl;
            cout << "Book name:" << classstudentobj[i].title << endl;
            cout << "Author of the book:" << classstudentobj[i].authorOfBook << endl;
            cout << "Cost of book:" << classstudentobj[i].costofBook << endl;
        }
        i++;
    }
}

void book_cost() {
    float search_cost;
    cout << "Enter the cost of the book you are looking for:" << endl;
    cin >> search_cost;
    int i = 0;
    while (i < arr) {
        if (search_cost == classstudentobj[i].costofBook) {
            cout << "BookID:" << classstudentobj[i].bookID << endl;
            cout << "Book name:" << classstudentobj[i].title << endl;
            cout << "Author of the book:" << classstudentobj[i].authorOfBook << endl;
            cout << "Cost of book:" << classstudentobj[i].costofBook << endl;
        }
        i++;
    }
}

int main() {
    int choice;
    char input;
    do {
        cout << "****----library Book record system----****" << endl;
        cout << "Press 1 to enter a book record:" << endl;
        cout << "Press 2 to display all the records of books:" << endl;
        cout << "Press 3 to search book by author name:" << endl;
        cout << "Press 4 to search book by cost:" << endl;
        cout << "Press 5 to count the number of books in the library:" << endl;
        cout << "Press 6 to exit from the system:" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                book_author();
                break;
            case 4:
                book_cost();
                break;
            case 5:
                cout << "Total number of books in the library:" << arr << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you still want to continue? Press 'x' or 'y':" << endl;
        cin >> input;
    } while (input == 'y' || input == 'x');

    return 0;
}

