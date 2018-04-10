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
# Date: 04/10/18
# Time: 20:47:18
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [a-zA-Z][a-zA-Z0-9]*

    2  [+-][0-9]+|[0-9]+

    3  ["].*["]

4: expression is never matched
    4  if|else|while|for|int|float|string

    5  ;


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x22               goto 3
	0x2b               goto 4
	0x2d               goto 4
	0x30 - 0x39 (10)   goto 5
	0x3b               goto 6
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x64 (4)    goto 7
	0x65               goto 8
	0x66               goto 9
	0x67 - 0x68 (2)    goto 7
	0x69               goto 10
	0x6a - 0x72 (9)    goto 7
	0x73               goto 11
	0x74 - 0x76 (3)    goto 7
	0x77               goto 12
	0x78 - 0x7a (3)    goto 7


state 2
	^INITIAL

	0x22               goto 3
	0x2b               goto 4
	0x2d               goto 4
	0x30 - 0x39 (10)   goto 5
	0x3b               goto 6
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x64 (4)    goto 7
	0x65               goto 8
	0x66               goto 9
	0x67 - 0x68 (2)    goto 7
	0x69               goto 10
	0x6a - 0x72 (9)    goto 7
	0x73               goto 11
	0x74 - 0x76 (3)    goto 7
	0x77               goto 12
	0x78 - 0x7a (3)    goto 7


state 3
	0x00 - 0x09 (10)   goto 3
	0x0b - 0x21 (23)   goto 3
	0x22               goto 13
	0x23 - 0xff (221)  goto 3


state 4
	0x30 - 0x39 (10)   goto 5


state 5
	0x30 - 0x39 (10)   goto 5

	match 2


state 6
	match 5


state 7
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x7a (26)   goto 7

	match 1


state 8
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x6b (11)   goto 7
	0x6c               goto 14
	0x6d - 0x7a (14)   goto 7

	match 1


state 9
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x6b (11)   goto 7
	0x6c               goto 15
	0x6d - 0x6e (2)    goto 7
	0x6f               goto 16
	0x70 - 0x7a (11)   goto 7

	match 1


state 10
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x65 (5)    goto 7
	0x66               goto 7
	0x67 - 0x6d (7)    goto 7
	0x6e               goto 17
	0x6f - 0x7a (12)   goto 7

	match 1


state 11
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x73 (19)   goto 7
	0x74               goto 18
	0x75 - 0x7a (6)    goto 7

	match 1


state 12
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x67 (7)    goto 7
	0x68               goto 19
	0x69 - 0x7a (18)   goto 7

	match 1


state 13
	0x00 - 0x09 (10)   goto 3
	0x0b - 0x21 (23)   goto 3
	0x22               goto 13
	0x23 - 0xff (221)  goto 3

	match 3


state 14
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x72 (18)   goto 7
	0x73               goto 20
	0x74 - 0x7a (7)    goto 7

	match 1


state 15
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x6e (14)   goto 7
	0x6f               goto 21
	0x70 - 0x7a (11)   goto 7

	match 1


state 16
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x71 (17)   goto 7
	0x72               goto 7
	0x73 - 0x7a (8)    goto 7

	match 1


state 17
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x73 (19)   goto 7
	0x74               goto 7
	0x75 - 0x7a (6)    goto 7

	match 1


state 18
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x71 (17)   goto 7
	0x72               goto 22
	0x73 - 0x7a (8)    goto 7

	match 1


state 19
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x68 (8)    goto 7
	0x69               goto 23
	0x6a - 0x7a (17)   goto 7

	match 1


state 20
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x64 (4)    goto 7
	0x65               goto 7
	0x66 - 0x7a (21)   goto 7

	match 1


state 21
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61               goto 17
	0x62 - 0x7a (25)   goto 7

	match 1


state 22
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x68 (8)    goto 7
	0x69               goto 24
	0x6a - 0x7a (17)   goto 7

	match 1


state 23
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x6b (11)   goto 7
	0x6c               goto 20
	0x6d - 0x7a (14)   goto 7

	match 1


state 24
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x6d (13)   goto 7
	0x6e               goto 25
	0x6f - 0x7a (12)   goto 7

	match 1


state 25
	0x30 - 0x39 (10)   goto 7
	0x41 - 0x5a (26)   goto 7
	0x61 - 0x66 (6)    goto 7
	0x67               goto 7
	0x68 - 0x7a (19)   goto 7

	match 1


#############################################################################
# Summary
#############################################################################

Expression 4 is never matched


1 start state(s)
5 expression(s), 25 state(s)


#############################################################################
# End of File
#############################################################################
