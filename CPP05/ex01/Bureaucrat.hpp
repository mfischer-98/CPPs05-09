/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:12:02 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 15:39:35 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

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
		//only copy grade because name is const and we do not need to copy name, since that's the way to identify each bureaucrat
		~Bureaucrat();

		// Getters
		std::string getName(void) const;
		int getGrade(void) const;

		// Member Functions
		void incrementGrade(void); //decrease number
		void decrementGrade(void); //increase number
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