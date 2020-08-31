#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>


using namespace std;


int rl_custom( int input1, int input2 ) {
}

int main( int argc, char** argv ) {
	int rl_value = rl_bind_key('\t', rl_custom );
}
