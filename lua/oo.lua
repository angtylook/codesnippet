Animal = {}

function Animal.new(name, sound)
	local o = {}
	o.name = name or "nothing"
	o.sound = sound or "say nothing"
	setmetatable(o, { __index = Animal })
	return o
end

function Animal.respond(self)
	print("The "..self.name.." will "..self.sound..".\n")
end

local something = Animal.new()
local cat = Animal.new("cat", "meow")
local dog = Animal.new("dog", "bark")

something.respond(something)
cat.respond(cat)
dog.respond(dog)

print(something.name)
print(cat.name)
print(dog.name)


