#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs):
	_name(rhs.getName()),_grade(rhs.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),_grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (150 < _grade)
		throw (GradeTooLowException());
}

const std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	if (form.getIsSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because the form is already signed" << "\n";
		return ;
	}
	else if (form.getGradeToSign() < _grade)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because the grade is too low" << "\n";
		return ;
	}
	form.beSigned(*this);
	std::cout << _name << " signed " << form.getName() << "\n";
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade cannot be greater than 1");
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade cannot be less than 150");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}
