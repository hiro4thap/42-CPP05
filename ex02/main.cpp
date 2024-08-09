#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	scform_execute_test(std::string target)
{
	try
	{
		Bureaucrat	adam("Adam", 137);
		std::cout << YELLOW << adam << NONE << "\n";
		ShrubberyCreationForm	scform(target + "_Adam");
		std::cout << YELLOW << scform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(scform);
		Log::out(" -> ");
		adam.executeForm(scform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	bob("Bob", 145);
		std::cout << YELLOW << bob << NONE << "\n";
		ShrubberyCreationForm	scform(target + "_Bob");
		std::cout << YELLOW << scform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(scform);
		Log::out(" -> ");
		bob.executeForm(scform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	carter("Carter", 146);
		std::cout << YELLOW << carter << NONE << "\n";
		ShrubberyCreationForm	scform(target + "_Carter");
		std::cout << YELLOW << scform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(scform);
		Log::out(" -> ");
		carter.executeForm(scform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

void	rrform_execute_test(std::string target)
{
	try
	{
		Bureaucrat	adam("Adam", 45);
		std::cout << YELLOW << adam << NONE << "\n";
		RobotomyRequestForm	ppform(target + "_Adam");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(ppform);
		Log::out(" -> ");
		adam.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	bob("Bob", 72);
		std::cout << YELLOW << bob << NONE << "\n";
		RobotomyRequestForm	ppform(target + "_Bob");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(ppform);
		Log::out(" -> ");
		bob.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	carter("Carter", 73);
		std::cout << YELLOW << carter << NONE << "\n";
		RobotomyRequestForm	ppform(target + "_Carter");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(ppform);
		Log::out(" -> ");
		carter.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

void	ppform_execute_test(std::string target)
{
	try
	{
		Bureaucrat	adam("Adam", 5);
		std::cout << YELLOW << adam << NONE << "\n";
		PresidentialPardonForm	ppform(target + "_Adam");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		adam.signForm(ppform);
		Log::out(" -> ");
		adam.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	bob("Bob", 25);
		std::cout << YELLOW << bob << NONE << "\n";
		PresidentialPardonForm	ppform(target + "_Bob");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		bob.signForm(ppform);
		Log::out(" -> ");
		bob.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		Bureaucrat	carter("Carter", 26);
		std::cout << YELLOW << carter << NONE << "\n";
		PresidentialPardonForm	ppform(target + "_Carter");
		std::cout << YELLOW << ppform << NONE << "\n";
		Log::out(" -> ");
		carter.signForm(ppform);
		Log::out(" -> ");
		carter.executeForm(ppform);
	}
	catch (std::exception &e)
	{
		Log::out(" -> ");
		Log::nl(e.what(), RED);
	}
}

int	main()
{
	Log::nl("ShrubberyCreattionForm Execute Test", CYAN);
	{
		scform_execute_test("target");
	}
	Log::nl();
	Log::nl("RobotomyRequestForm Execute Test", CYAN);
	{
		rrform_execute_test("target");
	}
	Log::nl();
	Log::nl("PresidentialPardonForm Execute Test", CYAN);
	{
		ppform_execute_test("target");
	}
}
