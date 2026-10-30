/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:50:57 by mefische          #+#    #+#             */
/*   Updated: 2026/10/30 11:27:15 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

# include <iostream>
# include <string>
# include <exception>

class PresidentialPardonForm: public AForm {
	protected:
		const std::string _target;
	public:
		// Canonical Form
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		// Member function
		void execute(Bureaucrat const & executor);
		// Informs that <target> has been pardoned by Zaphod Beeblebrox.
};