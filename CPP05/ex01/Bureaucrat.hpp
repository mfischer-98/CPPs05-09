/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:12:02 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 16:19:34 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade;
	public:
		// Canonical Form
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other); 
		~Bureaucrat();

		// Getters
		std::string getName(void) const;
		int getGrade(void) const;

		// Member Functions
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException :  public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif