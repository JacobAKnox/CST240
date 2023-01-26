#!/usr/bin/perl

# Jacob Knox CST240 Lab 3
# Due 2/1/2022

use strict;
use warnings;

# check arguments
if ($#ARGV != 1) {
    print "Usage: perl railfence.pl key filename\n";
    exit;
}

# read in key and filename from command line args
my $key = $ARGV[0];
my $filename = $ARGV[1];

# check key is a number and greater than 0
if ($key !~ /^\d+$/ || $key < 1) {
    print "Key must be a positiive integer\n";
    exit;
}

# open input file for reading
open (my $fh, '<', $filename) or die "Could not open file '$filename' $!\n";

# open cipher.txt for writing
open (my $fh2, '>', 'cipher.txt') or die "Could not open file 'cipher.txt' $!\n";

# read in file contents line by line
while (my $row = <$fh>) {
    chomp $row;
    # remove non lowercase letters
    $row =~ s/[^a-z]//g;
    # encrypt line using railfence cipher
    my $rail = $key;
    my $rail_length = length($row);
    my @rail_array;
    my $rail_index = 0;
    my $rail_direction = 1;
    # loop through each character in the row
    for (my $i = 0; $i < $rail_length; $i++) {
        # add character to the current rail
        $rail_array[$rail_index] .= substr($row, $i, 1);
        # change direction if we reach the top or bottom rail
        if ($rail_index == 0) {
            $rail_direction = 1;
        } elsif ($rail_index == $rail - 1) {
            $rail_direction = -1;
        }
        # move to the next rail
        $rail_index += $rail_direction;
    }
    # join the rails together
    $row = join "", @rail_array;
    # print encrypted line to cipher.txt
    print $fh2 "$row\n";
}

# close files
close $fh;
close $fh2;

# print success message
print "Encryption complete. Cipher text in cipher.txt\n";