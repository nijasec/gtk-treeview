\
#!bin/bash

gcc main.c -o main `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -mwindows 
