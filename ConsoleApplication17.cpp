#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* data;            
    size_t length;       
    static int objectCount; 

public:
    String() : String(80) {
    }

    explicit String(size_t size) : length(size) {
        data = new char[length + 1];
        data[0] = '\0';
        ++objectCount;
    }

    String(const char* str) : length(strlen(str)) {
        data = new char[length + 1];
        strcpy(data, str);
        ++objectCount;
    }

    ~String() {
        delete[] data;
        --objectCount;
    }

    void input() {
        cout << "Enter the line:";
        cin.getline(data, length + 1);
    }

    void output() const {
        cout << "Line:" << data << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    {
        String s1;
        s1.input();
        s1.output();

        String s2(50);
        s2.input();
        s2.output();

        String s3("Hello world!"); 
        s3.output();

        cout << "Number of created objects: " << String::getObjectCount() << endl;
    }
    cout << "Number of objects created after block completion: " << String::getObjectCount() << endl;
}
