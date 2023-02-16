#!/bin/perl

# Jacob Knox CST240 HW5 2/22/2023

use strict;
use warnings;

# prompt user for purchase price
print "Enter the purchase price: ";
my $purchase_price = <STDIN>;

# make sure the purchase price is an integer
if ($purchase_price !~ /^\d+$/) {
    print "Invalid purchase price. Enter an integer\n";
    exit;
}

# prompt user for current price
print "Enter the current price: ";
my $current_price = <STDIN>;

# make sure the current price is an integer
if ($current_price !~ /^\d+$/) {
    print "Invalid current price. Enter an integer\n";
    exit;
}

# print if they made a profit or loss
if ($current_price > $purchase_price) {
    print "You made money\n";
} elsif ($current_price < $purchase_price) {
    print "You lost money\n";
} else {
    print "You broke even\n";
}

# special case if purchase price is 0
if ($purchase_price == 0) {
    print "Return on investment is infinite%\n";
    exit;
}

# print the percentage of profit or loss
my $percentage = ($current_price - $purchase_price) / $purchase_price * 100;
print "Return on investment is $percentage%\n";
