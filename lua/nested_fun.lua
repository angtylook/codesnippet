function newCounter()
    local i = 0
    return function()
        i = i+1
        return i
    end
end

c1 = newCounter()
c2 = newCounter()
print(c1())
print(c2())
print(c1())

Lib = {}
Lib.add = function(x,y) return x + y end
Lib.sub = function(x,y) return x - y end

print(Lib.add(2,3))


