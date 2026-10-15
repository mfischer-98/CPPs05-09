/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:46 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 16:24:40 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _requiredGrade;
		const int _execGrade;
	public:
	// Canonical Form
		Form();
		Form(const std::string &name, const int req, const int exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

	// Getters
		std::string getName(void) const;
		bool getSigned(void);
		int getRequiredGrade(void);
		int getExecGrade(void);

	// Member Functions
		void beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& out, Form& form);


#endif