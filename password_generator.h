#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H
#include <string>

class password_generator
{
public:
	std::string generate();

private:
	char get_unique_random_alphanumeric();
	void generate_remaining_chars(int password_length);
	char get_random_char_from_range(char left_bound, char right_bound);
	void generate_minimal_content_requirements();
	int generate_password_length();
	bool is_unique_alphanumeric(char c);

	std::string password;
};

#endif // PASSWORD_GENERATOR_H