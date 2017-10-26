#include <iostream>

void merge_sort(int *ary, int size);
void print(int *ary, int size);

int *temp;

int main(int argc, char *argv[]) {
    int ary[] = {4, 12, 6, 1, 18, 55, -100, -4, 9000, 23};

    temp = new int[10];
    merge_sort(ary, 10);

    print(ary, 10);
    return 0;
}

void merge_sort(int *ary, int size) {
    // Setup the recursive
    if (size == 1) {
        return;
    }

    int middlePos = size / 2;
    merge_sort(ary, middlePos);
    if (size % 2 == 0) { // size is even
        merge_sort(ary + middlePos, middlePos);
    }else {
        merge_sort(ary + middlePos, middlePos + 1);
    }

    std::cout << "Before Merge, size = " << size << "\n";
    print(ary, size);
    // We need to merge!
    int s1pos = 0;
    int s2pos = middlePos;
    int pos = 0;

    for (pos = 0; pos < size; pos++) {
        if ((s2pos >= size) || (s1pos < middlePos && ary[s1pos] < ary[s2pos])) {
            temp[pos] = ary[s1pos];
            s1pos++;
        } else {
            temp[pos] = ary[s2pos];
            s2pos++;
        }
    }

    for (int i = 0; i < size; i++) {
        ary[i] = temp[i];
    }

    std::cout << "After Merge\n";
    print(ary, size);
}

void print(int *ary, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << ary[i] << ", ";
    }
    std::cout << "\n";
}
