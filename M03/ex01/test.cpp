#include <iostream>
#include <gtest/gtest.h>
#include "ScavTrap.hpp"

// Test parametric constructor
TEST(ScavTrapTest, ParametricConstructor) {
    ::testing::internal::CaptureStdout();
    ScavTrap scavTrap("Scavy");
    EXPECT_EQ(scavTrap.getName(), "Scavy");
    EXPECT_EQ(scavTrap.getHit(), 100);
    EXPECT_EQ(scavTrap.getEnergy(), 50);
    EXPECT_EQ(scavTrap.getAttack(), 20);
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap parametric constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ScavTrap parameter constructor called\n") != std::string::npos);
}

TEST(ScavTrapTest, CopyConstructor) {
    testing::internal::CaptureStdout();
    ScavTrap original("OriginalBot");
    ScavTrap copy(original);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ScavTrap copy constructor called\n") != std::string::npos);
    EXPECT_EQ(copy.getName(), "OriginalBot");
    EXPECT_EQ(copy.getHit(), 100);
    EXPECT_EQ(copy.getEnergy(), 50);
    EXPECT_EQ(copy.getAttack(), 20);
}

TEST(ScavTrapTest, CopyAssignmentOperator) {
    ScavTrap scavTrap1("Bot1");
    ScavTrap scavTrap2("Bot2");

    testing::internal::CaptureStdout();
    scavTrap2 = scavTrap1;
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ScavTrap copy assignment operator called.") != std::string::npos);
    EXPECT_EQ(scavTrap2.getName(), "Bot1");
    EXPECT_EQ(scavTrap2.getHit(), 100);
    EXPECT_EQ(scavTrap2.getEnergy(), 50);
    EXPECT_EQ(scavTrap2.getAttack(), 20);
}

TEST(ScavTrapTest, Attack) {
    ScavTrap scavTrap("Attacker");

    testing::internal::CaptureStdout();
    scavTrap.attack("Target");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ScavTrap Attacker attacksTarget, causing 20 points of damage !") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap Attacker attacksTarget, causing 20 points of damage !") == std::string::npos);
    EXPECT_EQ(scavTrap.getEnergy(), 49);  // Energy should decrease by 1
}

TEST(ScavTrapTest, GuardGate) {
    ScavTrap scavTrap("Guardian");

    testing::internal::CaptureStdout();
    scavTrap.guardGate();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ScavTrap Guardianis now in gate keeper mode.") != std::string::npos);
}

TEST(ScavTrapTest, NoHealthAttack) {
    ScavTrap scavTrap("BrokenBot");
    scavTrap.setHit(0);

    testing::internal::CaptureStdout();
    scavTrap.attack("Target");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ScavTrap BrokenBotcan't attack! No energy or health left.") != std::string::npos);
}

TEST(ScavTrapTest, DestructorOutput) {
    testing::internal::CaptureStdout();
    {
        ScavTrap scavTrap("DestructorBot");
    }
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("ScavTrap destructor called") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap destructor called") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
