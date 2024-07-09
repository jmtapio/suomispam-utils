#!/usr/bin/perl

# Takes a list of email addresses from standard input or a named file,
# checks them against the specified HashBL zone, and prints out a list
# of any addresses in the source that were NOT found on the list.

use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);

die "usage: $0 blzone [filename]" if ( $#ARGV < 0 );

$blzone = shift;

while (<>) {
  chomp $_;
  $dnsname = sha1_hex($_) . "." . $blzone;
  print $_ . "\n" unless gethostbyname($dnsname);
}
