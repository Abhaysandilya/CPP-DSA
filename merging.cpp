#include <iostream>

void merge(int x[], int y[], int n1, int n2) {
    int* result = new int[n1 + n2];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (x[i] <= y[j]) {
            result[k] = x[i];
            i++;
        } else {
            result[k] = y[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        result[k++] = x[i++];
    }
    while (j < n2) {
        result[k++] = y[j++];
    }

    // Print the merged result
    std::cout << "Merged array: ";
    for (int m = 0; m < n1 + n2; m++) {
        std::cout << result[m] << " ";
    }
    std::cout << std::endl;

    // Free allocated memory
    delete[] result;
}

int main() {
    int x[] = {1, 3, 5, 7};
    int y[] = {2, 4, 6, 8};
    int n1 = sizeof(x) / sizeof(x[0]);
    int n2 = sizeof(y) / sizeof(y[0]);

    merge(x, y, n1, n2);

    return 0;
}
