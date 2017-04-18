IntCell = { storedValue = 0 }

function IntCell:new(orig)
	if type(orig) == "number" then
		o = {}
		o.storedValue = orig
	else
		o = orig or {}
	end
	setmetatable(o, self)
	self.__index = self
	return o
end

function IntCell:read()
	return self.storedValue
end

function IntCell:write(x)
	self.storedValue = x
end

--test code
--new IntCEll and read and write
a = IntCell:new()
print("a:"..(a:read()))
a:write(10)
print("a:"..(a:read()))

--create IntCell from a
b = IntCell:new(a)
print("b:"..(b:read()))

--create IntCell from a number
c = IntCell:new(100)
print("c:"..(c:read()))



