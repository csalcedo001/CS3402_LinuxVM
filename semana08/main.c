#include <stdio.h>
#include <linux/unistd.h>
#include <sys/syscall.h>

int main (void) {
	syscall(181, NULL);
	return 0;
}
