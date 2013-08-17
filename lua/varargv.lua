function HowMany(...)
    if select('#',...) > 0 then
	for index = 1, select('#',...) do
	    local myString = string.format("%s%d","Argument ",index,":")
	    print(myString,select(index, ... ))
	end
    else
	print("No variables entered.")
    end
end

HowMany("a",2,"b",13)
HowMany(nil,nil)
HowMany()

