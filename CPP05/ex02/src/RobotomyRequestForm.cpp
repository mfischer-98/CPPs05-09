/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:18:41 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 11:39:14 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _name("RobotomyRequestForm"), _signed(false), _requiredGrade(72), _execGrade(45) {
	_target = "Not specified";
	std::cout << "Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _name("RobotomyRequestForm"), _signed(false), _requiredGrade(72), _execGrade(45), _target(target) {
	std::cout << "Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const Form& other) : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Form assignment operator called" << std::endl;
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
	std::cout << "Executed " << _name << std::endl;
}