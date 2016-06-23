#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {
	//if there aren't any arguments, we have nothing to do
	if( argc <= 1 )
	{
		return 0;
	}
	//otherwise...
	else
	{
		//input string, for concatenation
		//i'll just "waste" like 1kb of memory i guess
		char input[1024];
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

		//input now contains the text to be rot'd
		//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
		//NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm
		i = 0;
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
		printf( "%s\n", input );
		return 0;
	}
}
