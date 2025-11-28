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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void	print_status(const ClapTrap &ct)
{
	std::cout << "[Status] " << ct.get_name() << " | HP: " << ct.get_hit_points() << " | EP: " << ct.get_energy_points() << " | AD: " << ct.get_attack_damage() << std::endl;
}

int	main(void)
{
	ClapTrap	copy;

	std::cout << "=== Setup ===" << std::endl;
	ClapTrap alpha("Alpha");
	ScavTrap guardian("Guardian");
	FragTrap phoenix("Phoenix");
	print_status(alpha);
	print_status(guardian);
	print_status(phoenix);
	std::cout << "\n=== Basic interactions ===" << std::endl;
	alpha.attack(guardian.get_name());
	guardian.take_damage(alpha.get_attack_damage());
	print_status(guardian);
	guardian.guard_gate();
	std::cout << "\nGuardian retaliates against Phoenix:" << std::endl;
	guardian.attack(phoenix.get_name());
	phoenix.take_damage(guardian.get_attack_damage());
	print_status(phoenix);
	std::cout << "\nPhoenix repairs and uses special ability:" << std::endl;
	phoenix.be_repaired(15);
	print_status(phoenix);
	std::cout << "\nPhoenix asks for high fives:" << std::endl;
	phoenix.high_fives_guys();
	std::cout << "\n=== Energy exhaustion test ===" << std::endl;
	for (int i = 0; i < 12; ++i)
		alpha.attack("a training dummy");
	print_status(alpha);
	std::cout << "\n=== Copy / Assignment ===" << std::endl;
	copy = alpha;
	print_status(copy);
	ScavTrap assigned_scav("TempScav");
	assigned_scav = guardian;
	print_status(assigned_scav);
	FragTrap assigned_frag("TempFrag");
	assigned_frag = phoenix;
	print_status(assigned_frag);
	std::cout << "\nEnd of tests." << std::endl;
	return (0);
}
