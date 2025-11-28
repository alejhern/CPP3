/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:33:20 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 16:33:22 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hit_points(10), _energy_points(10),
	_attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(string const &name) : _name(name), _hit_points(10),
	_energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created with name constructor." << std::endl;
}
	
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_damage << " points of damage! "
					<< " (Energy points left: " << this->_energy_points << ")" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to attack." << std::endl;
	}
}

void ClapTrap::take_damage(unsigned int amount)
{
	if (this->_hit_points <= amount)
	{
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and is now destroyed!" << std::endl;
	}
	else
	{
		this->_hit_points -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! (Hit points left: " << this->_hit_points << ")" << std::endl;
	}
}

void ClapTrap::be_repaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_hit_points += amount;
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points! (Hit points: " << this->_hit_points << ",Energy points left: " << this->_energy_points << ")" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to repair." << std::endl;
	}
}

string ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}

void ClapTrap::set_name(const string &name)
{
	this->_name = name;
}

void ClapTrap::set_hit_points(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

void ClapTrap::set_energy_points(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}
