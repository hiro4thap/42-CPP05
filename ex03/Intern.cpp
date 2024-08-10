#include  "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &rhs)
{
	(void)rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	form_names[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	int	index = -1;
	while (++index < 3)
	{
		if (form_names[index] == form)
			break;
	}
	switch (index)
	{
		case 0:
			std::cout << "Intern creates " << form << "\n";
			return new ShrubberyCreationForm(target);
			break;
		case 1:
			std::cout << "Intern creates " << form << "\n";
			return new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Intern creates " << form << "\n";
			return new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "The form " << form << " is unkown" << "\n";
			return NULL;
	}
}
