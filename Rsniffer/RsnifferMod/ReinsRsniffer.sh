#!/bin/bash
make clean
make
sudo rmmod RsnifferMod
sudo insmod RsnifferMod.ko
