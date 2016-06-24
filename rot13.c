#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
			return 0;
		}
		input[strlen(input)-2] = 0;
		//input now contains the text to be rot'd
	}
	//otherwise...
	else
	{
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
