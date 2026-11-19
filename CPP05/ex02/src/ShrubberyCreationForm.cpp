/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:18:43 by mefische          #+#    #+#             */
/*   Updated: 2026/11/19 16:01:04 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Not specified") {
	std::cout << "Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  AForm(other), _target(other._target) {
	std::cout << "Form copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Form assignment operator called" << std::endl;
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Form " << getName() << " destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string name = _target + "_shrubbery";
	const char *p = name.c_str();
	//ofstream takes a pointer to first character of string, later versions of c++ take strings
	std::ofstream file(p);

	file << "        *\n";
	file << "       /|\\\n";
	file << "      /*|O\\\n";
	file << "     /*/|\\*\\\n";
	file << "    /O/*|*\\O\\\n";
	file << "   /*/O/|\\*\\*\\\n";
	file << "        |||\n";
	file << "        |||\n";

	file << "     ^\n";
	file << "    /^\\\n";
	file << "   /^^^\\\n";
	file << "  /^^^^^\\\n";
	file << " /^^^^^^^\\\n";
	file << "    |||\n";
	file << "    |||\n";

	file.close();
}