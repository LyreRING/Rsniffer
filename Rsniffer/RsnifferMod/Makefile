KERN_DIR = /lib/modules/$(shell uname -r)/build
obj-m += RsnifferMod.o
RsnifferMod-objs := RsnifferNlkernel.o RsnifferMod_main.o

all:
	make -C $(KERN_DIR) M=$(shell pwd) modules   
clean:                                  
	make -C $(KERN_DIR) M=$(shell pwd) modules clean
	rm -rf modules.order
	rm -f *.symvers

test: all
	rmmod -f RsnifferMod; \
	insmod RsnifferMod.ko
