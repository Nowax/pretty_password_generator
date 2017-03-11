#include <iostream>
#include <password_generator.h>

int main ()
{
	password_generator pg;
	std::cout << pg.generate() << std::endl;
	return 0;
}

