/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:11:19 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 18:11:22 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        string _name;
	public:
		DiamondTrap();
		DiamondTrap(const string &name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &rhs);
		void who_am_i(void);
};

#endif