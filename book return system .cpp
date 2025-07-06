#include <iostream>
using namespace std;
const int MAX_BOOKS = 5;

string borrowedBooks[MAX_BOOKS] = {"C++ Basics", "Data Structures", "Algorithms", "Operating Systems", "Networking"};

void displayBorrowedBooks() {
    cout << "\nBorrowed Books:\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (borrowedBooks[i] != "") {
            cout << i + 1 << ". " << borrowedBooks[i] << endl;
        }
    }
}

void returnBook() {
    int choice;
    displayBorrowedBooks();
    cout << "\nEnter the number of the book you want to return: ";
    cin >> choice;

    if (choice >= 1 && choice <= MAX_BOOKS && borrowedBooks[choice - 1] != "") {
        cout << "Returning \"" << borrowedBooks[choice - 1] << "\"...\n";
        borrowedBooks[choice - 1] = "";  // Mark the book as returned
        cout << "Book returned successfully.\n";
    } else {
        cout << "Invalid selection or book already returned.\n";
    }
}


void menu() {
    int option;

    do {
        cout << "\n===== Book Return System =====\n";
        cout << "1. View Borrowed Books\n";
        cout << "2. Return a Book\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                displayBorrowedBooks();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (option != 3);
}

int main() {
    menu();
    return 0;
}
