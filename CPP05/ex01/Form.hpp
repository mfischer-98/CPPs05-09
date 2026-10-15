/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:03:46 by mefische          #+#    #+#             */
/*   Updated: 2026/10/15 15:39:52 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

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
		bool getSigned(void) const;
		int getRequiredGrade(void) const;
		int getExecGrade(void) const;

	// Member Functions
		void beSigned(Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& out, const Form& form);


#endif