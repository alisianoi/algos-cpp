#ifndef SRC_SORT_HEAPSORT_HPP_
#define SRC_SORT_HEAPSORT_HPP_

#include <iterator>
#include <functional>

template<class RandomIt, class Key = std::less<>>
void plunge(RandomIt fst, RandomIt lst, RandomIt cur, Key key = Key{}) {
    auto lft = std::next(fst, 2 * std::distance(fst, cur) + 1);

    while (lft < lst) {
        auto rgt = std::next(lft);

        auto child = rgt < lst && key(*rgt, *lft) ? rgt : lft;

        if (key(*cur, *child)) return;

        std::iter_swap(cur, child);

        cur = child;
        lft = std::next(fst, 2 * std::distance(fst, cur) + 1);
    }
}

template<class RandomIt, class Key = std::less<>>
void makeheap(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) {
        return;
    }

    for (auto x = std::next(fst, std::distance(fst, lst) / 2); x >= fst; --x) {
        plunge(fst, lst, x, key);
    }
}

template<class RandomIt, class Key = std::less<>>
void pushheap(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) return;

    lst = std::prev(lst);

    while (fst != lst) {
        auto cur = std::next(fst, (std::distance(fst, lst) - 1) / 2);

        if (key(*cur, *lst)) return;

        std::iter_swap(cur, lst);
        lst = cur;
    }
}

template<class RandomIt, class Key = std::less<>>
void popheap(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) return;

    lst = std::prev(lst);

    std::iter_swap(fst, lst);
    plunge(fst, lst, fst, key);
}

template<class RandomIt, class Key = std::greater<>>
void heapsort(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) return;

    makeheap(fst, lst, key);

    for (auto cur = lst; cur != fst; --cur) {
        popheap(fst, cur, key);
    }
}

#endif  // SRC_SORT_HEAPSORT_HPP_
