/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:17:32 by mefische          #+#    #+#             */
/*   Updated: 2026/11/19 17:02:53 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"
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
	Intern		rory;
	std::cout << std::endl;

	std::cout << "**INTERN CREATES VALID FORMS**" << std::endl;
	AForm	*shrub = rory.makeForm("shrubbery creation", "stars_hollow");
	AForm	*robo = rory.makeForm("robotomy request", "Paris");
	AForm	*pardon = rory.makeForm("presidential pardon", "Lorelai");
	std::cout << std::endl;

	std::cout << "**FORM INFO**" << std::endl;
	if (shrub)
		std::cout << *shrub << std::endl;
	if (robo)
		std::cout << *robo << std::endl;
	if (pardon)
		std::cout << *pardon << std::endl;
	std::cout << std::endl;

	std::cout << "**SIGN & EXECUTE**" << std::endl;
	if (shrub) {
		kirk.signForm(*shrub);      // 100 <= 145, ok
		kirk.executeForm(*shrub);   // 100 <= 137, creates stars_hollow_shrubbery
	}
	if (robo) {
		luke.signForm(*robo);       // 10 <= 72, ok
		richard.executeForm(*robo); // 1 <= 45, ok
	}
	if (pardon) {
		richard.signForm(*pardon);  // 1 <= 25, ok
		richard.executeForm(*pardon); // 1 <= 5, ok
	}
	std::cout << std::endl;

	std::cout << "**INVALID FORM NAMES (should fail)**" << std::endl;
	AForm	*invalid = rory.makeForm("coffee order", "Luke");
	AForm	*empty = rory.makeForm("", "Taylor");
	std::cout << "invalid ptr: " << invalid << std::endl;
	std::cout << "empty ptr:   " << empty << std::endl;
	std::cout << std::endl;

	std::cout << "**INTERN COPY TESTS**" << std::endl;
	Intern	copy(rory);
	Intern	assigned;
	assigned = rory;

	AForm	*extra = assigned.makeForm("presidential pardon", "Jess");
	if (extra) {
		richard.signForm(*extra);
		richard.executeForm(*extra);
	}
	std::cout << std::endl;

	// Cleanup
	delete shrub;
	delete robo;
	delete pardon;
	delete invalid;
	delete empty;
	delete extra;

	return 0;
}