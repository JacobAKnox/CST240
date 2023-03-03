#!/usr/bin/perl

use strict;
use warnings;

my $phone_number = '(541)-471-3918';
my $phone_pattern = '.?(\d{3}).*(\d{3}).*(\d{4})';

my @phone = $phone_number =~ $phone_pattern;

print "@phone\n";
my $ppart;
foreach $ppart (@phone) {
	print "$ppart \n";
}
