#include <gtest/gtest.h>
#include <stdext/Executor.h>

USING_STDEXT_NS

namespace
{
    int fib(int n)
    {
        if(n == 0) return 0;
        return n + fib(n-1);
    }

    struct Fib
    {
        Fib(int n) : n(n)
        {
        }

        int operator()() const
        {
            return fib(n);
        }

    private:
        int n;
    };
}

struct ExecutorTest : testing::Test
{
    Executor executor{2};
};


TEST_F(ExecutorTest, should_execute_normal_function)
{
    auto result = executor.execute(fib, 5);
    ASSERT_EQ(result.get(), 15);
}

TEST_F(ExecutorTest, should_execute_lambda)
{
    const int num = 5;
    auto result = executor.execute([=](){ return fib(num); });
    ASSERT_EQ(result.get(), 15);
}

TEST_F(ExecutorTest, should_execute_functor)
{
    auto result = executor.execute(Fib(5));
    ASSERT_EQ(result.get(), 15);
}

TEST_F(ExecutorTest, should_execute_muti_task_concurrently)
{
    auto result1 = executor.execute(Fib(5));
    auto result2 = executor.execute(Fib(6));

    ASSERT_EQ(result1.get(), 15);
    ASSERT_EQ(result2.get(), 21);
}
