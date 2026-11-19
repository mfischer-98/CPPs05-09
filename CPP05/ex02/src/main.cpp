/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/11/19 16:08:03 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));

	Bureaucrat	richard("Richard", 1);
	Bureaucrat	luke("Luke", 10);
	Bureaucrat	kirk("Kirk", 100);
	std::cout << std::endl;

	ShrubberyCreationForm	shrub("stars_hollow");
	RobotomyRequestForm		robo("Paris");
	PresidentialPardonForm	pardon("Lorelai");
	std::cout << std::endl;

	std::cout << "**FORM INFO**" << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robo << std::endl;
	std::cout << pardon << std::endl;
	std::cout << std::endl;

	std::cout << "**EXECUTE UNSIGNED FORM (should fail)**" << std::endl;
	richard.executeForm(shrub);
	std::cout << std::endl;

	std::cout << "**SIGNING TESTS**" << std::endl;
	// Happy path
	kirk.signForm(shrub);      // 100 <= 145, ok
	luke.signForm(robo);       // 10 <= 72, ok
	richard.signForm(pardon);  // 1 <= 25, ok
	// Error: signing twice
	kirk.signForm(robo);       // already signed by Luke
	// Error: grade too low to sign
	RobotomyRequestForm freshRobo("Taylor");
	kirk.signForm(freshRobo);  // 100 > 72
	std::cout << std::endl;

	std::cout << "**EXECUTE: GRADE TOO LOW (should fail)**" << std::endl;
	luke.executeForm(pardon);  // 10 > 5
	kirk.executeForm(robo);    // 100 > 45
	std::cout << std::endl;

	std::cout << "**EXECUTE: SUCCESS**" << std::endl;
	kirk.executeForm(shrub);      // 100 <= 137, creates stars_hollow_shrubbery
	richard.executeForm(pardon);  // 1 <= 5
	std::cout << std::endl;

	std::cout << "**ROBOTOMY x6 (~50/50)**" << std::endl;
	for (int i = 0; i < 6; i++)
		richard.executeForm(robo);
	std::cout << std::endl;

	std::cout << "**DIRECT execute() WITH EXCEPTION**" << std::endl;
	try {
		pardon.execute(luke);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "**FORM COPY TESTS**" << std::endl;
	ShrubberyCreationForm copy(shrub);
	std::cout << copy << std::endl;

	ShrubberyCreationForm other("dragonfly_inn");
	copy = other;  // only non-const members can be copied
	std::cout << copy << std::endl;
	std::cout << std::endl;

	return 0;
}