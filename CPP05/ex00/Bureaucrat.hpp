/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:12:02 by mefische          #+#    #+#             */
/*   Updated: 2026/10/13 15:05:43 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade;
	public:
		// Canonical Form
		Bureaucrat(); // "Default" and 150
		Bureaucrat(const std::string &name, int grade); //highest grade = 1 and lowest = 150
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other); //only copy grade because name is const and we do not need to copy name, since that's the way to identify each bureaucrat
		~Bureaucrat();

		// Getters
		std::string getName(void) const;
		int getGrade(void) const;

		// Member Functions
		void incrementGrade(void); //decrease number
		void decrementGrade(void); //increase number

		class GradeTooHighException : std::exception {};
		class GradeTooLowException :  std::exception {};
};

// overload << operator to print: "NAME, bureaucrat grade GRADE."
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif