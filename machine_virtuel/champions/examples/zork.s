.name "zork"
.comment "I'M ALIIIIVE"

ardeftgt:
l2:		sti r1, %:live, %1
		sti r2, 23, %34
		#and r1, %0, r1

sti		r4, %:ardeftgt, r2

live:	live %1
		zjmp %:live
