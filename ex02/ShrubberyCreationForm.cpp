#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137),
	_target("Unknown")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(rhs.getTarget())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
	{
		std::cout << "The form needs to be signed before execution" << "\n";
		return;
	}
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException(executor.getGrade());
	std::ofstream	outfile(_target + "_shrubbery");
	if (outfile.is_open())
	{
		outfile <<
		"                                                 . " << "\n" <<
		"                                      .         ;   " << "\n" <<
		"         .              .              ;%     ;;    " << "\n" <<
		"           ,           ,                :;%  %;           " << "\n" <<
		"            :         ;                   :;%;'     .,    " << "\n" <<
		"   ,.        %;     %;            ;        %;'    ,; " << "\n" <<
		"     ;       ;%;  %%;        ,     %;    ;%;    ,%' " << "\n" <<
		"      %;       %;%;      ,  ;       %;  ;%;   ,%;'  " << "\n" <<
		"       ;%;      %;        ;%;        % ;%;  ,%;' " << "\n" <<
		"        `%;.     ;%;     %;'         `;%%;.%;' " << "\n" <<
		"         `:;%.    ;%%. %@;        %; ;@%;%' " << "\n" <<
		"            `:%;.  :;bd%;          %;@%;' " << "\n" <<
		"              `@%:.  :;%.         ;@@%;'    " << "\n" <<
		"                `@%.  `;@%.      ;@@%;          " << "\n" <<
		"                  `@%%. `@%%    ;@@%;         " << "\n" <<
		"                    ;@%. :@%%  %@@%;        " << "\n" <<
		"                      %@bd%%%bd%%:;      " << "\n" <<
		"                        #@%%%%%:;; " << "\n" <<
		"                        %@@%%%::; " << "\n" <<
		"                        %@@@%(o);  . '          " << "\n" <<
		"                        %@@@o%;:(.,'          " << "\n" <<
		"                    `.. %@@@o%::;          " << "\n" <<
		"                       `)@@@o%::;          " << "\n" <<
		"                        %@@(o)::;         " << "\n" <<
		"                       .%@@@@%::;          " << "\n" <<
		"                       ;%@@@@%::;.           " << "\n" <<
		"                      ;%@@@@%%:;;;.  " << "\n" <<
		"                  ...;%@@@@@%%:;;;;,.. " << "\n";
		std::cout << "Output a tree sucessfully" << "\n";
	}
	else
		std::cout << "failed to create file" << "\n";
}

std::ostream	&operator<<(std::ostream &os, const ShrubberyCreationForm &s)
{
	const std::string status = s.getIsSigned() ? "  Signed" : "Unsinged";
	return (os << s.getName() << ": " 
			<< status << ", "
			<< "SignGrade: " << s.getGradeToSign() << ", "
			<< "ExecuteGrade: " << s.getGradeToExecute()) << ", "
			<< "Target: " << s.getTarget();
}
