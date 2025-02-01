#include <gtest/gtest.h>
#include "DiamondTrap.hpp"

TEST(DiamondTrapTest, ConstructorTest) {
    testing::internal::CaptureStdout();
    DiamondTrap dt("TestDiamond");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap parametric constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ScavTrap parameter constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("FragTrap parameter constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("DiamondTrap parametric constructor called\n") != std::string::npos);
}

TEST(DiamondTrapTest, WhoAmITest) {
    testing::internal::CaptureStdout();
    DiamondTrap dt("WhoAmIDiamond");
    dt.whoAmI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("WhoAmIDiamond"), std::string::npos);
    EXPECT_NE(output.find("WhoAmIDiamond_clap_name"), std::string::npos);
}

TEST(DiamondTrapTest, AttackTest) {
    DiamondTrap dt("AttackerDiamond");
    testing::internal::CaptureStdout();
    dt.attack("Target");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("AttackerDiamond"), std::string::npos);
    EXPECT_NE(output.find("Target"), std::string::npos);
}

TEST(DiamondTrapTest, DestructorTest) {
    testing::internal::CaptureStdout();
    {
        DiamondTrap dt("DestructorDiamond");
    }
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ClapTrap parametric constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ScavTrap parameter constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("FragTrap parameter constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("DiamondTrap parametric constructor called\n") != std::string::npos);

    ASSERT_TRUE(output.find("DiamondTrap destructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ScavTrap destructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("FragTrap destructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap destructor called\n") != std::string::npos);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
