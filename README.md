# 8080_XorShift
a pre-compiled library for Pascal/MT+ with pure 8080 asembler for use on CPM


This is a simple to use include and use set of ERLS developed on a V20-MBC Single board computer running in 8080 mode.
You can inclde these files by adding {$I rand.def} after your declaration block.  You can then link xrnd.erl and rand.erl
to your main program code.

NOTE: the asembler code automatically handles the entry points within the context of pascal/mt+ if you wish to use this with
another compiled language that uses microsofts relocateable file format you will need to consult that compilers manual and update 
the code for working with your specific compiler.
