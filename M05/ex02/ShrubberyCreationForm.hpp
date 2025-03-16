#pragma once
#include "AForm.hpp"
#include <fstream>

#define apricot_tree                    \
	"          	  &&&& \n"              \
	"          &&& &&  & &&\n"          \
	"      && &\\/&\\|& ()|/ @, &&\n"   \
	"      &\\/(/&/&||/& /_/)_&/_&\n"   \
	"   &() &\\/&|()|/&\\/ '%\" & ()\n" \
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n" \
	"&&   && & &| &| /& & % ()& /&&\n"  \
	" ()&_---()&\\&\\|&&-&&--%---()~\n" \
	"     &&     \\|||\n"               \
	"             |||\n"                \
	"             |||\n"                \
	"             |||\n"                \
	"       , -=-~  .-^- _\n"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};
