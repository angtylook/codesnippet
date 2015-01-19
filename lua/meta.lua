--self define data type
fraction_a = {numberator=2, denominator=3}
fraction_b = {numberator=4, denominator=7}
--self define data operator
fraction_op = {}
function fraction_op.__add(f1, f2)
    ret = {}
    ret.numberator = f1.numberator * f2.denominator+ f2.numberator * f1.denominator
    ret.denominator = f1.denominator * f2.denominator
    return ret
end
--associate
setmetatable(fraction_a, fraction_op)
setmetatable(fraction_b, fraction_op)

fraction_s = fraction_a + fraction_b

for k,v in pairs(fraction_s) do
    print(k, v)
end

