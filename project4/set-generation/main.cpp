#include <stdio.h>
#include <stdlib.h>
#include <set>

int main(int argc, char *argv[]) {
    srand(100);
    std::set<int> group;
    if (argc < 5) {
        printf("usage:\n%s <NUM_SETS> <MIN_SET_LENGTH> <MAX_SET_LENGTH> <NUM_ELEMENTS>\n", argv[0]);
    }
    int num_sets = atoi(argv[1]);
    int min_set_length = atoi(argv[2]);
    int max_set_length = atoi(argv[3]);
    int num_elements = atoi(argv[4]);
    int diff = max_set_length - min_set_length;
    for (int i = 0; i < num_sets; i++) {
        int len = rand() % (diff) + min_set_length;
        while (group.size() < len) {
            group.insert(rand() % num_elements);
        }
        std::set<int>::iterator it = group.begin();
        printf("%d", *it);
        it++;
        for (; it != group.end(); ++it) {
            printf(" %d", *it);
        }
        printf("\n");
        group.clear();
    }
    return 0;
}
