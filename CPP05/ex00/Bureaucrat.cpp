/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:12:08 by mefische          #+#    #+#             */
/*   Updated: 2026/10/13 15:06:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade (grade) {
	//how to catch invalid numbers?
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

// Getters
std::string Bureaucrat::getName(void) const{
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

// Member Functions
void Bureaucrat::incrementGrade() {
	this->_grade -= 1;
	//if (this->_grade < 1)
		//gradetoohigh
}

void Bureaucrat::decrementGrade() {
	this->_grade += 1;
	//if (this->_grade > 150)
		//gradetoolow
}


// Operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
