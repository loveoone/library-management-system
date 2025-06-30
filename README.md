library management system review This project works library management system using c++ programming languages using statement,function,array,string. It does 1.Add, update, delete books 2. Register and manage users (students or staff) 3. Issue and return books 4. Search for books (by title, author, ID) 5. Generate reports (borrowed books, overdue books, etc.) 6. Store data using files This module handles all operations related to managing books in the Library Management System. It allows users (librarians/admins) to add, view, update, and delete books from the system. All data is stored persistently using text files (books.txt), enabling data recovery and long-term use.Library Management System: Report Requirements
A library management system typically tracks:
-Books: Title, author, ISBN, availability, etc.
-Members: Member ID, name, contact details, borrowed books.
-Transactions: Borrow/return dates, fines, etc.
-Common reports include:
-Book Inventory Report: List all books with details.
-Borrowed Books Report: Show currently borrowed books and their due dates.
-Overdue Books Report: Highlight books past their due date with fines.
-Member Report: List members and their borrowing history.


---

### 📦 System Integration Module

**👨‍💻 Author:** *Eliyas Tegegn (Elias)*
</br>
**📌 Role:** *System Integration*
</br>
**📁 File:** `main_integration.cpp`
</br>
#### 🔧 Summary

This module acts as the **central integration point** for the entire Library Management System. It connects all functional parts into one unified command-line application.

#### ✅ Integrated Features

| Feature           | Status     | Implemented By |
| ----------------- | ---------- | -------------- |
| Book Management   | ✅ Complete | Afomiya        |
| Book Return       | ✅ Complete | Nahom          |
| Report Generation | ✅ Complete | Samuel         |

#### 🚧 Pending Features (Placeholders Ready)

| Feature                 | Status     | Assigned To |
| ----------------------- | ---------- | ----------- |
| User Management         | 🚧 Pending | Afomiya     |
| Book Issuing            | 🚧 Pending | Biruk       |
| File Handling & Storage | 🚧 Pending | Tewodrose   |
| Backup & Recovery       | 🚧 Pending | Harun       |
| Search & File System    | 🚧 Pending | Huzeyfa     |

#### 🛠️ How to Run

```bash
g++ main_integration.cpp -o library_system
./library_system
```
#### Integrated Features Working 
Running Image 1
</br>
![image](https://github.com/user-attachments/assets/0191cf18-4e86-44ac-ac56-66d785765076)
</br>
Running Image 2
</br>
![image](https://github.com/user-attachments/assets/33e87f56-47ee-4d55-b3fc-a14904d137ae)
</br>
Running Image 3
</br>
![image](https://github.com/user-attachments/assets/35e52382-fcdf-420f-9424-5fad01a27e19)
</br>
Running Image 4
</br>
![image](https://github.com/user-attachments/assets/707c2c14-9ddd-403a-87a5-89eff8871656)
</br>
Running Image 5
</br>
![image](https://github.com/user-attachments/assets/a3dde6bb-c06f-473b-8e9f-5f009e22ce4d)
</br>
#### 📄 Output Files
</br>

* `borrowed_books.txt` – Text format report
* `borrowed_books.csv` – CSV format report

#### 🔗 Notes

* The `mainMenu()` function is the main entry point for running the entire system.
* All modules are designed for future extension and easy replacement of stubs with actual logic.

---
