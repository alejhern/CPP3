/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:49:47 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 17:49:50 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	printStatus(const ClapTrap &ct)
{
	std::cout << "[Status] " << ct.get_name() << " | HP: " << ct.get_hit_points() << " | EP: " << ct.get_energy_points() << " | AD: " << ct.get_attack_damage() << std::endl;
}

int	main(void)
{
	ClapTrap	copy;

	std::cout << "=== ClapTrap tests ===" << std::endl;
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");
	printStatus(alpha);
	printStatus(beta);
	std::cout << "\nAlpha attacks Beta:" << std::endl;
	alpha.attack(beta.get_name());
	beta.take_damage(alpha.get_attack_damage());
	printStatus(beta);
	std::cout << "\nBeta repairs itself by 5:" << std::endl;
	beta.be_repaired(5);
	printStatus(beta);
	std::cout << "\nExhaust Alpha's energy with repeated attacks:" << std::endl;
	for (int i = 0; i < 12; ++i)
		alpha.attack("a training dummy");
	printStatus(alpha);
	std::cout << "\nTesting copy/assignment:" << std::endl;
	copy = alpha;
	printStatus(copy);
	ClapTrap assigned("Temp");
	assigned = beta;
	printStatus(assigned);
	std::cout << "\n=== ScavTrap tests ===" << std::endl;
	ScavTrap guardian("Guardian");
	printStatus(guardian);
	guardian.guard_gate();
	std::cout << "\nGuardian attacks Alpha:" << std::endl;
	guardian.attack(alpha.get_name());
	alpha.take_damage(guardian.get_attack_damage());
	printStatus(alpha);
	std::cout << "\nGuardian takes heavy damage and tries to repair:" << std::endl;
	guardian.take_damage(50);
	printStatus(guardian);
	guardian.be_repaired(20);
	printStatus(guardian);
	std::cout << "\nEnd of tests." << std::endl;
	return (0);
}
