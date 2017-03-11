#include "password_generator.h"
#include <random>
#include <algorithm>

std::string password_generator::generate()
{
	generate_minimal_content_requirements();
	generate_remaining_chars(generate_password_length());
	std::shuffle(password.begin(), password.end(),
	             std::default_random_engine(std::random_device()()));

	return password;
}

void password_generator::generate_minimal_content_requirements()
{
	password.push_back(get_random_char_from_range('a','z'));
	password.push_back(get_random_char_from_range('A','Z'));
	password.push_back(get_random_char_from_range('0','9'));
}

char password_generator::get_random_char_from_range(char left_bound, char right_bound)
{
	std::random_device r;
	std::uniform_int_distribution<char> uid(left_bound, right_bound);
	return uid(r);
}

int password_generator::generate_password_length()
{
	return get_random_char_from_range(3,17);
}

void password_generator::generate_remaining_chars(int password_length)
{
	for (int i = 0; i < password_length; i++) {
		password.push_back(get_unique_random_alphanumeric());
	}
}

char password_generator::get_unique_random_alphanumeric()
{
	char t;

	do {
		t = get_random_char_from_range('0','z');
	} while (is_unique_alphanumeric(t));

	return t;
}

bool password_generator::is_unique_alphanumeric(char c)
{
	return !isalnum(c) ||
	       std::find(password.begin(), password.end(), c) != password.end();
}