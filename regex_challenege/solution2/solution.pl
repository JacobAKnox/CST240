#!/bin/perl
use strict;
use warnings;

# 's/.*([0-9]{3}).*([0-9]{3}).*([0-9]{4})/\1-\2-\3/g' =~ numbers.txt;

#loop over each line n numebrs.txt
open my $fh, '<', 'numbers.txt' or die "Can't open file: $!";
for my $line (<$fh>) {
    's/.*(\d{3}).*(\d{3}).*(\d{4})/\1-\2-\3/g' =~ $line;
    print $line;
}
