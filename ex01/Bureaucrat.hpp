#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

# include "Log.hpp"
# include "Form.hpp"
# include <exception>
# include <iostream>

class	Form;

class	Bureaucrat
{
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &hrs);
	Bureaucrat(std::string name, int grade);

	const std::string	getName() const;
	int					getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form) const;

	class	GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		const char	*what() const throw();
	};
		
private:
	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);

#endif
