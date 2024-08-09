#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iomanip>

class	Bureaucrat;

class	Form
{
public:
	Form();
	~Form();
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);
	Form(const std::string name, const int grade_to_sign, const int grade_to_execute);

	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(const Bureaucrat &bureaucrat);

	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		const char 		*what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(const int grade);
		const char 		*what() const throw();
	private:
		const int		_attempt_grade;
	};

private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
};

std::ostream	&operator<<(std::ostream &os, Form &f);

#endif
