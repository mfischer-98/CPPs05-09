/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:50 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 10:58:49 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _requiredGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int req, const int exec) : _name(name), _signed(false), _requiredGrade(req), _execGrade(exec) {
	if ((_requiredGrade < 1) || (_execGrade < 1))
		throw GradeTooHighException();
	else if ((_requiredGrade > 150) || (_execGrade > 150))
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(const Form& other) : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}


// Getters
std::string AForm::getName(void) const {
	return _name;
}

bool AForm::getSigned(void) const {
	return _signed;
}

int AForm::getRequiredGrade(void) const {
	return _requiredGrade;
}

int AForm::getExecGrade(void) const {
	return _execGrade;
}

// Member Functions
void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _requiredGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

// Overload
std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Form name: " << form.getName() << std::endl;
	out << "Signature status: " << form.getSigned() << std::endl;
	out << "Required grade to sign: " << form.getRequiredGrade() << std::endl;
	out << "Required grade to execute: " << form.getExecGrade() << std::endl;
	return out;
}
