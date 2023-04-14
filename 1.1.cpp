#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Type
{
    ART, TECH
};


class Book {
public:
    Book(const string& _avtor, const string& _nazvanie, Type _type) :avtor(_avtor), nazvanie(_nazvanie), type(_type) {}
    Type getType() const {
        return type;
    }
    ~Book() {
    }
private:
    const string avtor;
    const string nazvanie;
    const Type type;
};

class Library {
public:
    ~Library() {
        for (int i = 0; i < size(Libary); ++i) {
            delete Libary[i];
        }
    }
    void addBook(const string& _avtor, const string& _nazvanie, Type _type) {
        if ((_avtor == "") || (_nazvanie == "")) {
            cout << "the book wasn`t found" << endl;
        }
        else {
            Libary.push_back(new Book(_avtor, _nazvanie, _type));
        }

    }
    void ReturningTypel() {
        int hud = 0;
        int tech = 0;
        for (const Book* book : Libary) {
            switch (book->getType()) {
            case Type::ART:
                ++hud;
                break;
            case Type::TECH:
                ++tech;
            }
        }
        cout << hud << " " << tech << endl;
    }
    void ReturningType2() {
        int hud = 0;
        int tech = 0;
        for (const Book* book : Libary) {
            if (book->getType() == Type::ART) {
                hud++;
            }
            else //if
            {
                tech++;
            }
        }
        cout << hud << " " << tech << endl;
    }
private:
    vector<Book*> Libary;
};

int main() {
    Library LBook;
    LBook.addBook("J. K. Rowling", "Harry Potter", Type::ART);
    LBook.addBook("Stephen King", "dead zone", Type::ART);
    LBook.addBook("Herbert Schildt", "с++", Type::TECH);

    LBook.ReturningTypel();
    cout << endl;
    LBook.ReturningType2();
    return 0;
}
