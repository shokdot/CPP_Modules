#include <iostream>
#include <gtest/gtest.h>
#include "FragTrap.hpp"

// Test parametric constructor
TEST(FragTrapTest, ParametricConstructor) {
    ::testing::internal::CaptureStdout();
    FragTrap fragTrap("Fragy");
    EXPECT_EQ(fragTrap.getName(), "Fragy");
    EXPECT_EQ(fragTrap.getHit(), 100);
    EXPECT_EQ(fragTrap.getEnergy(), 100);
    EXPECT_EQ(fragTrap.getAttack(), 30);
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap parametric constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("FragTrap parameter constructor called\n") != std::string::npos);
}

TEST(FragTrapTest, CopyConstructor) {
    testing::internal::CaptureStdout();
    FragTrap original("OriginalBot");
    FragTrap copy(original);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("FragTrap copy constructor called\n") != std::string::npos);
    EXPECT_EQ(copy.getName(), "OriginalBot");
    EXPECT_EQ(copy.getHit(), 100);
    EXPECT_EQ(copy.getEnergy(), 100);
    EXPECT_EQ(copy.getAttack(), 30);
}

TEST(FragTrapTest, CopyAssignmentOperator) {
    FragTrap fragTrap1("Bot1");
    FragTrap fragTrap2("Bot2");

    testing::internal::CaptureStdout();
    fragTrap2 = fragTrap1;
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("FragTrap copy assignment operator called.") != std::string::npos);
    EXPECT_EQ(fragTrap2.getName(), "Bot1");
    EXPECT_EQ(fragTrap2.getHit(), 100);
    EXPECT_EQ(fragTrap2.getEnergy(), 100);
    EXPECT_EQ(fragTrap2.getAttack(), 30);
}

TEST(FragTrapTest, highFive) {
    testing::internal::CaptureStdout();
    FragTrap fragTrap("Bot");
    fragTrap.highFivesGuys();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("FragTrap Bot high five Guys!") != std::string::npos);
}

TEST(FragTrapTest, DestructorOutput) {
    testing::internal::CaptureStdout();
    {
        FragTrap fragTrap("DestructorBot");
    }
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("FragTrap destructor called") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap destructor called") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
