index = 100
repeat
    print("loop pass: ",index)
    index = index + 1
until index > 10

local function transform(arr, func)
    for k, v in pairs(arr) do
        arr[k] = func(arr[k])
    end
end

local arr = {1, 2, 3}
transform(arr, function(v) return v*v end)
for k, v in pairs(arr) do
    print(v)
end

