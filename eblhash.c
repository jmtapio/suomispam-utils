/*
 * Converts email address to Suomispam EBL hash name that you use to check for listing.
 * Compile gcc -Wall eblhash.c -lcrypto
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>


int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("USAGE\n    %s <emailaddress>\n", argv[0]);
		return 1;
	}

	char *data = argv[1];
	unsigned char buf[SHA_DIGEST_LENGTH];
	int i;

	for(i=0; data[i]; i++) {
		data[i] = tolower(data[i]);
	}

	SHA1((unsigned char*) data, strlen(data), buf);
	for (i=0; i<SHA_DIGEST_LENGTH; i++) {
		printf("%02x", buf[i]);
	}
	printf(".ebl.suomispam.net\n");
	return 0;
}
