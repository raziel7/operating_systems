#!/bin/bash

for VAR in {2..16}
do
	./first | ./second ${VAR}
done

