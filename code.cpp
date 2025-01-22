#include <iostream>
#include <string>
using namespace std;

class Books { // Base Class
private:
    int totalBooks;
// constructor
public:
    Books(int total_books = 0) { // Default value for total_books
        totalBooks = total_books;
    }
// function
    void showBooksInfo() const {
        cout << "Total Books: " << totalBooks << endl;
    }
};

class Library { // Base Class
protected:
    string name;

public:
    Library(string libraryName = "") { // Default value for libraryName
        name = libraryName;
    }

    void showLibraryInfo() const {
        cout << "Library: " << name << endl;
    }
};

class Supervisor : public Library, public Books { // Derived Class
private:
    string librarianName;

public:
    Supervisor(string libraryName, int totalBooks, string librarian)
        : Library(libraryName), Books(totalBooks) {
        librarianName = librarian;
    }

    void showLibrarianInfo() const {
        showLibraryInfo();
        showBooksInfo();
        cout << "Librarian: " << librarianName << endl;
    }
};

class Member : public Supervisor { // Derived Class
private:
    string memberName;
    int id;

public:
    Member(string libraryName, int totalBooks, string librarian, string memberName, int id)
        : Supervisor(libraryName, totalBooks, librarian) {
        this->memberName = memberName;
        this->id = id;
    }
// function to show info
    void showMemberInfo() const {
        showLibrarianInfo();
        cout << "Member Name: " << memberName << endl;
        cout << "Member ID: " << id << endl;
    }
};

int main() {
    Member member("City Library", 5000, "Mr. Awais", "Ilyas Baig", 101);
    member.showMemberInfo();

    return 0;
}

