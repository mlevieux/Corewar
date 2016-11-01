.name "zork"
.comment "I'M ALIIIIVE"

sti r1, r3, %34

live:	live %1
		zjmp %:live
