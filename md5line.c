#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif

// credit to Todd (http://stackoverflow.com/users/314941/todd)
char *str2md5(const char *str, int length)
{
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*)malloc(33);
	MD5_Init(&c);
	while (length > 0) {
		if (length > 512) {
			MD5_Update(&c, str, 512);
		} else {
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}
	MD5_Final(digest, &c);
	for (n = 0; n < 16; ++n) {
		snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
	}
	return out;
}

char *readFromIn(char *buffer)
{
	char *result = fgets(buffer, 1024, stdin);
	int len;
	if (result == NULL) {
		return NULL;
	}
	len = strlen (buffer);
	if (len == 0) {
		return NULL;
	}
	if (buffer[len - 1] == '\n') {
		buffer[len - 1] = 0;
	}
	return buffer;
}

int main(int argc, char *argv[])
{
	char buf[1024];
	while (readFromIn(buf)) {
		printf("%s  %s\n", str2md5(buf, strlen(buf)), buf);
	}

	return 0;
}
