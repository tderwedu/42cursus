/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:38:52 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/18 13:58:01 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define CHAR_INV_SIZE	4

class Character : public ICharacter
{
	private:
		Character();

		std::string		_name;
		int				_inv_size;
		AMateria*		_inv[CHAR_INV_SIZE];
	public:
		Character(std::string const& name);
		Character(Character const& src);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		Character const& operator=(Character const& src);
};

#endif
