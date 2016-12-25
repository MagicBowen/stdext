#include <gtest/gtest.h>
#include <stdext/Range.h>

TEST(TestRange, should_all_of_range_satisfied_when_lvalue)
{
    std::vector<int> container = {2, 3, 4};
    ASSERT_TRUE(stdext::all_of(container, [](auto v){return v > 1;}));
}

TEST(TestRange, should_all_of_range_satisfied_when_rvalue)
{
    ASSERT_TRUE(stdext::all_of(std::vector<int>{2, 3, 4}, [](auto v){return v > 1;}));
}

TEST(TestRange, should_any_of_range_satisfied_when_rvalue)
{
    ASSERT_TRUE(stdext::any_of(std::vector<int>{2, 3, 4}, [](auto v){return v > 3;}));
}

TEST(TestRange, should_find_by_pred)
{
    ASSERT_EQ(4, *stdext::find_if(std::vector<int>{2, 3, 4}, [](auto v){return v > 3;}));
}

TEST(TestRange, should_find_equal)
{
    int a[] = {2, 3, 4};
    ASSERT_EQ(a + 2, stdext::find(a, 4));
}

TEST(TestRange, should_operate_ech_by_unary_function)
{
    std::vector<int> container = {2, 3, 4};
    stdext::each(container, [](auto& v){v++;});
    ASSERT_EQ((std::vector<int>{3, 4, 5}), container);
}

TEST(TestRange, should_filter_the_satisfied_elements)
{
    std::vector<int> result(3, 0xff);
    stdext::filter(std::vector<int>{1, 2, 3}, result.begin(), [](auto v){return v > 1;});
    ASSERT_EQ((std::vector<int>{0xff, 2, 3}), result);
}

TEST(TestRange, should_map_all_elemes_by_funtion)
{
    std::vector<int> result(3, 0xff);
    stdext::map(std::vector<int>{1, 2, 3}, result.begin(), [](auto v){return v * v;});
    ASSERT_EQ((std::vector<int>{1, 4, 9}), result);
}

TEST(TestRange, should_reduce_a_container)
{
    ASSERT_EQ(6, stdext::reduce(std::vector<int>{1, 2, 3}, 1, [](auto& acc, auto v){acc *= v;}));
}

