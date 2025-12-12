/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:20:58 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 17:21:06 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default_ScavTrap"), _gate_keeper_mode(0)
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "ScavTrap " << this->get_name() << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(string const &name) : ClapTrap(name)
{
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "ScavTrap " << this->get_name() << " created with name constructor." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src), _gate_keeper_mode(src._gate_keeper_mode)
{
	std::cout << "ScavTrap " << this->get_name() << " created with copy constructor." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->get_name() << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->_gate_keeper_mode = rhs._gate_keeper_mode;
	}
	return (*this);
}

void ScavTrap::guard_gate(void)
{
	if (this->_gate_keeper_mode)
	{
		this->_gate_keeper_mode = 0;
		std::cout << "ScavTrap " << this->get_name() << " has exited Gate Keeper mode." << std::endl;
	}
	else if (this->get_hit_points() > 0)
	{
		this->_gate_keeper_mode = 1;
		std::cout << "ScavTrap " << this->get_name() << " is now in Gate Keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->get_name() << " has no hit points left to enter Gate Keeper mode." << std::endl;
}
