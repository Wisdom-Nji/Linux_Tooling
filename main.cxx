#include <iostream>
#include <vector>

#include <readline/readline.h>
#include <readline/history.h>


using namespace std;

auto best_guesses( const char* text, int state_counter ) {
	cout << "state counter: " << state_counter << endl;

	vector<string> options = { "sherlock", "spike", "shrek", "shit" };

	char* matches[options.size()];
	for( int i=0;i<options.size();++i) {
		// matches[i] = options[i].c_str();
		matches[i] = strdup( options[i].c_str());
	}

	return matches;
}


auto rl_custom( const char* text, int start, int end ) {
	// Any number > 0 will disable the default filename listings if matches not found
	rl_attempted_completion_over = 1;

	// Returns NULL if they are no matches
	rl_completion_matches( text, best_guesses );
}

int main( int argc, char** argv ) {
	rl_attempted_completion_function = rl_custom;
}
