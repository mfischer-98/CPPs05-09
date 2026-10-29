/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 15:48:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// do not understand grade too high for form
	// do not understand execution grade
	Bureaucrat gerald("Gerald", 10);
	Bureaucrat bob("Bob", 100);

	std::cout << "**FORM CREATION TESTS**" << std::endl;
	Form formA;
	Form formB("Form 1", 50, 10);

	std::cout << std::endl;
	std::cout << formA<< std::endl;
	std::cout << formB << std::endl;

	Form copy(formB);
	std::cout << copy << std::endl;

	// Only copies signed, should it copy all data?
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
	std::cout << std::endl;

	// signing grade too low
	try {
		bob.signForm(formB);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << std::endl;

	// signing grade too high?? need to use this exception
}