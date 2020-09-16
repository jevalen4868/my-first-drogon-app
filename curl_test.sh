#!/bin/sh

set -m # Enable Job Control

for i in `seq 10000`; do # start 30 jobs in parallel

	sleep 0.1
	curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


	curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


	        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


	        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


	        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &


        curl --header "Content-Type: application/json" "http://localhost:8080/users" -v --data '{ "name" : "Maximus4868", "email" : "Maximus@yahoo.com", "address" : "HOME" }' &



done

# Wait for all parallel jobs to finish
while [ 1 ]; do fg 2> /dev/null; [ $? == 1 ] && break; done
