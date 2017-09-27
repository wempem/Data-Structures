#include <iostream>

// We want to know can we navigate from (sx, sy) to (ex, ey)
bool canNavigate(int px, int py, int ex, int ey);
#define WIDTH (5)
#define HEIGHT (6)
    char maze[][5] = { 
        { 'O', 'O', 'W', 'O', 'O'}, 
        { 'O', 'O', 'W', 'O', 'O'}, 
        { 'O', 'O', 'W', 'O', 'O'}, 
        { 'O', 'O', 'O', 'O', 'O'}, 
        { 'O', 'O', 'W', 'O', 'O'}, 
        { 'O', 'O', 'W', 'O', 'O'}
    };
void printMaze();

int main(int argc, char *argv[]) {

    // We want to know can we navigate from (sx, sy) to (ex, ey)
    std::cout << "can we go from (1, 1) to (4, 4)? " << 
        canNavigate(1, 1, 4, 4) << "\n";
    return 0;
}

bool canNavigate(int px, int py, int ex, int ey) {
    std::cout << "canNavigate(" << px << ", " << py << ", " << ex << ", " << ey << ");\n";
    printMaze();
    // Base cases
    // Bounds checks first!
    if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT) {
        std::cout << "Out of bounds, returning false!\n";
        return false;
    }
    // Not a legal move.
    if (maze[px][py] != 'O') {
        std::cout << "Not Open, returning false!\n";
        return false;
    }
    // If we are at the end
    if (px == ex && py == ey) {
        std::cout << "Found the end, returning true!\n";
        return true;
    }

    // Mark as Visited
    maze[px][py] = 'V';

    if (canNavigate(px + 1, py, ex, ey)) {
        return true;
    }
    if (canNavigate(px - 1, py, ex, ey)) {
        return true;
    }
    if (canNavigate(px, py + 1, ex, ey)) {
        return true;
    }
    if (canNavigate(px, py - 1, ex, ey)) {
        return true;
    }

    // No paths found, return false
    return false;
}

void printMaze() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << "\n";
    }
}
