global	_ft_strlen

_ft_strlen:
				mov		rax,		-1

loop:
				inc		rax
				mov		cl,			[rdi + rax]
				cmp		cl,			0
				jne		loop

return:
				ret