#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class	PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	PresidentialPardonForm(const std::string target);

	std::string	getTarget() const;
	void		execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &s);

#endif

