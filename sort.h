#ifndef SORT
#define SORT

// Внутрішня функція порівняння
inline int32_t _sort_cmp(const char* fStr, const char* sStr) {
    while (*fStr && (*fStr == *sStr)) {
        fStr++;
        sStr++;
    }
    return *(const unsigned char*)fStr - *(const unsigned char*)sStr;
}

inline void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

inline int partition(char** arr, int low, int high) {
    char* pivot = *(arr + high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (_sort_cmp(*(arr + j), pivot) < 0) {
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return (i + 1);
}

inline void quickSortRecursive(char** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

inline void quick_sort(char** arr, size_t length)
{
    if (length > 0) {
        quickSortRecursive(arr, 0, (int)length - 1);
    }
}
#endif // !SORT