/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:50 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 15:46:09 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _requiredGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int req, const int exec) : _name(name), _signed(false), _requiredGrade(req), _execGrade(exec) {
	if (_requiredGrade || _execGrade < 1)
		throw GradeTooHighException();
	else if (_requiredGrade || _execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
		this->_requiredGrade = other._requiredGrade;
		this->_execGrade = other._execGrade;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}


// Getters
const std::string Form::getName(void) {
	return _name;
}

const bool Form::getSigned(void) {
	return _signed;
}

const int Form::getRequiredGrade(void) {
	return _requiredGrade;
}

cont int Form::getExecGrade(void) {
	return _execGrade;
}


// Member Functions
void	Form::beSigned(Bureaucrat& b) {
	if (b->_grade <= _requiredGrade)
	{
		_signed = true;
		std::cout << b << " signed " << _name;
	}
	else
		std::cout << b << " couldn’t sign " << _name << " because grade is too low" << std::endl;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high for the form.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low for the form.";
}

// Overload
std::ostream& operator<<(std::ostream& out, const Form& form) {
	std::cout << "Form name: " << _name << std::endl;
	std::cout << "Signature status: " << _signed << std::endl;
	std::cout << "Required grade to sign: " << _name << std::endl;
	std::cout << "Required grade to execute: " << _name << std::endl;
	return out;
}
