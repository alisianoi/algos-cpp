#define BOOST_TEST_MODULE test_quicksort
#define BOOST_TEST_DYN_LINK

#include "test_sort.hpp"
#include "sort/quicksort.hpp"


std::vector<sort_fun_rnd_inc> inc_sorts = {
    quicksort0<vi::iterator, std::less<int>, int>,
    quicksort1<vi::iterator, std::less<int>, int>
};

std::vector<sort_fun_rnd_dec> dec_sorts = {
    quicksort0<vi::iterator, std::greater<int>, int>,
    quicksort1<vi::iterator, std::greater<int>, int>
};

using bdata::make;

BOOST_DATA_TEST_CASE(inc_empty_size_0, make(inc_sorts), sort) {
    vi xs = {};

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);

    BOOST_TEST(xs.size() == 0);
}

BOOST_DATA_TEST_CASE(dec_empty_size_0, make(dec_sorts), sort) {
    vi xs = {};

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);

    BOOST_TEST(xs.size() == 0);
}

BOOST_DATA_TEST_CASE(inc_one_element, make(inc_sorts), sort) {
    vi xs = {42};

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);

    BOOST_TEST(xs.size() == 1);
    BOOST_TEST(xs[0] == 42);
}

BOOST_DATA_TEST_CASE(dec_one_element, make(dec_sorts), sort) {
    vi xs = {42};

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);

    BOOST_TEST(xs.size() == 1);
    BOOST_TEST(xs[0] == 42);
}

BOOST_DATA_TEST_CASE(
    inc_two_elements_0,
    make(inc_sorts) * make({41, 42}) * make({41, 42}),
    sort, a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::less<int>{});

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    dec_two_elements_0,
    make(dec_sorts) * make({41, 42}) * make({41, 42}),
    sort, a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::greater<int>{});

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    inc_two_elements_1,
    make(
        inc_sorts
    ) * make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ),
    sort, a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::less<int>{});

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    dec_two_elements_1,
    make(
        dec_sorts
    ) * make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ),
    sort, a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::greater<int>{});

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    inc_three_elements_0,
    make(
        inc_sorts
    ) * make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ) * make(
        create_vector(10, 3)
    ),
    sort, a, b, c
) {
    vi xs = {a, b, c};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::less<int>{});

    BOOST_TEST(xs.size() == 3);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    dec_three_elements_0,
    make(
        dec_sorts
    ) * make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ) * make(
        create_vector(10, 3)
    ),
    sort, a, b, c
) {
    vi xs = {a, b, c};
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::greater<int>{});

    BOOST_TEST(xs.size() == 3);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    inc_random_qsort_0,
    make(inc_sorts) * bdata::xrange(1, 256) * bdata::xrange(20),
    sort, n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::less<int>{});

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    dec_random_qsort_0,
    make(dec_sorts) * bdata::xrange(1, 256) * bdata::xrange(20),
    sort, n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::greater<int>{});

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    inc_random_qsort_stress_0,
    make(inc_sorts) * bdata::make(1e4) * bdata::xrange(10),
    sort, n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::less<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::less<int>{});

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    dec_random_qsort_stress_0,
    make(dec_sorts) * bdata::make(1e4) * bdata::xrange(10),
    sort, n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    sort(xs.begin(), xs.end(), std::greater<int>{}, 42);
    std::sort(ys.begin(), ys.end(), std::greater<int>{});

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
