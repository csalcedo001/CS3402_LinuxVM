#include <linux/kernel.h>

asmlinkage long newsyscall (struct prinfo *p) {
	printk("Sistemas Operativos !!!!\n");
	return 0;
}
