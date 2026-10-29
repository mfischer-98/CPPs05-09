/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 15:05:07 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	/* Functionality tests */
	std::cout << " - Test 0 - " << std::endl;
	Bureaucrat testA("Test A", 3);
	Bureaucrat testB("Test B", 4);

	Bureaucrat copy(testA);
	testB = copy;
	
	std::cout << std::endl;
	std::cout << testA << std::endl;
	std::cout << copy << std::endl;
	std::cout << testB << std::endl;
	std::cout << std::endl;

	/* Test happy path: creating default, creating with assignment, incrementing, decrementing */
	std::cout << " - Test 1 - " << std::endl;
	Bureaucrat a;
	Bureaucrat b("Robert", 5);
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	a.incrementGrade();
	b.decrementGrade();

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	/* Test wrong path 1: creating with invalid grades 
		- When creating an object with invalid number, 
			throw is called and the object is never completed, so no destructor called either
		- exception&, & because it refers to the object related to what
		- e is just a convention, it could be another name
		- const because what is a const member function */
	std::cout << " - Test 2 -" << std::endl;
	try {
		Bureaucrat c("Gerald", 200);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat d("Anthony", -10);
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << std::endl;


	/* Test wrong path 2: decrementing and incrementing limits 1 and 150 */
	std::cout << " - Test 3 -" << std::endl;
	Bureaucrat e("Patrick", 1);
	Bureaucrat f("Bob", 150);

	try {
		e.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << e << std::endl;

	try {
		f.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << f << std::endl;


}