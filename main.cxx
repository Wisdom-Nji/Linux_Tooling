#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>


using namespace std;


auto rl_custom( auto input ) {
}

int main( int argc, char** argv ) {
	int rl_value = rl_bind_key('\t', rl_custom );
}
