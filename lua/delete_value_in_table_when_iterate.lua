local bullets = {[1]='a', [2]='b', [3]='c'}
for id, bullet in pairs(bullets) do
    print(id, bullet)
    if bullet == 'b' then
        bullets[id] = nil
    end
end

print('after delete value')

for id, bullet in pairs(bullets) do
    print(id, bullet)
end

