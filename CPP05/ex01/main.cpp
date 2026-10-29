/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/10/29 12:02:25 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// do not understand grade too high for form, not implemented
	// do not understand execution grade
	Bureaucrat gerald("Gerald", 10);
	Bureaucrat bob("Bob", 100);
	std::cout << std::endl;

	std::cout << "**FORM CREATION TESTS**" << std::endl;
	Form formA;
	Form formB("Form 1", 50, 10);

	std::cout << std::endl;
	std::cout << formA<< std::endl;
	std::cout << formB << std::endl;

	Form copy(formB);
	std::cout << copy << std::endl;

	// Only copies signed variable
	copy = formA;
	std::cout << copy << std::endl;

	std::cout << "**SIGNING FORM TESTS**" << std::endl;
	// signing happy path
	try {
		gerald.signForm(formB);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << "Signed = " << formB.getSigned() << std::endl;
	std::cout << std::endl;
	
	// Error: signing twice
	try {
		bob.signForm(formB);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << "Signed = " << formB.getSigned() << std::endl;
	std::cout << std::endl;

	// Error: grade too low to sign
	Form formC("Form 2", 5, 2);
	try {
		bob.signForm(formC);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << "Signed = " << formC.getSigned() << std::endl;
	std::cout << std::endl;

	// signing grade too high?? need to use this exception 
	// FIX besigned with grade too high exception
	// should i be using the exceptions the way im using?
}