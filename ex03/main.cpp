#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	scform_execute_test(std::string target)
{
	Intern intern;

	Log::setColor(PURPLE);
	AForm *scform = intern.makeForm("ShrubberyCreationForm", target);
	Bureaucrat	adam("Adam", 137);
	std::cout << YELLOW << adam << NONE << "\n";
	try
	{
		std::cout << YELLOW << *scform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(*scform);
		Log::out(" -> ");
		adam.executeForm(*scform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	delete scform;

	Log::setColor(PURPLE);
	scform = intern.makeForm("ShrubberyCreationForm", target);
	Bureaucrat	bob("Bob", 145);
	std::cout << YELLOW << bob << NONE << "\n";
	try
	{
		std::cout << YELLOW << *scform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(*scform);
		Log::out(" -> ");
		bob.executeForm(*scform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	delete scform;

	Log::setColor(PURPLE);
	scform = intern.makeForm("ShrubberyCreationForm", target);
	Bureaucrat	carter("Carter", 146);
	std::cout << YELLOW << carter << NONE << "\n";
	try
	{
		std::cout << YELLOW << *scform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(*scform);
		Log::out(" -> ");
		carter.executeForm(*scform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

void	rrform_execute_test(std::string target)
{
	Intern intern;

	Log::setColor(PURPLE);
	AForm *rrform = intern.makeForm("RobotomyRequestForm", target);
	Bureaucrat	adam("Adam", 45);
	std::cout << YELLOW << adam << NONE << "\n";
	try
	{
		std::cout << YELLOW << *rrform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(*rrform);
		Log::out(" -> ");
		adam.executeForm(*rrform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::setColor(PURPLE);
	rrform = intern.makeForm("RobotomyRequestForm", target);
	Bureaucrat	bob("Bob", 72);
	std::cout << YELLOW << bob << NONE << "\n";
	try
	{
		std::cout << YELLOW << *rrform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(*rrform);
		Log::out(" -> ");
		bob.executeForm(*rrform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::setColor(PURPLE);
	rrform = intern.makeForm("RobotomyRequestForm", target);
	Bureaucrat	carter("Carter", 73);
	std::cout << YELLOW << carter << NONE << "\n";
	try
	{
		std::cout << YELLOW << *rrform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(*rrform);
		Log::out(" -> ");
		carter.executeForm(*rrform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

void	ppform_execute_test(std::string target)
{
	Intern intern;

	Log::setColor(PURPLE);
	AForm *ppform = intern.makeForm("PresidentialPardonForm", target);
	Bureaucrat	adam("Adam", 5);
	std::cout << YELLOW << adam << NONE << "\n";
	try
	{
		std::cout << YELLOW << *ppform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(*ppform);
		Log::out(" -> ");
		adam.executeForm(*ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::setColor(PURPLE);
	ppform = intern.makeForm("PresidentialPardonForm", target);
	Bureaucrat	bob("Bob", 25);
	std::cout << YELLOW << bob << NONE << "\n";
	try
	{
		std::cout << YELLOW << *ppform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(*ppform);
		Log::out(" -> ");
		bob.executeForm(*ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::setColor(PURPLE);
	ppform = intern.makeForm("PresidentialPardonForm", target);
	Bureaucrat	carter("Carter", 26);
	std::cout << YELLOW << carter << NONE << "\n";
	try
	{
		std::cout << YELLOW << *ppform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(*ppform);
		Log::out(" -> ");
		carter.executeForm(*ppform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

int	main()
{
	Log::nl("ShrubberyCreattionForm Create -> Execute Test", CYAN);
	{
		scform_execute_test("target");
	}
	Log::nl();
	Log::nl("RobotomyRequestForm Create -> Execute Test", CYAN);
	{
		rrform_execute_test("target");
	}
	Log::nl();
	Log::nl("PresidentialPardonForm Create -> Execute Test", CYAN);
	{
		ppform_execute_test("target");
	}
}
