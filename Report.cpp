#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>
using namesapace std;
// Structs for library data
struct Book {
    string isbn;
    string title;
    string author;
};

struct Member {
    int memberId;
    string name;
};

struct Transaction {
    string isbn;
    int memberId;
    string borrowDate;
    string dueDate;
};

// Helper function to get current date (simplified for comparison)
string getCurrentDate() {
    time_t now = time(nullptr);
    struct tm* t = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return string(buffer);
}

// Text report
void generateBorrowedBooksTextReport(
    const vector<Transaction>& transactions,
    const vector<Book>& books,
    const vector<Member>& members,
    const string& filename
) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Write header
    outFile << left << setw(15) << "ISBN"
            << setw(30) << "Book Title"
            << setw(20) << "Member Name"
            << setw(15) << "Borrow Date"
            << setw(15) << "Due Date"
            << setw(10) << "Status" << endl;
    outFile << std::string(105, '-') << endl;

    // Write data
    string currentDate = getCurrentDate();
    for (const auto& transaction : transactions) {
        // Find book and member details
        string bookTitle = "Unknown";
        string memberName = "Unknown";
        for (const auto& book : books) {
            if (book.isbn == transaction.isbn) {
                bookTitle = book.title;
                break;
            }
        }
        for (const auto& member : members) {
            if (member.memberId == transaction.memberId) {
                memberName = member.name;
                break;
            }
        }

        // Check if overdue
        string status = (transaction.dueDate < currentDate) ? "Overdue" : "On Time";

        outFile << left << setw(15) << transaction.isbn
                << setw(30) << bookTitle
                << setw(20) << memberName
                << setw(15) << transaction.borrowDate
                << setw(15) << transaction.dueDate
                << setw(10) << status << endl;
    }

    outFile.close();
    cout << "Text report generated: " << filename << endl;
}

// CSV report
void generateBorrowedBooksCSVReport(
    const vector<Transaction>& transactions,
    const vector<Book>& books,
    const vector<Member>& members,
    const string& filename
) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Write CSV header
    outFile << "ISBN,Book Title,Member Name,Borrow Date,Due Date,Status\n";

    // Write data
   string currentDate = getCurrentDate();
    for (const auto& transaction : transactions) {
        string bookTitle = "Unknown";
        string memberName = "Unknown";
        for (const auto& book : books) {
            if (book.isbn == transaction.isbn) {
                bookTitle = book.title;
                break;
            }
        }
        for (const auto& member : members) {
            if (member.memberId == transaction.memberId) {
                memberName = member.name;
                break;
            }
        }

        string status = (transaction.dueDate < currentDate) ? "Overdue" : "On Time";

        outFile << transaction.isbn << "," << bookTitle << "," << memberName << ","
                << transaction.borrowDate << "," << transaction.dueDate << ","
                << status << "\n";
    }

    outFile.close();
    cout << "CSV report generated: " << filename << std::endl;
}

int main() {
    // Sample data
    vector<Book> books = {
        {"123456", "The Great Gatsby", "F. Scott Fitzgerald"},
        {"789012", "1984", "George Orwell"},
        {"345678", "Pride and Prejudice", "Jane Austen"}
    };

    vector<Member> members = {
        {1, "Alice Smith"},
        {2, "Bob Johnson"}
    };

    vector<Transaction> transactions = {
        {"123456", 1, "2025-06-01", "2025-06-15"},
        {"789012", 2, "2025-06-10", "2025-06-24"},
        {"345678", 1, "2025-06-20", "2025-07-05"}
    };

    // Generate reports
    generateBorrowedBooksTextReport(transactions, books, members, "borrowed_books.txt");
    generateBorrowedBooksCSVReport(transactions, books, members, "borrowed_books.csv");

    return 0;
}
