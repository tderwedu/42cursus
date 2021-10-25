/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:33:14 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/25 11:30:45 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) {}
		Awesome( int n ) : _n( n ) {}
	
		int	get(void) const
		{ return (this->_n); }
		bool operator==(Awesome const & rhs ) const
		{ return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs ) const
		{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const
		{ return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const
		{ return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const
		{ return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const
		{ return (this->_n <= rhs._n); }
	private:
		int _n;
};

std::ostream&	operator<<(std::ostream &os, Awesome const& rhs)
{
	os << rhs.get();
	return os;
}

template<typename T>
void	print(T const& x)
{
	std::cout << x <<std::endl;
	return ;
}

#endif
