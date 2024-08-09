#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iomanip>

class	Bureaucrat;

class	AForm
{
public:
	AForm();
	~AForm();
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &rhs);
	AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);

	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor) const;

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

	class	AlreadySignedException : public std::exception
	{
	public:
		AlreadySignedException();
		const char 		*what() const throw();
	};

	class	NotSignedException : public std::exception
	{
	public:
		NotSignedException();
		const char 		*what() const throw();
	};

private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
};

std::ostream	&operator<<(std::ostream &os, AForm &f);

#endif
