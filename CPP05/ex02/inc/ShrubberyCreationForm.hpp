/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:49:16 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 11:27:22 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

# include <iostream>
# include <string>
# include <exception>

class ShrubberyCreationForm: public AForm {
	protected:
		const std::string _target;
	public:
		// Canonical Form
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		// Member function
		void execute(Bureaucrat const & executor);
		// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
};