#include <iostream>

using namespace std;

const int kSize = 10;

void initThreeDimArray(int *a) {
    for (int i = 0; i < kSize; i++)
        for (int j = 0; j < kSize; j++)
            for (int k = 0; k < kSize; k++)
                *(a + kSize*kSize*i + kSize*j + k) = i + j + k;
}

int main() {
    int array[kSize][kSize][kSize] = {{{ 0 }}};
    initThreeDimArray((int *)array);

    for (int i = 0; i < kSize; i++)
        for (int j = 0; j < kSize; j++) {
            for (int k = 0; k < kSize; k++) {
                cout << array[i][j][k] << "\t";
            }
            cout << endl;
        }
}
