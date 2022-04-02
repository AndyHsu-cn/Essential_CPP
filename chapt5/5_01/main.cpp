#include "LibMat.hpp"

void print(const LibMat & mat)
{
    cout << "In global print(): about to print mat.print()" << endl;
    mat.print();
}

int main()
{
    // cout << "\nCreating a LibMat object to print()" << endl;
    // LibMat libmat;
    // print(libmat);

    // cout << "\nCreating a Book object to print()" << endl;
    // Book b("The Castle", "Franz Kafka");
    // print(b);

    // cout << "\nCreating a AudiBook object to print()" << endl;
    // AudioBook ab("Man Without Qualities", "Robert Musil", "Keneth Meyer");
    // print(ab);

    LibMat * audio = new AudioBook("Man Without Qualities", "Robert Musil", "Keneth Meyer");
    delete audio;
    
    return 0;
}