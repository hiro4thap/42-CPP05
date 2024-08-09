#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45),
	_target("Unknown")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs):
	AForm("RobotomyRequestForm", 72, 45),
	_target(rhs.getTarget())
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
	{
		std::cout << "The form needs to be signed before execution" << "\n";
		return;
	}
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException(executor.getGrade());

	std::srand(std::time(nullptr));
	std::cout << "BRRRRRR.... ";
	bool	is_success = rand() % 2;
	if (is_success)
		std::cout << _target << " has been robotomized!!" << "\n";
	else
		std::cout << _target << "'s oepration failed..." << "\n";
}

std::ostream	&operator<<(std::ostream &os, const RobotomyRequestForm &r)
{
	const std::string status = r.getIsSigned() ? "  Signed" : "Unsinged";
	return (os << r.getName() << ": " 
			<< status << ", "
			<< "SignGrade: " << r.getGradeToSign() << ", "
			<< "ExecuteGrade: " << r.getGradeToExecute()) << ", "
			<< "Target: " << r.getTarget();
}
