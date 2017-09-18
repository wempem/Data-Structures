#include <iostream>

class Student {
    public:
        virtual int getAge() = 0;
        virtual int getHeight() = 0;
};

class Jonah : public Student {
    public:
        int getAge() {
            return 12;
        }
        int getHeight() {
            return 62;
        }
};

int main(int argc, char *argv[]) {
    Jonah jonah;
    Student *alex;

    alex = &jonah;
    std::cout << "Jonah's age: " << jonah.getAge() << "\n";
    std::cout << "Alex is pointing to a student of age: " << alex->getAge() << "\n";
    return 0;
}
