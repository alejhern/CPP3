/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:56:03 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 17:56:07 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default_FragTrap")
{
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
    std::cout << "FragTrap " << this->get_name() << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(string const &name) : ClapTrap(name)
{
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
    std::cout << "FragTrap " << this->get_name() << " created with name constructor." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    std::cout << "FragTrap " << this->get_name() << " created with copy constructor." << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->get_name() << " destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return (*this);
}

void FragTrap::high_fives_guys(void)
{
    std::cout << "FragTrap " << this->get_name() << " requests a high five!" << std::endl;
}
