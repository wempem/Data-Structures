#include <iostream>

class Student{
    private:
        int mAge;
        int mHeight;
    public:
        Student() {
            mAge = 12;
            mHeight = 62;
        }
        int getHeight() {
            return mHeight;
        }
        void operator+(int a) {
            mHeight += a;
        }
        bool operator==(Student &st) {
            return this->mAge == st.mAge && (this->mHeight == st.mHeight);
        }
        // This is confusing!
        int operator[](const int pos) {
            return mAge + pos;
        }

        friend std::ostream& operator << (std::ostream &out, const Student& st) {
            out << "My age is: " << st.mAge;
            return out;
        }

        // jonah = alex
        Student& operator=(const Student &st) {
            this->mAge = st.mAge;
            this->mHeight = st.mHeight;
            return *this;
        }

        Student& operator++(int) {
            this->mHeight--;
            return *this;
        }
};

int main(int argc, char *argv[]) {
    Student jonah;
    Student alex;
    std::cout << "jonah's height: " << jonah.getHeight() << "\n";
    std::cout << "jonah == alex ? " << (jonah == alex) << "\n";
    jonah + 13;
    std::cout << "jonah's height: " << jonah.getHeight() << "\n";
    std::cout << "jonah == alex ? " << (jonah == alex) << "\n";

    std::cout << "jonah[15] = " << jonah[15] << "\n";
    std::cout << jonah << "\n";

    jonah = alex;
    std::cout << "jonah == alex ? " << (jonah == alex) << "\n";
    jonah++;
    std::cout << "jonah's height: " << jonah.getHeight() << "\n";
    return 0;
}
