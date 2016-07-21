#include <stdio.h>
#include <unistd.h>
#include <string.h>

int printhelp( char *input )
{
	if( input[0] != 0x2f && input[0] != 0x2d )
	{
		//arg1 doesn't start with / or -, don't worry abt it
		return 0;
	}
	
	int i = 0;
	for( ; i < 6; i++ )
	{
		//if it's uppercase
		if( input[i] >= 0x41 && input[i] <= 0x5a )
		{
			//make it lowercase
			input[i] += 0x20;
		}
		else if( input[i] == 0 )
		{
			break;
		}
	}
	while( input[0] == 0x2f || input[0] == 0x2d )
	{
		//trim / and - from beginning of string
		input++;
	}
	if(
		strcmp( input, "h" ) == 0 ||
		strcmp( input, "help" ) == 0 ||
		strcmp( input, "?" ) == 0
		)
	{
		printf(
"A simple rot13 utility. Built for Windows but compatible with Linux.\n"
"Licensed under the MIT license, a copy of which is provided in license.txt.\n"
"\n"
"The only available arguments print this text & must be placed before any input:\n"
"\x09-h, --help, /help, -?, or /? (case insensitive)\n"
"\n"
"rot13 will read from the arguments, eg:\n"
"\x09./rot13 The quick brown fox jumps...\n"
"Or, if no arguments are found, the pipeline, eg:\n"
"\x09$ echo \"The quick brown fox jumps...\" | ./rot13\n"
"\n"
"Input past the first 1024 characters is abandoned. Sorry!\n"
"Input outside of ASCII's latin characters aren't modified, ie anything outside\n"
"of 0x41 to 0x5a and 0x61 to 0x7a.\n"
"\n"
"The rot13 of \"help\" is \"uryc\"\n"
"\n"
"More information is available in readme.md or at github.com/9999years/rot13\n"
"Pull requests welcome!\n"
		);
		return 1;
	}
	return 0;
}

char rot13( char *input )
{
	int i = 0;
	for( ; i < strlen( input ); i++ )
	{
		if( //uppercase, first half
			( input[i] >= 0x41 && input[i] <= 0x4d ) ||
			//or lowercase, first half
			( input[i] >= 0x61 && input[i] <= 0x6d )
			)
		{
			input[i] += 13;
		}
		else if ( //uppercase, second half
			( input[i] >= 0x4e && input[i] <= 0x5a ) ||
			//or lowercase, second half
			( input[i] >= 0x6e && input[i] <= 0x7a )
			)
		{
			input[i] -= 13;
		}
	}
	return *input;
}

int main( int argc, char *argv[] )
{
	//input string, for concatenation
	//i'll just "waste" like 1kb of memory i guess
	char input[1024];
	//if there aren't any arguments, look in stdin
	if( argc <= 1 )
	{
		if( read(0, input, 1024) <= 0 )
		{
			//something went wrong, get outta here
			printf( "ERROR reading from stdin" );
			return -1;
		}

		//start at the end of the string, -1 for obo error
		int i = strlen( input ) - 1;

		//go backwards through the string to trim
		//extra \n's or \r's
		while( input[i] == 0xa //lf
			|| input[i] == 0xd
			 )
		{
			input[i] = 0;
			i--;
		}
		//input now contains the text to be rot'd
	}
	//otherwise...
	else
	{
		char firstargument[8];
		strcpy( firstargument, argv[1] );
		if( printhelp( firstargument ) )
		{
			return 0;
		}

		strcpy( input, "\0" );

		int i = 1;
		for( ; i < argc; i++ )
		{
			//if there was a space in the input
			if( i > 1 )
			{
				//tack on a space
				strcat ( input, " " );
			}
			strcat( input, argv[i] );
		}
	}
	//input now contains the text to be rot'd
	rot13( input );
	printf( "%s\n", input );
	return 0;
}
