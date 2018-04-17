#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 1 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 04/17/18
# Time: 17:50:10
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  if|else|while|for|int|float|string

    2  [a-zA-Z][a-zA-Z0-9]*

    3  [+-][0-9]+|[0-9]+

    4  ["].*["]

    5  [+]|[-]|[*]|[/]|[=]|[+][=]|[-][=]|[*][=]|[/][=]|[=][=]|[<][=]|[>][=]|[<]|[>]

    6  ;


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x22               goto 3
	0x2a               goto 4
	0x2b               goto 5
	0x2d               goto 5
	0x2f               goto 4
	0x30 - 0x39 (10)   goto 6
	0x3b               goto 7
	0x3c               goto 4
	0x3d               goto 4
	0x3e               goto 4
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x64 (4)    goto 8
	0x65               goto 9
	0x66               goto 10
	0x67 - 0x68 (2)    goto 8
	0x69               goto 11
	0x6a - 0x72 (9)    goto 8
	0x73               goto 12
	0x74 - 0x76 (3)    goto 8
	0x77               goto 13
	0x78 - 0x7a (3)    goto 8


state 2
	^INITIAL

	0x22               goto 3
	0x2a               goto 4
	0x2b               goto 5
	0x2d               goto 5
	0x2f               goto 4
	0x30 - 0x39 (10)   goto 6
	0x3b               goto 7
	0x3c               goto 4
	0x3d               goto 4
	0x3e               goto 4
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x64 (4)    goto 8
	0x65               goto 9
	0x66               goto 10
	0x67 - 0x68 (2)    goto 8
	0x69               goto 11
	0x6a - 0x72 (9)    goto 8
	0x73               goto 12
	0x74 - 0x76 (3)    goto 8
	0x77               goto 13
	0x78 - 0x7a (3)    goto 8


state 3
	0x00 - 0x09 (10)   goto 3
	0x0b - 0x21 (23)   goto 3
	0x22               goto 14
	0x23 - 0xff (221)  goto 3


state 4
	0x3d               goto 15

	match 5


state 5
	0x30 - 0x39 (10)   goto 6
	0x3d               goto 15

	match 5


state 6
	0x30 - 0x39 (10)   goto 6

	match 3


state 7
	match 6


state 8
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x7a (26)   goto 8

	match 2


state 9
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x6b (11)   goto 8
	0x6c               goto 16
	0x6d - 0x7a (14)   goto 8

	match 2


state 10
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x6b (11)   goto 8
	0x6c               goto 17
	0x6d - 0x6e (2)    goto 8
	0x6f               goto 18
	0x70 - 0x7a (11)   goto 8

	match 2


state 11
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x65 (5)    goto 8
	0x66               goto 19
	0x67 - 0x6d (7)    goto 8
	0x6e               goto 20
	0x6f - 0x7a (12)   goto 8

	match 2


state 12
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x73 (19)   goto 8
	0x74               goto 21
	0x75 - 0x7a (6)    goto 8

	match 2


state 13
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x67 (7)    goto 8
	0x68               goto 22
	0x69 - 0x7a (18)   goto 8

	match 2


state 14
	0x00 - 0x09 (10)   goto 3
	0x0b - 0x21 (23)   goto 3
	0x22               goto 14
	0x23 - 0xff (221)  goto 3

	match 4


state 15
	match 5


state 16
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x72 (18)   goto 8
	0x73               goto 23
	0x74 - 0x7a (7)    goto 8

	match 2


state 17
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x6e (14)   goto 8
	0x6f               goto 24
	0x70 - 0x7a (11)   goto 8

	match 2


state 18
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x71 (17)   goto 8
	0x72               goto 19
	0x73 - 0x7a (8)    goto 8

	match 2


state 19
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x7a (26)   goto 8

	match 1


state 20
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x73 (19)   goto 8
	0x74               goto 19
	0x75 - 0x7a (6)    goto 8

	match 2


state 21
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x71 (17)   goto 8
	0x72               goto 25
	0x73 - 0x7a (8)    goto 8

	match 2


state 22
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x68 (8)    goto 8
	0x69               goto 26
	0x6a - 0x7a (17)   goto 8

	match 2


state 23
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x64 (4)    goto 8
	0x65               goto 19
	0x66 - 0x7a (21)   goto 8

	match 2


state 24
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61               goto 20
	0x62 - 0x7a (25)   goto 8

	match 2


state 25
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x68 (8)    goto 8
	0x69               goto 27
	0x6a - 0x7a (17)   goto 8

	match 2


state 26
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x6b (11)   goto 8
	0x6c               goto 23
	0x6d - 0x7a (14)   goto 8

	match 2


state 27
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x6d (13)   goto 8
	0x6e               goto 28
	0x6f - 0x7a (12)   goto 8

	match 2


state 28
	0x30 - 0x39 (10)   goto 8
	0x41 - 0x5a (26)   goto 8
	0x61 - 0x66 (6)    goto 8
	0x67               goto 19
	0x68 - 0x7a (19)   goto 8

	match 2


#############################################################################
# Summary
#############################################################################

1 start state(s)
6 expression(s), 28 state(s)


#############################################################################
# End of File
#############################################################################
