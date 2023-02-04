#!/bin/perl

use strict;
use warnings;

# check for correct number of arguments
if ($#ARGV != 1) {
    print "Usage: script.pl <input file> <output file>\n";
    exit 1;
}

# open file
open(my $fh, '<', $ARGV[0]) or die "Could not open file '$ARGV[0]' $!\n";

# open output file
open(my $fh2, '>', $ARGV[1]) or die "Could not open file '$ARGV[1]' $!\n";

# read file line by line
while (my $row = <$fh>) {
    chomp $row;
    
    # check if the line contains any digits
    if ($row =~ /\d/) {
        # replace all digits with a 'x'
        $row =~ s/\d/x/g;
        #output the line to file
        print $fh2 "$row\n";
    }

    # if the line does not contain any digits do nothing
}

# close files
close $fh;
close $fh2;