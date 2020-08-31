#include <iostream>
#include <vector>

#include <readline/readline.h>
#include <readline/history.h>


using namespace std;

char* best_guesses( const char* text, int state_counter ) {
	cout << "state counter: " << state_counter << endl;

	vector<string> options = { "sherlock", "spike", "shrek", "shit" };

	/*
	char* matches[options.size()];
	for( int i=0;i<options.size();++i) {
		// matches[i] = options[i].c_str();
		matches[i] = strdup( options[i].c_str());
	}

	return matches;
	*/
	return strdup("spike");
}


auto rl_custom( const char* text, int start, int end ) {
	// Any number > 0 will disable the default filename listings if matches not found
	rl_attempted_completion_over = 1;

	// Returns NULL if they are no matches
	return rl_completion_matches( text, best_guesses );
}

int print_custom(int count, int key) {
	rl_attempted_completion_over = 1;
	cout << "count: " << count << endl;
	cout << "key: " << key << endl; 

	return key;
}

int main( int argc, char** argv ) {
	// rl_completion_entry_function = best_guesses;
	// rl_bind_key('\t', rl_custom);
	rl_attempted_completion_function = rl_custom;

	char* buf;
	while((buf = readline(">> "))!= nullptr ) {
		if(strlen(buf) > 0) {
			add_history( buf );
		}

		cout << buf << endl;

		free(buf);
	}
	return 0;
}
