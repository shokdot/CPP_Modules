#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();

	void highFivesGuys(void);
};
