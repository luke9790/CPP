/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:06:57 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:06:58 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();

	void announce() const;
	static Zombie* newZombie(std::string name);
	static void randomChump(std::string name);
};

#endif