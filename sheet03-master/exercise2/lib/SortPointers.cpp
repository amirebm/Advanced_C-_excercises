#include <algorithm>
#include <cassert>
#include <vector>

namespace sort_pointers {

const unsigned** partition(const unsigned** low, const unsigned** high) {
    const unsigned* pivot = *high;
    const unsigned** i = low - 1;

    for (const unsigned** j = low; j < high; ++j) {
        if (**j < *pivot) {
            ++i;
            std::swap(*i, *j);
        }
    }

    std::swap(*(i + 1), *(high));
    return i + 1;
}

void quicksort_helper(const unsigned** begin, const unsigned** end) {
    if (begin < end) {
        const unsigned** partition_ptr = partition(begin, end - 1);
        quicksort_helper(begin, partition_ptr);
        quicksort_helper(partition_ptr + 1, end);
    }
}

void quicksort(const unsigned** begin, const unsigned** end) {
    assert(begin != nullptr && end != nullptr && begin <= end);
    quicksort_helper(begin, end);
}

void merge(const unsigned** begin, const unsigned** mid, const unsigned** end) {
    size_t left_size = mid - begin;
    size_t right_size = end - mid;

    std::vector<const unsigned*> left(begin, mid);
    std::vector<const unsigned*> right(mid, end);

    size_t i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (*left[i] < *right[j]) {
            *(begin + k) = left[i];
            ++i;
        } else {
            *(begin + k) = right[j];
            ++j;
        }
        ++k;
    }

    while (i < left_size) {
        *(begin + k) = left[i];
        ++i;
        ++k;
    }

    while (j < right_size) {
        *(begin + k) = right[j];
        ++j;
        ++k;
    }
}

void mergesort_helper(const unsigned** begin, const unsigned** end) {
    if (end - begin > 1) {
        const unsigned** mid = begin + (end - begin) / 2;
        mergesort_helper(begin, mid);
        mergesort_helper(mid, end);
        merge(begin, mid, end);
    }
}

void mergesort(const unsigned** begin, const unsigned** end) {
    assert(begin != nullptr && end != nullptr && begin <= end);
    mergesort_helper(begin, end);
}

} // namespace sort_pointers
