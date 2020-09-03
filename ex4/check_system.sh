#!/bin/bash

####################
# Lab 1 Exercise 4
# Name: Chee You
# Student No: A0188719J
# Lab Group: 01
####################

# fill the below up
hostname=$(uname -n)
kernel_version=$(uname -r)
process_cnt=$(ps axu --no-headers | wc -l)
user_process_cnt=$(ps -U cheeyou --no-headers | wc -l)
mem_usage=$(free | awk 'NR==2{print 100*$3/$2}')
swap_usage=$(free | awk 'NR==3{print 100*$3/$2}')

echo "Hostname: $hostname"
echo "Linux Kernel Version: $kernel_version"
echo "Total Processes: $process_cnt"
echo "User Processes: $user_process_cnt"
echo "Memory Used (%): $mem_usage"
echo "Swap Used (%): $swap_usage"
