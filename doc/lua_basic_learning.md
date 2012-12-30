#lua的基本语法
##hello world
```lua
print("hello world")
```
最简单的hello world，输出函数print，参数是字符串。

##词法

标识符的定义方法跟Ｃ语言一样，下划线或者字母开头，后面的可以是下划线、字母、数字。
注释： 单行用`--`多行用`--[[comment]]`

##变量

```lua
print(b)
b = 10
print(b)
b = nil
print(b)
```

lua中使用变量，赋值后直接用，若没赋值，那值就是nil，若要删除一个变量，那就赋值为nil吧。

**这里的变量都是全局变量，在函数中定义的变量也是，除非声明为`local`**

##数据类型

`nil, boolean, number, string, userdata,function,thread,table`

* `nil`啥也没有
* `boolean`除了false和nil为假，其它的俱为真
* `userdata`应该相当于自定义数据类型
* `thread` 线程？不太好理解
* `table`  表，据说比较复杂
* `string`用单引号或双引号括起来的字符序列，包含以＼开始的的转义字符。
	* 字符串可以与数字间相互转换，用`tonumber(string)`和`tostring(number)`
	* 可以用`[[multi line string]]`括起一段字符串。

##function

```lua
function foo(a,b,c)
    local sum = a + b
    return sum,c
end

r1,r2 = foo(1,"123","hello")
print(r1,r2)
```

- 定义一个函数以function开始，end结束。跟其它语法一样，后面跟有函数名和小括号内的参数列表。

- 函数内可以使用函数外的的变量，默认都是全局变量，要定义本地变量，用local修饰。

-  可以返回多个值，并进行平行的赋值，就是一一对应。

##table

```lua
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
```
定义一个表，就是用`{}`括起来定义一些键值对，以后也可以通过`.`和`[]`进行访问或得添加，删除的话，置为`nil`即可！这里的键值对可以是任何东西，比如表到表的键值对。
