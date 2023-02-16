#!/bin/perl

# Jacob Knox CST240 Midterm 2/15/2023

use strict;
use warnings;

# check the number of arguments
if ($#ARGV != 1) {
    print "Usage: xorencryption.pl <key> <filename>\n";
    exit;
}

# read in a key and filename
my $key = $ARGV[0];
my $filename = $ARGV[1];

# make sure key is an integer
if ($key !~ /^\d+$/) {
    print "Key must be an integer\n";
    exit;
}

# make sure key is int the 0-127 range
if ($key < 0 || $key > 127) {
    print "Key must be in the range 0-127\n";
    exit;
}

# open the file
open my $file, '<', $filename or die "Could not open file '$filename'";

# loop through the file
while (my $row = <$file>) {
    chomp $row;
    # loop through each character in the line
    for (my $i = 0; $i < length($row); $i++) {
        # if the character is not A-Z skip it
        if (ord(substr($row, $i, 1)) < 65 || ord(substr($row, $i, 1)) > 90) {
            next;
        }
        # get the character
        my $char = substr($row, $i, 1);
        # xor the character with the key
        my $xor = ord($char) ^ $key;
        # print the character
        print chr($xor);
    }
    # print a new line
    print "\n";
}

# close the file
close $file;
