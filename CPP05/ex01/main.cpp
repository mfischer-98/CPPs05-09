/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 10:43:38 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat gerald("Gerald", 10);
	Bureaucrat bob("Bob", 100);
	std::cout << std::endl;

	std::cout << "**FORM CREATION TESTS**" << std::endl;
	Form formA;
	Form formB("Form 1", 50, 10);
	Form formC("Form 2", 5, 2);

	std::cout << std::endl;
	std::cout << formA<< std::endl;
	std::cout << formB << std::endl;


	std::cout << "**FAILED FORM CREATION TESTS**" << std::endl;
	try {
		Form formD("Fail 1", 5, 160);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		Form formE("Fail 2", 0, 50);	
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	try {
		Form formF("Fail 3", -1, 200);
	}
	catch (const std::exception& e) {
		std::cout <<e.what() <<std::endl;
	}
	std::cout << std::endl;
	

	std::cout << "**SIGNING FORM TESTS**" << std::endl;
	// signing happy path
	gerald.signForm(formB);
	std::cout << "Signed = " << formB.getSigned() << std::endl;
	std::cout << std::endl;
	
	// Error: signing twice
	bob.signForm(formB);
	std::cout << "Signed = " << formB.getSigned() << std::endl;
	std::cout << std::endl;

	// Error: grade too low
	bob.signForm(formC);
	std::cout << "Signed = " << formC.getSigned() << std::endl;
	std::cout << std::endl;

	
	std::cout << "**FORM COPY TESTS**" << std::endl;
	Form copy(formB);
	std::cout << copy << std::endl;

	// Only copies signed variable from form A:
	// The name and the grades are const, so they can’t be reassigned after construction. operator= can only copy the non-const _signed.
	copy = formA;
	std::cout << copy << std::endl;
}