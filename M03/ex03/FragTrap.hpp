#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &rhs);
	virtual ~FragTrap();

	void highFivesGuys(void);
};
