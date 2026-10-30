/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:46 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 11:26:40 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _requiredGrade;
		const int _execGrade;
	public:
	// Canonical AForm
		AForm();
		AForm(const std::string &name, const int req, const int exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

	// Getters
		std::string getName(void) const;
		bool getSigned(void) const;
		int getRequiredGrade(void) const;
		int getExecGrade(void) const;

	// Member Functions
		void beSigned(const Bureaucrat& b);
		//create function to check if it was signed and grade (new exception?)
		virtual void execute(Bureaucrat const & executor) const = 0;

	// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException :  public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif