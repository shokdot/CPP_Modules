#include <iostream>
#include <gtest/gtest.h>
#include "ClapTrap.hpp"

// Test parametric constructor
TEST(ClapTrapTest, ParametricConstructor) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(clapTrap.getName(), "Clappy");
    EXPECT_EQ(clapTrap.getHit(), 10);
    EXPECT_EQ(clapTrap.getEnergy(), 10);
    EXPECT_EQ(clapTrap.getAttack(), 0);
    EXPECT_EQ(output, "ClapTrap parametric constructor called\n");
}

// Test copy constructor
TEST(ClapTrapTest, CopyConstructor) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap1("Clappy");
    clapTrap1.setHit(20);
    clapTrap1.setEnergy(100);
    clapTrap1.setAttack(8);
    ClapTrap clapTrap2 = clapTrap1;
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(clapTrap2.getName(), "Clappy");
    EXPECT_EQ(clapTrap2.getHit(), 20);
    EXPECT_EQ(clapTrap2.getEnergy(), 100);
    EXPECT_EQ(clapTrap2.getAttack(), 8);
    ASSERT_TRUE(output.find("ClapTrap copy constructor called\n") != std::string::npos);
}

// Test assignment operator
TEST(ClapTrapTest, AssignmentOperator) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap1("Clappy");
    ClapTrap clapTrap2("OldName");

    clapTrap2 = clapTrap1;

    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(clapTrap2.getName(), "Clappy");
    EXPECT_EQ(clapTrap2.getHit(), 10);
    EXPECT_EQ(clapTrap2.getEnergy(), 10);
    EXPECT_EQ(clapTrap2.getAttack(), 0);
    ASSERT_TRUE(output.find("ClapTrap assignment operator called\n") != std::string::npos);
}

// Test attack function
TEST(ClapTrapTest, AttackDef) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    EXPECT_EQ(clapTrap.getEnergy(), 10);

    clapTrap.attack("Enemy");
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(clapTrap.getEnergy(), 9);
    ASSERT_TRUE(output.find("ClapTrap Clappy attacks Enemy, causing 0 points of damage!\n") != std::string::npos);
}

TEST(ClapTrapTest, AttackZero) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    clapTrap.setEnergy(0);
    EXPECT_EQ(clapTrap.getEnergy(), 0);
    // Perform an attack
    clapTrap.attack("Enemy");
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy can't attack! No energy or health left.\n") != std::string::npos);
}

TEST(ClapTrapTest, AttackNegative) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    clapTrap.setEnergy(-8000);
    EXPECT_EQ(clapTrap.getEnergy(), -8000);
    // Perform an attack
    clapTrap.attack("Enemy");
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy can't attack! No energy or health left.\n") != std::string::npos);
}

TEST(ClapTrapTest, AttackHpZero) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    clapTrap.setHit(0);
    EXPECT_EQ(clapTrap.getHit(), 0);
    // Perform an attack
    clapTrap.attack("Enemy");
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy can't attack! No energy or health left.\n") != std::string::npos);
}

TEST(ClapTrapTest, AttackHpNegative) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    clapTrap.setHit(-789876876);
    EXPECT_EQ(clapTrap.getHit(), -789876876);
    // Perform an attack
    clapTrap.attack("Enemy");
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy can't attack! No energy or health left.\n") != std::string::npos);
}

// Test takeDamage function
TEST(ClapTrapTest, TakeDamage) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    // Damage before hitting zero health
    clapTrap.takeDamage(3);
    EXPECT_EQ(clapTrap.getHit(), 7);

    // Damage that brings health to zero
    clapTrap.takeDamage(7);
    EXPECT_EQ(clapTrap.getHit(), 0);
    // Attempt to take damage when health is already zero
    clapTrap.takeDamage(5);
    EXPECT_EQ(clapTrap.getHit(), 0);
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy taked 3 amount of damage!\n") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap Clappy taked 7 amount of damage!\n") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap Clappy can't damaged! No health left.\n") != std::string::npos);
}

// Test beRepaired function
TEST(ClapTrapTest, BeRepaired) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    // Repair when health and energy are available
    clapTrap.beRepaired(5);
    EXPECT_EQ(clapTrap.getHit(), 15);
    std::string output = ::testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap Clappy be repaired 5 amount of health!\n") != std::string::npos);
}

TEST(ClapTrapTest, BeRepaired2) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    // Repair when health and energy are available
    clapTrap.beRepaired(-444545245);
    EXPECT_EQ(clapTrap.getHit(), 10);
    std::string output = ::testing::internal::GetCapturedStdout();
}

TEST(ClapTrapTest, BeRepaireNegative) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    // Repair when health and energy are available
    clapTrap.beRepaired(-444545245);
    EXPECT_EQ(clapTrap.getHit(), 10);
    std::string output = ::testing::internal::GetCapturedStdout();
}

TEST(ClapTrapTest, BeRepairedEnergyZero) {
    ::testing::internal::CaptureStdout();
    ClapTrap clapTrap("Clappy");

    clapTrap.setEnergy(0);
    clapTrap.beRepaired(5);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(clapTrap.getHit(), 10);
    EXPECT_EQ(clapTrap.getEnergy(), 0);
    ASSERT_TRUE(output.find("ClapTrap Clappy can't be repaird! No energy or health left.\n") != std::string::npos);
}

// Test if the constructor and destructor are properly called
TEST(ClapTrapTest, ConstructorDestructor) {
    testing::internal::CaptureStdout();
    {
        ClapTrap clapTrap("TestTrap");
    }
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("ClapTrap parametric constructor called\n") != std::string::npos);
    ASSERT_TRUE(output.find("ClapTrap destructor called\n") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
