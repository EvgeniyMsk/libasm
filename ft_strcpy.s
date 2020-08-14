global		_ft_strcpy

_ft_strcpy:
				mov		rax, 			-1

loop:
				inc		rax
				mov		cl,				[rsi + rax]
				mov		[rdi + rax],	cl
				cmp		cl,				0
				jne		loop

return:
				mov		rax,			rdi
				ret