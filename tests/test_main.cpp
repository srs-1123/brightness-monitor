#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

// サンプルテストグループ
TEST_GROUP(SampleTests)
{
    void setup()
    {
        // テスト前の初期化処理
    }

    void teardown()
    {
        // テスト後のクリーンアップ処理
    }
};

// 基本的なテストケース
TEST(SampleTests, BasicTest)
{
    int expected = 42;
    int actual = 42;
    CHECK_EQUAL(expected, actual);
}

TEST(SampleTests, StringTest)
{
    const char* expected = "Hello, World!";
    const char* actual = "Hello, World!";
    STRCMP_EQUAL(expected, actual);
}

TEST(SampleTests, BooleanTest)
{
    bool condition = true;
    CHECK_TRUE(condition);
}

// メイン関数
int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
