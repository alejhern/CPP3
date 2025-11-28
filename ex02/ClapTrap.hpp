/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:29:43 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 16:29:52 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <typeinfo>
typedef std::string string;

class ClapTrap
{
  private:
	string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

  public:
	ClapTrap(void);
	ClapTrap(string const &name);
	~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &rhs);
	void attack(const string &target);
	void take_damage(unsigned int amount);
	void be_repaired(unsigned int amount);
    string get_name() const;
	unsigned int get_hit_points() const;
	unsigned int get_energy_points() const;
	unsigned int get_attack_damage() const;
	void set_name(const string &name);
	void set_hit_points(unsigned int hit_points);
	void set_energy_points(unsigned int energy_points);
	void set_attack_damage(unsigned int attack_damage);
};

#endif