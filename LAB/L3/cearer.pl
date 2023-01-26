#!/usr/bin/perl

# Jacob Knox CST240 Lab 3
# Due 2/1/2022

use strict;
use warnings;

# check arguments
if ($#ARGV != 1) {
    print "Usage: perl caesar.pl key filename\n";
    exit;
}

# read in key and filename from command line args
my $key = $ARGV[0];
my $filename = $ARGV[1];

# check key is between 0 and 25
if ($key < 0 || $key > 25) {
    print "Key must be between 0 and 25\n";
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
    # encrypt line using ceasar cipher
    $row = join "", map { $_ = chr((ord($_) - 97 + $key) % 26 + 97) } split //, $row;
    # print encrypted line to cipher.txt
    print $fh2 "$row\n";
}

# close files
close $fh;
close $fh2;

# print success message
print "Encryption complete. Cipher text in cipher.txt\n";