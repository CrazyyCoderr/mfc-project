#include <iostream>
using namespace std;

#define MAX_BOOKS 100
#define MAX_MEMBERS 100

class Library {
private:
    struct Book {
        int id;
        string title;
        string author;
    } books[MAX_BOOKS];
    int bookCount = 0;

    struct Member {
        int id;
        string name;
    } members[MAX_MEMBERS];
    int memberCount = 0;

public:
    void addBook(int bookID, string title, string author) {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full, cannot add more books." << endl;
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookID) {
                cout << "Book ID already exists." << endl;
                return;
            }
        }
        books[bookCount++] = {bookID, title, author};
        cout << "Book added successfully." << endl;
    }

    void viewBooks() {
        if (bookCount == 0) {
            cout << "No books available." << endl;
        } else {
            for (int i = 0; i < bookCount; i++) {
                cout << "ID: " << books[i].id << ", Title: " << books[i].title << ", Author: " << books[i].author << endl;
            }
        }
    }

    void updateBook(int bookID, string title, string author) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookID) {
                books[i].title = title;
                books[i].author = author;
                cout << "Book updated successfully." << endl;
                return;
            }
        }
        cout << "Book ID not found." << endl;
    }

    void deleteBook(int bookID) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookID) {
                books[i] = books[--bookCount];
                cout << "Book deleted successfully." << endl;
                return;
            }
        }
        cout << "Book ID not found." << endl;
    }

    void addMember(int memberID, string name) {
        if (memberCount >= MAX_MEMBERS) {
            cout << "Cannot add more members." << endl;
            return;
        }
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberID) {
                cout << "Member ID already exists." << endl;
                return;
            }
        }
        members[memberCount++] = {memberID, name};
        cout << "Member added successfully." << endl;
    }

    void viewMembers() {
        if (memberCount == 0) {
            cout << "No members available." << endl;
        } else {
            for (int i = 0; i < memberCount; i++) {
                cout << "ID: " << members[i].id << ", Name: " << members[i].name << endl;
            }
        }
    }

    void updateMember(int memberID, string name) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberID) {
                members[i].name = name;
                cout << "Member updated successfully." << endl;
                return;
            }
        }
        cout << "Member ID not found." << endl;
    }

    void deleteMember(int memberID) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberID) {
                members[i] = members[--memberCount];
                cout << "Member deleted successfully." << endl;
                return;
            }
        }
        cout << "Member ID not found." << endl;
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author, name;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book\n2. View Books\n3. Update Book\n4. Delete Book\n";
        cout << "5. Add Member\n6. View Members\n7. Update Member\n8. Delete Member\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID: "; cin >> id;
                cout << "Enter book title: "; cin.ignore(); getline(cin, title);
                cout << "Enter book author: "; getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                cout << "Enter book ID: "; cin >> id;
                cout << "Enter new title: "; cin.ignore(); getline(cin, title);
                cout << "Enter new author: "; getline(cin, author);
                library.updateBook(id, title, author);
                break;
            case 4:
                cout << "Enter book ID: "; cin >> id;
                library.deleteBook(id);
                break;
            case 5:
                cout << "Enter member ID: "; cin >> id;
                cout << "Enter member name: "; cin.ignore(); getline(cin, name);
                library.addMember(id, name);
                break;
            case 6:
                library.viewMembers();
                break;
            case 7:
                cout << "Enter member ID: "; cin >> id;
                cout << "Enter new name: "; cin.ignore(); getline(cin, name);
                library.updateMember(id, name);
                break;
            case 8:
                cout << "Enter member ID: "; cin >> id;
                library.deleteMember(id);
                break;
            case 9:
                cout << "Exiting Library Management System." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
