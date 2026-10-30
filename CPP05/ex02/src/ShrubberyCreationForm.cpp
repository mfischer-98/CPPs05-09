/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:18:43 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 11:39:20 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name("ShrubberyCreationForm"), _signed(false), _requiredGrade(145), _execGrade(137) {
	_target = "Not specified";
	std::cout << "Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _name("ShrubberyCreationForm"), _signed(false), _requiredGrade(145), _execGrade(137), _target(target) {
	std::cout << "Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const Form& other) : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Form assignment operator called" << std::endl;
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	std::cout << "Executed " << _name << std::endl;
}