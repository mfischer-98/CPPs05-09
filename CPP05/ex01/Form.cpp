/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:50 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 16:26:18 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _requiredGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int req, const int exec) : _name(name), _signed(false), _requiredGrade(req), _execGrade(exec) {
	if ((_requiredGrade < 1) || (_execGrade < 1))
		throw GradeTooHighException();
	else if ((_requiredGrade > 150) || (_execGrade > 150))
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}


// Getters
std::string Form::getName(void) const {
	return _name;
}

bool Form::getSigned(void) {
	return _signed;
}

int Form::getRequiredGrade(void) {
	return _requiredGrade;
}

int Form::getExecGrade(void) {
	return _execGrade;
}


// Member Functions
void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _requiredGrade)
	{
		_signed = true;
		std::cout << b << " signed " << _name << std::endl;
	}
	else
		throw GradeTooLowException();
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high for the form.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low for the form.";
}

// Overload
std::ostream& operator<<(std::ostream& out, Form& form) {
	out << "Form name: " << form.getName() << std::endl;
	out << "Signature status: " << form.getSigned() << std::endl;
	out << "Required grade to sign: " << form.getRequiredGrade() << std::endl;
	out << "Required grade to execute: " << form.getExecGrade() << std::endl;
	return out;
}
