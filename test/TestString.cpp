#include <gtest/gtest.h>
#include <stdext/String.h>

TEST(TestString, should_trans_string_to_int)
{
    ASSERT_EQ(5, stdext::string_as<int>("5"));
}

TEST(TestString, should_trans_string_to_char)
{
    ASSERT_EQ('5', stdext::string_as<char>("5"));
}

TEST(TestString, should_trans_string_to_float)
{
    ASSERT_NEAR(5.1, stdext::string_as<float>("5.1"), 0.01);
}

TEST(TestString, should_int_to_string)
{
    ASSERT_EQ("10", stdext::toString(10));
}

TEST(TestString, should_float_to_string)
{
    ASSERT_EQ("0.50", stdext::toString(0.5f));
}

TEST(TestString, should_double_to_string)
{
    ASSERT_EQ("0.50", stdext::toString(0.5));
}

TEST(TestString, should_bool_to_string)
{
    ASSERT_EQ("true", stdext::toString(true));
}

TEST(TestString, should_bool_varaible_to_string)
{
    auto b = false;
    ASSERT_EQ("false", stdext::toString(b));
}

TEST(TestString, should_null_to_string)
{
    ASSERT_EQ("nullptr", stdext::toString(nullptr));
}

TEST(TestString, should_ptr_to_string)
{
    ASSERT_EQ("0x00001234", stdext::toString(reinterpret_cast<void*>(0x1234)));
}

TEST(TestString, should_user_defined_to_string)
{
    struct
    {
        unsigned char a1{0xab};
        unsigned char a2{0xcd};
        unsigned char a3{0xef};
        unsigned char a4{0x00};
        unsigned char a5{0x02};

    } var;
    ASSERT_EQ("[ab cd ef 00 ...]", stdext::toString(var));
}

TEST(TestString, should_trans_string_to_upper)
{
    ASSERT_EQ("ABCD", stdext::to_upper("abcd"));
}

TEST(TestString, should_trans_string_to_lowwer)
{
    ASSERT_EQ("abcd", stdext::to_lower("AbCd"));
}

TEST(TestString, should_trim_a_string)
{
    ASSERT_EQ("abcd", stdext::trim(" \tabcd \n"));
}
