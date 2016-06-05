#!/bin/bash

top | grep "load"&

./SharedMemory

./GettingSharedMemory

kill -9 $!;
