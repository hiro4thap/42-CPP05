#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>

class	ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm(const std::string target);

	std::string	getTarget() const;
	void		execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &s);

#endif
