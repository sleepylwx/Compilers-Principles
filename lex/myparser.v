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
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 04/10/18
# Time: 20:18:12
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : Grammar $end

    1  Grammar :


##############################################################################
# States
##############################################################################

state 0
	$accept : . Grammar $end
	Grammar : .  (1)

	.  reduce 1

	Grammar  goto 1


state 1
	$accept : Grammar . $end  (0)

	$end  accept


##############################################################################
# Summary
##############################################################################

2 token(s), 2 nonterminal(s)
2 grammar rule(s), 2 state(s)


##############################################################################
# End of File
##############################################################################
