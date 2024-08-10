#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	_target("Unknown")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	(void)rhs;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs):
	AForm("PresidentialPardonForm", 25, 5),
	_target(rhs.getTarget())
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
	{
		std::cout << "The form needs to be signed before execution" << "\n";
		return;
	}
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException(executor.getGrade());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << "\n";
}

std::ostream	&operator<<(std::ostream &os, const PresidentialPardonForm &r)
{
	const std::string status = r.getIsSigned() ? "  Signed" : "Unsinged";
	return (os << r.getName() << ": " 
			<< status << ", "
			<< "SignGrade: " << r.getGradeToSign() << ", "
			<< "ExecuteGrade: " << r.getGradeToExecute()) << ", "
			<< "Target: " << r.getTarget();
}
