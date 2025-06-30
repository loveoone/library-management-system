#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;
struct Book {
    int id;
    string title;
    string issuedTo;
    string issueDate;
    bool isIssued;
};
Book books[SIZE];
int bookCount = 0;
void addBook() {
    cout << "Enter Book ID: ";
    cin >> books[bookCount].id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, books[bookCount].title);
    books[bookCount].isIssued = false;
    bookCount++;
    cout << "Book added.\n";
}
void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id && !books[i].isIssued) {
            cout << "Issued To: ";
            getline(cin, books[i].issuedTo);
            cout << "Issue Date: ";
            getline(cin, books[i].issueDate);
            books[i].isIssued = true;
            cout << "Book issued.\n";
            return;
        }
    }
    cout << "Book not found or already issued.\n";
}
void viewIssued() {
    cout << "\n--- Issued Books ---\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued) {
            cout << "Book ID: " << books[i].id << "\n";
            cout << "Title: " << books[i].title << "\n";
            cout << "Issued To: " << books[i].issuedTo << "\n";
            cout << "Issue Date: " << books[i].issueDate << "\n";
            cout << "--------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No books are currently issued.\n";
    }
}
int main() {
    int choice;
    do {
        cout << "\n1. Add Book\n2. Issue Book\n3. View Issued Books\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addBook();
        else if (choice == 2) issueBook();
        else if (choice == 3) viewIssued();
    } while (choice != 0);
    return 0;
}
