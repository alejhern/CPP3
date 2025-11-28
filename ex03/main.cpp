/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto-generated                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:00:00 by GitHub Copilot    #+#    #+#             */
/*   Updated: 2025/11/28 00:00:00 by GitHub Copilot   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void print_status(const ClapTrap &ct)
{
    std::cout << "[Status] " << ct.get_name()
              << " | HP: " << ct.get_hit_points()
              << " | EP: " << ct.get_energy_points()
              << " | AD: " << ct.get_attack_damage()
              << std::endl;
}

int main()
{
    std::cout << "=== DiamondTrap quick test ===" << std::endl;

    DiamondTrap d1("Diamondo");
    print_status(d1);

    std::cout << "\n-- Identity --" << std::endl;
    d1.who_am_i();

    std::cout << "\n-- Basic actions --" << std::endl;
    d1.attack("Training Dummy");
    d1.take_damage(15);
    print_status(d1);

    d1.be_repaired(10);
    print_status(d1);

    std::cout << "\n-- Inherited abilities --" << std::endl;
    d1.high_fives_guys(); // from FragTrap
    d1.guard_gate();      // from ScavTrap

    std::cout << "\n-- Drain energy by attacking --" << std::endl;
    for (int i = 0; i < 12; ++i)
        d1.attack("Exhaustion Target");
    print_status(d1);

    std::cout << "\n-- Big damage test --" << std::endl;
    d1.take_damage(200); // force HP to 0
    print_status(d1);
    d1.be_repaired(5); // verify behavior when HP is 0
    print_status(d1);

    std::cout << "\n-- Copy & assignment --" << std::endl;
    DiamondTrap d2(d1);
    d2.who_am_i();
    print_status(d2);

    DiamondTrap d3("Temp");
    d3 = d2;
    d3.who_am_i();
    print_status(d3);

    std::cout << "\nEnd of tests." << std::endl;
    return 0;
}
// ...existing code...