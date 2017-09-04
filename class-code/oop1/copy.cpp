#include <iostream>

class Structures {
    public:
        Structures(const char *name) {
            mHeight = 10;
            mWidth = 20;
            mName = new std::string(name);
        }
        Structures(Structures *s) {
            mHeight = s->mHeight;
            mWidth = s->mWidth;
            mName = new std::string(*(s->mName));
        }
        Structures() {
            mHeight = 10;
            mWidth = 20;
            mName = NULL;
        }
        int getHeight() {
            return mHeight;
        }
        int getWidth() {
            return mWidth;
        }
        std::string getName() {
            return *mName;
        }
        ~Structures() {
            std::cout << "I'm in " << *mName << " deconstructor\n";
            delete mName;
        }
    private:
        int mHeight, mWidth;
        std::string *mName;
};

int main(int argc, char *argv[]) {
    Structures structures("Johnny Boy");
    Structures *s2 = new Structures("Boy Johnny");

    Structures *s3 = s2; // Shallow copy, making an alias
    Structures *s4 = new Structures(s2); // Deep Copy

    //std::cout << "structures = " << structures << "\n";
    std::cout << "structures.getHeight() = " << structures.getHeight() << "\n";
    std::cout << "structures.getName() = " << structures.getName() << "\n";

    std::cout << "s2.getHeight() = " << (*s2).getHeight() << "\n";
    std::cout << "s2.getName() = " << s2->getName() << "\n";

    std::cout << "s3.getHeight() = " << (*s3).getHeight() << "\n";
    std::cout << "s3.getName() = " << s3->getName() << "\n";

    std::cout << "s4.getHeight() = " << (*s4).getHeight() << "\n";
    std::cout << "s4.getName() = " << s4->getName() << "\n";

    std::cout << "s3 = " << s3 << "\n";
    std::cout << "s2 = " << s2 << "\n";

    delete s2; // Calls s2 deconstructor, before freeing memory
    delete s4; // Calls s4 deconstructor, before freeing memory
    return 0;
}
