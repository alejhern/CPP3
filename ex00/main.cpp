/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:44:03 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 17:44:25 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap alice("Alice");
    ClapTrap bob("Bob");
    ClapTrap defaultTrap;
    ClapTrap copyTrap(alice);
    ClapTrap assignedTrap;

    // Usar setters para establecer el daño de ataque
    alice.set_attack_damage(10);
    bob.set_attack_damage(4);
    defaultTrap.set_attack_damage(2);
    copyTrap.set_attack_damage(5);  // prueba en copia

    // Mostrar estado inicial usando getters
    std::cout << alice.get_name() << " - HP: " << alice.get_hit_points()
              << " | EP: " << alice.get_energy_points()
              << " | AD: " << alice.get_attack_damage() << std::endl;

    std::cout << bob.get_name() << " - HP: " << bob.get_hit_points()
              << " | EP: " << bob.get_energy_points()
              << " | AD: " << bob.get_attack_damage() << std::endl;

    // Ataque usando getters para obtener el daño y setters ya aplicado arriba
    alice.attack(bob.get_name());
    bob.take_damage(alice.get_attack_damage());

    // Bob se cura
    bob.be_repaired(3);

    // Depletar la energía de Alice atacando repetidamente
    for (int i = 0; i < 12; ++i)
        alice.attack("training dummy");

    // Infligir daño fatal a Bob y tratar de repararlo
    bob.take_damage(100);
    bob.be_repaired(10);

    // Probar assignment y mostrar estados finales
    assignedTrap = bob;
    assignedTrap.set_attack_damage(7);

    std::cout << "Final states:\n";
    std::cout << alice.get_name() << " - HP: " << alice.get_hit_points()
              << " | EP: " << alice.get_energy_points()
              << " | AD: " << alice.get_attack_damage() << std::endl;

    std::cout << bob.get_name() << " - HP: " << bob.get_hit_points()
              << " | EP: " << bob.get_energy_points()
              << " | AD: " << bob.get_attack_damage() << std::endl;

    std::cout << assignedTrap.get_name() << " (assigned) - HP: " << assignedTrap.get_hit_points()
              << " | EP: " << assignedTrap.get_energy_points()
              << " | AD: " << assignedTrap.get_attack_damage() << std::endl;

    (void)defaultTrap;
    (void)copyTrap;
    return 0;
}
