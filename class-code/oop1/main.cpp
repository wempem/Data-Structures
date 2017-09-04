#include <iostream>

class Structures {
    public:
        Structures() {
            mHeight = 10;
            mWidth = 20;
        }
        int getHeight() {
            return mHeight;
        }
        int getWidth() {
            return mWidth;
        }
    private:
        int mHeight, mWidth;
};

int main(int argc, char *argv[]) {
    int x[20];
    Structures structures[10];
    Structures *s2;

    s2 = new Structures[5];
    std::cout << "x = " << x << "\n";
    x[0] = 100;
    std::cout << "x[0] = " << x[0] << "\n";

    std::cout << "structures = " << structures << "\n";
    std::cout << "structures[0].getHeight() = " << structures[0].getHeight() << "\n";

    std::cout << "s2 = " << s2 << "\n";
    std::cout << "s2[1].getHeight() = " << s2[1].getHeight() << "\n";

    delete[] s2;
    //delete[] structures; // DON'T DO THIS!
    return 0;
}
