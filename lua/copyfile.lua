function FileSaveLoad()
    local file = io.open("function.lua","r")
    local data = file:read("*a")
    file:close()
    file = io.open("_function1.lua","w")
    file:write(data)
    file:close()
end

FileSaveLoad()

