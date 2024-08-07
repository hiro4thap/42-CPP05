#include "Log.hpp"
#include "Bureaucrat.hpp"

void	construct_test(std::string name, int grade)
{
	Log::out("Bureaucrat(", YELLOW);
	Log::out(name, YELLOW);
	Log::out(", ", YELLOW);
	Log::out(grade, YELLOW);
	Log::nl(")", YELLOW);
	Log::out(" -> ", NONE);
	try
	{
		Bureaucrat	bureaucrat(name, grade);
		std::cout << bureaucrat << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}

void	increment_test(std::string name, int grade)
{
	Bureaucrat	bureaucrat(name, grade);
	try
	{
		std::cout << YELLOW << bureaucrat << NONE <<"\n";
		Log::out(" -> ", NONE);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}

void	decrement_test(std::string name, int grade)
{
	Bureaucrat	bureaucrat(name, grade);
	try
	{
		std::cout << YELLOW << bureaucrat << NONE <<"\n";
		Log::out(" -> ", NONE);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}

int	main()
{
	Log::nl("Bureaucrat Constructor Test", CYAN);
	{
		construct_test("Adam", 0);
		construct_test("Bob", 1);
		construct_test("Cindy", 150);
		construct_test("Dan", 151);
	}
	Log::nl();
	Log::nl("Bureaucrat Increment Test", CYAN);
	{
		increment_test("Elon", 1);
		increment_test("Foo", 150);
	}
	Log::nl();
	Log::nl("Bureaucrat Decrement Test", CYAN);
	{
		decrement_test("George", 1);
		decrement_test("Heren", 150);
	}
}
