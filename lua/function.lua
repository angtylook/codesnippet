function foo(a,b,c)
    local sum = a + b
    return sum,c
end

r1,r2 = foo(1,"123","hello")
print(r1,r2)

a = {}
b = { x = 1, ["hello"] = "world!"}
a.str = "string"
a[1] = 100
a["table"] = b

function bar()
end

a[bar] = foo

for k,v in pairs(a) do
print(k,"->",v)
end

for k,v in pairs(b) do
print(k,"->",v)
end


