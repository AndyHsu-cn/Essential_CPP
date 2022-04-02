#include <iostream>
#include <string>
using namespace std;

class LibMat
{
public:
    LibMat()
    {
        cout << "LibMat::LibMat() default constructor was called" << endl;
    }

    virtual ~LibMat()
    {
        cout << "LibMat::~LibMat() default destructor was called" << endl;
    }
    virtual void print() const
    {
        cout << "LibMat::print() -- I am a LibMat object" << endl;
    }
};

class Book : public LibMat
{
public:
    Book(const string &title, const string &author) : _title(title), _author(author)
    {
        cout << "Book::Book( " << _title << ", " << _author << " ) constructor was called" << endl; 
    }

    virtual ~Book()
    {
        cout << "Book::~Book() was called" << endl;
    }

    virtual void print() const
    {
        cout << "Book::print() -- I am a Book object" << endl;
        cout << "My title is: " << _title << endl;
        cout << "My author is: " << _author << endl;
    }

    const string & title() const { return _title;}
    const string & author() const { return _author;}

protected:
    string _title;
    string _author;
};

class AudioBook : public Book
{
public:
    AudioBook(const string &title, const string &author, const string &narrator) : Book(title, author), _narrator(narrator)
    {
        cout << "AudioBook::AudioBook(" << _title << ", " << _author << ", " << _narrator
            << " ) constructor was called" << endl;
    }

    ~AudioBook()
    {
        cout << "AudioBook::~AudioBook() destructor was called" << endl;
    }

    virtual void print() const
    {
        cout << "AudiBook::print() -- I am a AudiBook object" << endl;
        cout << "My title is: " << _title << endl;
        cout << "My author is: " << _author << endl;
        cout << "My narrator is: " << _narrator << endl;
    }

    const string & narrator() const { return _narrator;}
protected:
    string _narrator;
};
