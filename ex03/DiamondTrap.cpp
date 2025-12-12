/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:36:46 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 18:36:50 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
    this->ClapTrap::set_hit_points(FragTrap::get_hit_points());
    this->ClapTrap::set_energy_points(ScavTrap::get_energy_points());
    this->ClapTrap::set_attack_damage(FragTrap::get_attack_damage());
    std::cout << "DiamondTrap " << this->ClapTrap::get_name() << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(string const &name) : ScavTrap(name), FragTrap(name)
{
    this->ClapTrap::set_name(name + "_clap_name");
    this->_name = name;
    this->ClapTrap::set_hit_points(FragTrap::get_hit_points());
    this->ClapTrap::set_energy_points(ScavTrap::get_energy_points());
    this->ClapTrap::set_attack_damage(FragTrap::get_attack_damage());
    std::cout << "DiamondTrap " << this->ClapTrap::get_name() << " created with name constructor." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    this->_name = src._name;
    std::cout << "DiamondTrap " << this->ClapTrap::get_name() << " created with copy constructor." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->ClapTrap::get_name() << " destroyed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    if (this != &rhs)
    {
        ScavTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        this->_name = rhs._name;
    }
    return (*this);
}

void DiamondTrap::who_am_i(void)
{
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << this->ClapTrap::get_name() << std::endl;
}
