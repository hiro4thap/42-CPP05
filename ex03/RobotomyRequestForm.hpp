#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <ctime>
# include <cstdlib>

class	RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm(const std::string target);

	std::string	getTarget() const;
	void		execute(const Bureaucrat &executor) const;

private:
	const std::string	_target;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &s);

#endif
