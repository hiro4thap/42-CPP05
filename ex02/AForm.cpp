#include "AForm.hpp"

AForm::AForm():
	_name("Unknown"),
	_is_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &rhs):
	_name(rhs.getName()),
	_is_signed(rhs.getIsSigned()),
	_grade_to_sign(rhs.getGradeToSign()),
	_grade_to_execute(rhs.getGradeToExecute())
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	else if (150 < _grade_to_sign)
		throw GradeTooLowException(_grade_to_sign);
	else if (150 <_grade_to_execute)
		throw GradeTooLowException(_grade_to_execute);
}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_is_signed = rhs.getIsSigned();
	return *this;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute):
	_name(name),
	_is_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	else if (150 < _grade_to_sign)
		throw GradeTooLowException(_grade_to_sign);
	else if (150 <_grade_to_execute)
		throw GradeTooLowException(_grade_to_execute);
}

const std::string	&AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _is_signed;
}

int		AForm::getGradeToSign() const
{
	return _grade_to_sign;
}

int		AForm::getGradeToExecute() const
{
	return _grade_to_execute;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
	{
		throw AForm::AlreadySignedException();
	}
	else if (_grade_to_sign < bureaucrat.getGrade())
	{
		throw AForm::GradeTooLowException(bureaucrat.getGrade());
	}
	_is_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
}

AForm::GradeTooHighException::GradeTooHighException()
{
}

const char 		*AForm::GradeTooHighException::what() const throw()
{
	return "Grade cannot be greater than 1";
}

AForm::GradeTooLowException::GradeTooLowException(const int grade)
	:_attempt_grade(grade)
{
}

const char 		*AForm::GradeTooLowException::what() const throw()
{
	if (150 < _attempt_grade)
		return "Grade cannot be less than 150";
	else
		return "Grade is too low to operate form";
}

AForm::AlreadySignedException::AlreadySignedException()
{
}

const char 		*AForm::AlreadySignedException::what() const throw()
{
	return "The form is alredy signed";
}

AForm::NotSignedException::NotSignedException()
{
}

const char 		*AForm::NotSignedException::what() const throw()
{
	return "The form is not signed";
}

std::ostream	&operator<<(std::ostream &os, AForm &f)
{
	const std::string status = f.getIsSigned() ? "  Signed" : "Unsinged";
	return (os << f.getName() << ": " 
			<< status << ", "
			<< "SignGrade: " << f.getGradeToSign() << ", "
			<< "ExecuteGrade: " << f.getGradeToExecute());
}
