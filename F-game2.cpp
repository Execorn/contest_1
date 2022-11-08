#include <iostream>
#include <cstdint>

unsigned char get_winner(unsigned char** dynamic, int current_x, int current_y, int x, int y) {

    int tmp = current_x;
    while (tmp < x) {
        if (dynamic[current_y][tmp] == 1) return 0;
        ++tmp;
    }

    int tmp_y = current_y;
    while (tmp_y >= 0) {
        if (dynamic[tmp_y][current_x] == 1) return 0;
        --tmp_y;
    }

    while (current_x < x && current_y >= 0) {
        if (dynamic[current_y][current_x] == 1) return 0;
        ++current_x;
        --current_y;
    }

    return 1;
}

int main() {
    int x = 0, y = 0;
    std::cin >> x >> y;

    unsigned char** dynamic = new unsigned char*[y]();
    for (size_t current = 0; current < y; ++current) dynamic[current] = new unsigned char[x]();

    dynamic[0][x - 1] = 1;
    for (int current_x = x - 1; current_x >= 0; --current_x) {
        for (int current_y = 0; current_y < y; ++current_y) {
            
            if ((current_x == x - 1) && (current_y == 0)) continue;
            dynamic[current_y][current_x] = get_winner(dynamic, current_x, current_y, x, y);
        }
    }

    if (!dynamic[y - 1][0]) { std::cout << "F" << std::endl;
    } else std::cout << "S" << std::endl;

    for (size_t current = 0; current < y; ++current) delete[] dynamic[current];

    delete[] dynamic;
}