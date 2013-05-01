-- file 'foo.lua'
function foo(n)
	if n < 2 then
		return 1
	else
		return foo(n-1) + foo(n-2)
	end
end
