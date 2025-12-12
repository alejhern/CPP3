/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:55:28 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 17:55:34 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
  public:
    FragTrap(void);
    FragTrap(string const &name);
    FragTrap(FragTrap const &src);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const &rhs);
    void high_fives_guys(void);
};

#endif
