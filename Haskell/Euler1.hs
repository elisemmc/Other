{--
Project Euler Problem 1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
--}

intModBool x
	| (mod x 3) == 0 = True
	| (mod x 5) == 0 = True
	| otherwise = False

numList = [1..1000]

listOfMultiples = filter intModBool numList

answer = sum listOfMultiples