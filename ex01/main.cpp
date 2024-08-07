#include "Bureaucrat.hpp"
#include "Form.hpp"

void	form_construct_test(std::string name, const int grade_to_sign, const int grade_to_execute)
{
	Log::out("Form(", YELLOW);
	Log::out(name, YELLOW);
	Log::out(", ", YELLOW);
	Log::out(grade_to_sign, YELLOW);
	Log::out(", ", YELLOW);
	Log::out(grade_to_execute, YELLOW);
	Log::nl(")", YELLOW);
	Log::out(" -> ");
	try
	{
		Form	form(name, grade_to_sign, grade_to_execute);
		std::cout << form << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}

void	form_signed_test(const Bureaucrat &b, std::string name, const int grade_to_sign, const int grade_to_execute)
{
	Form form(name, grade_to_sign, grade_to_execute);
	try
	{
		std::cout << YELLOW << form << NONE << "\n";
		Log::out(" -> ", NONE);
		form.beSigned(b);
		std::cout << form << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}
	
void	bureaucrat_sign_test(Form &f, std::string name, const int grade)
{
	const Bureaucrat bureaucrat(name, grade);
	try
	{
		std::cout << YELLOW << bureaucrat << NONE << "\n";
		Log::out(" -> ", NONE);
		bureaucrat.signForm(f);
		Log::out(" -> ", NONE);
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
}

int	main()
{
	Log::nl("Form Constructor Test", CYAN);
	{
		form_construct_test("A", 1, 1);
		form_construct_test("B", 150, 150);
		form_construct_test("C", 0, 10);
		form_construct_test("D", 151, 10);
		form_construct_test("E", 10, 0);
		form_construct_test("F", 10, 151);
	}
	Log::nl();
	Log::nl("Form Signed Test", CYAN);
	Bureaucrat bureaucrat("Bure", 10);
	std::cout << CYAN << "* " << bureaucrat << "\n";
	{
		form_signed_test(bureaucrat, "G", 9 , 9);
		form_signed_test(bureaucrat, "H", 9 , 10);
		form_signed_test(bureaucrat, "I", 10, 9);
	}
	Log::nl();
	Log::nl("Bureaucrat Sign Test", CYAN);
	Form form("Sample-Form", 10, 20);
	std::cout << CYAN << "* " << form << "\n";
	{
		bureaucrat_sign_test(form, "Jason", 11);
		bureaucrat_sign_test(form, "Kate", 10);
		bureaucrat_sign_test(form, "Linda", 10);
	}
}
