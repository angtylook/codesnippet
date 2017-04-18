function multi(...)
	arg = {...}
	for i = 1, #arg, 1 do
		print(arg[i])
	end
end

multi(1, 2, 4, "a", "b")


