#include "Form.hpp"

Form::Form():
	_name("Unknown"),
	_is_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1)
{
}

Form::~Form()
{
}

Form::Form(const Form &rhs):
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

Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_is_signed = rhs.getIsSigned();
	return *this;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute):
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

const std::string	&Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _is_signed;
}

int		Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int		Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
	{
		throw Form::AlreadySignedException();
	}
	else if (_grade_to_sign < bureaucrat.getGrade())
	{
		throw Form::GradeTooLowException(bureaucrat.getGrade());
	}
	_is_signed = true;
}

Form::GradeTooHighException::GradeTooHighException()
{
}

const char 		*Form::GradeTooHighException::what() const throw()
{
	return "Grade cannot be greater than 1";
}

Form::GradeTooLowException::GradeTooLowException(const int grade)
	:_attempt_grade(grade)
{
}

const char 		*Form::GradeTooLowException::what() const throw()
{
	if (150 < _attempt_grade)
		return "Grade cannot be less than 150";
	else
		return "Grade is too low to sign this form";
}

Form::AlreadySignedException::AlreadySignedException()
{
}

const char 		*Form::AlreadySignedException::what() const throw()
{
	return "The form is alredy signed";
}

std::ostream	&operator<<(std::ostream &os, Form &f)
{
	const std::string status = f.getIsSigned() ? "  Signed" : "Unsinged";
	return (os << f.getName() << ": " 
			<< status << ", "
			<< "SignGrade: " << f.getGradeToSign() << ", "
			<< "ExecuteGrade: " << f.getGradeToExecute());
}
